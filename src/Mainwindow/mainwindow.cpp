#include "mainwindow.hpp"

Mainwindow *Mainwindow::instance() {
    if(!s_instance) {
        s_instance = new Mainwindow;
    }
    return s_instance;
}
Mainwindow *Mainwindow::s_instance = NULL;

Mainwindow::Mainwindow() : QWidget() {
    setFixedSize(300,150);

    m_pushbutton = new QPushButton("Bye bye", this);
    m_pushbutton->setCursor(Qt::PointingHandCursor);
    m_pushbutton->move(110,100);

    m_lcd = new QLCDNumber(this);
    m_lcd->setSegmentStyle(QLCDNumber::Flat);
    m_lcd->move(50, 20);

    m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setRange(200,600);
    m_slider->setGeometry(10, 60, 150, 20);

    QObject::connect(m_slider, SIGNAL(valueChanged(int)), this, SLOT(changeWidth(int)));
    QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_lcd, SLOT(display(int)));
    QObject::connect(m_pushbutton, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void Mainwindow::changeWidth(int width) {
    setFixedSize(width, 200);
}
