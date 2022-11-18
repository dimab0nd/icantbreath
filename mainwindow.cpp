#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);
    dropitems_.clear();

    setWindowTitle("I cant breath the game");

    QGraphicsScene *scene = new QGraphicsScene(this);

    scene->addText("Hello, world!");

    ui_->graphicsView->setScene(scene);


    addfloyd();
//    QGraphicsView view(&scene);
//    view.show();

    timer_ = new QTimer(this);
    connect(timer_, &QTimer::timeout, this, &MainWindow::moveFloyds);
    timer_->start(33);


}

MainWindow::~MainWindow()
{
    delete ui_;
}

void MainWindow::addfloyd()
{
    for(int i = 0 ; i < floydsCount_; i ++)
    {
        DropsItems *floyd = new DropsItems(this);
        floyd->moveBy(i*100,i*100);
        ui_->graphicsView->scene()->addItem(floyd);
        dropitems_.append(floyd);
    }
}

void MainWindow::moveFloyds()
{
    for(auto i : dropitems_)
    {
        if(i->y()+100 > ui_->graphicsView->sceneRect().height())
        {
            i->setY(10);
        }
        else
        {
            i->moveBy(0,3);
        }
    }
}

