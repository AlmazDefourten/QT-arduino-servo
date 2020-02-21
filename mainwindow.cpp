#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>
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
serialPort.setPortName("COM4");
serialPort.setBaudRate(QSerialPort::Baud9600);
if (serialPort.open(QIODevice::ReadWrite))
{
    serialPort.write(QByteArray::number(position));
}
}
