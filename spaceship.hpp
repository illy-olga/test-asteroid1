#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP
#include <string>
#include "FlyingObject.hpp"

class Spaceship : public FlyingObject  {
private :

    double m_angle;
    double m_Xspeed;
    double m_Yspeed;

public:
    Spaceship(double x, double y, double size, double speed,double angle);
    
    double GetAngle();

    void SpeedUp(double acceleration);
    void SpeedDown(double deceleration);
    void Rotate(double r_Angle);

    //std::string GetTypeName() override;

    float getShieldLevel() const;
    bool isWarning() const;

    void move(double screenWidth, double screenHeight) override;

    std::string GetTypeName() const override {
        return "Spaceship";
    }



};




#endif
