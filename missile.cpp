#include <iostream>
#include "missile.hpp"
#include <string>

using namespace std;

/*FlyingObjet::Missile(double x, double y, double size, double speed, double angle){
    
}*/

Missile::Missile(double x, double y, double size, double speed, double angle) 
: FlyingObject(x,y,size,speed,angle){


}

void Missile::move(double screenWidth, double screenHeight)
{
    return;
}



/*std::string Missile::GetTypeName() const{
    return "Missile";
}*/

// bool move(double screenWidth, double screenHeight);

//void Missile::Update(){}




