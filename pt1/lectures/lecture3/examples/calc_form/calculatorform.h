#pragma once
#include "ui_calculatorform.h"


class CalculatorForm : public QWidget
{
    Q_OBJECT

public:
    CalculatorForm(QWidget *parent = nullptr);

private slots:
    void _onValueChanged(int value);

private:
    Ui::CalculatorForm _ui;

    
};
