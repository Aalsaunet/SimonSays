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

class SimonSays : public QMainWindow {
    Q_OBJECT

public:
    enum Color { red, blue, yellow, green };
    static const int COLOR_COUNT = 4;

    SimonSays(QApplication *app = nullptr, QWidget *parent = nullptr);
    ~SimonSays();

private slots:
    void on_redButton_clicked();
    void on_blueButton_clicked();
    void on_yellowButton_clicked();
    void on_greenButton_clicked();
    virtual void keyPressEvent(QKeyEvent *event);

private:
    QApplication *app;
    Ui::SimonSays *ui;
    std::vector<Color> sequence;
    std::map<Color, QPushButton *> colorToButton;
    int currentColorIdx = 0;

    void startNewGame();
    void displayColorSequence();
    void receiveAnswer(Color);
};
#endif // SIMONSAYS_H
