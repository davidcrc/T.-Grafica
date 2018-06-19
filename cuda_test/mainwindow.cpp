#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>
#include <fstream>
#include "cuda_runtime.h"
#include <iostream>
#include <QtGui>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>

using namespace cv;
using namespace std;

#define MASK_WIDTH 3

__constant__ char M[MASK_WIDTH*MASK_WIDTH];

extern "C"
cudaError_t cuda_main();
cudaError_t convolucionCuda(int, int, int, int, unsigned char *,unsigned char *&,int ,char *);
cudaError_t convolucionCudaColor(int , int , int , unsigned char * ,unsigned char * ,unsigned char * , \
                                 unsigned char *& ,unsigned char *&,unsigned char *&, int , char *h_M, float coef);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbrir_triggered(QString rutaImagen)
{
    if (rutaImagen.isEmpty()) {

         //Abrir ruta y seleccionar tipo de imagen
        rutaImagen = QFileDialog::getOpenFileName(this, tr("Abrir imagen"), QString(),
            tr("Imagen BMP (*.bmp);;Todos los archivos (*)"));
    }

    if (!rutaImagen.isEmpty()) {

        QFile file(rutaImagen);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr(WINDOW_CRITICAL), tr("No se puede abrir la imagen."));
            return;
        }

        //Borrar imagen anterior
//        ui->show_img->clear();
        std::string input = rutaImagen.toUtf8().constData();
        cout << "la ruta: " << input << endl;
        //Cargar imagen
        inputImage = cv::imread(input, IMREAD_COLOR);

        if (inputImage.data){
            cvtColor(inputImage, inputImage, 4 );
            cout << "ok!" << "av er " << inputImage.cols<< " " <<inputImage.rows <<" step: " << inputImage.step << endl;
            image1= QImage(inputImage.data, inputImage.cols, inputImage.rows, inputImage.step, QImage::Format_RGB888);

            //show Qimage using QLabel
            ui->show_img->setPixmap(QPixmap::fromImage(image1));
//            ui->show_img->adjustSize();
            ui->show_img->setScaledContents( true );

            ui->show_imgBi->setPixmap(QPixmap::fromImage(image1));
//            ui->show_imgBi->adjustSize();
            ui->show_imgBi->setScaledContents( true );

            QHBoxLayout *hlayout1 = new QHBoxLayout;
            hlayout1->addWidget(ui->show_imgBi);

//            setLayout(hlayout1);

        }


    }
}

void MainWindow::on_infoCuda_clicked()
{
    // run your cuda application
    cudaError_t cuerr = cuda_main();
    // check for errors is always a good practice!
    if (cuerr != cudaSuccess) cout << "CUDA Error: " << cudaGetErrorString( cuerr ) << endl;
}


void MainWindow::on_button_sobel_clicked()
{

}

void MainWindow::on_actionAbrir_Filtro_triggered(QString rutaFiltro)
{
    if (rutaFiltro.isEmpty()) {

         //Abrir ruta y seleccionar tipo de imagen
        rutaFiltro = QFileDialog::getOpenFileName(this, tr("Abrir filtro"), QString(),
            tr("Archivo txt (*.txt);;Todos los archivos (*)"));
    }

    if (!rutaFiltro.isEmpty()) {
        std::string input = rutaFiltro.toUtf8().constData();
        int x, y;
        ifstream in(input);

        if (!in) {
            cout << "No se pudo abrir el archivo.\n";
            return;
        }

        int size[2]; //0=rows, 1=columns,

        in >> size[0] >> size[1];

        int Matrix[size[0]*size[1]];
        size_matrixFilter = size[0];
        output = new char[size[0]];

        for (y = 0; y < size[0]; y++) {
            for (x = 0; x < size[1]; x++) {
                in >> Matrix[x*size[1]+y];
                cout << Matrix[x*size[1]+y] << " , ";
            }
            cout<< endl;
        }
        for (y = 0; y < size[0]; y++) {
            for (x = 0; x < size[1]; x++) {
                output[x*size[0]+y] = Matrix[x*size[0]+y];
//                cout << output[x*size[1]+y] << " , ";

            }
        }


        h_M = output;

        in.close();

        ui->actionConvolucion->setEnabled(true);
//        ui->actionBilinieal->setEnabled(true);
        ui->infoFiltro->setText("Filtro cargado!");
    }
    else{
        ui->infoFiltro->setText("Filtro No cargado!");
    }
}

void MainWindow::on_actionCerrar_triggered()
{
    ui->show_img->clear();
    ui->show_imgConv->clear();
}

void MainWindow::on_actionSalir_triggered()
{
    qApp->quit();
}

void MainWindow::on_actionConvolucion_triggered()
{
    if (inputImage.data){
//        clock_t start, end, startGPU, endGPU;
//        double cpu_time_used, gpu_time_used;
//        char h_M[] = {-1,0,1,-2,0,2,-1,0,1};        //sobel
//        char h_M[] = {-1,-1,1,0,0,0,1,1,1};        //op borde
//        h_M = output;

//        char h_M[] = {1,2,1,2,4,2,1,2,1};
//        char h_M[] = {1,1,1,1,0,0,1,1,1};
        bool ischeck_g = ui->radioButton_gr->isChecked();
        bool ischeck_c = ui->radioButton_col->isChecked();
        int opc = -1;
        if (ischeck_g){
            cout << "selccionado gris"<< endl;
            opc = 0;
        }
        if (ischeck_c){
            cout << "selccionado color"<< endl;
            opc = 1;
        }
        Size s = inputImage.size();

        //inicializamos variables
        int width = s.width;
        int height = s.height;
        int size = sizeof(unsigned char)*width*height*inputImage.channels();
        int sizeGray = sizeof(unsigned char)*width*height;

        if(opc == 0){
            unsigned char *dataRawImage;
            unsigned char *h_imageOutput;
            dataRawImage = (unsigned char*)malloc(size);
            h_imageOutput = (unsigned char *)malloc(sizeGray);
            dataRawImage = inputImage.data;


            cudaError_t cuerr = convolucionCuda(width, height, size,sizeGray, dataRawImage, h_imageOutput, 3,h_M );
            if (cuerr != cudaSuccess)
                cout << "CUDA Error: " << cudaGetErrorString( cuerr ) << endl;

            //creamos la matriz de la imagen
            Mat gray_image;
            gray_image.create(height,width,CV_8UC1);
            gray_image.data = h_imageOutput;

//            imwrite("output.bmp",gray_image);
    //        gray_image = cv::imread("output.bmp");
            saveImage = gray_image.clone();
            if (gray_image.data){

                const uchar *qImageBuffer = (const uchar*)gray_image.data;
                image1= QImage(qImageBuffer, gray_image.cols, gray_image.rows, gray_image.step, QImage::Format_Indexed8);

                //show Qimage using QLabel
                ui->show_imgConv->setPixmap(QPixmap::fromImage(image1));
                ui->show_imgConv->setScaledContents( true );


            }
        }
        if(opc == 1){
            cout << "en color" << endl;
            unsigned char *dataRawImageB, *dataRawImageG, *dataRawImageR;
            unsigned char *h_imageOutputB, *h_imageOutputG, *h_imageOutputR;

            dataRawImageB = (unsigned char*)malloc(sizeGray);
            dataRawImageG = (unsigned char*)malloc(sizeGray);
            dataRawImageR = (unsigned char*)malloc(sizeGray);
            //Reserva de Memoria para d_imageOutput
            h_imageOutputB = (unsigned char *)malloc(sizeGray);
            h_imageOutputG = (unsigned char *)malloc(sizeGray);
            h_imageOutputR = (unsigned char *)malloc(sizeGray);

            vector<Mat > spl;
            std::vector<Mat> vec_merge;
//            Mat fin_img;
            split(inputImage, spl);
            dataRawImageB = spl[0].data;
            dataRawImageG = spl[1].data;
            dataRawImageR = spl[2].data;



            cudaError_t cuerr = convolucionCudaColor(width, height, sizeGray, dataRawImageB,dataRawImageG,dataRawImageR,\
                                h_imageOutputB,h_imageOutputG,h_imageOutputR, size_matrixFilter , h_M, 1.0);
            if (cuerr != cudaSuccess)
                cout << "CUDA Error: " << cudaGetErrorString( cuerr ) << endl;

            Mat gray_imageR,gray_imageG,gray_imageB;
            gray_imageB.create(height,width,CV_8UC1);
            gray_imageG.create(height,width,CV_8UC1);
            gray_imageR.create(height,width,CV_8UC1);

            gray_imageB.data = h_imageOutputB;      //dataRawImageB
            gray_imageG.data = h_imageOutputG;
            gray_imageR.data = h_imageOutputR;
            vec_merge.push_back(gray_imageB);
            vec_merge.push_back(gray_imageG);
            vec_merge.push_back(gray_imageR);
//            h_imageOutputB = '\0';h_imageOutputG = '\0';h_imageOutputR = '\0';
            merge(vec_merge, saveImage);

//            imwrite("fin_img.bmp",fin_img);

            if (saveImage.data){

                image1= QImage(saveImage.data, saveImage.cols, saveImage.rows, saveImage.step, QImage::Format_RGB888);
                //show Qimage using QLabel
                ui->show_imgConv->setPixmap(QPixmap::fromImage(image1));
                ui->show_imgConv->setScaledContents( true );


            }
        }


    }
}


void MainWindow::mousePressEvent(QMouseEvent *e)
{
    mFirstX=0;
    mFirstY=0;
    mFirstClick=true;
    mpaintflag=false;

    if(e->button() == Qt::RightButton)
    {
        //store 1st point
        if(mFirstClick)
        {
            mFirstX = e->x();
            mFirstY = e->y();
            mFirstClick = false;
            mpaintflag = true;
            qDebug() << "First image's coordinates" << mFirstX << "," << mFirstY ;
            update();

        }

    }
}

void MainWindow::paintEvent(QPaintEvent * e)
{

//    ui->show_imgBi->paintEvent(e);

    if(mpaintflag)
    {
       QImage tmp(ui->show_imgBi->pixmap()->toImage());
       QPainter painter(&tmp);
       QPen paintpen(Qt::green);
       paintpen.setWidth(10);
       QPoint p1;
       p1.setX(mFirstX);
       p1.setY(mFirstY);
       painter.setPen(paintpen);
       painter.drawPoint(p1);
       ui->show_imgBi->setPixmap(QPixmap::fromImage(tmp));
    }

}

void MainWindow::on_actionBilinieal_triggered()
{

    Point2f inputPoint[4];
    Point2f outputPoint[4];

//    cargar una matriz lambda
    Mat lambda( 2, 4, CV_32FC1 );
    Mat input, output;

//    copiar la imagen
    input = inputImage.clone();

    // crear una imagen de igual tamano
    lambda = Mat::zeros( input.rows, input.cols, input.type() );

//  seleccionar cuatro puntos en izquierda a derecha
    inputPoint[0] = Point2f( 0,-50 );
    inputPoint[1] = Point2f( input.cols,-50);
    inputPoint[2] = Point2f( input.cols+100,input.rows+50);
    inputPoint[3] = Point2f( -50,input.rows+50  );

    // cuatro puntos para la salida
    outputPoint[0] = Point2f( 0,0 );
    outputPoint[1] = Point2f( input.cols-1,0);
    outputPoint[2] = Point2f( input.cols-1,input.rows-1);
    outputPoint[3] = Point2f( 0,input.rows-1  );


    lambda = getPerspectiveTransform( inputPoint, outputPoint );
    warpPerspective(input,output,lambda,output.size() );


    QImage out = QImage(output.data, output.cols, output.rows, output.step, QImage::Format_RGB888);

    //show Qimage using QLabel
    ui->show_imgBilineal->setPixmap(QPixmap::fromImage(out));
    ui->show_imgBilineal->setScaledContents( true );


    ui->show_imgBilineal2->setPixmap(QPixmap::fromImage(out));
    ui->show_imgBilineal2->setScaledContents( true );

    imwrite("out_bilineal.jpg",output);
    saveImage = output.clone();

}

void MainWindow::on_actionGuardar_triggered()
{

    //Seleccionar ruta nueva
    QString rutaNueva = QFileDialog::getSaveFileName(this, tr("Guardar imagen"), QString(),
            tr("Imagen BMP (*.bmp);;Todos los archivos (*)"));

    if (!rutaNueva.isEmpty()) {

        QFile file(rutaNueva);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::critical(this, tr(WINDOW_CRITICAL), tr("No se puede guardar la imagen."));
            return;
        }

        //Guardar imagen en la nueva ruta
        string ruta= rutaNueva.toStdString();
        cvtColor(saveImage, saveImage, 4 );
        imwrite(string(ruta+".bmp"), saveImage);

        QMessageBox::warning(this, tr(WINDOW_ABOUT), tr("Se ha guardado correctamente."));
    }

}

void MainWindow::on_actionCorreccion_Bil_triggered()
{
    Point2f inputPoint[4];
    Point2f outputPoint[4];

//    cargar una matriz lambda
    Mat lambda( 2, 4, CV_32FC1 );
    Mat input, output;

//    copiar la imagen
    input = saveImage.clone();

    // crear una imagen de igual tamano
    lambda = Mat::zeros( input.rows, input.cols, input.type() );

//  seleccionar cuatro puntos en izquierda a derecha
    inputPoint[0] = Point2f( 0,50 );
    inputPoint[1] = Point2f( input.cols, 50);
    inputPoint[2] = Point2f( input.cols-100,input.rows-50);
    inputPoint[3] = Point2f( 50,input.rows-50 );

    // cuatro puntos para la salida
    outputPoint[0] = Point2f( 0,0 );
    outputPoint[1] = Point2f( input.cols-1,0);
    outputPoint[2] = Point2f( input.cols-1,input.rows-1);
    outputPoint[3] = Point2f( 0,input.rows-1  );


    lambda = getPerspectiveTransform( inputPoint, outputPoint );
    warpPerspective(input,output,lambda,output.size() );


    QImage out = QImage(output.data, output.cols, output.rows, output.step, QImage::Format_RGB888);

    //show Qimage using QLabel
    ui->show_imgBi_coreg->setPixmap(QPixmap::fromImage(out));
    ui->show_imgBi_coreg->setScaledContents( true );
}
