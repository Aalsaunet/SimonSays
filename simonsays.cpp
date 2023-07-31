#include <stdlib.h>
#include <QThread>
#include <iostream>
#include "simonsays.h"
#include "./ui_simonsays.h"

SimonSays::SimonSays(QApplication *a, QWidget *parent) : QMainWindow(parent), ui(new Ui::SimonSays) {
    ui->setupUi(this);
    ui->gameOverText->setVisible(false);
    app = a;
    sequence = std::vector<Color>();

    colorToButton[SimonSays::Color(red)] = ui->redButton;
    colorToButton[SimonSays::Color(blue)] = ui->blueButton;
    colorToButton[SimonSays::Color(yellow)] = ui->yellowButton;
    colorToButton[SimonSays::Color(green)] = ui->greenButton;
}

SimonSays::~SimonSays() {
    delete ui;
}

void SimonSays::startNewGame() {
    ui->gameOverText->setVisible(false);
    sequence.clear();
    displayColorSequence();
}

void SimonSays::displayColorSequence() {

    currentColorIdx = 0;

    // Add new color to the sequence
    Color draw = static_cast<Color>(arc4random_uniform(COLOR_COUNT));
    sequence.push_back(draw);

    // Update streak length
    ui->sequenceLength->setText(QString::number(sequence.size()));

    // Display all colors in the sequence + the newly inserted one
    for (int i = 0; i < sequence.size(); i++) {
        colorToButton[sequence[i]]->setChecked(true);
        app->processEvents();
        QThread::sleep(1);
        colorToButton[sequence[i]]->setChecked(false);
        app->processEvents();
        QThread::sleep(1);
    }
}

void SimonSays::receiveAnswer(Color answer) {

    colorToButton[answer]->setChecked(false);
    if (sequence.size() == 0)
        return;

    bool correctlyAnswered = (answer == sequence[currentColorIdx]);
    if (correctlyAnswered) {
        bool sequenceCompleted = (++currentColorIdx == sequence.size());
        if (sequenceCompleted) {
            displayColorSequence();
        }
    } else {
        ui->gameOverText->setVisible(true);
    }
}

void SimonSays::keyPressEvent(QKeyEvent *e) {
    if (e->key() == Qt::Key_Space) {
        startNewGame();
    }
}

void SimonSays::on_redButton_clicked() {
    receiveAnswer(SimonSays::Color(red));
}


void SimonSays::on_blueButton_clicked() {
    receiveAnswer(SimonSays::Color(blue));
}


void SimonSays::on_yellowButton_clicked() {
    receiveAnswer(SimonSays::Color(yellow));
}


void SimonSays::on_greenButton_clicked() {
    receiveAnswer(SimonSays::Color(green));
}

