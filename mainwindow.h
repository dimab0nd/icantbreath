#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "dropsitems.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void addfloyd();
    void moveFloyds();

private:
    Ui::MainWindow *ui_;
    QList<DropsItems*> dropitems_;
    QTimer *timer_;
    int floydsCount_ {4};
};
#endif // MAINWINDOW_H
