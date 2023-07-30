#ifndef SIMONSAYS_H
#define SIMONSAYS_H

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QKeyEvent>
#include <vector>
#include <unordered_map>

QT_BEGIN_NAMESPACE
namespace Ui { class SimonSays; }
QT_END_NAMESPACE

class SimonSays : public QMainWindow
{
    Q_OBJECT

public:
    SimonSays(QApplication *app = nullptr, QWidget *parent = nullptr);
    ~SimonSays();
    void init();
    enum Color { red, blue, yellow, green };
    static const int COLOR_COUNT = 4;

private slots:
    void on_redButton_clicked();
    void on_blueButton_clicked();
    void on_yellowButton_clicked();
    void on_greenButton_clicked();

    virtual void keyPressEvent(QKeyEvent *event);

private:
    void startNewGame();
    void playSequence();

    QApplication *app;
    Ui::SimonSays *ui;
    std::vector<Color> sequence;
    std::map<Color, QPushButton *> colorToButton;
};
#endif // SIMONSAYS_H
