#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    c[0] = 250;
    c[1] = 250;

    QStringList htex;
    htex << "X" << "Y";
    ui->tableWidget->setHorizontalHeaderLabels(htex);
    ui->tableWidget_2->setHorizontalHeaderLabels(htex);

    show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
    for (int i=0; i<3; i++) {
        for (int j=0; j<2; j++) {
            a[i][j] = ui->tableWidget->item(i,j)->text().toInt();
            b[i][j] = ui->tableWidget_2->item(i,j)->text().toInt();
        }
    }

    c[0] = ui->lineEdit->text().toInt();
    c[1] = ui->lineEdit_2->text().toInt();
    QPen pen3(Qt::blue);
    QBrush brush3(QColor(255, 0, 0, 255));

    scene -> addEllipse(c[0], c[1], 6, 6, pen3, brush3);

    for (int i=0; i<3; i++) {
        for (int j=0; j<2; j++) {
            QPen pen(Qt::red);
            QBrush brush(QColor(255, 0, 0, 255));

            scene -> addEllipse(a[i][0]-3, a[i][1]-3, 6, 6, pen, brush);

            QPen pen2(Qt::green);
            QBrush brush2(QColor(0, 255, 0, 255));
            scene -> addEllipse(b[i][0]-3, b[i][1]-3, 6, 6, pen2, brush2);


            ui->graphicsView->setScene(scene);
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    eta[0] = (int)(a[1][1]+a[2][1]+a[3][1]/3);
    eta[1] = (int)(a[1][2]+a[1][2]+a[1][3]/3);

    etb[0] = (int)(b[1][1]+b[2][1]+b[3][1]/3);
    etb[1] = (int)(b[1][2]+b[1][2]+b[1][3]/3);

    da = (int)sqrt((eta[0]-c[0])^2+(eta[1]-c[1])^2);
    db = (int)sqrt((etb[0]-c[0])^2+(etb[1]-c[1])^2);

    if (da < db)
    {
        ui->result->setText("Objekts pieder A");
    }

    if (da > db)
    {
        ui->result->setText("Objekts pieder B");
    }

    if (da == db)
    {
        ui->result->setText("Objekts pieder abiem");
    }
}
