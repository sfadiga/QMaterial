#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qmaterialbutton.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMaterialButton *m = new QMaterialButton("Test", ui->centralWidget);
    ui->verticalLayout_2->addWidget(m);

    QPushButton *b = new QPushButton("test", ui->centralWidget);
    ui->verticalLayout_2->addWidget(b);
}

MainWindow::~MainWindow()
{
    delete ui;
}
