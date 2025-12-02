#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "escenario.h"
#include "Arma.h"
#include <QResizeEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    escena = new QGraphicsScene(this);
    escena->setSceneRect(0, 0, 600, 400);
    ui->escena->setScene(escena);
    ui->escena->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->escena->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //QGraphicsRectItem *cuadrado = new QGraphicsRectItem(150, 100, 10, 100);
    //QGraphicsRectItem *cuadrado1 = new QGraphicsRectItem(100, 100, 10, 100);
    Escenario *esc = new Escenario(escena);
    esc->crearSuelo();

    //cuadrado->setBrush(Qt::red);
    //cuadrado1->setBrush(Qt::green);
    //escena->addItem(cuadrado);
   // escena->addItem(cuadrado1);
    Arma *canon = new Arma(escena, 250, 330);

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

void MainWindow::resizeEvent(QResizeEvent *event)
{

    QRectF nuevoRect(0, 0, ui->escena->width(), ui->escena->height());
    escena->setSceneRect(nuevoRect);


    QMainWindow::resizeEvent(event);
}
