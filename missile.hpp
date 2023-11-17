#ifndef missile_HPP
#define missile_HPP
#include <iostream>
#include "FlyingObject.hpp"
#include <string>

using namespace std;

class Missile: public FlyingObject
{

public:
    Missile(double x, double y, double size, double speed, double angle);

    bool move(double screenWidth,double screenHeight);

    //void Update() override;

    std::string GetTypeName() const override {
        return "Missile";
    }

    //std::string GetTypeName() const override;

};

#endif
