#include "view.hpp"
#include <iostream>
#include "framework.hpp"
#include <string>

View::View() {

}

View::~View(){

}

void View::Actualise_Affichage( std::vector<FlyingObject *> flyingObjects, Framework* framework){
    
    for (FlyingObject* object : flyingObjects ) 
    {

        std::string objectType = object->GetTypeName();

        if (objectType == "Spaceship"){
            double shieldLevel = dynamic_cast<Spaceship*>(object)->GetShieldLevel();
            bool isWarning = dynamic_cast<Spaceship*>(object)->GetInvincible();

            framework->DrawShip(object->getX(), object->getY(), object->getAngle(), shieldLevel, isWarning);
                }
        else if (objectType == "Missile"){
           
            framework->DrawMissile(object->getX(),object->getY());
        }
        else if (objectType == "Asteroid") {
         
            framework->DrawAsteroid(object->getX(),object->getY(), object->getSize());
        }
    }

    framework->Update();

}



