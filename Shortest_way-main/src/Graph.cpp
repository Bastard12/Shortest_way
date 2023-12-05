#include <iostream>
#include <vector>

#include "ui_mainwindow.h"
#include "mainwindow.h"

#define inf 100000 // Значение бесконечности



std::vector<int> MainWindow::bellman_ford(int n, int s, int e)
{
    using namespace std;

    vector<int> rt(n); // Возвращаемое значение

    // Изначально всё бесконечно.
    for (int i = 0; i < n; ++i)
        d[i] = inf;
    ui->logs->append("Func: dellman_ford -- calculating lengths");

    ui->logs->append("Filling the length table with the value 00");
    // Расстояние к себе приравниваем к нулю
    d[s] = 0; 


    // Ищем кратчайшие расстояния
    ui->logs->append("Calculation of lengths....");
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < e; ++j)
            if (d[edge[j].v] + edge[j].w < d[edge[j].u])
            {
                d[edge[j].u] = d[edge[j].v] + edge[j].w;
                ui->logs->append("ok )");
            }
            else
            {
                ui->logs->append("fail (");
            }

    ui->logs->append("Filling in an array of lengths....");
    // Заполняем выходной вектор
    // -1 значит, что пути нет
    for (int i = 0; i < n; ++i)
        if (d[i] == inf)
            rt[i] = -1;
        else
            rt[i] = d[i];
    return rt;
}

// Это функция ввода. Просто надо использовать её.
std::vector<int> MainWindow::Enter(std::vector<std::vector<int>> matrix, int n, int start)
{
    ui->logs->setText("Start....");
    ui->logs->append("----------------------");
    // matrix -- матрица
    // n -- количество вершин
    // start -- стартовая позиция

    int e = 0; // Счётчик рёбер

    // Заполняем таблицу рёбер
    ui->logs->append("Fubc: Enter -- Filling an array of edges");
    ui->logs->append("(The table contains information about the length of each edge)");
    ui->logs->append("----------------------");
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrix[i][j] != 0)
            {
                QString tmp = QString("Edge" + QString::number(e) + "-" + QString::number(matrix[i][j]));
                ui->logs->append(tmp);
                edge[e].v = i;
                edge[e].u = j;
                edge[e].w = matrix[i][j];
                ++e;
            }
        }
    }

    ui->logs->append("----------------------");

    ui->logs->append("Calling the length calculation function");

    std::vector<int> rt = bellman_ford(n, start-1, e);
    ui->logs->append("----------------------");
    ui->logs->append("Response output....");

    ui->logs->append("Finish!");
    return rt;
}
