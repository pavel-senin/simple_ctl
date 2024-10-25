#include "crossroad.h"
#include "./ui_crossroad.h"

Crossroad::Crossroad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Crossroad)
    , CrX()
{
    ui->setupUi(this);

    // Создание и настройка таймера
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Crossroad::updateTrafficLight);
    timer->start(500);
    std::thread trafficThread([this]() {
        CrX.controlTraffic();
    });

    trafficThread.detach();
}

Crossroad::~Crossroad()
{
    delete ui;
}

void Crossroad::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);  // Сглаживание линий для красоты

    int radiusC = 30;  // Радиус автосветофора
    int radiusP = 15;  // Радиус пешеходного светофора

    std::array<QPoint, 4> ctlsPositions = {
        QPoint(600, 600),
        QPoint(500, 500),
        QPoint(600, 400),
        QPoint(700, 500)
    };

    std::array<QPoint, 8> ptlsPositions = {
        QPoint(450, 650),
        QPoint(800, 650),
        QPoint(450, 375),
        QPoint(450, 700),
        QPoint(750, 375),
        QPoint(400, 375),
        QPoint(750, 650),
        QPoint(750, 325)
    };

    // Цикл по светофорам для их отрисовки и раскраски
    for (size_t i = 0; i < std::max(CrX.ctlsSize(), CrX.ptlsSize()); ++i) {
        QColor color;
        if (i < CrX.ctlsSize()){
            if (CrX.ctlsInfo(i).state == TrafficLightState::Green){
                color = Qt::green;
            }
            else if (CrX.ctlsInfo(i).state == TrafficLightState::Yellow){
                color = Qt::yellow;
            }
            else{
                color = Qt::red;
            }
            painter.setBrush(color);
            painter.drawEllipse(ctlsPositions[i], radiusC, radiusC);
        }
        if (i < CrX.ptlsSize()){
            if (CrX.ptlsInfo(i).state == TrafficLightState::Green){
                color = Qt::green;
            }
            else{
                color = Qt::red;
            }
            painter.setBrush(color);
            painter.drawEllipse(ptlsPositions[i], radiusP, radiusP);
        }
    }
    // Отображение счетчика авто
    this->ui->from0Cs->display(static_cast<int>(CrX.ctlsInfo(0).queueCounter));
    this->ui->from3Cs->display(static_cast<int>(CrX.ctlsInfo(1).queueCounter));
    this->ui->from6Cs->display(static_cast<int>(CrX.ctlsInfo(2).queueCounter));
    this->ui->from9Cs->display(static_cast<int>(CrX.ctlsInfo(3).queueCounter));
    // Отображение счетчика пешеходов
    this->ui->fromLeft0Ps->display(static_cast<int>(CrX.ptlsInfo(0).queueCounter));
    this->ui->fromRight0Ps->display(static_cast<int>(CrX.ptlsInfo(1).queueCounter));
    this->ui->fromUp3Ps->display(static_cast<int>(CrX.ptlsInfo(2).queueCounter));
    this->ui->fromDown3Ps->display(static_cast<int>(CrX.ptlsInfo(3).queueCounter));
    this->ui->fromRight6Ps->display(static_cast<int>(CrX.ptlsInfo(4).queueCounter));
    this->ui->fromLeft6Ps->display(static_cast<int>(CrX.ptlsInfo(5).queueCounter));
    this->ui->fromDown9Ps->display(static_cast<int>(CrX.ptlsInfo(6).queueCounter));
    this->ui->fromUp9Ps->display(static_cast<int>(CrX.ptlsInfo(7).queueCounter));
};
