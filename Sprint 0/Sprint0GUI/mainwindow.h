#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class QLabel;
class QCheckBox;
class QRadioButton;
class QFrame;
class QLineEdit;

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    QLabel* label;
    QFrame* line1;
    QFrame* line2;
    QCheckBox* checkBox1;
    QCheckBox* checkBox2;
    QRadioButton* radioS;
    QRadioButton* radioO;
};

#endif // MAINWINDOW_H
