#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<string>
#include<stack>
#include<QDebug>
#include<queue>
#include <QtWidgets/QMessageBox>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_multip_clicked()
{
    QString temp=ui->lineEdit->text();
    temp+="*";
    ui->lineEdit->setText(temp);
}

void MainWindow::on_pushButton_0_clicked()
{
    QString temp=ui->lineEdit->text();
    if(temp=='0')
        temp="0";
    else
    temp+="0";
    ui->lineEdit->setText(temp);
}

void MainWindow::on_pushButton_1_clicked()
{
    QString temp=ui->lineEdit->text();
    if(temp=='0')
        temp="1";
    else
    temp+="1";
    ui->lineEdit->setText(temp);
}

void MainWindow::on_pushButton_9_clicked()
{
    QString temp=ui->lineEdit->text();
    if(temp=='0')
        temp="2";
    else
    temp+="2";
    ui->lineEdit->setText(temp);
}

void MainWindow::on_pushButton_10_clicked()
{
    QString temp=ui->lineEdit->text();
    if(temp=='0')
        temp="3";
    else
    temp+="3";
    ui->lineEdit->setText(temp);
}

void MainWindow::on_pushButton_5_clicked()
{
    QString temp=ui->lineEdit->text();
    if(temp=='0')
        temp="4";
    else
    temp+="4";
    ui->lineEdit->setText(temp);
}

void MainWindow::on_pushButton_6_clicked()
{
    QString temp=ui->lineEdit->text();
    if(temp=='0')
        temp="5";
    else
    temp+="5";
    ui->lineEdit->setText(temp);
}

void MainWindow::on_pushButton_7_clicked()
{
    QString temp=ui->lineEdit->text();
    if(temp=='0')
        temp="6";
    else
    temp+="6";
    ui->lineEdit->setText(temp);
}

void MainWindow::on_pushButton_11_clicked()
{
    QString temp=ui->lineEdit->text();
    if(temp=='0')
        temp="7";
    else
    temp+="7";
    ui->lineEdit->setText(temp);
}

void MainWindow::on_pushButton_14_clicked()
{
    QString temp=ui->lineEdit->text();
    if(temp=='0')
        temp="8";
    else
    temp+="8";
    ui->lineEdit->setText(temp);
}

void MainWindow::on_pushButton_17_clicked()
{
    QString temp=ui->lineEdit->text();
    if(temp=='0')
        temp="9";
    else
    temp+="9";
    ui->lineEdit->setText(temp);
}

void MainWindow::on_pushButton_division_clicked()
{
    QString temp=ui->lineEdit->text();
    temp+="/";
    ui->lineEdit->setText(temp);
}

void MainWindow::on_pushButton_subtrac_clicked()
{
    QString temp=ui->lineEdit->text();
    temp+="-";
    ui->lineEdit->setText(temp);
}

void MainWindow::on_pushButton_add_clicked()
{
    QString temp=ui->lineEdit->text();
    temp+="+";
    ui->lineEdit->setText(temp);
}

void MainWindow::on_pushButton_bankspace_clicked()
{
    QString temp=ui->lineEdit->text();
   temp=temp.left(temp.size()-1);
    ui->lineEdit->setText(temp);
}




int getPriority(char ch)
{
    //获取优先级
    if (ch == '(') return 1;
    else if (ch == '+' || ch == '-') return 2;
    else if (ch == '*' || ch == '/') return 3;
    else return 4;
}

QString getPosfix(QString str1)
{
    string str=str1.toStdString();
    stack<char> mystack;
    int size = str.size();
    int i = 0;
    char tmp;
    string res = "";
    while (i < size) {
        if (str[i] >= '0' && str[i] <= '9'){
            res.push_back(str[i]);
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            res.push_back('p');//添加高位数标识
            if (mystack.empty()) {
                mystack.push(str[i]);
            }
            else {
                while (!mystack.empty()) {
                    tmp = mystack.top();
                    if (getPriority(tmp) >= getPriority(str[i])) {
                        //弹出栈顶元素
                        res.push_back(tmp);
                        mystack.pop();
                    }
                    else break;
                }
                mystack.push(str[i]);
            }
        }
        else {
            if(str[i]=='(') mystack.push(str[i]);
            else {
                while (mystack.top() != '(') {
                    tmp = mystack.top();
                    res.push_back(tmp);
                    mystack.pop();
                }
                mystack.pop();
            }
        }
        i++;
    }
    res.push_back('p');
    //遍历完后，若栈非空，弹出所有元素
    while (!mystack.empty()) {
        tmp = mystack.top();
        res.push_back(tmp);
        mystack.pop();
    }
  QString temp= QString::fromStdString(res);
  return temp;

}
double transtion(QChar ch)
{
    return ch.toLatin1()-'0';
}
void MainWindow::on_pushButton_equal_clicked()
{
    QString temp=getPosfix(ui->lineEdit->text());
    qDebug().noquote()<<temp;
    stack<double>Numstack;
    queue<double>tempQ;
    for(auto i=temp.begin();i!=temp.end();i++)
    {
        if(*i=='p'||(*i>='0'&&*i<='9'))
        {
            double temp_Num;
            if(*i!='p')
            tempQ.push(transtion(*i));
            else
            {
                while(!tempQ.empty())
                {
                    temp_Num=temp_Num*10+tempQ.front();
                    tempQ.pop();
                }
                 qDebug()<<"temp_Num="<<temp_Num;
                Numstack.push(temp_Num);
                temp_Num=0;
            }

        }
        else
        {
                double Right=Numstack.top();
                 qDebug()<<Right;
                Numstack.pop();
                double Lift=Numstack.top();
                qDebug()<<Lift;
                Numstack.pop();
                if(*i=='+')
                {
                         Numstack.push(Lift+Right);
                  }
                        else if(*i=='-')
                {
                          Numstack.push(Lift-Right);
                  }
                        else if(*i=='*')
                {
                         Numstack.push(Lift*Right);
                  }
                       else
                {
                        if(Right>0)
                            Numstack.push(Lift/Right);
                        else

                           QMessageBox::critical(this,"错误","除数不能为0");
                  }
        }

    }
    ui->lineEdit->setText(QString::number(Numstack.top()));
    Numstack.pop();

 // ui->lineEdit->setText();
}
