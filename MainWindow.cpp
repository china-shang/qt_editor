/*************************************************************************
    > File Name: MainWindow.cpp
    > Created Time: 2017年01月29日 星期日 20时00分20秒
 ************************************************************************/

#include <QString>
#include <QCoreApplication>
#include <QFile>

#include <QtWidgets>
#include "MainWindow.h"
void MainWindow::open()
{
    this->filename = QFileDialog::getOpenFileName(this, tr("open file"), QString(), tr("cpp file (*.cpp *.h)"));
    if(!filename.isEmpty())
    {
        QFile file(filename);
        if(!file.open(QFile::ReadOnly))
        {
            QMessageBox::critical(this, tr("error"), tr("cann't open file"));
            return ;
        }
        QTextStream in(&file);
        if(!this->edit)
        {
            this->edit = new QTextEdit(this);
        }
        this->edit->setText(in.readAll());
        this->edit->show();
        this->setCentralWidget(this->edit);
        file.close();
    }
}
void MainWindow::save()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("save"), this->filename);
    if(!filename.isEmpty())
    {
    QFile file(filename);
        if(!file.open(QFile::WriteOnly)){
            QMessageBox::critical(this, tr("error"), tr("cann't save file"));
            return ;
        }
        QTextStream out(&file);
        out<<this->edit->toPlainText();
        out.flush();
        file.close();
        QMessageBox::information(this, "save", "has saved");
    }
}
MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), edit(0)
{
    this->resize(400, 400);
    QMenu *file = menuBar()->addMenu(tr("file"));

    open_action = new QAction(QIcon(":/images/doc-open"), tr("open"));
    save_action = new QAction(tr("save"));
    quit_action = new QAction(tr("quit"));
    file->addAction(open_action);
    file->addAction(save_action);
    file->addAction(quit_action) ;

    test_action = new QAction(tr("test"));
    QMenu *test =menuBar()->addMenu(tr("test"));
    test->addAction(test_action);

    connect(open_action,&QAction::triggered, this, &MainWindow::open );
    connect(save_action,&QAction::triggered, this, &MainWindow::save );
    connect(quit_action,&QAction::triggered,&QCoreApplication::quit );
    connect(test_action,&QAction::triggered, this, &MainWindow::test );
    }
void MainWindow::test()
{
    //nothing
}

