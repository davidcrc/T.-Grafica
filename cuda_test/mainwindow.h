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
#include <QPushButton>
#include <vector>
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    //Archivo
    void on_actionAbrir_triggered(QString rutaImagen="");

private slots:
    //void on_actionAbrir_triggered(QString rutaImagen = "");

    void on_infoCuda_clicked();

    void on_button_sobel_clicked();

    void on_actionAbrir_Filtro_triggered(QString rutaFiltro="");

    void on_actionCerrar_triggered();

    void on_actionSalir_triggered();

    void on_actionConvolucion_triggered();
    void mousePressEvent(QMouseEvent * e);


    void on_actionBilinieal_triggered();

    void on_actionGuardar_triggered();

    void on_actionCorreccion_Bil_triggered();

private:
    Ui::MainWindow *ui;
    void paintEvent(QPaintEvent * e);
    QImage image1;
    Mat inputImage;
    Mat saveImage;
    char *h_M;

    char *output;
    QLabel *label1 ;
    int mFirstX;
    int mFirstY;
    bool mFirstClick;
    bool mpaintflag;
    int size_matrixFilter;
};

#endif // MAINWINDOW_H
