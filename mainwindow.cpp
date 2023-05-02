#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

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

Vector<int> v(14);
Vector<int> b(10);

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(Vector<int>& arr)
{
    int n=arr.size();
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);

}




void MainWindow::on_push_back_clicked()
{
    QString el= ui->lineEdit->text();
       v.push_back(el.toInt());
       qDebug()<<el;
       el="";
       ui->lineEdit->clear();

}


void MainWindow::on_pushButton_clicked()
{
    for (int i = 0; i < v.size(); i += 3)
           {
               int median;
               if (i + 2 < v.size())
               {
                   Vector<int> tmp;
                   tmp.push_back(v[i]); tmp.push_back(v[i + 1]); tmp.push_back(v[i + 2]);

                   sort(tmp);
                   median = tmp[1];
               }
               else if (i + 1 < v.size())
               {
                   median = (v[i] + v[i + 1]) / 2;
               }
               else
               {
                   median = v[i];
               }

               b.push_back(median);
           }

           QString vec="";

           for (int i : b)
           {
              vec+=QString::number(i);
              vec+=" ";
           }

           QMessageBox::information(this,"Вектор из медиан",vec);
           v.clear();
           b.clear();
}


void MainWindow::on_pushButton_2_clicked()
{
    QString vec="";

    for (int i : v)
    {
       vec+=QString::number(i);
       vec+=" ";
    }

    QMessageBox::information(this,"Вектор ",vec);
}

