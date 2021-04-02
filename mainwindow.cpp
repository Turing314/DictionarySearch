#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QListWidget>
#include <bits/stdc++.h>

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


void MainWindow::set_items(QString word){                                 // function which is responsible for adding new elements to the list
    std::ifstream file;
    file.open("D:/JB/words.txt");                           // CHANGE PATH TO MATCH YOUR PATH TO words.txt files
    std::string line;

    std::string utf8_word = word.toUtf8().constData();                    // change Qstring to string

    while(getline(file, line)){                                           // for every word in file
        if (line.find(utf8_word) != std::string::npos) {                  // check if word is a substring
            QListWidgetItem *newItem = new QListWidgetItem;               // add new element to the list
            newItem->setText(QString::fromStdString(line));
            ui->listWidget->addItem(newItem);
        }
    }
}

void MainWindow::on_pushButton_clicked()                                  // when button "find" pressed
{
    QString word = ui->lineEdit->text();                                  // get the word
    ui->listWidget->clear();                                              // clear the list
    set_items(word);                                                      // call the function
}

void MainWindow::on_lineEdit_returnPressed()                              // when return pressed
{
    QString word = ui->lineEdit->text();                                  // get the word
    ui->listWidget->clear();                                              // clear the list
    set_items(word);                                                      // call the function
}
