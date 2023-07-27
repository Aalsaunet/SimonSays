#include <stdlib.h>
#include <QThread>
#include <iostream>
#include "simonsays.h"
#include "./ui_simonsays.h"

SimonSays::SimonSays(QWidget *parent) : QMainWindow(parent), ui(new Ui::SimonSays) {
    ui->setupUi(this);

    colorToButton[SimonSays::Color(red)] = ui->redButton;
    colorToButton[SimonSays::Color(blue)] = ui->blueButton;
    colorToButton[SimonSays::Color(yellow)] = ui->yellowButton;
    colorToButton[SimonSays::Color(green)] = ui->greenButton;

    std::cout << "SimonSays initialization complete." << std::endl;

    startNewGame();
}

SimonSays::~SimonSays() {
    delete ui;
}

void SimonSays::startNewGame() {
    sequence = std::vector<Color>();
    Color draw = static_cast<Color>(rand() % COLOR_COUNT);
    sequence.push_back(draw);
    playSequence();
}

void SimonSays::playSequence() {

    for (int i = 0; i < sequence.size(); i++) {
        colorToButton[sequence[i]]->setEnabled(true);
        //colorToButton[sequence[i]]->setFlat(true);
        std::cout << i << ": Simon says " << sequence[i] << std::endl;
        QThread::sleep(5); // wait for 1 sec
        colorToButton[sequence[i]]->setEnabled(false);
    }
}

void SimonSays::on_redButton_clicked() {

}


void SimonSays::on_blueButton_clicked() {

}


void SimonSays::on_yellowButton_clicked() {

}


void SimonSays::on_greenButton_clicked() {

}

