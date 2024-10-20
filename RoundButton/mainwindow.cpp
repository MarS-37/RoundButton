#include "mainwindow.h"
#include <QVBoxLayout>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), dialog(new DemoDialog(this))
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    label = new QLabel("Label", this);
    layout->addWidget(label);

    lineEdit = new QLineEdit(this);
    layout->addWidget(lineEdit);

    // кнопка "OD"
    button = new QPushButton("OD", this);

    // делаем кнопку круглой с помощью QSS
    // устанавливаем фиксированный размер кнопки
    button->setFixedSize(50, 50);
    button->setStyleSheet(
        "QPushButton {"
        "  border-radius: 25px;"     // радиус равен половине ширины/высоты для круглой формы
        "  border: 2px solid #555;"
        "  background-color: #ddd;"
        "  font-size: 16px;"
        "}"
        "QPushButton:pressed {"
        "  background-color: #aaa;"  // изменение фона при нажатии
        "}"
        );

    // центрируем кнопку
    layout->addWidget(button, 0, Qt::AlignCenter);

    connect(button, &QPushButton::clicked, this, &MainWindow::openDialog);

    setCentralWidget(centralWidget);
    setWindowTitle("Main Window");

    // связываем сигналы из диалога с слотами для обновления компонентов
    connect(dialog, &DemoDialog::labelButtonClicked, this, &MainWindow::setLabelText);
    connect(dialog, &DemoDialog::lineEditButtonClicked, this, &MainWindow::setLineEditText);
}

MainWindow::~MainWindow() {}

void MainWindow::openDialog()
{
    dialog->exec();  // открываем модальное окно
}

void MainWindow::setLabelText(const QString &text)
{
    label->setText(text);
}

void MainWindow::setLineEditText(const QString &text)
{
    lineEdit->setText(text);
}
