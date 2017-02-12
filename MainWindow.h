/*************************************************************************
    > File Name: MainWindow.h
    > Created Time: 2017年01月29日 星期日 19时58分38秒
 ************************************************************************/

#include <QMainWindow>
#include <QAction>
#include <QTextEdit>
class MainWindow :public QMainWindow
{
    Q_OBJECT
public:
    void open();
    QTextEdit *edit;
    void save();
    MainWindow(QWidget *parent = 0);
    void test();
private:
    QAction *quit_action;
    QAction *open_action;
    QAction *save_action;
    QAction *test_action;
    QString filename;
};
