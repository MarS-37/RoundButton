#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "demodialog.h"
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openDialog();
    void setLabelText(const QString &text);
    void setLineEditText(const QString &text);

private:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *button;
    DemoDialog *dialog;
};

#endif // MAINWINDOW_H
