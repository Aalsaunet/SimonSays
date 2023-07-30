#include <stdlib.h>
#include <QThread>
#include <iostream>
#include "simonsays.h"
#include "./ui_simonsays.h"

SimonSays::SimonSays(QApplication *a, QWidget *parent) : QMainWindow(parent), ui(new Ui::SimonSays) {
    ui->setupUi(this);
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

    ui->redButton->setChecked(false);
    ui->blueButton->setChecked(false);
    ui->yellowButton->setChecked(false);
    ui->greenButton->setChecked(false);

    std::cout << "SimonSays initialization complete." << std::endl;

    startNewGame();
}

void SimonSays::startNewGame() {
    sequence = std::vector<Color>();
    //Color draw = static_cast<Color>(rand() % COLOR_COUNT);
    //sequence.push_back(draw);

    // TODO Remove test code
    sequence.push_back(SimonSays::Color(red));
    sequence.push_back(SimonSays::Color(blue));
    sequence.push_back(SimonSays::Color(yellow));
    sequence.push_back(SimonSays::Color(green));
    // ENDTODO

    playSequence();
}

void SimonSays::playSequence() {

    for (int i = 0; i < sequence.size(); i++) {
        colorToButton[sequence[i]]->setChecked(true);
        app->processEvents();//a->processEvents();
        std::cout << i << ": Simon says " << sequence[i] << std::endl;
        QThread::sleep(2); // wait for 1 sec
        colorToButton[sequence[i]]->setChecked(false);
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

