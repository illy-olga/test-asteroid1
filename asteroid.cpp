#include <iostream>
#include "Asteroid.hpp"
#include <string>

using namespace std;

Asteroid::Asteroid(double x, double y, double size, double speed, double angle) 
: FlyingObject(x,y,size,speed,angle){


}

void Asteroid::move(double screenWidth, double screenHeight){

    if (m_x>screenWidth)
    {
        m_x = 0;
    }
    else if (m_x<0)
    {
        m_x = screenWidth;
    }
    else if (m_y>screenHeight)
    {
        m_y = 0;
    }
    else if (m_y<0)
    {
        m_y = screenHeight;
    }
    else {
        m_x = m_x + m_xSpeed;
        m_y = m_y + m_ySpeed;
    }
}
