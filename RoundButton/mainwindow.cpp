#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), dialog(new DemoDialog(this))
{
    QWidget *centralWidget = new QWidget(this);

    // основной вертикальный лейаут
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // горизонтальный лейаут для кнопки в правом верхнем углу
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    // кнопка "OD"
    button = new QPushButton("OD", this);
    button->setFixedSize(50, 50);    // устанавливаем фиксированный размер кнопки
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

    // добавляем кнопку в правый верхний угол
    buttonLayout->addStretch();  // добавляем растяжение перед кнопкой, чтобы выровнять её вправо
    buttonLayout->addWidget(button, 0, Qt::AlignRight);

    // добавляем горизонтальный лейаут с кнопкой в основной лейаут
    mainLayout->addLayout(buttonLayout);

    // остальные элементы интерфейса
    label = new QLabel("Label", this);
    mainLayout->addWidget(label);

    lineEdit = new QLineEdit(this);
    mainLayout->addWidget(lineEdit);

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
