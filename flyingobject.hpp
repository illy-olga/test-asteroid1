#ifndef ASTEROID_HPP
#define ASTEROID_HPP
#include <string>
#include "FlyingObject.hpp"

class FlyingObject {

private : 
    double m_x;
    double m_y;
    double m_size;
    double m_speed;
    double m_angle;

public :
    virtual ~FlyingObject() {}
    virtual std::string GetTypeName() const=0;

    FlyingObject(double x, double y, double size, double speed, double angle);

    virtual void move(double screenWidth, double screenHeight) = 0;

    double getX() const;
    double getY() const;
    void setY(double x);
    void setX(double y);
    void setAngle(double angle);
    void setSpeed(double speed);
    double getSpeed() const;
    double getSize() const;
    double getAngle() const;


    void setSpeedX(double speedX);
    void setSpeedY(double speedY);


    static bool Collide(const FlyingObject& o1, const FlyingObject& o2) ;

};

#endif
