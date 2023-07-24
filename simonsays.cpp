#include "simonsays.h"
#include "./ui_simonsays.h"

SimonSays::SimonSays(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SimonSays)
{
    ui->setupUi(this);
}

SimonSays::~SimonSays()
{
    delete ui;
}

