#ifndef COUNTER_H
#define COUNTER_H
#include "ui_counter.h"

#include <QDialog>
#include <QCloseEvent>
#include <QEvent>

namespace Ui {
class Counter;
}

class Counter : public QDialog
{
    Q_OBJECT

public:
    explicit Counter(QWidget *parent = 0);
    ~Counter();
    void closeEvent(QCloseEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Counter *ui;
};

#endif // COUNTER_H
