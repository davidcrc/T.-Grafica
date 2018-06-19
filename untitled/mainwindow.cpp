#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include "readB.cpp"
#include <iostream>
using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    cv::Mat inputImage = cv::imread("lady.jpg");
//    cvtColor(inputImage, inputImage, 4 );
//    if(!inputImage.empty()){
//        cout << "ok!";
//        QImage image1= QImage(inputImage.data, inputImage.cols, inputImage.rows, inputImage.step, QImage::Format_RGB888);

//        //show Qimage using QLabel
//        ui->show_img->setPixmap(QPixmap::fromImage(image1));
//        ui->show_img->setScaledContents( true );

//        ui->show_img->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
////      ui->show_img->show();
////    cv::imshow("Display Image", inputImage);
//    }
//    else
//        cout << "No cargo!";
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAbrir_triggered(QString rutaImagen) {

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
        ui->show_img->clear();
        std::string input = rutaImagen.toUtf8().constData();

        //Cargar imagen
        inputImage = cv::imread(input, CV_LOAD_IMAGE_COLOR);
        cvtColor(inputImage, inputImage, 3 );
        cout << "ok!" << "av er " << inputImage.cols<< " " <<inputImage.rows <<" step: " << inputImage.step << endl;
        image1= QImage(inputImage.data, inputImage.cols, inputImage.rows, inputImage.step, QImage::Format_RGB888);
        image1 = image1.scaledToHeight(ui->show_img->height(), Qt::SmoothTransformation);
        //show Qimage using QLabel
        ui->show_img->setPixmap(QPixmap::fromImage(image1));
        ui->show_img->setScaledContents( true );

        ui->show_lineal->setPixmap(QPixmap::fromImage(image1));
        ui->show_lineal->setScaledContents( true );


//        ui->show_img->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
//            cv::imshow("Display Image", inputImage);
//        save_img = inputImage.clone();
//        Mostrar el historgrama
        showHistogram(inputImage);

//    Clonar una imagen temporal editable en pantalla
        save_img = inputImage.clone();
        ui->valor_opLineal->setEnabled(true);
        ui->actionGuardar->setEnabled(true);
        ui->actionGuardar_como->setEnabled(true);
        ui->actionCerrar->setEnabled(true);
        ui->slider_contraste->setEnabled(true);
        ui->slider_brillo->setEnabled(true);
        ui->load_img_estirar->setEnabled(true);
        ui->load_img_equalzr->setEnabled(true);
    }
}

void MainWindow::save(QString ruta) {

}
void MainWindow::on_actionGuardar_como_triggered() {

    //Seleccionar ruta nueva
    QString rutaNueva = QFileDialog::getSaveFileName(this, tr("Guardar imagen"), QString(),
            tr("Imagen BMP (*.bmp);;Todos los archivos (*);;"));

    if (!rutaNueva.isEmpty()) {

        QFile file(rutaNueva);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::critical(this, tr(WINDOW_CRITICAL), tr("No se puede guardar la imagen."));
            return;
        }

        //Guardar imagen en la nueva ruta
        string ruta= rutaNueva.toStdString();
        cvtColor(save_img, save_img, 3 );
        imwrite(string(ruta+".bmp"), save_img);

        QMessageBox::warning(this, tr(WINDOW_ABOUT), tr("Se ha guardado correctamente."));
    }

}

void MainWindow::getMinmax(Mat& hist, float umbral ,double &m, double &M){
//    cout << "umbral" << umbral << endl;
    for (int j = 0; j < 256-1; j++){
        if (hist.at<int>(j) >= umbral){
            m = j;
            break;
        }

//        cout << j <<" "<< j <<" "<<hist.at<int>(j) << " -> " <<m << " " <<M <<endl;
    }
    for (int j = 256-1; j > 0 ; j--){
        if (hist.at<int>(j) >= umbral){
            M = j;
//            M = abs(255-M);
            break;
        }

//        cout << j <<" "<< j <<" "<<hist.at<int>(j) << " -> " <<m << " " <<M <<endl;
    }
}


void MainWindow::showHistogram(Mat& img)
{
    int bins = 256;             //
    int nc = img.channels();    // canales

    vector<Mat> hist(nc);       //

    // Inicialzar el array
    for (int i = 0; i < hist.size(); i++)
        hist[i] = Mat::zeros(1, bins, CV_32SC1);

    // Calcular el histograma
    for (int i = 0; i < img.rows; i++)
    {
        for (int j = 0; j < img.cols; j++)
        {
            for (int k = 0; k < nc; k++)
            {
                uchar val = nc == 1 ? img.at<uchar>(i,j) : img.at<Vec3b>(i,j)[k];
                hist[k].at<int>(val) += 1;
            }
        }
    }

    int hmax[3] = {0,0,0};
    for (int i = 0; i < nc; i++)
    {
        for (int j = 0; j < bins-1; j++){
            hmax[i] = hist[i].at<int>(j) > hmax[i] ? hist[i].at<int>(j) : hmax[i];
//            cout << i <<" "<< j <<" "<<hist[i].at<int>(j) << endl;
        }
    }
//    Copiar e histograma a una variable global
    histogramaBGR = hist;
//    cout << "maximo echo " << hmax[0] << " " << hmax[1] << " " << hmax[2] << endl;

    const char* wname[3] = { "blue", "green", "red" };
    Scalar colors[3] = { Scalar(255,0,0), Scalar(0,255,0), Scalar(0,0,255) };

    vector<Mat> canvas(nc);

    // mostrar cada histograma
    for (int i = 0; i < nc; i++)
    {
        canvas[i] = Mat::ones(125, bins, CV_8UC3);
        canvas[i] = cv::Scalar(255, 255, 255);

        for (int j = 0, rows = canvas[i].rows; j < bins-1; j++)
        {
            line(
                canvas[i],
                Point(j, rows),
                Point(j, rows - (hist[i].at<int>(j) * rows/hmax[i])),
                nc == 1 ? Scalar(120,120,120) : colors[i],
                1, 8, 0
            );
        }

//        imshow(nc == 1 ? "value" : wname[i], canvas[i]);
        if (nc==1){
            imshow(wname[i],canvas[i]);
//            QImage image1= QImage(inputImage.data, inputImage.cols, inputImage.rows, inputImage.step, QImage::Format_RGB888);
        }
        else{
//            imshow(wname[i],canvas[i]);

//            Hallar el valor max y min de la imagen para calcular el estiramiento
            double min=0, max = 0;

            cout << i <<" "<<hmax[i] << endl;
            float umbral = 5.0/100.0;
            getMinmax(hist[i],hmax[i]*umbral ,min,max);
            histmin[i] = min;
            histmax[i] = max;

//            Cargar cada historgrama BGR
            cvtColor(canvas[i], canvas[i], 3 );
            QImage imageH= QImage(canvas[i].data, canvas[i].cols, canvas[i].rows, canvas[i].step, QImage::Format_RGB888);
            if (i == 0){
                ui->ui_histogramaB->setPixmap(QPixmap::fromImage(imageH));
                ui->ui_histogramaB->setScaledContents( true );
                ui->ui_histogramaB->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

            }
            if (i == 1){
                ui->ui_histogramaG->setPixmap(QPixmap::fromImage(imageH));
                ui->ui_histogramaG->setScaledContents( true );
                ui->ui_histogramaG->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
            }
            if (i == 2){
                ui->ui_histogramaR->setPixmap(QPixmap::fromImage(imageH));
                ui->ui_histogramaR->setScaledContents( true );
                ui->ui_histogramaR->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
            }
        }

    }
}

void MainWindow::OpeGlobales(float a, float v){
//    v [1.0-3.0] = contraste
//    a [0-100] = brillo

    for (int y = 0; y < inputImage.rows; y++)
        {
            for (int x = 0; x < inputImage.cols; x++)
            {

                for( int c = 0; c < 3; c++ )
                    save_img.at<Vec3b>(y,x)[c] =  saturate_cast<uchar>( v*( inputImage.at<Vec3b>(Point(x, y))[c] ) + a );

                // get pixel, usandolo como referencia
//                 Vec3b & color = save_img.at<Vec3b>(Point(x, y));
//                 Vec3b color = save_img.at<Vec3b>(Point(x, y));

                // cout << color[2] << endl;
//                color[0] = saturate_cast<uchar>( (v *color[0] + a)) ;
//                color[1] = saturate_cast<uchar>( (v *color[1] + a));
//                color[2] = saturate_cast<uchar>( (v *color[2] + a));
                // set pixel
                // save_img.at<Vec3b>(Point(x, y)) = color;
            }
        }
//    cout << "ok!" << "av er " << save_img.cols<< " " <<save_img.rows <<" step: " << save_img.step;
//    cvtColor(save_img, save_img, 3 );
    image1= QImage(save_img.data, save_img.cols, save_img.rows, save_img.step, QImage::Format_RGB888);

    //mostrar en qlabel
    ui->show_lineal->setPixmap(QPixmap::fromImage(image1));
    ui->show_lineal->setScaledContents( true );

    showHistogram(save_img);
}

void MainWindow::OpeEstirar(float m, float M){


    for (int y = 0; y < inputImage.rows; y++)
        {
            for (int x = 0; x < inputImage.cols; x++)
            {

                for( int c = 0; c < 3; c++ ){
                    m = histmin[c];
                    M = histmax[c];
//                    cout << "Minimo Max ("<< c << "): " << m << " , " << M << endl;
                    save_img.at<Vec3b>(y,x)[c] =  saturate_cast<uchar>( ( save_img.at<Vec3b>(Point(x, y))[c] - m )*255.0/(M-m) );
                }

            }
        }
    image1= QImage(save_img.data, save_img.cols, save_img.rows, save_img.step, QImage::Format_RGB888);

    //show Qimage using QLabel
    ui->show_estiramiento->setPixmap(QPixmap::fromImage(image1));
    ui->show_estiramiento->setScaledContents( true );
}

void MainWindow::on_actionSumar_triggered()
{
    float val=0;
    string str_val= ui->valor_opLineal->text().toStdString();
    if (str_val == "")
            QMessageBox::warning(this, tr(WINDOW_WARNING), tr("Ingrese un valor entre 0 y 255"));
    else{
        val = atoi(str_val.c_str());
        OpeGlobales(val,1);
    }

}

void MainWindow::on_actionRestar_triggered(){
    float val=0;
    string str_val= ui->valor_opLineal->text().toStdString();
    if (str_val == "")
            QMessageBox::warning(this, tr(WINDOW_WARNING), tr("Ingrese un valor entre 0 y 255"));
    else{
        val = atoi(str_val.c_str());
        OpeGlobales(-val,1);
    }

}

void MainWindow::on_actionMultiplicar_triggered(){
//    Brillo = OP - suma y resta
    float val=0;
    string str_val= ui->valor_opLineal->text().toStdString();
    if (str_val == "")
            QMessageBox::warning(this, tr(WINDOW_WARNING), tr("Ingrese un valor entre 0 y 255"));
    else{
        std::stringstream sstr(str_val);
        sstr >> val;
//        cout << "valor div " << val<< endl;
        OpeGlobales(0,val);
    }

}

void MainWindow::on_actionDividir_triggered(){
//    contraste = OP - multi y/o division
    float val=0;
    string str_val= ui->valor_opLineal->text().toStdString();
    if (str_val == "")
            QMessageBox::warning(this, tr(WINDOW_WARNING), tr("Ingrese un valor entre 0 y 255"));
    else{
        std::stringstream sstr(str_val);
        sstr >> val;
//        cout << "valor div " << val<< endl;
        OpeGlobales(0,val);
    }

}

void MainWindow::on_actionEstiramiento_triggered()
{
    float m,M;
    OpeEstirar(m, M);
    showHistogram(save_img);
    ui->save_img_estira->setEnabled(true);
//    cout << "Estiradaa" << endl;
}

void MainWindow::on_actionRestaurar_triggered()
{
    save_img = inputImage.clone();
    image1= QImage(inputImage.data, inputImage.cols, inputImage.rows, inputImage.step, QImage::Format_RGB888);
    ui->show_lineal->setPixmap(QPixmap::fromImage(image1));
    ui->show_lineal->setScaledContents( true );
    showHistogram(inputImage);
}

void MainWindow::on_actionEcualizar_triggered()
{
    int bins = 256;
    int nc = inputImage.channels();
    int np = inputImage.cols * inputImage.rows;

    vector<Mat> histEq(nc);       // histogram arrays

    // Initalize histogram arrays
    for (int i = 0; i < histEq.size(); i++)
        histEq[i] = Mat::zeros(1, bins, CV_32SC1);

    if(inputImage.channels() == 3)
    {
        for (int i = 0; i < nc; i++){
//            Para cada canal
            histEq[i].at<int>(0) = 0 ;         // histEq[0-255]
            float acumulado = histogramaBGR[i].at<int>(0);
            for (int j=1; j < 255; j++){
                histEq[i].at<int>(j) = acumulado*255.0/np ;       //np=numero de pixeles de a imagen
                acumulado = acumulado + histogramaBGR[i].at<int>(j) ;
//                cout << "acumulado " << acumulado << endl;
            }
            histEq[i].at<int>(255) = 255;
        }
    }

    for (int y = 0; y < inputImage.rows; y++)
    {
        for (int x = 0; x < inputImage.cols; x++)
        {

            for( int c = 0; c < 3; c++ ){
                save_img.at<Vec3b>(y,x)[c] =  saturate_cast<uchar>( histEq[c].at<int>(save_img.at<Vec3b>(Point(x, y))[c])  );
            }

        }
    }

    image1= QImage(save_img.data, save_img.cols, save_img.rows, save_img.step, QImage::Format_RGB888);
    ui->show_ecualizar->setPixmap(QPixmap::fromImage(image1));
    ui->show_ecualizar->setScaledContents( true );
    showHistogram(save_img);
}

//=====================================================================

void MainWindow::on_slider_brillo_actionTriggered(int action)
{
//    Brillo OP = suma , resta
    double xvalue=ui->slider_brillo->value();
//    xvalue = xvalue/100.0;
//    cout << "slide menor "<< xvalue << endl;
//  0.6 - 0.7 - 09
    OpeGlobales(xvalue,1);
//    if (xvalue >= 0.0 || xvalue <= 15.0 ){
//        xvalue = xvalue/10.0;
//        cout << "slide brillo menor "<< xvalue << endl;
//        OpeGlobales(xvalue,1);
//    }
//    if (xvalue > 15.0 || xvalue <= 30.0){
//        xvalue = xvalue/10.0;
//        cout << "slide brillo mayor"<< xvalue << endl;
//        OpeGlobales(-xvalue,1);
//    }
}

void MainWindow::on_slider_contraste_actionTriggered(int action)
{
//    contraste OP = multi y /o divi
    float xvalue = ui->slider_contraste->value();
    float val = (xvalue)/100.0;
    float a =50-val;
//    xvalue = xvalue/100.0;
//    cout << "slide menor "<< xvalue << endl;
//  0.6 - 0.7 - 09
    OpeGlobales(a,val);


}

void MainWindow::on_load_img_estirar_clicked()
{
    ui->show_estiramiento->setPixmap(QPixmap::fromImage(image1));
    ui->show_estiramiento->setScaledContents( true );
    showHistogram(save_img);
//    for (int i =0; i < 3; i++)
//        cout << "Minimo Max ("<< i << "): " << histmin[i] << " , " << histmax[i] << endl;
    ui->min_r->setText(QString::number(histmin[2]));
    ui->max_r->setText(QString::number(histmax[2]));

    ui->min_g->setText(QString::number(histmin[1]));
    ui->max_g->setText(QString::number(histmax[1]));

    ui->min_b->setText(QString::number(histmin[0]));
    ui->max_b->setText(QString::number(histmax[0]));

}



void MainWindow::on_save_img_estira_clicked()
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
        cvtColor(save_img, save_img, 3 );
        imwrite(string(ruta+".bmp"), save_img);
        QMessageBox::warning(this, tr(WINDOW_ABOUT), tr("Se ha guardado correctamente."));
    }
    ui->save_img_estira->setEnabled(false);
}

void MainWindow::on_load_img_equalzr_clicked()
{
    ui->show_ecualizar->setPixmap(QPixmap::fromImage(image1));
    ui->show_ecualizar->setScaledContents( true );
    showHistogram(save_img);
}

//=====================================================================
void MainWindow::on_actionCerrar_triggered() {

    ui->show_img->clear();
    ui->ui_histogramaB->clear();
    ui->ui_histogramaG->clear();
    ui->ui_histogramaR->clear();
    ui->show_lineal->clear();
    ui->valor_opLineal->clear();
    inputImage.release();
    save_img.release();
    ui->actionGuardar->setEnabled(false);
    ui->actionGuardar_como->setEnabled(false);
    ui->actionCerrar->setEnabled(false);
    ui->slider_brillo->setEnabled(false);
    ui->slider_contraste->setEnabled(false);
    ui->load_img_estirar->setEnabled(false);
    ui->load_img_equalzr->setEnabled(false);
}

void MainWindow::on_actionSalir_triggered() {

    qApp->quit();
}

void MainWindow::on_actionAyuda_triggered() {

    QMessageBox::warning(this, tr(WINDOW_WARNING), tr("La documentación no está disponible."));
}

void MainWindow::on_actionAcerca_de_triggered()
{
    QMessageBox::about(this, tr(WINDOW_ABOUT), tr("Topicos en Comp. Gráfica - Computer Science by DaviD RCR "));
}


void MainWindow::on_load_img_seg_clicked(QString rutaImagen)
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
        ui->show_img_seg->clear();
        std::string input = rutaImagen.toUtf8().constData();

        //Cargar imagen
        SeginputImage= cv::imread(input, CV_LOAD_IMAGE_COLOR);
        cvtColor(SeginputImage, SeginputImage, 3 );
//        cout << "ok!" << "av er " << SeginputImage.cols<< " " <<SeginputImage.rows <<" step: " << SeginputImage.step << endl;
        image2= QImage(SeginputImage.data, SeginputImage.cols, SeginputImage.rows, SeginputImage.step, QImage::Format_RGB888);

        //show Qimage using QLabel
        ui->show_img_seg->setPixmap(QPixmap::fromImage(image2));
        ui->show_img_seg->setScaledContents( true );

//        ui->show_lineal->setPixmap(QPixmap::fromImage(image1));
//        ui->show_lineal->setScaledContents( true );
    }
}

void MainWindow::on_load_img_comb_clicked(QString rutaImagen)
{
    if (rutaImagen.isEmpty()) {

         //Abrir ruta y seleccionar tipo de imagen
        rutaImagen = QFileDialog::getOpenFileName(this, tr("Abrir imagen"), QString(),
            tr("Imagen BMP (*.bmp);;Todos los archivos (*);;"));
    }

    if (!rutaImagen.isEmpty()) {

        QFile file(rutaImagen);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr(WINDOW_CRITICAL), tr("No se puede abrir la imagen."));
            return;
        }

        //Borrar imagen anterior
        ui->show_img_comb->clear();
        std::string input = rutaImagen.toUtf8().constData();

        //Cargar imagen
        SeginputImage= cv::imread(input, CV_LOAD_IMAGE_COLOR);
        cvtColor(SeginputImage, SeginputImage, 3 );
//        cout << "ok!" << "av er " << SeginputImage.cols<< " " <<SeginputImage.rows <<" step: " << SeginputImage.step << endl;
        image2= QImage(SeginputImage.data, SeginputImage.cols, SeginputImage.rows, SeginputImage.step, QImage::Format_RGB888);

        //show Qimage using QLabel
        ui->show_img_comb->setPixmap(QPixmap::fromImage(image2));
        ui->show_img_comb->setScaledContents( true );

//        ui->show_lineal->setPixmap(QPixmap::fromImage(image1));
//        ui->show_lineal->setScaledContents( true );
    }
}

void MainWindow::on_slider_umbral_actionTriggered(int action)
{

    Mat src_gray, mask, mask_inv, img1_bg,img2_fg; // mask = salida
    int xvalue=ui->slider_umbral->value();
    cvtColor(SeginputImage, src_gray, COLOR_BGR2GRAY); // Convert the image to Gray

    QString num = QString::number(xvalue);
    ui->view_num->setText(num);

    threshold(src_gray, mask, xvalue, 255, 0);
    bitwise_not(mask, mask_inv);
    bitwise_and(SeginputImage,SeginputImage,img1_bg,mask_inv);

    QImage image2= QImage(img1_bg.data, img1_bg.cols, img1_bg.rows, img1_bg.step, QImage::Format_RGB888);
    ui->show_img_seg_umbral->setPixmap(QPixmap::fromImage(image2));
    ui->show_img_seg_umbral->setScaledContents( true );

    /////////////////////////////////
//    cv::resize(mask, mask, cv::Size(inputImage.cols,inputImage.rows));//resize image
    bitwise_and(inputImage,inputImage,img2_fg,mask);
    add(img1_bg,img2_fg, save_img);

    image1= QImage(save_img.data, save_img.cols, save_img.rows, save_img.step, QImage::Format_RGB888);

    //show Qimage using QLabel
    ui->show_seg->setPixmap(QPixmap::fromImage(image1));
    ui->show_seg->setScaledContents( true );

//    imshow("Mascara", mask);
//    imshow("Mascara inversa", mask_inv);
////    cvtColor(img1_bg, img1_bg, 3 );
//    imshow("img 1", img1_bg);
//    imshow("img 2", img2_fg);
//    imshow("final", save_img);

}

void MainWindow::on_slider_sumPond_actionTriggered(int action)
{
//    inputimage y la SeginputImage -> saveimage
    int xvalue=ui->slider_sumPond->value();
    float a = xvalue/100.0;
//    std:: cout << "suma ponderada " << a <<endl;

    QString num = QString::number(a);
    ui->view_num_comb->setText(num);


    for (int y = 0; y < inputImage.rows; y++)
    {
        for (int x = 0; x < inputImage.cols; x++)
        {

            for( int c = 0; c < 3; c++ ){
                //  cout << "Minimo Max ("<< c << "): " << m << " , " << M << endl;
                save_img.at<Vec3b>(y,x)[c] =  saturate_cast<uchar>( \
                            a*( inputImage.at<Vec3b>( Point(x, y))[c]) + \
                            ((1.0-a)* ( SeginputImage.at<Vec3b>( Point(x, y))[c]) ) );
            }

        }
    }
    image1= QImage(save_img.data, save_img.cols, save_img.rows, save_img.step, QImage::Format_RGB888);

    //show Qimage using QLabel
    ui->show_comb->setPixmap(QPixmap::fromImage(image1));
    ui->show_comb->setScaledContents( true );
}

void MainWindow::on_slider_restComb_actionTriggered(int action)
{
    //    inputimage y la SeginputImage -> saveimage
    int xvalue=ui->slider_restComb->value();

//    std:: cout << "suma ponderada " << a <<endl;

    if (xvalue == 0){
        for (int y = 0; y < inputImage.rows; y++)
        {
            for (int x = 0; x < inputImage.cols; x++)
            {

                for( int c = 0; c < 3; c++ ){
                    //  cout << "Minimo Max ("<< c << "): " << m << " , " << M << endl;
                    save_img.at<Vec3b>(y,x)[c] =  saturate_cast<uchar>( \
                                (( inputImage.at<Vec3b>( Point(x, y))[c]) - \
                                ( SeginputImage.at<Vec3b>( Point(x, y))[c]))/2.0 + 128 );            }

            }
        }
    }else{
        for (int y = 0; y < inputImage.rows; y++)
        {
            for (int x = 0; x < inputImage.cols; x++)
            {

                for( int c = 0; c < 3; c++ ){
                    //  cout << "Minimo Max ("<< c << "): " << m << " , " << M << endl;
                    save_img.at<Vec3b>(y,x)[c] =  saturate_cast<uchar>( \
                                ( SeginputImage.at<Vec3b>( Point(x, y))[c]) - \
                                (( inputImage.at<Vec3b>( Point(x, y))[c]) )/2.0 + 128 );            }

            }
        }
    }
    image1= QImage(save_img.data, save_img.cols, save_img.rows, save_img.step, QImage::Format_RGB888);

    //show Qimage using QLabel
    ui->show_comb->setPixmap(QPixmap::fromImage(image1));
    ui->show_comb->setScaledContents( true );
}

void MainWindow::on_comb_multi_clicked()
{
    float a = 255.0;
    for (int y = 0; y < inputImage.rows; y++)
    {
        for (int x = 0; x < inputImage.cols; x++)
        {

            for( int c = 0; c < 3; c++ ){
                //  cout << "Minimo Max ("<< c << "): " << m << " , " << M << endl;
                save_img.at<Vec3b>(y,x)[c] =  saturate_cast<uchar>( \
                            ( inputImage.at<Vec3b>( Point(x, y))[c]) * \
                            ( SeginputImage.at<Vec3b>( Point(x, y))[c]) /a );
            }

        }
    }
    image1= QImage(save_img.data, save_img.cols, save_img.rows, save_img.step, QImage::Format_RGB888);

    //show Qimage using QLabel
    ui->show_comb->setPixmap(QPixmap::fromImage(image1));
    ui->show_comb->setScaledContents( true );
}

void MainWindow::on_comb_division_clicked()
{
    float a = 255.0;
    for (int y = 0; y < inputImage.rows; y++)
    {
        for (int x = 0; x < inputImage.cols; x++)
        {

            for( int c = 0; c < 3; c++ ){
                //  cout << "Minimo Max ("<< c << "): " << m << " , " << M << endl;
                save_img.at<Vec3b>(y,x)[c] =  saturate_cast<uchar>( \
                            a*( inputImage.at<Vec3b>( Point(x, y))[c]) / \
                            ( SeginputImage.at<Vec3b>( Point(x, y))[c])  );
            }

        }
    }
    image1= QImage(save_img.data, save_img.cols, save_img.rows, save_img.step, QImage::Format_RGB888);

    //show Qimage using QLabel
    ui->show_comb->setPixmap(QPixmap::fromImage(image1));
    ui->show_comb->setScaledContents( true );
}

void MainWindow::on_actionAbrir_myBMP_triggered()
{
    std::cout << "Lector de imagenes BMP" << '\n';

    QString rutaImagen = QFileDialog::getOpenFileName(this, tr("Abrir imagen"), QString(),
        tr("Imagen BMP (*.bmp);;Todos los archivos (*)"));


    if (!rutaImagen.isEmpty()) {

        QFile file(rutaImagen);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr(WINDOW_CRITICAL), tr("No se puede abrir la imagen."));
            return;
        }
        std::string input = rutaImagen.toUtf8().constData();

        bmpFileHeader fileHead;
        bmpInfoHeader infoHead;
        unsigned char *img;
//        unsigned char *img_edit;
        img = readBMP(input, &fileHead, &infoHead);
        // DisplayInfo(&infoHead);
//        img_edit = sumar(infoHead, img, 0);
        // saveImg("test_img2.bmp", infoHead, fileHead, img);
//        saveImg("editada.bmp", infoHead, fileHead, img_edit);

        ///////////////////////////////////////////////////////////////7

        inputImage.create(infoHead.alto,infoHead.ancho,CV_8UC3);

        inputImage.data = img;

        cvtColor(inputImage, inputImage, 3 );
//        cout << "ok!" << "av er " << SeginputImage.cols<< " " <<SeginputImage.rows <<" step: " << SeginputImage.step << endl;
        image1= QImage(inputImage.data, inputImage.cols, inputImage.rows, inputImage.step, QImage::Format_RGB888);

        //show Qimage using QLabel
        ui->show_img->setPixmap(QPixmap::fromImage(image1));
        ui->show_img->setScaledContents( true );

        ui->show_lineal->setPixmap(QPixmap::fromImage(image1));
        ui->show_lineal->setScaledContents( true );

        showHistogram(inputImage);

        //    Clonar una imagen temporal editable en pantalla
        save_img = inputImage.clone();
        ui->valor_opLineal->setEnabled(true);
        ui->actionGuardar->setEnabled(true);
        ui->actionGuardar_como->setEnabled(true);
        ui->actionCerrar->setEnabled(true);
        ui->slider_contraste->setEnabled(true);
        ui->slider_brillo->setEnabled(true);
        ui->load_img_estirar->setEnabled(true);
        ui->load_img_equalzr->setEnabled(true);
    }


}
