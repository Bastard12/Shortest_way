#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    answer_ = answer;
}



void MainWindow::on_pushButton_clicked()
{
    ui->table->clear();
    QFile file(QFileDialog::getOpenFileName(this, "Title"));
    std::vector<std::vector<QString>> input;

    if (file.open(QIODevice::ReadOnly))
    {
        std::stringstream ss(file.readAll().toStdString());
        std::string line;
        int count = 0;
        while(std::getline(ss, line, '\n'))
        {
            input.push_back({});
            std::stringstream ssline(line);
            std::string number;
            while(std::getline(ssline, number, ';'))
            {
                input[input.size()-1].push_back(QString::fromStdString(number));
            }
            count += 1;
        }
        ui->table->setRowCount(count);
        ui->table->setColumnCount(count);

        ui->edit_count->setText(QString::number(count));
        ui->edit_start->setText(QString::number(1));
    }

    int maxWidth = 0;
    for (auto line: input) if ( line.size() > maxWidth ) maxWidth = line.size();

    ui->table->setColumnCount(maxWidth);
    ui->table->setRowCount(input.size());

    for (int i = 0; i < input.size(); i += 1)
    {
        for (int j = 0; j < input[i].size(); j += 1)
        {
            ui->table->setItem(i,j, new QTableWidgetItem(input[i][j]));
        }
    }
    on_create_button_clicked();
}


void MainWindow::on_save_answer_button_clicked()
{
    auto filePath = QFileDialog::getSaveFileName(this);
    QFile file(filePath);

    if (file.open(QIODevice::WriteOnly))
    {
        for (auto item : answer_)
        {
            file.write(std::to_string(item).c_str(), 1);
            file.write("\n");
        }
        file.close();
    }
    else
    {
        QMessageBox::critical(this, "Save error", "Error with save to file!");
    }
}

