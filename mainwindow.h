#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QScrollArea>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void loadMore();

private:
    Ui::MainWindow *ui;
    QScrollArea *scrollArea;
    QVBoxLayout *scrollLayout;
    QPushButton *loadButton;
    int startIndex;
    int batchSize;
};

#endif // MAINWINDOW_H
