#ifndef CROSSROADXTYPE_H
#define CROSSROADXTYPE_H


#include <array>
#include <queue>
#include <ctime>
#include <QTimer>
#include <thread>
#include <chrono>
#include "icrossroad.h"
#include "pedestriantrafficlight.h"
#include "cartrafficlight.h"
#include "car.h"
#include "pedestrian.h"


// Описание конфигурации перекрестка, приведенной в задаче
class CrossroadXType : public ICrossroad
{




    // Пешеходные светофоры указывают, откуда пешеход соверешает переход
    // (против часовой стрелки, 0 - север)
    // PedestrianTrafficLight fromLeft0;
    // PedestrianTrafficLight fromRight0;
    // ...
    // PedestrianTrafficLight fromDown9;
    // PedestrianTrafficLight fromUp9;
    std::array<PedestrianTrafficLight, 8> ptls;

    // Автомобильные светофоры показывают, с какой стороны автомобиль
    // ждет своей очереди проехать через перекресток
    // CarTrafficLight from0, from3, from6, from9;
    std::array<CarTrafficLight, 4> ctls;

    // Контейнеры с пешеходами и машинами
    std::array<std::queue<Car>, 4> Cs;
    // В соответствии с картинкой
    std::array<std::queue<Pedestrian>, 8> Ps;
    // 7 возможных состояний светофоров на перекрестке
    void state1();

    void state2();

    void state3();

    void state4();

    void state5();

    void state6();

    void state7();

    int nextState();

    // Увеличить/уменьшить размер очереди
    void incCsPs();
    void decCs();
    void decPs();

public:

    CrossroadXType();

    int ctlsSize() noexcept {return ctls.size();};
    int ptlsSize() noexcept {return ptls.size();};

    // Получить tlInfo
    TrafficLightInfo ptlsInfo(int ix);
    TrafficLightInfo ctlsInfo(int ix);

    // Состояния пешеходных светофоров
    void setPedestrianRed(int ix);
    void setPedestrianGreen(int ix);

    // Состояния автосветофоров
    void setCarRed(int ix);
    void setCarGreen(int ix);





    // Управление траффиком
    void controlTraffic();
};

#endif // CROSSROADXTYPE_H
