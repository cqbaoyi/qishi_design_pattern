#include <iostream>
#include <string>

class Vehicle 
{
public: 
    virtual void startEngine() = 0;
    virtual void accelerate() = 0;
};

class gasolineCar : public Vehicle
{
public:
    void startEngine()
    {
        igniteEngine();
    }
    
    void accelerate()
    {
        pushGasPedal();
    }
    
    void igniteEngine()
    {
        std::cout << "Turn the key" << std::endl;
    }
    
    void pushGasPedal()
    {
        std::cout << "Push gas pedal smoothly" << std::endl;
    }
};

class electricCar : public Vehicle
{
public:
    void startEngine()
    {
        increaseVoltage();
    }
    
    void accelerate()
    {
        voiceControl();
    }
    
    void increaseVoltage()
    {
        std::cout << "Push button" << std::endl;
    }
    
    void voiceControl()
    {
        std::cout << "Say \"I want to accelerate\"" << std::endl;
    }
};

int main()
{
    gasolineCar c1;
    c1.startEngine();
    c1.accelerate();
    
    electricCar c2;
    c2.startEngine();
    c2.accelerate();
    
    return 0;
}
