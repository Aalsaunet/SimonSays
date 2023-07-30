#include <stdlib.h>
#include <QThread>
#include <iostream>
#include "simonsays.h"
#include "./ui_simonsays.h"

SimonSays::SimonSays(QApplication *a, QWidget *parent) : QMainWindow(parent), ui(new Ui::SimonSays) {
    ui->setupUi(this);
    ui->gameOverText->setVisible(false);
    app = a;
}

SimonSays::~SimonSays() {
    delete ui;
}

 void SimonSays::keyPressEvent(QKeyEvent *e) {
    if (e->key() == Qt::Key_Space) {
        init();
    }
}

void SimonSays::init() {
    colorToButton[SimonSays::Color(red)] = ui->redButton;
    colorToButton[SimonSays::Color(blue)] = ui->blueButton;
    colorToButton[SimonSays::Color(yellow)] = ui->yellowButton;
    colorToButton[SimonSays::Color(green)] = ui->greenButton;
    std::cout << "SimonSays initialization complete." << std::endl;

    startNewGame();
}

void SimonSays::startNewGame() {

    ui->redButton->setChecked(false);
    ui->blueButton->setChecked(false);
    ui->yellowButton->setChecked(false);
    ui->greenButton->setChecked(false);
    ui->gameOverText->setVisible(false);

    sequence = std::vector<Color>();
    playSequence();
}

void SimonSays::playSequence() {
    currentColor = 0;

    Color draw = static_cast<Color>(rand() % COLOR_COUNT);
    sequence.push_back(draw);

    ui->sequenceLength->setText(QString::number(sequence.size()));

    for (int i = 0; i < sequence.size(); i++) {
        colorToButton[sequence[i]]->setChecked(true);
        app->processEvents();
        std::cout << i << ": Simon says " << sequence[i] << std::endl;
        QThread::sleep(1); // wait for 1 sec
        colorToButton[sequence[i]]->setChecked(false);
        app->processEvents();
        QThread::sleep(1);
    }

    ui->answerCount->setText(QString::number(currentColor));
}

void SimonSays::receiveAnswer(Color answer) {

    if (answer == sequence[currentColor]) {
        // Correctly answered
        currentColor++;
        ui->answerCount->setText(QString::number(currentColor));
        if (currentColor == sequence.size()) {
            // Whole sequenced is answered correctly
            playSequence();
        }

    } else {
        // Wrong color answered
        // TODO add game over screen
        ui->gameOverText->setVisible(true);
    }

}

void SimonSays::on_redButton_clicked() {
    ui->redButton->setChecked(false);
    receiveAnswer(SimonSays::Color(red));
}


void SimonSays::on_blueButton_clicked() {
    ui->blueButton->setChecked(false);
    receiveAnswer(SimonSays::Color(blue));
}


void SimonSays::on_yellowButton_clicked() {
    ui->yellowButton->setChecked(false);
    receiveAnswer(SimonSays::Color(yellow));
}


void SimonSays::on_greenButton_clicked() {
    ui->greenButton->setChecked(false);
    receiveAnswer(SimonSays::Color(green));
}

