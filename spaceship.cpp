#include "spaceship.hpp"
#include <cmath>
#include <string>
#include <chrono>

Spaceship::Spaceship(double x, double y, double size, double speed, double angle) 
: FlyingObject(x,y,size,0,angle),m_angle(angle),m_Xspeed(0),m_Yspeed(0), m_shieldLevel(1.0){

}

double Spaceship::GetAngle (){
    return m_angle;

}

void Spaceship::SpeedUp(double acceleration) {
    m_Xspeed += acceleration * sin(M_PI * getAngle() /180);
    m_Yspeed -= acceleration * cos(M_PI * getAngle() /180);

}

void Spaceship::SpeedDown(double deceleration) {
    m_Xspeed -= deceleration * sin(M_PI * getAngle() /180);
    m_Yspeed += deceleration * cos(M_PI * getAngle() /180);

}

void Spaceship::Rotate(double r_Angle){
    setAngle(getAngle() + r_Angle);
}

bool Spaceship::isWarning() const {
    return false;

}

void Spaceship::move(double screenWidth, double screenHeight){
    if (getX()>screenWidth)
    {
        setX(0);
    }
    else if (getX()<0)
    {
        setX(screenWidth);
    }
    else if (getY()>screenHeight)
    {
        setY(0);
    }
    else if (getY()<0)
    {
        setY(screenHeight);
    }
    else {
    setX(getX()+m_Xspeed);
    setY(getY()+m_Yspeed);
    }
}

double Spaceship::GetShieldLevel() const {
    return m_shieldLevel;
}

void Spaceship::SetShieldLevel(double level) {
    m_shieldLevel = level;
}

bool Spaceship::GetInvincible() const {
    return std::chrono::high_resolution_clock::now() < m_invincibleEndTime;
}

void Spaceship::SetInvincibleFor(double duration) {
    m_invincibleEndTime = std::chrono::high_resolution_clock::now() + std::chrono::seconds(static_cast<long long>(duration));
}
