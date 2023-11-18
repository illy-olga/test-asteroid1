#ifndef MISSILE_HPP
#define MISSILE_HPP
#include <iostream>
#include "FlyingObject.hpp"
#include <string>

using namespace std;

class Missile: public FlyingObject
{

public:
    Missile(double x, double y, double size, double speed, double angle);

    void move(double screenWidth,double screenHeight) override;

    //void Update() override;

    //std::string GetTypeName() override;
    std::string GetTypeName() const override {
        return "Missile";
    }
    //std::string GetTypeName() const;

    //std::string GetTypeName() const override;

};

#endif
