#include "ui.h"
#include "ui_ui.h"

ui::ui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui)
{
    ui->setupUi(this);
}

ui::~ui()
{
    delete ui;
}
