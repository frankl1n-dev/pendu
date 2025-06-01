#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class GameBoard;
class ScoreBoard;
class RulesPage;
class AboutPage;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow(); 

private slots:
    void newGame();
    void showScores();
    void showRules();
    void showAbout();


private:
    // Ui::MainWindow *ui;
    QWidget *centralWidget;
    QBoxLayout *mainLayout;
    QPushButton *newGameButton;
    QPushButton *scoreBoardButton;
    QPushButton *rulesButton;
    QPushButton *aboutButton;

    
    GameBoard *gameBoard;
    ScoreBoard *scoreBoard;
    RulesPage *rulesPage;
    AboutPage *aboutPage;

    void setupHomePage();
    void setupMenu();

};
#endif // MAINWINDOW_H
