#include <iostream>
#include "missile.hpp"
#include <string>
#include <cmath>
#include "flyingObject.hpp"

using namespace std;

Missile::Missile(double x, double y, double size, double speed, double angle) 
: FlyingObject(x,y,size,speed,angle){

}

void Missile::move(double screenWidth, double screenHeight)
{

    setX(getX()+sin(getAngle() * M_PI/180)* getSpeed());
    setY(getY() - cos(getAngle() * M_PI/180)* getSpeed());

}






