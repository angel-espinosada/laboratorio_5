#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene *escena = new QGraphicsScene(this);
    ui->escena->setScene(escena);
    QGraphicsRectItem *cuadrado = new QGraphicsRectItem(150, 100, 10, 100);
    QGraphicsRectItem *cuadrado1 = new QGraphicsRectItem(-150, 100, 10, 100);
    cuadrado->setBrush(Qt::red);
    cuadrado1->setBrush(Qt::green);
    escena->addItem(cuadrado);
    escena->addItem(cuadrado1);
}




MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    double altura=0;
    altura=ui->Altura->text().toDouble();
}

