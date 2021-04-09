#include "blackwindow.h"

BlackWindow::BlackWindow(QWidget *parent) : QWidget(parent)
{
    messageLabel = new QLabel("Take a break. Look at an object 20 feet away.");
    messageLabel->setFont(QFont("Sans Serif", 32));
    messageLabel->setAlignment(Qt::AlignCenter);
    gridLayout = new QGridLayout(this);
    gridLayout->addWidget(messageLabel);

    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint);
    setPalette(QPalette(Qt::GlobalColor::black));
    setCursor(Qt::BlankCursor);
}

void BlackWindow::closeEvent(QCloseEvent *event)
{
    event->ignore();
}
