#ifndef ITRAFFICLIGHT_H
#define ITRAFFICLIGHT_H

#include <cstdint>


struct coords{
    double x;
    double y;
};

// Возможные состояния светофора
enum class TrafficLightState{
    Red,
    Yellow,
    Green
};

// Структура-контейнер, хранящая основную информацию светофора
struct TrafficLightInfo {
    uint8_t id;
    TrafficLightState state;
    unsigned int queueCounter;
};

// Интерфейс светофора
class ITrafficLight
{
public:
    ITrafficLight();
    // Метод устанавливает id из внешнего контроллера
    virtual void setId (const uint8_t newId) = 0;
    // Получить id
    virtual uint8_t getId () const = 0;
    // Смена состояния по определенным правилам
    virtual void setState (TrafficLightState newState) = 0;
    // Получить текущее состояние
    virtual TrafficLightState getState () const = 0;
    // Очередь светофора
    virtual unsigned int getCounter () const = 0;
    // Задать размер очереди
    virtual void setCounter (int queueSize) = 0;
    // Спросить другой светофор о его состоянии
    virtual TrafficLightInfo askOther (const ITrafficLight& other) const = 0;

    virtual ~ITrafficLight() = default;
};

#endif // ITRAFFICLIGHT_H
