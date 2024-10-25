#include "crossroadxtype.h"


CrossroadXType::CrossroadXType(){
    for (int i = 0; i < 8; ++i){
        if (i < 4){
            TrafficLightInfo initState;
            initState.state = TrafficLightState::Red;
            initState.id = i;
            ctls[i].initState(initState);
        }
        TrafficLightInfo initState;
        initState.state = TrafficLightState::Green;
        initState.id = i;
        ptls[i].initState(initState);
    }
};

void CrossroadXType::setPedestrianRed(int ix){
    ptls[ix].setState(TrafficLightState::Red);
};
void CrossroadXType::setPedestrianGreen(int ix){
    ptls[ix].setState(TrafficLightState::Green);
}

TrafficLightInfo CrossroadXType::ptlsInfo(int ix){
    TrafficLightInfo ptlInfo;
    ptlInfo.id = ptls[ix].getId();
    ptlInfo.queueCounter = ptls[ix].getCounter();
    ptlInfo.state = ptls[ix].getState();
    return ptlInfo;
};

TrafficLightInfo CrossroadXType::ctlsInfo(int ix){
    TrafficLightInfo ctlInfo;
    ctlInfo.id = ctls[ix].getId();
    ctlInfo.queueCounter = ctls[ix].getCounter();
    ctlInfo.state = ctls[ix].getState();
    return ctlInfo;
};


void CrossroadXType::setCarRed(int ix){
    if (ctls[ix].getState() == TrafficLightState::Yellow ||
        this->ctls[ix].getState() == TrafficLightState::Red){
        return;
    }
    ctls[ix].setState(TrafficLightState::Yellow);
    std::thread([this, ix]{
        std::this_thread::sleep_for(std::chrono::seconds(3));
        this->ctls[ix].setState(TrafficLightState::Red);
    }).detach();
};
void CrossroadXType::setCarGreen(int ix){
    ctls[ix].setState(TrafficLightState::Green);
};

void CrossroadXType::state1(){
    // 02_
    for (int i = 0; i < ptls.size(); ++i){
        this->setPedestrianRed(i);
    };
    if (ctls[1].getState() == TrafficLightState::Green){
        this->setCarRed(1);
    };
    if (ctls[3].getState() == TrafficLightState::Green){
        this->setCarRed(3);
    };

    std::thread([this]{
        std::this_thread::sleep_for(std::chrono::seconds(5));
        setCarGreen(0);
    }).detach();
    std::thread([this]{
        std::this_thread::sleep_for(std::chrono::seconds(5));
        setCarGreen(2);
    }).detach();
};

void CrossroadXType::state2(){
    // 13_
    for (int i = 0; i < ptls.size(); ++i){
        this->setPedestrianRed(i);
    };

    if (ctls[0].getState() == TrafficLightState::Green){
        setCarRed(0);
    };
    if (ctls[2].getState() == TrafficLightState::Green){
        setCarRed(2);
    };

    std::thread([this]{
        std::this_thread::sleep_for(std::chrono::seconds(5));
        setCarGreen(1);
    }).detach();
    std::thread([this]{
        std::this_thread::sleep_for(std::chrono::seconds(5));
        setCarGreen(3);
    }).detach();
};

void CrossroadXType::state3(){
    // 0_14
    std::thread([this]{
        this->setCarRed(1);
        this->setCarRed(2);
        this->setCarRed(3);
    }).detach();
    std::thread([this]{
        std::this_thread::sleep_for(std::chrono::seconds(5));
        this->setCarGreen(0);
        for (int i = 0; i < ptls.size(); ++i){
            if (i == 1 || i == 4){
                this->setPedestrianGreen(i);
            }
            else{
                this->setPedestrianRed(i);
            }
        };
    }).detach();


};

void CrossroadXType::state4(){
    // 1_36
    std::thread([this]{
        this->setCarRed(0);
        this->setCarRed(2);
        this->setCarRed(3);
    }).detach();
    std::thread([this]{
        std::this_thread::sleep_for(std::chrono::seconds(5));
        this->setCarGreen(1);
        for (int i = 0; i < ptls.size(); ++i){
            if (i == 3 || i == 6){
                this->setPedestrianGreen(i);
            }
            else{
                this->setPedestrianRed(i);
            }
        };
    }).detach();


};

void CrossroadXType::state5(){
    // 2_50
    std::thread([this]{
        this->setCarRed(0);
        this->setCarRed(1);
        this->setCarRed(3);
    }).detach();
    std::thread([this]{
        std::this_thread::sleep_for(std::chrono::seconds(5));
        this->setCarGreen(2);
        for (int i = 0; i < ptls.size(); ++i){
            if (i == 5 || i == 0){
                this->setPedestrianGreen(i);
            }
            else{
                this->setPedestrianRed(i);
            }
        };
    }).detach();


};

void CrossroadXType::state6(){
    // 3_72
    std::thread([this]{
        this->setCarRed(0);
        this->setCarRed(1);
        this->setCarRed(2);
    }).detach();
    std::thread([this]{
        std::this_thread::sleep_for(std::chrono::seconds(5));
        this->setCarGreen(3);
        for (int i = 0; i < ptls.size(); ++i){
            if (i == 7 || i == 2){
                this->setPedestrianGreen(i);
            }
            else{
                this->setPedestrianRed(i);
            }
        };
    }).detach();


};

void CrossroadXType::state7(){
    // _01234567
    std::thread([this]{
        this->setCarRed(0);
        this->setCarRed(1);
        this->setCarRed(2);
        this->setCarRed(3);
        std::this_thread::sleep_for(std::chrono::seconds(5));
        for (int i = 0; i < ptls.size(); ++i){
            this->setPedestrianGreen(i);
        };
    }).detach();
};

int CrossroadXType::nextState(){
    int ns = 0;

    int maxCsIndex = 0;
    int maxCs = 0;
    int maxPsIndex = 0;
    int maxPs = 0;
    for (int i = 0; i < std::max(this->Ps.size(), this->Cs.size()); ++i){
        if (i < this->Cs.size()){
            if (maxCs < this->Cs[i].size()){
                maxCs = this->Cs[i].size();
                maxCsIndex = i;
            }
        }
        if (i < this->Ps.size()){
            if (maxPs < this->Ps[i].size()){
                maxPs = this->Ps[i].size();
                maxPsIndex = i;
            }
        }
    }


    if (maxCs <= 3) {
        ns = 7;
        return ns;
    }
    if ((maxCsIndex == 0 || maxCsIndex == 2) && maxPs <= 4){
        ns = 1;
        return ns;
    }
    if ((maxCsIndex == 1 || maxCsIndex == 3) && maxPs <= 4){
        ns = 2;
        return ns;
    }

    if (maxCsIndex == 0 && (maxPsIndex == 1 || maxPsIndex == 4)){
        ns = 3;
        return ns;
    }
    if (maxCsIndex == 1 && (maxPsIndex == 3 || maxPsIndex == 6)){
        ns = 4;
        return ns;
    }
    if (maxCsIndex == 2 && (maxPsIndex == 5 || maxPsIndex == 0)){
        ns = 5;
        return ns;
    }
    if (maxCsIndex == 3 && (maxPsIndex == 7 || maxPsIndex == 2)){
        ns = 6;
        return ns;
    }
    ns = 7;
    return ns;
}

void CrossroadXType::incCsPs(){
    srand(time(0));
    // Случайное добавление авто
    // Случайное добавление пешеходов
    for (int i = 0; i < std::max(this->Cs.size(), this->Ps.size()); ++i){
        if (i < this->Cs.size()){
            if (rand() % 100 < 21) {
                this->Cs[i].push(Car());
                this->ctls[i].setCounter(Cs[i].size());
            }
        }
        if (i < this->Ps.size()){
            if (rand() % 100 < 21) {
                this->Ps[i].push(Pedestrian());
                this->ptls[i].setCounter(Ps[i].size());
            }
        }
    }
};

// Имитация поведения авто на перекрестке
void CrossroadXType::decCs(){
    for (int i = 0; i < Cs.size(); ++i){
        if (ctls[i].getState() == TrafficLightState::Green && !Cs[i].empty()){
                Cs[i].pop();
                ctls[i].setCounter(Cs[i].size());
        }
        else if (ctls[i].getState() == TrafficLightState::Yellow && !Cs[i].empty()){
           if (rand() % 2 == 0){
               Cs[i].pop();
               ctls[i].setCounter(Cs[i].size());
           }
        }
    }
};

void CrossroadXType::decPs(){
    for (int i = 0; i < Ps.size(); ++i){
        if (ptls[i].getState() == TrafficLightState::Green && !Ps[i].empty()){
            Ps[i].pop();
            ptls[i].setCounter(Ps[i].size());
        }
    }
};

void CrossroadXType::controlTraffic(){
    std::thread([this](){
        while (true){
            this->incCsPs();
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }).detach();

    std::thread([this](){
        while (true){
            this->decPs();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }).detach();

    std::thread([this](){
        while (true){
            this->decCs();
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }).detach();

    std::thread([this](){
        int csPass = 0;
        while (true) {

            int ns = nextState();
            // Чтобы 1-2 машины не ждали более 30 секунд
            if (csPass>=2){
                int maxQueue = 0;
                int maxQueueIndex = 0;
                for (int i = 0; i < Cs.size(); ++i){
                    if (Cs[i].size() > maxQueue){
                        maxQueue = Cs[i].size();
                        maxQueueIndex = i;
                    }
                }
                if (maxQueueIndex == 0 || maxQueueIndex == 2){
                    ns = 1;
                }
                if (maxQueueIndex == 1 || maxQueueIndex == 3){
                    ns = 2;
                }
                csPass = 0;
            }
            switch(ns){
                case 1:
                    this->state1();
                    break;
                case 2:
                    this->state2();
                    break;
                case 3:
                    this->state3();
                    break;
                case 4:
                    this->state4();
                    break;
                case 5:
                    this->state5();
                    break;
                case 6:
                    this->state6();
                    break;
                case 7:
                    this->state7();
                    break;
                default:
                    break;;
            }

            std::this_thread::sleep_for(std::chrono::seconds(15));
            csPass++;
        }
    }).detach();

};
