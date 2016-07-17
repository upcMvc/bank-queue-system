#ifndef UI_H
#define UI_H

#include <QWidget>

namespace Ui {
class ui;
}

class ui : public QWidget
{
    Q_OBJECT

public:
    explicit ui(QWidget *parent = 0);
    ~ui();

private:
    Ui::ui *ui;
};

#endif // UI_H
