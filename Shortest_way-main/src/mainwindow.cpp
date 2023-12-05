#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTableWidgetItem>
#include <QString>

//#include "Graph.cpp"

#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_create_button_clicked()
{
    count = ui->edit_count->text().toInt();

    ui->table->setRowCount(count);
    ui->table->setColumnCount(count);

    for (int i= 0;i<count;i+=1)
    {
        ui->table->setRowHeight(i, 40);
        ui->table->setColumnWidth(i, 40);
    }
}


void MainWindow::on_get_answer_button_clicked()
{
    ui->edit_answer->setText("");

    start = ui->edit_start->text().toInt();

    std::vector<std::vector<int> > table;
    table.resize(count);

    for (int i = 0;i<count;i+=1)
    {
        table[i].resize(count);
        for (int j = 0;j<count;j+=1)
        {
            table[i][j] = ui->table->item(i,j)->text().toInt();
        }
    }

    std::vector<int> answer;
    answer = Enter(table,count, start);

    for (int i = 0;i<count;i+=1)
    {
        ui->edit_answer->append("Distance to the edge " + QString::number(i+1) + " --  " + QString::number(answer[i]));
    }


}


