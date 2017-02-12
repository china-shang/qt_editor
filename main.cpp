/*************************************************************************
    > File Name: main.cpp
    > Created Time: 2017年01月29日 星期日 19时56分39秒
 ************************************************************************/
 #include <QApplication>
 #include "MainWindow.h"

 int main(int argc, char * argv[])
 {
     QApplication app(argc, argv);

     MainWindow win;
     win.show();

     return app.exec();
 }

