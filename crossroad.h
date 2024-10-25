#ifndef CROSSROAD_H
#define CROSSROAD_H

#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QColor>
#include <QTimer>
#include <QLCDNumber>
#include <array>
#include "crossroadxtype.h"
#include <thread>
#include <chrono>

QT_BEGIN_NAMESPACE
namespace Ui {
class Crossroad;
}
QT_END_NAMESPACE

class Crossroad : public QMainWindow
{
public:
    Crossroad(QWidget *parent = nullptr);
    ~Crossroad();

private:
    Q_OBJECT

    Ui::Crossroad *ui;
    QTimer* timer;

    CrossroadXType CrX;

    void paintEvent(QPaintEvent *event) override;

public slots:
    // Метод для обновления состояния интерфейса
    void updateTrafficLight() {
        update();
    };

};
#endif // CROSSROAD_H
