#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP
#include <string>
#include "flyingObject.hpp"
#include <chrono>

class Spaceship : public FlyingObject  {
private :

    double m_angle;
    double m_Xspeed;
    double m_Yspeed;

    double m_shieldLevel;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_invincibleEndTime;


public:
    Spaceship(double x, double y, double size, double speed,double angle);
    
    double GetShieldLevel() const;
    void SetShieldLevel(double level);
    bool GetInvincible() const;
    void SetInvincibleFor(double duration);
    double GetAngle();
    void SpeedUp(double acceleration);
    void SpeedDown(double deceleration);
    void Rotate(double r_Angle);
    float getShieldLevel() const;
    bool isWarning() const;
    void move(double screenWidth, double screenHeight) override;

    std::string GetTypeName() const override {
        return "Spaceship";
    }
};

#endif
