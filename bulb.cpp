#include "bulb.h"
//#include "Bulb.h"
#include "ui_bulb.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QMessageBox>
#include<iostream>

using namespace std;

// Conditions for transitions based on voltage
int off_condition(int voltage) { return voltage == 0; }
int on_condition(int voltage) { return voltage > 0 && voltage <= 240; }
int broken_condition(int voltage) { return voltage > 240; }

Bulb::Bulb(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Bulb)
{
    ui->setupUi(this);

  //  voltage = 0;
  //  Bulb* bulb = new Bulb();
    // Initial state
  //  bulb->Update();

//    // Voltage transitions
//    bulb->voltage = 0;
//    bulb->Update();

//    bulb->voltage = 240;
//    bulb->Update();

//    bulb->voltage = 300;
//    bulb->Update();

   // delete bulb;

    // Initialize FSM with the Off state
    fsm = new FSM(Off);

    // Add transitions between states
    fsm->AddTransition(new Transition(Off, On, on_condition));
    fsm->AddTransition(new Transition(On, Off, off_condition));
    fsm->AddTransition(new Transition(On, Broken, broken_condition));
    fsm->AddTransition(new Transition(Broken, Off, off_condition));

    // Create a regular expression for values between 1 and 240
//    QRegularExpression regex("^(240|[1-9][0-9]?|1[0-9]{2}|2[0-3][0-9])$");
  //  QRegularExpressionValidator *validator = new QRegularExpressionValidator(regex, this);

    // Apply the validator to the QLineEdit for correct values (1-240)
//    ui->voltageLineEdit->setValidator(validator);

    // Connect the QLineEdit's textChanged signal to validate the input
    connect(ui->voltageLineEdit, &QLineEdit::textChanged, this, &Bulb::validateInput);
    connect(ui->pbVoltageTest,&QPushButton::clicked,this,&Bulb::on_pbVoltageTest_clicked);
    connect(ui->quitButton, &QPushButton::clicked, this, &Bulb::on_pbExit_clicked);

}

Bulb::~Bulb()
{
    delete ui;
    delete fsm;
}

void Bulb::Update() {
    cout << "Voltage: " << voltage << "V\n";
    fsm->Update(voltage);

    // Output the current state
    StateEnum currentState = fsm->GetCurrentState();
    if (currentState == Off) {
        cout << "Bulb is Off.\n";
    }
    else if (currentState == On) {
        cout << "Bulb is On.\n";
    }
    else if (currentState == Broken) {
        cout << "Bulb is Broken.\n";
    }
}

void Bulb::validateInput()
{
    QString input = ui->voltageLineEdit->text();
    bool isValid = true;

    // Convert the input to an integer
    int value = input.toInt(&isValid);

    if (isValid) {
        // Check if the value is in the incorrect range (241-440)   voltage
        if (value >= 241 && value <= 440) {
            // Show a warning message
            QMessageBox::warning(this, "Input Error", "The value is in the incorrect range (241-440).");
            ui->voltageLineEdit->clear();  // Optionally clear the input
        }
        //Check if the value is in the incorrect range (441-1100) voltage
        else if(value >= 441 && value <= 1100)
        {
            //Show a warning message
               QMessageBox::warning(this,"Input Error","The value is in the incorrect range (441-1100)");
               ui->voltageLineEdit->clear();
        }
        //Check if the value is in the incorrect range (1101-9999) voltage
        else if(value >= 441 && value <= 1100)
        {
            //Show a warning message
               QMessageBox::warning(this,"Input Error","The value is in the incorrect range (441-1100)");
               ui->voltageLineEdit->clear();
        }
    }
}

void Bulb::on_pbVoltageTest_clicked()
{

    Bulb *bulb = new Bulb();
    bulb->voltage = ui->voltageLineEdit->text().toDouble();
    bulb->Update();
}

void Bulb::on_pbExit_clicked()
{
    // QCoreApplication::quit();  // Exits the application
   close();
}
