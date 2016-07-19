#ifndef CLOSE_H
#define CLOSE_H

#include <QDialog>

namespace Ui {
class Close;
}

class Close : public QDialog
{
    Q_OBJECT

public:
    explicit Close(QWidget *parent = 0);
    ~Close();
    int flag;

private slots:
    void on_pushButton_clicked();

private:
    Ui::Close *ui;
};

#endif // CLOSE_H
