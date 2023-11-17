#include "Spaceship.hpp"
#include <cmath>
#include <string>

Spaceship::Spaceship(double x, double y, double size, double speed, double angle) 
: FlyingObject(x,y,size,0,angle){

}

double Spaceship::GetAngle (){
    return m_angle;

}

void Spaceship::SpeedUp(double acceleration) {
    setSpeed(acceleration + getSpeed());
}

void Spaceship::SpeedDown(double deceleration) {
    setSpeed(getSpeed() - deceleration);

}

void Spaceship::Rotate(double r_Angle){
    setAngle(getAngle() + r_Angle);
}

float Spaceship::getShieldLevel() const {
    return 0;
}

bool Spaceship::isWarning() const {
    return false;

}

std::string Spaceship::GetTypeName() const {
    return "Spaceship";
}
