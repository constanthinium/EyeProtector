#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "blackwindow.h"

#include <QMainWindow>
#include <QWindow>
#include <QTimer>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QTime elapsedTime;
    BlackWindow *blackWindow;
    QTimer *timer;

    const QTime workTime = QTime(0, 20);
    const QTime breakTime = QTime(0, 0, 20);

    void timerTick();
};
#endif // MAINWINDOW_H
