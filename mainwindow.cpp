#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_wordList << "PROGRAMMATION" << "ORDINATEUR" << "TRADING" << "BENIN" << "MEMOIRE" << "BEYONCE";

    initializeGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}
