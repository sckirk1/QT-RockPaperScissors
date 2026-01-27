#ifndef ROCKPAPERSCISSORSWINDOW_H
#define ROCKPAPERSCISSORSWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class RockPaperScissorsWindow;
}
QT_END_NAMESPACE

class RockPaperScissorsWindow : public QMainWindow
{
    Q_OBJECT

public:
    RockPaperScissorsWindow(QWidget *parent = nullptr);
    ~RockPaperScissorsWindow();

private slots:

    void on_rockButton_clicked();

    void on_paperButton_clicked();

    void on_scissorsButton_clicked();

    void on_playButton_clicked();

private:
    std::string userChoice;
    Ui::RockPaperScissorsWindow *ui;
};
#endif // ROCKPAPERSCISSORSWINDOW_H
