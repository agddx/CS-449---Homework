#include "MainWindow.h"
#include <QLabel>
#include <QCheckBox>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QFrame>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    // Create label
    label = new QLabel("Choose which letter to place", this);

    // Create horizontal line
    line1 = new QFrame(this);
    line1->setFrameShape(QFrame::HLine);
    line1->setFrameShadow(QFrame::Sunken);

    // Create checkbox
    checkBox1 = new QCheckBox("Human", this);
    checkBox2 = new QCheckBox("Computer", this);


    line2 = new QFrame(this);
    line2->setFrameShape(QFrame::HLine);
    line2->setFrameShadow(QFrame::Sunken);

    // Create radio buttons
    radioS = new QRadioButton("S", this);
    radioO = new QRadioButton("O", this);

    // Layout
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(label);
    layout->addWidget(line1);
    layout->addWidget(checkBox1);
    layout->addWidget(checkBox2);
    layout->addWidget(line2);
    layout->addWidget(radioS);
    layout->addWidget(radioO);

    setLayout(layout);
    setWindowTitle("Sprint 0 test");
    resize(250, 150);
}
