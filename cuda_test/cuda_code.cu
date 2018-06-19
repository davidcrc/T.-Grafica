#include <ctime>
#include <stdio.h>
#include <cuda_runtime.h>
#include <iostream>
#include <vector>

#define RED 2
#define GREEN 1
#define BLUE 0


using namespace std;

extern "C"
cudaError_t cuda_main()
{
    const int kb = 1024;
    const int mb = kb * kb;
    wcout << "NBody.GPU" << endl << "=========" << endl << endl;


    int devCount;
    cudaGetDeviceCount(&devCount);
    wcout << "Dispositivo CUDA : " << endl << endl;

    for(int i = 0; i < devCount; ++i)
    {
        cudaDeviceProp props;
        cudaGetDeviceProperties(&props, i);
        wcout << i << ": " << props.name << ": " << props.major << "." << props.minor << endl;
        wcout << "Memoria global:   " << props.totalGlobalMem / mb << "mb" << endl;
        wcout << "Memoria compartida:   " << props.sharedMemPerBlock / kb << "kb" << endl;
        wcout << "Memoria constante: " << props.totalConstMem / kb << "kb" << endl;
        wcout << "Registros por bloque: " << props.regsPerBlock << endl << endl;
        wcout << "Multi Processor Count: " << props.multiProcessorCount << endl << endl;

        wcout << "Tamano Warp :         " << props.warpSize << endl;
        wcout << "Threads por block: " << props.maxThreadsPerBlock << endl;
        wcout << "Dimension Max block : [ " << props.maxThreadsDim[0] << ", " << props.maxThreadsDim[1]  << ", " << props.maxThreadsDim[2] << " ]" << endl;
        wcout << "Dimension Max grid :  [ " << props.maxGridSize[0] << ", " << props.maxGridSize[1]  << ", " << props.maxGridSize[2] << " ]" << endl;
        wcout << endl;
    }

    return cudaGetLastError();
}

//funcion device
__device__ unsigned char clamp(int value){
    if(value < 0)
        value = 0;
    else
        if(value > 255)
            value = 255;
    return (unsigned char)value;
}

//funcion global de filtro
__global__ void Convolucion(char *M, unsigned char *imageInput, int width, int height, \
        unsigned int maskWidth,unsigned char *imageOutput){

    unsigned int row = blockIdx.y*blockDim.y+threadIdx.y;
    unsigned int col = blockIdx.x*blockDim.x+threadIdx.x;

    int Pvalue = 0;

    int start_row = row - (maskWidth/2);
    int start_col = col - (maskWidth/2);

    for(int i = 0; i < maskWidth; i++){
        for(int j = 0; j < maskWidth; j++ ){
            if((start_col + j >=0 && start_col + j < width) \
                    &&(start_row + i >=0 && start_row + i < height)){
                Pvalue += imageInput[(start_row + i)*width+(start_col + j)] * M[i*maskWidth+j];
            }
        }
    }
    imageOutput[row*width+col] = clamp(Pvalue);
}

//funcion global de escala de grises
__global__ void img2gray(unsigned char *imageInput, int width, int height, unsigned char *imageOutput){
    int row = blockIdx.y*blockDim.y+threadIdx.y;
    int col = blockIdx.x*blockDim.x+threadIdx.x;

    if((row < height) && (col < width)){
        imageOutput[row*width+col] = imageInput[(row*width+col)*3+RED]*0.299 + imageInput[(row*width+col)*3+GREEN]*0.587 \
                                     + imageInput[(row*width+col)*3+BLUE]*0.114;
    }
}

//funcion global de filtro
__global__ void FilterColor(char *M, unsigned char *imageInput, int width, int height, \
    unsigned int maskWidth,unsigned char *imageOutput, float coef){

    unsigned int row = blockIdx.y*blockDim.y+threadIdx.y;
    unsigned int col = blockIdx.x*blockDim.x+threadIdx.x;

    int Pvalue = 0.0;

    int start_row = row - (maskWidth/2);
    int start_col = col - (maskWidth/2);

    for(int i = 0; i < maskWidth; i++){
        for(int j = 0; j < maskWidth; j++ ){
            if((start_col + j >=0 && start_col + j < width) \
                    &&(start_row + i >=0 && start_row + i < height)){
                Pvalue += imageInput[(start_row + i)*width+(start_col + j)] * M[i*maskWidth+j]*coef;
            }
        }
    }
    imageOutput[row*width+col] = clamp(Pvalue);

}
cudaError_t  convolucionCuda(int width, int height, int size, int sizeGray, unsigned char *dataRawImage, unsigned char *&h_imageOutput, \
                             int MASK_WIDTH, char *h_M){
    cudaError_t error = cudaSuccess;
    clock_t startGPU, endGPU;
    double gpu_time;
    int sizeM = sizeof(char)*MASK_WIDTH*MASK_WIDTH;
    char *d_M;
    unsigned char *d_dataRawImage, *d_imageOutput, *d_sobelOutput;

    //Reserva de Memoria para M
    error = cudaMalloc((void**)&d_M,sizeM);
    if(error != cudaSuccess){
        printf("Error reservando memoria para d_M\n");
        exit(-1);
    }

    //Reserva de Memoria para d_dataRawImage
    error = cudaMalloc((void**)&d_dataRawImage,size);
    if(error != cudaSuccess){
        printf("Error reservando memoria para d_dataRawImage\n");
        exit(-1);
    }

    //Reserva de Memoria para d_imageOutput
    error = cudaMalloc((void**)&d_imageOutput,sizeGray);
    if(error != cudaSuccess){
        printf("Error reservando memoria para d_imageOutput\n");
        exit(-1);
    }

    //Reserva de Memoria para d_sobelOutput
    error = cudaMalloc((void**)&d_sobelOutput,sizeGray);
    if(error != cudaSuccess){
        printf("Error reservando memoria para d_sobelOutput\n");
        exit(-1);
    }

    //Algoritmo Paralelo con CUDA
    startGPU = clock();

    error = cudaMemcpy(d_dataRawImage,dataRawImage,size, cudaMemcpyHostToDevice);
    if(error != cudaSuccess){
       printf("Error copiando los datos de dataRawImage a d_dataRawImage \n");
       exit(-1);
    }

    error = cudaMemcpy(d_M,h_M,sizeM, cudaMemcpyHostToDevice);
    if(error != cudaSuccess){
       printf("Error copiando los datos de h_M a d_M \n");
       exit(-1);
    }

    int blockSize = 32;
    dim3 dimBlock(blockSize,blockSize,1);
    dim3 dimGrid(ceil(width/float(blockSize)),ceil(height/float(blockSize)),1);
    //llamamos la funcion de escala de grises
    img2gray<<<dimGrid,dimBlock>>>(d_dataRawImage,width,height,d_imageOutput);
    //Sincronizamos
    cudaDeviceSynchronize();
    //llamamos la funcion de filtro de sobel
    Convolucion<<<dimGrid,dimBlock>>>(d_M, d_imageOutput,width,height,MASK_WIDTH,d_sobelOutput);
    cudaMemcpy(h_imageOutput,d_sobelOutput,sizeGray,cudaMemcpyDeviceToHost);

    endGPU = clock();
    //fin algoritmo Paralelo con CUDA

    //imprimir tiempos de ejecucion
    gpu_time = ((double) (endGPU - startGPU)) / CLOCKS_PER_SEC;
    printf("Tiempo Algoritmo Paralelo CUDA: %.10f\n",gpu_time);

    //limpiar memoria
    cudaFree(d_dataRawImage);
    cudaFree(d_imageOutput);
    cudaFree(d_M);
    cudaFree(d_sobelOutput);

    return cudaGetLastError();
}


cudaError_t  convolucionCudaColor(int width, int height, int sizeGray, unsigned char * splB, unsigned char * splG, unsigned char * splR,\
                    unsigned char *&h_imageOutputB,unsigned char *&h_imageOutputG,unsigned char *&h_imageOutputR,\
                    int MASK_WIDTH, char *h_M, float coef){

    cudaError_t error = cudaSuccess;
    clock_t startGPU, endGPU;
    double gpu_time;
    int sizeM = sizeof(char)*MASK_WIDTH*MASK_WIDTH;
    char *d_M;
    unsigned char *d_dataRawImageB, *d_dataRawImageG, *d_dataRawImageR, *d_sobelOutput;

    //Reserva de Memoria para M
    error = cudaMalloc((void**)&d_M,sizeM);
    if(error != cudaSuccess){
        printf("Error reservando memoria para d_M\n");
        exit(-1);
    }

    error = cudaMalloc((void**)&d_dataRawImageB,sizeGray);
    error = cudaMalloc((void**)&d_dataRawImageG,sizeGray);
    error = cudaMalloc((void**)&d_dataRawImageR,sizeGray);
    if(error != cudaSuccess){
        printf("Error reservando memoria para d_dataRawImage\n");
        exit(-1);
    }


    //Reserva de Memoria para d_sobelOutput
    error = cudaMalloc((void**)&d_sobelOutput,sizeGray);
    if(error != cudaSuccess){
        printf("Error reservando memoria para d_sobelOutput\n");
        exit(-1);
    }

    //Algoritmo Paralelo con CUDA
    startGPU = clock();


    error = cudaMemcpy(d_M,h_M,sizeM, cudaMemcpyHostToDevice);
    if(error != cudaSuccess){
       printf("Error copiando los datos de h_M a d_M  \n");
       exit(-1);
    }

    int blockSize = 32;
    dim3 dimBlock(blockSize,blockSize,1);
    dim3 dimGrid(ceil(width/float(blockSize)),ceil(height/float(blockSize)),1);

    cudaDeviceSynchronize();

    error = cudaMemcpy(d_dataRawImageB,splB,sizeGray, cudaMemcpyHostToDevice);
    if(error != cudaSuccess){
        printf("Error copiando los datos de splB a d_dataRawImage \n");
        exit(-1);
    }
    FilterColor<<<dimGrid,dimBlock>>>(d_M, d_dataRawImageB,width,height,MASK_WIDTH,d_sobelOutput,coef);
    cudaMemcpy(h_imageOutputB,d_sobelOutput,sizeGray,cudaMemcpyDeviceToHost);
    cudaDeviceSynchronize();

    ///////////////////////////

    error = cudaMemcpy(d_dataRawImageG,splG,sizeGray, cudaMemcpyHostToDevice);
    if(error != cudaSuccess){
        printf("Error copiando los datos de splG a d_dataRawImage \n");
        exit(-1);
    }


    FilterColor<<<dimGrid,dimBlock>>>(d_M,d_dataRawImageG,width,height,MASK_WIDTH,d_sobelOutput,coef);
    cudaMemcpy(h_imageOutputG,d_sobelOutput,sizeGray,cudaMemcpyDeviceToHost);

    cudaDeviceSynchronize();

    /////////////////////////////

    error = cudaMemcpy(d_dataRawImageR,splR,sizeGray, cudaMemcpyHostToDevice);
    if(error != cudaSuccess){
        printf("Error copiando los datos de splR a d_dataRawImage \n");
        exit(-1);
    }

    FilterColor<<<dimGrid,dimBlock>>>(d_M,d_dataRawImageR,width,height,MASK_WIDTH,d_sobelOutput,coef);
    cudaMemcpy(h_imageOutputR,d_sobelOutput,sizeGray,cudaMemcpyDeviceToHost);
    cudaDeviceSynchronize();


    endGPU = clock();
    //fin algoritmo Paralelo con CUDA

    //imprimir tiempos de ejecucion
    gpu_time = ((double) (endGPU - startGPU)) / CLOCKS_PER_SEC;
    printf("Tiempo Algoritmo Paralelo CUDA: %.10f\n",gpu_time);

    //limpiar memoria
    cudaFree(d_dataRawImageB);
    cudaFree(d_dataRawImageG);
    cudaFree(d_dataRawImageR);

    cudaFree(d_M);
    cudaFree(d_sobelOutput);

    return cudaGetLastError();
}
