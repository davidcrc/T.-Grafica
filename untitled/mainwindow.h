#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#define WINDOW_TITLE "Editor de imágenes"
#define WINDOW_CRITICAL "Error - Editor de imágenes"
#define WINDOW_WARNING "Aviso - Editor de imágenes"
#define WINDOW_ABOUT "Acerca de - Editor de imágenes"

#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void showHistogram(Mat& img);
    void save(QString ruta);
    void getMinmax(Mat& hist, float umbral , double &m, double &M);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QImage image1;
    QImage image2;
    vector<Mat> histogramaBGR;
    float histmax[3] = {0.0,0.0,0.0};
    float histmin[3] = {0.0,0.0,0.0};
    cv::Mat inputImage;
    cv::Mat SeginputImage;
    cv::Mat save_img;

public slots:
    //Archivo
    void on_actionAbrir_triggered(QString rutaImagen = "");
    void on_actionGuardar_como_triggered();
    void on_actionCerrar_triggered();
    void on_actionSalir_triggered();
    void on_actionAyuda_triggered();
//    ========================================

private slots:
    void OpeGlobales(float a=0, float v=0);
    void OpeEstirar(float a=0, float v=0);


    void on_actionSumar_triggered();
    void on_actionRestar_triggered();
    void on_actionMultiplicar_triggered();
    void on_actionDividir_triggered();
    void on_actionRestaurar_triggered();
    void on_actionAcerca_de_triggered();

    void on_slider_contraste_actionTriggered(int action);
    void on_slider_brillo_actionTriggered(int action);
    void on_load_img_estirar_clicked();
    void on_actionEstiramiento_triggered();
    void on_save_img_estira_clicked();
    void on_load_img_equalzr_clicked();
    void on_actionEcualizar_triggered();


    void on_load_img_seg_clicked(QString rutaImagen="");
    void on_load_img_comb_clicked(QString rutaImagen="");
    void on_slider_umbral_actionTriggered(int action);
    void on_slider_sumPond_actionTriggered(int action);
    void on_slider_restComb_actionTriggered(int action);
    void on_comb_multi_clicked();
    void on_comb_division_clicked();
    void on_actionAbrir_myBMP_triggered();
};

#endif // MAINWINDOW_H
