#ifndef SIMONSAYS_H
#define SIMONSAYS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SimonSays; }
QT_END_NAMESPACE

class SimonSays : public QMainWindow
{
    Q_OBJECT

public:
    SimonSays(QWidget *parent = nullptr);
    ~SimonSays();

private:
    Ui::SimonSays *ui;
};
#endif // SIMONSAYS_H
