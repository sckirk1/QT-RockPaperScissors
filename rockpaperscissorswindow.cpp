#include "rockpaperscissorswindow.h"
#include "./ui_rockpaperscissorswindow.h"
#include <time.h>
#include <string.h>
#include "aboutdialog.h"

using namespace std;

static std::string options[] = {"rock", "paper", "scissors"};
static AboutDialog *about; // TODO: This is currently a static varaible, we may be able to make it not static. Look into which options are better

// ============== CONSTRUCTORS & DESTRUCTOR =====================
RockPaperScissorsWindow::RockPaperScissorsWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::RockPaperScissorsWindow) {
    // QT Required setup call
    ui->setupUi(this);

    // Setting up the lables to hold PixMaps
    ui->userChoiceLabel->setScaledContents(true);
    ui->oppPickLabel->setScaledContents(true);

    // Setup the initial images
    ui->oppPickLabel->setPixmap(loadQuestionMarkImage());
    ui->userChoiceLabel->setPixmap(loadQuestionMarkImage());


    ui->playButton->setEnabled(false);
    std::srand(time(NULL));
}

RockPaperScissorsWindow::~RockPaperScissorsWindow() {
    // Cleans up the memory used by this window when closed
    delete ui;
}


// ================= SLOTS ====================

void RockPaperScissorsWindow::on_rockButton_clicked() {
    userChoice = "rock";
    ui->userChoiceLabel->setPixmap(loadRockImage());
    ui->playButton->setEnabled(true);
}


void RockPaperScissorsWindow::on_paperButton_clicked() {
    userChoice = "paper";
    ui->userChoiceLabel->setPixmap(loadPaperImage());
    ui->playButton->setEnabled(true);
}


void RockPaperScissorsWindow::on_scissorsButton_clicked() {
    userChoice = "scissors";
    ui->userChoiceLabel->setPixmap(loadScissorsImage());
    ui->playButton->setEnabled(true);
}


void RockPaperScissorsWindow::on_playButton_clicked() {
    //TODO: Compare Enums instead of strings
    // Game Logic could also be cleaner probably
    string computerChoice = options[(rand() % 3)];
    setComputerImage(computerChoice);

    if (computerChoice == userChoice) {
        // Tie Game
        ui->resultLabel->setText("It's a Tie!");
    } else {
        if (userChoice == "scissors") {
            if (computerChoice == "rock") {
                // Comp wins
                ui->resultLabel->setText("You Lose!");
            } else {
                // User wins
                ui->resultLabel->setText("You Win!");
            }
        } else if (userChoice == "rock") {
            if (computerChoice == "paper") {
                // Comp wins
                ui->resultLabel->setText("You Lose!");
            } else {
                // User wins
                ui->resultLabel->setText("You Win!");
            }
        } else if (computerChoice == "scissors") {
            // Comp wins
            ui->resultLabel->setText("You Lose!");
        } else {
            // User wins
            ui->resultLabel->setText("You Win!");
        }
    }
    ui->playButton->setEnabled(false);
}


void RockPaperScissorsWindow::on_resetButton_clicked()
{
    ui->oppPickLabel->setPixmap(loadQuestionMarkImage());
    ui->userChoiceLabel->setPixmap(loadQuestionMarkImage());
    ui->playButton->setEnabled(false);
}


void RockPaperScissorsWindow::on_aboutButton_clicked()
{
    about = new AboutDialog(this);
    about->show();
}





// ================ HELPER METHODS ====================
// TODO: See if these can be loaded once instead of created each time we need them
// TODO: See of we can use relative paths instead, maybe ./path/from/root?
QPixmap RockPaperScissorsWindow::loadQuestionMarkImage() {
    QPixmap pixmap("C:/Users/samki/Desktop/RPS/questionMark.png");
    return pixmap;
}


QPixmap RockPaperScissorsWindow::loadScissorsImage() {
    QPixmap pixmap("C:/Users/samki/Desktop/RPS/scissors.png");
    return pixmap;
}


QPixmap RockPaperScissorsWindow::loadPaperImage() {
    QPixmap pixmap("C:/Users/samki/Desktop/RPS/paper.jpg");
    return pixmap;
}


QPixmap RockPaperScissorsWindow::loadRockImage() {
    QPixmap pixmap("C:/Users/samki/Desktop/RPS/rock.png");
    return pixmap;
}

void RockPaperScissorsWindow::setComputerImage(string computerChoice) {
    if (computerChoice == "rock") {
        ui->oppPickLabel->setPixmap(loadRockImage());
    } else if (computerChoice == "paper") {
        ui->oppPickLabel->setPixmap(loadPaperImage());
    } else {
        ui->oppPickLabel->setPixmap(loadScissorsImage());
    }
}

