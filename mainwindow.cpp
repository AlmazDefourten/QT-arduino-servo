#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QSerialPort serialPort;
void MainWindow::on_dial_sliderMoved(int position)
{
    qDebug() << "chose";
serialPort.setPortName("COM4");
serialPort.setBaudRate(QSerialPort::Baud9600);
if (serialPort.isOpen() && serialPort.isWritable())
{
    qDebug() << "yes";
    serialPort.write(QByteArray::number(position, 200));
    serialPort.flush();
    serialPort.waitForBytesWritten(500);
    serialPort.close();
}
}
