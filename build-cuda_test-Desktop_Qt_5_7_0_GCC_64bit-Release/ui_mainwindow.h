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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbrir;
    QAction *actionAbrir_Filtro;
    QAction *actionCerrar;
    QAction *actionSalir;
    QAction *actionConvolucion;
    QAction *actionBilinieal;
    QAction *actionAyuda;
    QAction *actionGuardar;
    QAction *actionCorreccion_Bil;
    QWidget *centralWidget;
    QPushButton *infoCuda;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *show_img;
    QLabel *show_imgConv;
    QRadioButton *radioButton_gr;
    QRadioButton *radioButton_col;
    QLabel *label;
    QLabel *infoFiltro;
    QWidget *tab_2;
    QLabel *show_imgBi;
    QLabel *show_imgBilineal;
    QWidget *tab_3;
    QLabel *show_imgBilineal2;
    QLabel *show_imgBi_coreg;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuRun;
    QMenu *menuAyuda;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(819, 577);
        actionAbrir = new QAction(MainWindow);
        actionAbrir->setObjectName(QStringLiteral("actionAbrir"));
        actionAbrir_Filtro = new QAction(MainWindow);
        actionAbrir_Filtro->setObjectName(QStringLiteral("actionAbrir_Filtro"));
        actionCerrar = new QAction(MainWindow);
        actionCerrar->setObjectName(QStringLiteral("actionCerrar"));
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        actionConvolucion = new QAction(MainWindow);
        actionConvolucion->setObjectName(QStringLiteral("actionConvolucion"));
        actionConvolucion->setEnabled(false);
        actionBilinieal = new QAction(MainWindow);
        actionBilinieal->setObjectName(QStringLiteral("actionBilinieal"));
        actionBilinieal->setEnabled(true);
        actionAyuda = new QAction(MainWindow);
        actionAyuda->setObjectName(QStringLiteral("actionAyuda"));
        actionGuardar = new QAction(MainWindow);
        actionGuardar->setObjectName(QStringLiteral("actionGuardar"));
        actionCorreccion_Bil = new QAction(MainWindow);
        actionCorreccion_Bil->setObjectName(QStringLiteral("actionCorreccion_Bil"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        infoCuda = new QPushButton(centralWidget);
        infoCuda->setObjectName(QStringLiteral("infoCuda"));
        infoCuda->setGeometry(QRect(690, 10, 81, 21));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(50, 30, 721, 461));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        show_img = new QLabel(tab);
        show_img->setObjectName(QStringLiteral("show_img"));
        show_img->setGeometry(QRect(50, 50, 301, 351));
        show_img->setStyleSheet(QStringLiteral("border: 1px solid black"));
        show_imgConv = new QLabel(tab);
        show_imgConv->setObjectName(QStringLiteral("show_imgConv"));
        show_imgConv->setGeometry(QRect(390, 50, 301, 351));
        show_imgConv->setStyleSheet(QStringLiteral("border: 1px solid black"));
        radioButton_gr = new QRadioButton(tab);
        radioButton_gr->setObjectName(QStringLiteral("radioButton_gr"));
        radioButton_gr->setGeometry(QRect(130, 10, 100, 20));
        radioButton_gr->setChecked(true);
        radioButton_col = new QRadioButton(tab);
        radioButton_col->setObjectName(QStringLiteral("radioButton_col"));
        radioButton_col->setGeometry(QRect(250, 10, 100, 20));
        radioButton_col->setChecked(false);
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 10, 59, 21));
        infoFiltro = new QLabel(tab);
        infoFiltro->setObjectName(QStringLiteral("infoFiltro"));
        infoFiltro->setGeometry(QRect(390, 10, 161, 21));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(239, 84, 7, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 159, 111, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(247, 121, 59, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(119, 42, 3, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(159, 56, 4, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush7(QColor(0, 0, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush7);
        QBrush brush8(QColor(247, 169, 131, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush8);
        QBrush brush9(QColor(255, 255, 220, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush7);
        infoFiltro->setPalette(palette);
        infoFiltro->setStyleSheet(QStringLiteral("color : red; "));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        show_imgBi = new QLabel(tab_2);
        show_imgBi->setObjectName(QStringLiteral("show_imgBi"));
        show_imgBi->setGeometry(QRect(50, 40, 301, 351));
        show_imgBi->setStyleSheet(QStringLiteral("border: 1px solid black"));
        show_imgBilineal = new QLabel(tab_2);
        show_imgBilineal->setObjectName(QStringLiteral("show_imgBilineal"));
        show_imgBilineal->setGeometry(QRect(380, 40, 301, 351));
        show_imgBilineal->setStyleSheet(QStringLiteral("border: 1px solid black"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        show_imgBilineal2 = new QLabel(tab_3);
        show_imgBilineal2->setObjectName(QStringLiteral("show_imgBilineal2"));
        show_imgBilineal2->setGeometry(QRect(50, 40, 301, 351));
        show_imgBilineal2->setStyleSheet(QStringLiteral("border: 1px solid black"));
        show_imgBi_coreg = new QLabel(tab_3);
        show_imgBi_coreg->setObjectName(QStringLiteral("show_imgBi_coreg"));
        show_imgBi_coreg->setGeometry(QRect(380, 40, 301, 351));
        show_imgBi_coreg->setStyleSheet(QStringLiteral("border: 1px solid black"));
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 819, 19));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        menuRun = new QMenu(menuBar);
        menuRun->setObjectName(QStringLiteral("menuRun"));
        menuAyuda = new QMenu(menuBar);
        menuAyuda->setObjectName(QStringLiteral("menuAyuda"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menuRun->menuAction());
        menuBar->addAction(menuAyuda->menuAction());
        menuArchivo->addAction(actionAbrir);
        menuArchivo->addAction(actionAbrir_Filtro);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionGuardar);
        menuArchivo->addAction(actionCerrar);
        menuArchivo->addAction(actionSalir);
        menuRun->addAction(actionConvolucion);
        menuRun->addAction(actionBilinieal);
        menuRun->addAction(actionCorreccion_Bil);
        menuAyuda->addAction(actionAyuda);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionAbrir->setText(QApplication::translate("MainWindow", "Abrir", 0));
        actionAbrir_Filtro->setText(QApplication::translate("MainWindow", "Abrir Filtro", 0));
        actionCerrar->setText(QApplication::translate("MainWindow", "Cerrar", 0));
        actionCerrar->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", 0));
        actionSalir->setText(QApplication::translate("MainWindow", "Salir", 0));
        actionSalir->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionConvolucion->setText(QApplication::translate("MainWindow", "Convolucion", 0));
        actionConvolucion->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+C", 0));
        actionBilinieal->setText(QApplication::translate("MainWindow", "Bilinieal", 0));
        actionBilinieal->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+B", 0));
        actionAyuda->setText(QApplication::translate("MainWindow", "Ayuda", 0));
        actionGuardar->setText(QApplication::translate("MainWindow", "Guardar", 0));
        actionCorreccion_Bil->setText(QApplication::translate("MainWindow", "Correccion Bil.", 0));
        infoCuda->setText(QApplication::translate("MainWindow", "Info Cuda", 0));
        show_img->setText(QString());
        show_imgConv->setText(QString());
        radioButton_gr->setText(QApplication::translate("MainWindow", "Grises", 0));
        radioButton_col->setText(QApplication::translate("MainWindow", "Color", 0));
        label->setText(QApplication::translate("MainWindow", "Imagen:", 0));
        infoFiltro->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Convolucion", 0));
        show_imgBi->setText(QString());
        show_imgBilineal->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Bilineal", 0));
        show_imgBilineal2->setText(QString());
        show_imgBi_coreg->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Corregir Boil.", 0));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", 0));
        menuRun->setTitle(QApplication::translate("MainWindow", "Run", 0));
        menuAyuda->setTitle(QApplication::translate("MainWindow", "Ayuda", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
