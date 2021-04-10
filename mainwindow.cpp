#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QApplication::beep();
    blackWindow = new BlackWindow;
    ui->label->setStyleSheet("color: green");
    elapsedTime = workTime;
    timer = new QTimer(this);
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

    if (elapsedTime.minute() * 60 + elapsedTime.second() == 0)
    {
        if (blackWindow->isHidden())
        {
            blackWindow->showFullScreen();
            elapsedTime = breakTime;
        }
        else
        {
            blackWindow->hide();
            elapsedTime = workTime;
        }
    }
}
