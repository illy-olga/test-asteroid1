#ifndef MISSILE_HPP
#define MISSILE_HPP
#include <iostream>
#include "flyingObject.hpp"
#include <string>

using namespace std;

class Missile: public FlyingObject
{

public:
    Missile(double x, double y, double size, double speed, double angle);

    void move(double screenWidth,double screenHeight) override;

    std::string GetTypeName() const override {
        return "Missile";
    }
};

#endif
