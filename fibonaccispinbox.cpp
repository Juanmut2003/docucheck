#include "fibonaccispinbox.h"

#include <QtGlobal>

namespace {
const QList<int> kFibonacciValues = {0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987};
}

FibonacciSpinBox::FibonacciSpinBox(QWidget *parent)
    : QSpinBox(parent)
{
    setRange(kFibonacciValues.first(), kFibonacciValues.last());
}

int FibonacciSpinBox::nearestFibonacci(int value)
{
    int nearest = kFibonacciValues.first();
    for (int fib : kFibonacciValues) {
        if (qAbs(fib - value) < qAbs(nearest - value))
            nearest = fib;
    }
    return nearest;
}

void FibonacciSpinBox::stepBy(int steps)
{
    int index = kFibonacciValues.indexOf(nearestFibonacci(value()));
    index = qBound(0, index + steps, kFibonacciValues.size() - 1);
    setValue(kFibonacciValues.at(index));
}

QAbstractSpinBox::StepEnabled FibonacciSpinBox::stepEnabled() const
{
    StepEnabled flags;
    int index = kFibonacciValues.indexOf(nearestFibonacci(value()));
    if (index > 0)
        flags |= StepDownEnabled;
    if (index < kFibonacciValues.size() - 1)
        flags |= StepUpEnabled;
    return flags;
}

QValidator::State FibonacciSpinBox::validate(QString &text, int &pos) const
{
    Q_UNUSED(pos);
    if (text.isEmpty())
        return QValidator::Intermediate;

    bool ok = false;
    int val = text.toInt(&ok);
    if (!ok)
        return QValidator::Invalid;
    if (kFibonacciValues.contains(val))
        return QValidator::Acceptable;

    for (int fib : kFibonacciValues) {
        if (QString::number(fib).startsWith(text))
            return QValidator::Intermediate;
    }
    return QValidator::Invalid;
}

void FibonacciSpinBox::fixup(QString &text) const
{
    bool ok = false;
    int val = text.toInt(&ok);
    text = QString::number(nearestFibonacci(ok ? val : 0));
}
