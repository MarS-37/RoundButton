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

    button = new QPushButton("Open Dialog", this);
    layout->addWidget(button);

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
    // открываем модальное окно
    dialog->exec();
}

void MainWindow::setLabelText(const QString &text)
{
    label->setText(text);
}

void MainWindow::setLineEditText(const QString &text)
{
    lineEdit->setText(text);
}
