#include "flyingObject.hpp"
#include <cmath>

FlyingObject::FlyingObject(double x, double y, double size, double speed, double angle)
    : m_x(x),m_y(y), m_size(size),m_speed(speed),m_angle(angle) {}

double FlyingObject::getX() const {
    return m_x;
}

void FlyingObject::setX(double x) {
    m_x = x;
}

void FlyingObject::setY(double y) {
    m_y = y;
}

void FlyingObject::setSpeed(double speed) {
    m_speed = speed;
}

void FlyingObject::setAngle(double angle) {
    m_angle = angle;
}


double FlyingObject::getY() const {
    return m_y;
}
double FlyingObject::getSize() const {
    return m_size;
}
double FlyingObject::getSpeed() const {
    return m_speed;
}
double FlyingObject::getAngle() const {
    return m_angle;
}


static bool Collide(const FlyingObject& o1, const FlyingObject& o2);

bool FlyingObject::Collide( const FlyingObject& o1, const FlyingObject& o2) 

{
    double distance = sqrt(pow(o1.m_x -o2.m_x,2) + pow(o1.m_y - o2.m_y,2)) ;
    double sommerayons = o1.m_size + o2.m_size ;

    if (distance < sommerayons)
    {
        return true;
    }
    else 
    {
        return false;
    }

}




