#include "Asteroid.hpp"
#include "missile.hpp"
#include "Spaceship.hpp"
#include <vector>
#include "Model.hpp"
#include "framework.hpp"
#include <string>

Model::Model(Framework* framework){
    spaceship = new Spaceship(framework->GetScreenWidth()/2,framework->GetScreenHeight()/2,20,0,0);
    missile = new Missile(0,0,5,3,30);
    asteroid = new Asteroid(100,100,50,10,15);
    flyingObjects = std::vector<FlyingObject*>();
    flyingObjects.push_back(spaceship);
    flyingObjects.push_back(asteroid);
    flyingObjects.push_back(missile);

}



Model::~Model(){
    delete spaceship;
    delete missile;
    delete asteroid;
}

void Model::UpdateAction(int action){
    switch (action){
        case SDLK_LEFT:
            spaceship->Rotate(-20);
            break;
        case SDLK_RIGHT :
            spaceship->Rotate(20);
            break;
        case SDLK_SPACE :
            fireMissile();
            break;
        case SDLK_UP:
            spaceship->SpeedUp(5);
            break;
        case SDLK_DOWN:
            spaceship->SpeedDown(5);
            break;        
        case SDLK_ESCAPE:
            exit(0);
            break;    
    }
}

void Model::UpdateData(Framework * framework){
    for (FlyingObject* object : flyingObjects ) 
    {
        object->move(framework->GetScreenWidth(),framework->GetScreenHeight());
    }
    

}

std::vector<FlyingObject*> Model::getFlyingObjects() const {
    return flyingObjects;    

}

void Model::moveShipLeft() {

}

void Model::moveShipRight() {

}

void Model::fireMissile(){

}

void Model::update() {

}

std::vector<FlyingObject*> Model::GetGameObjects() const {
    return flyingObjects;
}



/*Model model(screenWidth, screenHeight);

Spaceship* spaceship = model.getSpaceship();
Missile* missile = model.getMissile();
Asteroid* asteroid = model.getAsteroid();*/

/*void Model::MovementSpaceship_Gauche() {

    spaceship->Movement_Gauche();
}

void Model::MovementSpaceship_Droite() {

    spaceship->Movement_Droite();
}

void Model::Feu_missile(){

    if (!missile->Vol()) {
        missile->Launch(spaceship->getX(),spaceship->getY());

    }
}

void Model::UpdateJeu(){


}*/
