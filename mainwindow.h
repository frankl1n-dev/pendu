#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QSet>
#include <QPixmap>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void on_guessButton_clicked();

private:
    Ui::MainWindow *ui;

    // Declaration des variables
    QString m_secretWord;
    QString m_displayWord;

    int m_incorrectGuesses;

    QSet<QChar> m_guessedLetters;

    QStringList m_wordList;

    QVector<QPixmap> m_hangmanImages;
    QString m_hangmanImagePath = ":/images/hangman_";

    void initializeGame(); // pour une nouvelle partie
    void updateUI();
    void processGuess(QChar guess);
    void isGameWon();
    void isGameLost();
    void updateHangmanDisplay();

};
#endif // MAINWINDOW_H
