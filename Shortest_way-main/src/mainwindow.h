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

private slots:
    void on_create_button_clicked();

    void on_get_answer_button_clicked();
public slots:
    std::vector<int> Enter(std::vector<std::vector<int>> matrix, int n, int start);

    std::vector<int> bellman_ford(int n, int s, int e);


private:

    struct Edges
    {
        int u,  // Откуда
            v,  // Куда
            w;  // Расстояние
    };

    Ui::MainWindow *ui;
    bool empty_table = true;
    int count = 0;
    int start = 0;

    Edges edge[499];
    int d[1000];

};
#endif // MAINWINDOW_H
