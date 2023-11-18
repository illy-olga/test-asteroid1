#include <iostream>
#include "missile.hpp"
#include <string>
#include <cmath>
#include "FlyingObject.hpp"

using namespace std;

/*FlyingObjet::Missile(double x, double y, double size, double speed, double angle){
    
}*/

Missile::Missile(double x, double y, double size, double speed, double angle) 
: FlyingObject(x,y,size,speed,angle){


}

void Missile::move(double screenWidth, double screenHeight)
{

    setX(getX()+sin(getAngle() * M_PI/180)* getSpeed());
    setY(getY() - cos(getAngle() * M_PI/180)* getSpeed());

}



/*std::string Missile::GetTypeName() {
    return "Missile";
}*/

// bool move(double screenWidth, double screenHeight);

//void Missile::Update(){}




