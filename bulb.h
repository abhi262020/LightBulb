#ifndef BULB_H
#define BULB_H

#include <QMainWindow>
#include <QRegularExpressionValidator>
#include "FSM.h"
#include "Transition.h"
#include "State.h"
#include<QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Bulb; }
QT_END_NAMESPACE

class Bulb : public QMainWindow {
    Q_OBJECT

public:
    Bulb(QWidget *parent = nullptr);
    ~Bulb();

    int voltage;
    FSM* fsm;

    void Update();  // Function to update the state of the bulb

     QPushButton *quitButton;

private:
    Ui::Bulb *ui;

private slots:
    void validateInput();
    void on_pbExit_clicked();
    void on_pbVoltageTest_clicked();
};

#endif // BULB_H
