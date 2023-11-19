#include <iostream>
#include "asteroid.hpp"
#include <string>
#include <cmath>

using namespace std;

Asteroid::Asteroid(double x, double y, double size, double speed, double angle) 
: FlyingObject(x,y,size,speed,angle){

}


void Asteroid::move(double screenWidth, double screenHeight){
    m_xSpeed = getSpeed() * sin(M_PI * getAngle() /180);
    m_ySpeed = getSpeed() * cos(M_PI * getAngle() /180);

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
    setX(getX()+m_xSpeed);
    setY(getY()+m_ySpeed);
    }
}

double Asteroid::GetExplosionsLeft() const {
    return nbExplosionsLeft;
    }

Asteroid* Asteroid::Explode(double xSpeed, double ySpeed) {
    if (nbExplosionsLeft > 0) {
        
        double newSize = getSize() * 0.5;

        Asteroid* newAsteroid = new Asteroid(getX(), getY(), newSize, 10, 45); 

        newAsteroid->nbExplosionsLeft = nbExplosionsLeft - 1;

        return newAsteroid;
    }

    return nullptr; 
}
