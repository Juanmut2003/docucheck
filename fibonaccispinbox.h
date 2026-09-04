#ifndef FIBONACCISPINBOX_H
#define FIBONACCISPINBOX_H

#include <QSpinBox>

class FibonacciSpinBox : public QSpinBox
{
    Q_OBJECT
public:
    explicit FibonacciSpinBox(QWidget *parent = nullptr);

protected:
    void stepBy(int steps) override;
    StepEnabled stepEnabled() const override;
    QValidator::State validate(QString &text, int &pos) const override;
    void fixup(QString &text) const override;

private:
    static int nearestFibonacci(int value);
};

#endif // FIBONACCISPINBOX_H
