#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLCDNumber>
#include <QSlider>
#include <curl/curl.h>
#include <string>


class Mainwindow : public QWidget {
    Q_OBJECT
public:
    static Mainwindow *instance();

public slots:
    void changeWidth(int width);
private:
    static Mainwindow *s_instance;
    Mainwindow();
    QLCDNumber* m_lcd;
    QSlider* m_slider;
    QPushButton* m_pushbutton;
};
#endif
