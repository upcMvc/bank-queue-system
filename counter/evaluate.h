#ifndef EVALUATE_H
#define EVALUATE_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class evaluate;
}

class evaluate : public QDialog
{
    Q_OBJECT

public:
    explicit evaluate(QWidget *parent = 0);
    ~evaluate();
    QString value;
    QMessageBox thanks;



private slots:
    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

private:
    Ui::evaluate *ui;
};

#endif // EVALUATE_H
