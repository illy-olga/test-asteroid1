#include <iostream>
#include "missile.hpp"
#include <string>

using namespace std;

/*FlyingObjet::Missile(double x, double y, double size, double speed, double angle){
    
}*/

Missile::Missile(double x, double y, double size, double speed, double angle) 
: FlyingObject(x,y,size,speed,angle){


}

bool Missile::move(double screenWidth, double screenHeight)
{
    return false;
}



/*std::string Missile::GetTypeName() const{
    return "Missile";
}*/

// bool move(double screenWidth, double screenHeight);

//void Missile::Update(){}


