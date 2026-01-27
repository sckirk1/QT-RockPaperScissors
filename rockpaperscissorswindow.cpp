#include "rockpaperscissorswindow.h"
#include "./ui_rockpaperscissorswindow.h"
#include <QPixmap>

RockPaperScissorsWindow::RockPaperScissorsWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RockPaperScissorsWindow)
{
    ui->setupUi(this);

    QPixmap paperImage("C:/Users/samki/Desktop/RPS/paper.jpg");
    QPixmap scissorsImage("C:/Users/samki/Desktop/RPS/R.png");
    ui->userChoiceLabel->setPixmap(scissorsImage);
}

RockPaperScissorsWindow::~RockPaperScissorsWindow()
{
    delete ui;
}


void RockPaperScissorsWindow::on_rockButton_clicked()
{
    QPixmap rockImage("C:/Users/samki/Desktop/RPS/rock.png");
    ui->userChoiceLabel->setText("You Chose: Rock");
    ui->userChoiceLabel->setPixmap(rockImage);
    ui->userChoiceLabel->setScaledContents(true);
}


void RockPaperScissorsWindow::on_paperButton_clicked()
{
    QPixmap paperImage("C:/Users/samki/Desktop/RPS/paper.jpg");
    ui->userChoiceLabel->setText("You Chose: Paper");
    ui->userChoiceLabel->setPixmap(paperImage);
    ui->userChoiceLabel->setScaledContents(true);
    userChoice = "Paper";
}


void RockPaperScissorsWindow::on_scissorsButton_clicked()
{
    QPixmap scissorsImage("C:/Users/samki/Desktop/RPS/R.png");
    ui->userChoiceLabel->setText("You Chose: Scissors");
    ui->userChoiceLabel->setPixmap(scissorsImage);
    ui->userChoiceLabel->setScaledContents(true);
}




void RockPaperScissorsWindow::on_playButton_clicked()
{
    userChoice

}

