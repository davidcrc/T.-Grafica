/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbrir;
    QAction *actionAbrir_myBMP;
    QAction *actionSumar;
    QAction *actionRestar;
    QAction *actionMultiplicar;
    QAction *actionDividir;
    QAction *actionEstiramiento;
    QAction *actionGuardar;
    QAction *actionGuardar_como;
    QAction *actionSalir;
    QAction *actionAyuda;
    QAction *actionCerrar;
    QAction *actionRestaurar;
    QAction *actionAcerca_de;
    QAction *actionEcualizar;
    QWidget *centralWidget;
    QTabWidget *Agregar;
    QWidget *tab;
    QLabel *show_lineal;
    QLabel *label_3;
    QLineEdit *valor_opLineal;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QSlider *slider_brillo;
    QLabel *label_4;
    QSlider *slider_contraste;
    QWidget *tab_2;
    QLabel *show_estiramiento;
    QPushButton *load_img_estirar;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *min_r;
    QLabel *max_r;
    QLabel *max_g;
    QLabel *min_g;
    QLabel *min_b;
    QLabel *max_b;
    QPushButton *save_img_estira;
    QWidget *tab_3;
    QLabel *show_ecualizar;
    QPushButton *load_img_equalzr;
    QPushButton *save_img_equalzr;
    QWidget *tab_5;
    QLabel *label_11;
    QLabel *show_img_seg;
    QLabel *show_seg;
    QPushButton *load_img_seg;
    QSlider *slider_umbral;
    QLabel *label_12;
    QLabel *view_num;
    QLabel *show_img_seg_umbral;
    QWidget *tab_4;
    QLabel *label_10;
    QPushButton *load_img_comb;
    QLabel *show_comb;
    QLabel *show_img_comb;
    QSlider *slider_sumPond;
    QLabel *label_13;
    QSlider *slider_restComb;
    QLabel *label_23;
    QLabel *view_num_comb;
    QLabel *view_num_comb_2;
    QLabel *view_num_comb_3;
    QLabel *label_24;
    QPushButton *comb_multi;
    QPushButton *comb_division;
    QLabel *label_25;
    QPushButton *save_img_estira_2;
    QLabel *show_img;
    QLabel *ui_histogramaR;
    QLabel *label;
    QLabel *label_2;
    QLabel *ui_histogramaG;
    QLabel *ui_histogramaB;
    QLabel *label_6;
    QLabel *label_7;
    QMenuBar *menuBar;
    QMenu *menuAbrir;
    QMenu *menuEditar;
    QMenu *menuAyuda;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(964, 759);
        actionAbrir = new QAction(MainWindow);
        actionAbrir->setObjectName(QStringLiteral("actionAbrir"));
        actionAbrir_myBMP = new QAction(MainWindow);
        actionAbrir_myBMP->setObjectName(QStringLiteral("actionAbrir_myBMP"));
        actionSumar = new QAction(MainWindow);
        actionSumar->setObjectName(QStringLiteral("actionSumar"));
        actionRestar = new QAction(MainWindow);
        actionRestar->setObjectName(QStringLiteral("actionRestar"));
        actionMultiplicar = new QAction(MainWindow);
        actionMultiplicar->setObjectName(QStringLiteral("actionMultiplicar"));
        actionDividir = new QAction(MainWindow);
        actionDividir->setObjectName(QStringLiteral("actionDividir"));
        actionEstiramiento = new QAction(MainWindow);
        actionEstiramiento->setObjectName(QStringLiteral("actionEstiramiento"));
        actionGuardar = new QAction(MainWindow);
        actionGuardar->setObjectName(QStringLiteral("actionGuardar"));
        actionGuardar->setEnabled(false);
        actionGuardar_como = new QAction(MainWindow);
        actionGuardar_como->setObjectName(QStringLiteral("actionGuardar_como"));
        actionGuardar_como->setEnabled(false);
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        actionAyuda = new QAction(MainWindow);
        actionAyuda->setObjectName(QStringLiteral("actionAyuda"));
        actionCerrar = new QAction(MainWindow);
        actionCerrar->setObjectName(QStringLiteral("actionCerrar"));
        actionCerrar->setEnabled(false);
        actionRestaurar = new QAction(MainWindow);
        actionRestaurar->setObjectName(QStringLiteral("actionRestaurar"));
        actionAcerca_de = new QAction(MainWindow);
        actionAcerca_de->setObjectName(QStringLiteral("actionAcerca_de"));
        actionEcualizar = new QAction(MainWindow);
        actionEcualizar->setObjectName(QStringLiteral("actionEcualizar"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Agregar = new QTabWidget(centralWidget);
        Agregar->setObjectName(QStringLiteral("Agregar"));
        Agregar->setEnabled(true);
        Agregar->setGeometry(QRect(360, 20, 571, 691));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        show_lineal = new QLabel(tab);
        show_lineal->setObjectName(QStringLiteral("show_lineal"));
        show_lineal->setGeometry(QRect(70, 90, 431, 511));
        show_lineal->setStyleSheet(QStringLiteral("border: 1px solid black"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 30, 59, 21));
        valor_opLineal = new QLineEdit(tab);
        valor_opLineal->setObjectName(QStringLiteral("valor_opLineal"));
        valor_opLineal->setEnabled(false);
        valor_opLineal->setGeometry(QRect(90, 30, 71, 22));
        valor_opLineal->setMaxLength(4);
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(260, 0, 221, 78));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        slider_brillo = new QSlider(layoutWidget);
        slider_brillo->setObjectName(QStringLiteral("slider_brillo"));
        slider_brillo->setEnabled(false);
        slider_brillo->setMinimum(-100);
        slider_brillo->setMaximum(100);
        slider_brillo->setSingleStep(1);
        slider_brillo->setPageStep(1);
        slider_brillo->setValue(0);
        slider_brillo->setSliderPosition(0);
        slider_brillo->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider_brillo);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        slider_contraste = new QSlider(layoutWidget);
        slider_contraste->setObjectName(QStringLiteral("slider_contraste"));
        slider_contraste->setEnabled(false);
        slider_contraste->setMinimum(20);
        slider_contraste->setMaximum(200);
        slider_contraste->setSingleStep(1);
        slider_contraste->setPageStep(1);
        slider_contraste->setValue(100);
        slider_contraste->setSliderPosition(100);
        slider_contraste->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider_contraste);

        Agregar->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        show_estiramiento = new QLabel(tab_2);
        show_estiramiento->setObjectName(QStringLiteral("show_estiramiento"));
        show_estiramiento->setGeometry(QRect(70, 70, 431, 501));
        show_estiramiento->setStyleSheet(QStringLiteral("border: 1px solid black"));
        load_img_estirar = new QPushButton(tab_2);
        load_img_estirar->setObjectName(QStringLiteral("load_img_estirar"));
        load_img_estirar->setEnabled(false);
        load_img_estirar->setGeometry(QRect(70, 20, 101, 21));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(60, 590, 71, 21));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(60, 620, 71, 21));
        min_r = new QLabel(tab_2);
        min_r->setObjectName(QStringLiteral("min_r"));
        min_r->setGeometry(QRect(170, 590, 71, 21));
        min_r->setLayoutDirection(Qt::LeftToRight);
        min_r->setAutoFillBackground(false);
        min_r->setStyleSheet(QStringLiteral("border: 1px solid red"));
        min_r->setAlignment(Qt::AlignCenter);
        max_r = new QLabel(tab_2);
        max_r->setObjectName(QStringLiteral("max_r"));
        max_r->setGeometry(QRect(170, 620, 71, 21));
        max_r->setStyleSheet(QStringLiteral("border: 1px solid red"));
        max_r->setAlignment(Qt::AlignCenter);
        max_g = new QLabel(tab_2);
        max_g->setObjectName(QStringLiteral("max_g"));
        max_g->setGeometry(QRect(270, 620, 71, 21));
        max_g->setStyleSheet(QStringLiteral("border: 1px solid green"));
        max_g->setAlignment(Qt::AlignCenter);
        min_g = new QLabel(tab_2);
        min_g->setObjectName(QStringLiteral("min_g"));
        min_g->setGeometry(QRect(270, 590, 71, 21));
        min_g->setStyleSheet(QStringLiteral("border: 1px solid green"));
        min_g->setAlignment(Qt::AlignCenter);
        min_b = new QLabel(tab_2);
        min_b->setObjectName(QStringLiteral("min_b"));
        min_b->setGeometry(QRect(370, 590, 71, 21));
        min_b->setStyleSheet(QStringLiteral("border: 1px solid blue"));
        min_b->setAlignment(Qt::AlignCenter);
        max_b = new QLabel(tab_2);
        max_b->setObjectName(QStringLiteral("max_b"));
        max_b->setGeometry(QRect(370, 620, 71, 21));
        max_b->setStyleSheet(QStringLiteral("border: 1px solid blue"));
        max_b->setAlignment(Qt::AlignCenter);
        save_img_estira = new QPushButton(tab_2);
        save_img_estira->setObjectName(QStringLiteral("save_img_estira"));
        save_img_estira->setEnabled(false);
        save_img_estira->setGeometry(QRect(390, 10, 111, 41));
        Agregar->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        show_ecualizar = new QLabel(tab_3);
        show_ecualizar->setObjectName(QStringLiteral("show_ecualizar"));
        show_ecualizar->setGeometry(QRect(70, 70, 431, 501));
        show_ecualizar->setStyleSheet(QStringLiteral("border: 1px solid black"));
        load_img_equalzr = new QPushButton(tab_3);
        load_img_equalzr->setObjectName(QStringLiteral("load_img_equalzr"));
        load_img_equalzr->setEnabled(false);
        load_img_equalzr->setGeometry(QRect(70, 20, 91, 22));
        save_img_equalzr = new QPushButton(tab_3);
        save_img_equalzr->setObjectName(QStringLiteral("save_img_equalzr"));
        save_img_equalzr->setEnabled(false);
        save_img_equalzr->setGeometry(QRect(390, 10, 111, 41));
        Agregar->addTab(tab_3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        label_11 = new QLabel(tab_5);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(40, 30, 101, 31));
        show_img_seg = new QLabel(tab_5);
        show_img_seg->setObjectName(QStringLiteral("show_img_seg"));
        show_img_seg->setGeometry(QRect(40, 80, 191, 151));
        show_img_seg->setStyleSheet(QStringLiteral("border: 1px solid black"));
        show_seg = new QLabel(tab_5);
        show_seg->setObjectName(QStringLiteral("show_seg"));
        show_seg->setGeometry(QRect(40, 240, 431, 391));
        show_seg->setStyleSheet(QStringLiteral("border: 1px solid black"));
        load_img_seg = new QPushButton(tab_5);
        load_img_seg->setObjectName(QStringLiteral("load_img_seg"));
        load_img_seg->setEnabled(true);
        load_img_seg->setGeometry(QRect(150, 30, 41, 22));
        slider_umbral = new QSlider(tab_5);
        slider_umbral->setObjectName(QStringLiteral("slider_umbral"));
        slider_umbral->setEnabled(true);
        slider_umbral->setGeometry(QRect(350, 30, 160, 16));
        slider_umbral->setMinimum(0);
        slider_umbral->setMaximum(255);
        slider_umbral->setSingleStep(1);
        slider_umbral->setPageStep(1);
        slider_umbral->setValue(0);
        slider_umbral->setSliderPosition(0);
        slider_umbral->setOrientation(Qt::Horizontal);
        label_12 = new QLabel(tab_5);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(270, 20, 61, 31));
        view_num = new QLabel(tab_5);
        view_num->setObjectName(QStringLiteral("view_num"));
        view_num->setGeometry(QRect(520, 20, 31, 31));
        show_img_seg_umbral = new QLabel(tab_5);
        show_img_seg_umbral->setObjectName(QStringLiteral("show_img_seg_umbral"));
        show_img_seg_umbral->setGeometry(QRect(280, 80, 191, 151));
        show_img_seg_umbral->setStyleSheet(QStringLiteral("border: 1px solid black"));
        Agregar->addTab(tab_5, QString());
        label_11->raise();
        show_img_seg->raise();
        load_img_seg->raise();
        slider_umbral->raise();
        label_12->raise();
        show_seg->raise();
        view_num->raise();
        show_img_seg_umbral->raise();
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label_10 = new QLabel(tab_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(60, 20, 111, 31));
        load_img_comb = new QPushButton(tab_4);
        load_img_comb->setObjectName(QStringLiteral("load_img_comb"));
        load_img_comb->setEnabled(true);
        load_img_comb->setGeometry(QRect(190, 20, 41, 22));
        show_comb = new QLabel(tab_4);
        show_comb->setObjectName(QStringLiteral("show_comb"));
        show_comb->setGeometry(QRect(60, 230, 431, 391));
        show_comb->setStyleSheet(QStringLiteral("border: 1px solid black"));
        show_img_comb = new QLabel(tab_4);
        show_img_comb->setObjectName(QStringLiteral("show_img_comb"));
        show_img_comb->setGeometry(QRect(60, 70, 181, 151));
        show_img_comb->setStyleSheet(QStringLiteral("border: 1px solid black"));
        slider_sumPond = new QSlider(tab_4);
        slider_sumPond->setObjectName(QStringLiteral("slider_sumPond"));
        slider_sumPond->setEnabled(true);
        slider_sumPond->setGeometry(QRect(350, 30, 160, 16));
        slider_sumPond->setMinimum(0);
        slider_sumPond->setMaximum(100);
        slider_sumPond->setSingleStep(1);
        slider_sumPond->setPageStep(1);
        slider_sumPond->setValue(0);
        slider_sumPond->setSliderPosition(0);
        slider_sumPond->setOrientation(Qt::Horizontal);
        label_13 = new QLabel(tab_4);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(270, 20, 61, 31));
        slider_restComb = new QSlider(tab_4);
        slider_restComb->setObjectName(QStringLiteral("slider_restComb"));
        slider_restComb->setEnabled(true);
        slider_restComb->setGeometry(QRect(350, 70, 160, 16));
        slider_restComb->setMinimum(0);
        slider_restComb->setMaximum(1);
        slider_restComb->setSingleStep(1);
        slider_restComb->setPageStep(1);
        slider_restComb->setValue(0);
        slider_restComb->setSliderPosition(0);
        slider_restComb->setOrientation(Qt::Horizontal);
        label_23 = new QLabel(tab_4);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(270, 60, 61, 31));
        view_num_comb = new QLabel(tab_4);
        view_num_comb->setObjectName(QStringLiteral("view_num_comb"));
        view_num_comb->setGeometry(QRect(520, 20, 31, 31));
        view_num_comb_2 = new QLabel(tab_4);
        view_num_comb_2->setObjectName(QStringLiteral("view_num_comb_2"));
        view_num_comb_2->setGeometry(QRect(330, 90, 71, 31));
        view_num_comb_3 = new QLabel(tab_4);
        view_num_comb_3->setObjectName(QStringLiteral("view_num_comb_3"));
        view_num_comb_3->setGeometry(QRect(480, 90, 71, 31));
        label_24 = new QLabel(tab_4);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(270, 140, 91, 31));
        comb_multi = new QPushButton(tab_4);
        comb_multi->setObjectName(QStringLiteral("comb_multi"));
        comb_multi->setEnabled(true);
        comb_multi->setGeometry(QRect(370, 150, 81, 22));
        comb_division = new QPushButton(tab_4);
        comb_division->setObjectName(QStringLiteral("comb_division"));
        comb_division->setEnabled(true);
        comb_division->setGeometry(QRect(370, 200, 81, 22));
        label_25 = new QLabel(tab_4);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(270, 190, 91, 31));
        save_img_estira_2 = new QPushButton(tab_4);
        save_img_estira_2->setObjectName(QStringLiteral("save_img_estira_2"));
        save_img_estira_2->setEnabled(true);
        save_img_estira_2->setGeometry(QRect(470, 160, 81, 41));
        Agregar->addTab(tab_4, QString());
        show_img = new QLabel(centralWidget);
        show_img->setObjectName(QStringLiteral("show_img"));
        show_img->setGeometry(QRect(60, 40, 211, 241));
        show_img->setStyleSheet(QStringLiteral("border: 1px solid black"));
        show_img->setScaledContents(true);
        ui_histogramaR = new QLabel(centralWidget);
        ui_histogramaR->setObjectName(QStringLiteral("ui_histogramaR"));
        ui_histogramaR->setGeometry(QRect(50, 310, 241, 111));
        ui_histogramaR->setStyleSheet(QStringLiteral("border: 2px solid white"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 151, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 280, 91, 21));
        ui_histogramaG = new QLabel(centralWidget);
        ui_histogramaG->setObjectName(QStringLiteral("ui_histogramaG"));
        ui_histogramaG->setGeometry(QRect(50, 458, 241, 121));
        ui_histogramaG->setStyleSheet(QStringLiteral("border: 2px solid white"));
        ui_histogramaB = new QLabel(centralWidget);
        ui_histogramaB->setObjectName(QStringLiteral("ui_histogramaB"));
        ui_histogramaB->setGeometry(QRect(50, 607, 241, 111));
        ui_histogramaB->setStyleSheet(QStringLiteral("border: 2px solid white"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 430, 241, 21));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(50, 580, 241, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 964, 19));
        menuAbrir = new QMenu(menuBar);
        menuAbrir->setObjectName(QStringLiteral("menuAbrir"));
        menuEditar = new QMenu(menuBar);
        menuEditar->setObjectName(QStringLiteral("menuEditar"));
        menuAyuda = new QMenu(menuBar);
        menuAyuda->setObjectName(QStringLiteral("menuAyuda"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuAbrir->menuAction());
        menuBar->addAction(menuEditar->menuAction());
        menuBar->addAction(menuAyuda->menuAction());
        menuAbrir->addAction(actionAbrir);
        menuAbrir->addAction(actionAbrir_myBMP);
        menuAbrir->addSeparator();
        menuAbrir->addAction(actionGuardar);
        menuAbrir->addAction(actionGuardar_como);
        menuAbrir->addAction(actionCerrar);
        menuAbrir->addAction(actionSalir);
        menuEditar->addAction(actionSumar);
        menuEditar->addAction(actionRestar);
        menuEditar->addAction(actionMultiplicar);
        menuEditar->addAction(actionDividir);
        menuEditar->addSeparator();
        menuEditar->addSeparator();
        menuEditar->addAction(actionEstiramiento);
        menuEditar->addSeparator();
        menuEditar->addAction(actionEcualizar);
        menuEditar->addSeparator();
        menuEditar->addAction(actionRestaurar);
        menuAyuda->addAction(actionAyuda);
        menuAyuda->addAction(actionAcerca_de);

        retranslateUi(MainWindow);

        Agregar->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionAbrir->setText(QApplication::translate("MainWindow", "Abrir BMP", 0));
        actionAbrir->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionAbrir_myBMP->setText(QApplication::translate("MainWindow", "Abrir myBMP", 0));
        actionSumar->setText(QApplication::translate("MainWindow", "Sumar", 0));
        actionSumar->setShortcut(QApplication::translate("MainWindow", "Ctrl++", 0));
        actionRestar->setText(QApplication::translate("MainWindow", "Restar", 0));
        actionRestar->setShortcut(QApplication::translate("MainWindow", "Ctrl+-", 0));
        actionMultiplicar->setText(QApplication::translate("MainWindow", "Multiplicar", 0));
        actionMultiplicar->setShortcut(QApplication::translate("MainWindow", "Ctrl+*", 0));
        actionDividir->setText(QApplication::translate("MainWindow", "Dividir", 0));
        actionDividir->setShortcut(QApplication::translate("MainWindow", "Ctrl+/", 0));
        actionEstiramiento->setText(QApplication::translate("MainWindow", "Estiramiento", 0));
        actionGuardar->setText(QApplication::translate("MainWindow", "Guardar", 0));
        actionGuardar->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionGuardar_como->setText(QApplication::translate("MainWindow", "Guardar como", 0));
        actionGuardar_como->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", 0));
        actionSalir->setText(QApplication::translate("MainWindow", "Salir", 0));
        actionSalir->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionAyuda->setText(QApplication::translate("MainWindow", "Ayuda", 0));
        actionCerrar->setText(QApplication::translate("MainWindow", "Cerrar", 0));
        actionCerrar->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", 0));
        actionRestaurar->setText(QApplication::translate("MainWindow", "Restaurar", 0));
        actionRestaurar->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0));
        actionAcerca_de->setText(QApplication::translate("MainWindow", "Acerca de", 0));
        actionEcualizar->setText(QApplication::translate("MainWindow", "Ecualizar", 0));
#ifndef QT_NO_WHATSTHIS
        Agregar->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p>Ecualiza la imagen</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        show_lineal->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Valor :", 0));
        valor_opLineal->setPlaceholderText(QApplication::translate("MainWindow", "0-255", 0));
        label_5->setText(QApplication::translate("MainWindow", "Brillo        :", 0));
        label_4->setText(QApplication::translate("MainWindow", "Contraste :", 0));
        Agregar->setTabText(Agregar->indexOf(tab), QApplication::translate("MainWindow", "Op. Lineal", 0));
        show_estiramiento->setText(QString());
        load_img_estirar->setText(QApplication::translate("MainWindow", "Ver Imagen", 0));
        label_8->setText(QApplication::translate("MainWindow", "Valor Min :", 0));
        label_9->setText(QApplication::translate("MainWindow", "Valor Max :", 0));
        min_r->setText(QString());
        max_r->setText(QString());
        max_g->setText(QString());
        min_g->setText(QString());
        min_b->setText(QString());
        max_b->setText(QString());
        save_img_estira->setText(QApplication::translate("MainWindow", "Guardar", 0));
        Agregar->setTabText(Agregar->indexOf(tab_2), QApplication::translate("MainWindow", "Estiramiento", 0));
        show_ecualizar->setText(QString());
        load_img_equalzr->setText(QApplication::translate("MainWindow", "Ver Imagen", 0));
        save_img_equalzr->setText(QApplication::translate("MainWindow", "Guardar", 0));
        Agregar->setTabText(Agregar->indexOf(tab_3), QApplication::translate("MainWindow", "Ecualizar", 0));
        label_11->setText(QApplication::translate("MainWindow", "Segunda imagen", 0));
        show_img_seg->setText(QString());
        show_seg->setText(QString());
        load_img_seg->setText(QApplication::translate("MainWindow", "abrir", 0));
        label_12->setText(QApplication::translate("MainWindow", "Umbral", 0));
        view_num->setText(QApplication::translate("MainWindow", "0", 0));
        show_img_seg_umbral->setText(QString());
        Agregar->setTabText(Agregar->indexOf(tab_5), QApplication::translate("MainWindow", "Segmentacion y Comb", 0));
        label_10->setText(QApplication::translate("MainWindow", "Segunda imagen", 0));
        load_img_comb->setText(QApplication::translate("MainWindow", "abrir", 0));
        show_comb->setText(QString());
        show_img_comb->setText(QString());
        label_13->setText(QApplication::translate("MainWindow", "Sum Pond", 0));
        label_23->setText(QApplication::translate("MainWindow", "Resta", 0));
        view_num_comb->setText(QApplication::translate("MainWindow", "0", 0));
        view_num_comb_2->setText(QApplication::translate("MainWindow", "img1-img2", 0));
        view_num_comb_3->setText(QApplication::translate("MainWindow", "img2 - img1", 0));
        label_24->setText(QApplication::translate("MainWindow", "Producto", 0));
        comb_multi->setText(QApplication::translate("MainWindow", "producto", 0));
        comb_division->setText(QApplication::translate("MainWindow", "division", 0));
        label_25->setText(QApplication::translate("MainWindow", "Division", 0));
        save_img_estira_2->setText(QApplication::translate("MainWindow", "Guardar", 0));
        Agregar->setTabText(Agregar->indexOf(tab_4), QApplication::translate("MainWindow", "Combinacon OP. G.", 0));
        show_img->setText(QString());
        ui_histogramaR->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Imagen original", 0));
        label_2->setText(QApplication::translate("MainWindow", "Histograma", 0));
        ui_histogramaG->setText(QString());
        ui_histogramaB->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "0                           127                      255", 0));
        label_7->setText(QApplication::translate("MainWindow", "0                           127                      255", 0));
        menuAbrir->setTitle(QApplication::translate("MainWindow", "Archivo", 0));
        menuEditar->setTitle(QApplication::translate("MainWindow", "Editar", 0));
        menuAyuda->setTitle(QApplication::translate("MainWindow", "Ayuda", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
