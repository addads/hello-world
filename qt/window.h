#ifndef WINDOW_H
#define WINDOW_H

#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QProgressBar>
#include <QSlider>

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);

private:
    QPushButton *m_button;
    QPushButton *m_quit_button;
    bool m_clicked;
    QGraphicsSceneMouseEvent *m_event;

signals:

public slots:
    void mousePressEvent(QMouseEvent *event);
    void setColors();
    void hoverColor();

};

#endif // WINDOW_H
