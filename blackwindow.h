#ifndef BLACKWINDOW_H
#define BLACKWINDOW_H

#include <QWidget>
#include <QCloseEvent>
#include <QLayout>
#include <QLabel>
#include <QGridLayout>

class BlackWindow : public QWidget
{
    Q_OBJECT
public:
    explicit BlackWindow(QWidget *parent = nullptr);

private:
    void closeEvent(QCloseEvent *event) override;

    QGridLayout *gridLayout;
    QLabel *messageLabel;
signals:

};

#endif // BLACKWINDOW_H
