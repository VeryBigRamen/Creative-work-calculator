#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private slots:
    //Основная клавиатура
    void CPressed();
    void ZPressed();
    void HPressed();
    //Математические действия
    void Operations();
    void Equal();
    void ChangeHZ();
    void ChangeSign();
    void Back();
};
#endif // MAINWINDOW_H
