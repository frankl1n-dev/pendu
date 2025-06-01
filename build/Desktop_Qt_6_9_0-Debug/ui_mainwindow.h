/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *hangmanImageLabel;
    QLineEdit *lineEdit;
    QPushButton *guessButton;
    QLabel *triedLettersLabel;
    QLabel *messageLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 30, 511, 51));
        label->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label->setStyleSheet(QString::fromUtf8("font: 700 36pt \"Noto Sans Brahmi\";"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        hangmanImageLabel = new QLabel(centralwidget);
        hangmanImageLabel->setObjectName("hangmanImageLabel");
        hangmanImageLabel->setGeometry(QRect(530, 100, 251, 351));
        hangmanImageLabel->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(10, 190, 351, 61));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        lineEdit->setFont(font);
        lineEdit->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        lineEdit->setMaxLength(1);
        guessButton = new QPushButton(centralwidget);
        guessButton->setObjectName("guessButton");
        guessButton->setGeometry(QRect(10, 280, 351, 61));
        QFont font1;
        font1.setPointSize(15);
        guessButton->setFont(font1);
        guessButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        guessButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(53, 132, 228, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(36, 31, 49);"));
        triedLettersLabel = new QLabel(centralwidget);
        triedLettersLabel->setObjectName("triedLettersLabel");
        triedLettersLabel->setGeometry(QRect(10, 380, 341, 61));
        triedLettersLabel->setFont(font1);
        triedLettersLabel->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        triedLettersLabel->setTextFormat(Qt::TextFormat::PlainText);
        messageLabel = new QLabel(centralwidget);
        messageLabel->setObjectName("messageLabel");
        messageLabel->setGeometry(QRect(10, 490, 511, 61));
        messageLabel->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        messageLabel->setStyleSheet(QString::fromUtf8("font: 15pt \"Ubuntu\";"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "_ _ _ _ _ _ _", nullptr));
        hangmanImageLabel->setText(QCoreApplication::translate("MainWindow", "_", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez une lettre ...", nullptr));
        guessButton->setText(QCoreApplication::translate("MainWindow", "D\303\251viner", nullptr));
        triedLettersLabel->setText(QCoreApplication::translate("MainWindow", "Lettres essay\303\251es : ", nullptr));
        messageLabel->setText(QCoreApplication::translate("MainWindow", "Bienvenue au Pendu !", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
