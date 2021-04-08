#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label->setStyleSheet("color: green");
    elapsedTime = QTime(0, 20);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::timerTick);
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerTick()
{
    elapsedTime = elapsedTime.addSecs(-1);
    ui->timeLabel->setText(elapsedTime.toString("mm:ss"));
}
