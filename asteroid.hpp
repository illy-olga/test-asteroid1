#ifndef Asteroid_HPP
#define Asteroid_HPP
#include <iostream>
#include "FlyingObject.hpp"
#include <string>

using namespace std;

class Asteroid : public FlyingObject
{
private:
    double m_x;
    double m_y;
    double m_size;
    double m_xSpeed;
    double m_ySpeed;

public :
    Asteroid(double x, double y, double size, double speed, double angle);

    /*
    double getXSpeed();
    double getYSpeed();
    

    void setX(double x);
    void setY(double y);
    void setXSpeed(double xSpeed);
    void setYSpeed(double ySpeed);
    void setSize(double size);*/

    void move(double screenWidth, double screenHeight) override;

    //std::string GetTypeName() override;

    std::string GetTypeName() const override {
        return "Asteroid";
    }
    
        
};  

#endif














