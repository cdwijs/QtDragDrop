#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAcceptDrops(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();

    qDebug() << "dragenter";
    //if (event->mimeData()->hasFormat("text/plain"))
    //    event->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent *event)
{
    qDebug() << "dropevent";
    const QMimeData *mimeData = event->mimeData();
    if (mimeData->hasUrls())
    {
         QList<QUrl> urlList = mimeData->urls();
         QString text;
         for (int i = 0; i < urlList.size(); ++i)
         {
             text = urlList.at(i).path();
             qDebug()<<text;
         }
    }
}
