#include "demodialog.h"
#include <QVBoxLayout>


DemoDialog::DemoDialog(QWidget *parent) : QDialog(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    edit = new QLineEdit(this);
    layout->addWidget(edit);

    // кнопка для обновления label на главном окне
    labelButton = new QPushButton("Label", this);

    connect(labelButton, &QPushButton::clicked, this, &DemoDialog::onLabelButtonClicked);
    layout->addWidget(labelButton);

    // кнопка для обновления lineEdit на главном окне
    lineEditButton = new QPushButton("LineEdit", this);

    connect(lineEditButton, &QPushButton::clicked, this, &DemoDialog::onLineEditButtonClicked);
    layout->addWidget(lineEditButton);

    // кнопка для закрытия окна
    closeButton = new QPushButton("Close", this);

    connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);
    layout->addWidget(closeButton);

    setLayout(layout);
    setWindowTitle("Demo Dialog");
}

DemoDialog::~DemoDialog()
{
}

void DemoDialog::onLabelButtonClicked()
{
    // передаем текст из QLineEdit в слот
    emit labelButtonClicked(edit->text());
}

void DemoDialog::onLineEditButtonClicked()
{
    // передаем текст из QLineEdit в слот
    emit lineEditButtonClicked(edit->text());
}
