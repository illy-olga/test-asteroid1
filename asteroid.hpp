#ifndef Asteroid_HPP
#define Asteroid_HPP
#include <iostream>
#include "flyingObject.hpp"
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
    double nbExplosionsLeft;

public :
    Asteroid(double x, double y, double size, double speed, double angle);
    Asteroid* Explode(double xSpeed, double ySpeed);
    double GetExplosionsLeft() const;
    
    void move(double screenWidth, double screenHeight) override;

    std::string GetTypeName() const override {
        return "Asteroid";
    }
    
        
};  

#endif





















