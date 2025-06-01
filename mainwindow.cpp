#include "mainwindow.h"
#include "gameboard.h"
#include "scoreboard.h"
#include "rulespage.h"
#include "aboutpage.h"
#include <QMenuBar>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    gameBoard(nullptr),
    scoreBoard(nullptr),
    rulesPage(nullptr),
    aboutPage(nullptr)
{
     centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    mainLayout = new QVBoxLayout(centralWidget); 

    setupMenu();
    setupHomePage();
}

MainWindow::~MainWindow()
{
    // 
}

void MainWindow::setupMenu()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&Fichier"));
    QAction *newGameAction = fileMenu->addAction(tr("&Nouveau"));
    connect(newGameAction, &QAction::triggered, this, &MainWindow::newGame);

    QMenu *gameMenu = menuBar()->addMenu(tr("&Jeu"));
    QAction *scoresAction = gameMenu->addAction(tr("&Scores"));
    connect(scoresAction, &QAction::triggered, this, &MainWindow::showScores);
    QAction *rulesAction = gameMenu->addAction(tr("&Règles"));
    connect(rulesAction, &QAction::triggered, this, &MainWindow::showRules);

    QMenu *helpMenu = menuBar()->addMenu(tr("À pr&opos"));
    QAction *aboutAction = helpMenu->addAction(tr("À propos"));
    connect(aboutAction, &QAction::triggered, this, &MainWindow::showAbout);
}

void MainWindow::setupHomePage() {
    // Nettoyer le layout existant si nécessaire
    QLayoutItem *item;
    while ((item = mainLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    welcomeLabel = new QLabel("Bienvenue dans le jeu du PENDU", this); // [cite: 12]
    welcomeLabel->setAlignment(Qt::AlignCenter);
    welcomeLabel->setStyleSheet("font-size: 24px; font-weight: bold;");

    newGameButton = new QPushButton("Nouveau Jeu", this);
    scoresButton = new QPushButton("Scores", this);
    rulesButton = new QPushButton("Règles", this);
    aboutButton = new QPushButton("À propos", this);

    connect(newGameButton, &QPushButton::clicked, this, &MainWindow::newGame);
    connect(scoresButton, &QPushButton::clicked, this, &MainWindow::showScores);
    connect(rulesButton, &QPushButton::clicked, this, &MainWindow::showRules);
    connect(aboutButton, &QPushButton::clicked, this, &MainWindow::showAbout);

    mainLayout->addWidget(welcomeLabel);
    mainLayout->addStretch();
    mainLayout->addWidget(newGameButton);
    mainLayout->addWidget(scoresButton);
    mainLayout->addWidget(rulesButton);
    mainLayout->addWidget(aboutButton);
    mainLayout->addStretch();
}

void MainWindow::newGame() {
    // Nettoyer l'affichage actuel
    QLayoutItem *item;
    while ((item = mainLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    if (!gameBoard) {
        gameBoard = new GameBoard(this);
        connect(gameBoard, &GameBoard::gameOver, this, [this](int score) {
            // Logique pour vérifier le top dix et rediriger
            if (scoreBoard && scoreBoard->isTopTen(score)) { // Supposons une méthode isTopTen dans ScoreBoard
                QString pseudo = QMessageBox::getText(this, "Top Dix !", "Félicitations ! Entrez votre pseudo :");
                if (!pseudo.isEmpty()) {
                    scoreBoard->addScore(pseudo, score); // Supposons une méthode addScore
                    showScores(); // Rediriger vers la page des scores [cite: 4]
                } else {
                    showHomePage(); // Rediriger vers l'accueil si le pseudo est vide [cite: 5]
                }
            } else {
                showHomePage(); // Rediriger vers l'accueil si pas assez de points [cite: 5]
            }
        });
    }
    mainLayout->addWidget(gameBoard);
    gameBoard->startNewGame();
}

void MainWindow::showScores() {
    // Nettoyer l'affichage actuel
    QLayoutItem *item;
    while ((item = mainLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    if (!scoreBoard) {
        scoreBoard = new ScoreBoard(this);
    }
    mainLayout->addWidget(scoreBoard);
    QPushButton *backButton = new QPushButton("Retour à l'accueil", this);
    connect(backButton, &QPushButton::clicked, this, &MainWindow::showHomePage);
    mainLayout->addWidget(backButton);
}

void MainWindow::showRules() {
    // Nettoyer l'affichage actuel
    QLayoutItem *item;
    while ((item = mainLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    if (!rulesPage) {
        rulesPage = new RulesPage(this);
    }
    mainLayout->addWidget(rulesPage);
    QPushButton *backButton = new QPushButton("Retour à l'accueil", this);
    connect(backButton, &QPushButton::clicked, this, &MainWindow::showHomePage);
    mainLayout->addWidget(backButton);
}

void MainWindow::showAbout() {
    // Nettoyer l'affichage actuel
    QLayoutItem *item;
    while ((item = mainLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    if (!aboutPage) {
        aboutPage = new AboutPage(this);
    }
    mainLayout->addWidget(aboutPage);
    QPushButton *backButton = new QPushButton("Retour à l'accueil", this);
    connect(backButton, &QPushButton::clicked, this, &MainWindow::showHomePage);
    mainLayout->addWidget(backButton);
}

void MainWindow::showHomePage() {
    // Nettoyer l'affichage actuel et revenir à la page d'accueil
    QLayoutItem *item;
    while ((item = mainLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    setupHomePage();
}
