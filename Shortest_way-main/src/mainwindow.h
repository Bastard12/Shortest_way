//! @file mainwindow.h
//! @author Акопян Р.О.
//! @note Ответственный: Полевой Д.В.
//! @brief Заголовочный фойл, описывающий главное окно программы

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTableWidgetItem>
#include <QString>
#include <QFile>
#include <vector>
#include <sstream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


struct Edges
{
    int u;  // Откуда
    int v;  // Куда
    int w;  // Расстояние
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //! @brief Конструктор окна
    //! @param[in] parent - Родительский виджет
    MainWindow(QWidget *parent = nullptr);

    //! @brief Деструктор окна
    ~MainWindow();

private slots:
    //! @brief Создание таблицы для ввода графа
    void on_create_button_clicked();

    //! @brief Запуск алгоритма для расчета кратчайших путей
    void on_get_answer_button_clicked();

    //! @brief Чтение графа из файла и запись в таблицу
    void on_pushButton_clicked();

public slots:
    //! @brief Преобразование матрицы в удобный для расчета вид
    //! @param[in] start Номер стартового узла
    //! @param[in] matrix Массив узлов
    //! @param[in] n Кол-во узлов
    std::vector<int> Enter(std::vector<std::vector<int>> matrix, int n, int start);

    //! @brief Реализация алгоритма Беллмара-Форда
    //! @param[in] n
    //! @param[in] s
    //! @param[in] e
    std::vector<int> bellman_ford(int n, int s, int e);

private:

    Ui::MainWindow *ui; //!< Указатель на графический интерфейс
    bool empty_table = true; //!< Флаг пустой таблицы
    int count = 0; //!< Кол-во узлов
    int start = 0; //!< Номер настартового узла

    Edges edge[499]; //!< Массив узлов
    int d[1000]; //!< Массив промежуточных значений

};
#endif // MAINWINDOW_H
