#include "View.hpp"
#include <iostream>
#include "framework.hpp"
#include <string>


View::View() {

}

View::~View(){

}

void View::Actualise_Affichage(const std::vector<FlyingObject *>& gameObjects, Framework* framework){
    
    for (FlyingObject* object : gameObjects ) 
    {

        std::string objectType = object->GetTypeName();

        if (objectType == "Spaceship"){
            Spaceship* spaceship = dynamic_cast<Spaceship*>(object);
            framework->DrawShip(spaceship->getX(), spaceship->getY(), spaceship->getAngle(), 1.0,false);

        }
        else if (objectType == "Missile"){
            Missile* missile = dynamic_cast<Missile*>(object);
            framework->DrawMissile(object->getX(),object->getY());
        }
        else if (objectType == "Asteroid") {
            Asteroid* asteroid = dynamic_cast<Asteroid*>(object);
            framework->DrawAsteroid(object->getX(),object->getY(), object->getSize());
        }
    }

    framework->Update();

}

