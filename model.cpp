#include "Asteroid.hpp"
#include "missile.hpp"
#include "Spaceship.hpp"
#include <vector>
#include "Model.hpp"
#include "framework.hpp"
#include <string>
#include <random>


Model::Model(Framework* framework) : angleDist(-180,180) {

    flyingObjects.push_back(new Spaceship(framework->GetScreenWidth()/2,framework->GetScreenHeight()/2,20,0,0));
    flyingObjects.push_back(new Missile(200,200,500,10,80));

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> zoneDist(0,7);

    int nb_asteroids = 10;
    for (int i =0; i<nb_asteroids; i++){
        int selectedZone = zoneDist(gen);

        int minX, minY, maxX, maxY;



        switch (selectedZone) {
            case 0:
                minX = 0;
                minY = 0;
                maxX = framework->GetScreenWidth() /3;
                maxY= framework->GetScreenHeight() /3;
                break;

            case 1:
                minX = framework->GetScreenWidth() /3;
                minY = 0;
                maxX = 2 * (framework->GetScreenWidth() /3);
                maxY= framework->GetScreenHeight() /3;
                break;

            case 2:
                minX = 2 * (framework->GetScreenWidth() /3);
                minY = 0;
                maxX = framework->GetScreenWidth();
                maxY= framework->GetScreenHeight() /3;
                break;

            case 3:
                minX = 0;
                minY = framework->GetScreenHeight() /3;
                maxX = framework->GetScreenWidth() /3;
                maxY= 2 * (framework->GetScreenHeight() /3);
                break;

            case 4:
                minX = framework->GetScreenWidth() /3;
                minY = framework->GetScreenHeight() /3;
                maxX = 2 * (framework->GetScreenWidth() /3);
                maxY= 2 * (framework->GetScreenHeight() /3);
                break;

            case 5:
                minX = 2 * (framework->GetScreenWidth() /3);
                minY = framework->GetScreenHeight() /3;
                maxX = framework->GetScreenWidth() ;
                maxY= 2 * (framework->GetScreenHeight() /3);
                break;

            case 6:
                minX = 0;
                minY = 2 * (framework->GetScreenHeight() /3);
                maxX = framework->GetScreenWidth() /3;
                maxY= framework->GetScreenHeight();
                break;

            case 7:
                minX = framework->GetScreenWidth() / 3;
                minY = 2 * (framework->GetScreenHeight() / 3);
                maxX = 2 * (framework->GetScreenWidth() / 3);
                maxY = framework->GetScreenHeight();
                break;

            default:
                break;

        }

        std::uniform_real_distribution<double> coordDistX(minX,maxX);
        std::uniform_real_distribution<double> coordDistY(minY,maxY);

        std::uniform_real_distribution<double> randomSize(50,110);
        double random_size = randomSize(gen);

        double randomAngle = static_cast<double>(angleDist(gen));
        
        flyingObjects.push_back(new Asteroid(coordDistX(gen), coordDistY(gen), random_size,10, randomAngle));

    }

   



    //flyingObjects = std::vector<FlyingObject*>();
   

    //IniatialisationAsteroid();

}



Model::~Model(){
    delete spaceship;
    delete missile;
    //delete asteroid;

    for (auto object : flyingObjects) {
        delete object;
    }
}

void Model::UpdateAction(int action){
    switch (action){
        case SDLK_LEFT:
            spaceship->Rotate(-20);
            break;
        case SDLK_RIGHT :
            spaceship->Rotate(20);
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
        case SDLK_SPACE:
            FireMissile();
        break;   
    }
}




void Model::UpdateData(Framework * framework){
    for (FlyingObject* object : flyingObjects ) 
    {
       
        
        object->move(framework->GetScreenWidth(),framework->GetScreenHeight());

        if (object->GetTypeName() == "Missile" && object->getX() > framework->GetScreenWidth()) {
            missileLaunched = false;
            }

        

/*        if (CheckShipAsteroidCollision()) {
        // Gérer la collision (par exemple, détruire le vaisseau ou l'astéroïde)
            return -1;
        }
        if (CheckMissileAsteroidCollision()) {
        // Gérer la collision (par exemple, détruire le missile et l'astéroïde)
        }

        bool asteroidsRemaining = false;
        for (FlyingObject* object : flyingObjects) {
        if (object->GetTypeName() == "Asteroid") {
            asteroidsRemaining = true;
            break;
        }
    }
        if (!asteroidsRemaining) {
            return 1;
        }*/

        //return 0;
    }
}



void Model::FireMissile(){
    if (!missileLaunched) {

        double shipX = spaceship->getX();
        double shipY = spaceship->getY();
        double shipAngle = spaceship->getAngle();

        double missileSpeed = 10;
        double missileXSpeed = missileSpeed * sin(M_PI * shipAngle / 180.0);
        double missileYSpeed = -missileSpeed * cos(M_PI * shipAngle / 180.0);

        flyingObjects.push_back(new Missile(shipX,shipY,20,missileSpeed,shipAngle));

        missileLaunched = true;

        

       
       
        
    }

}


std::vector<FlyingObject*> Model::getFlyingObjects() const {
    return flyingObjects;    

}

void Model::moveShipLeft() {

}

void Model::moveShipRight() {

}



/*void Model::FireMissile(){
    if (!missileLaunched) {
        //if (missile == nullptr || missile->getX() > framework->GetScreenWidth()){
        double shipX = spaceship->getX();
        double shipY = spaceship->getY();
        double shipAngle = spaceship->getAngle();

        double missileSpeed = 10;
        double missileXSpeed = missileSpeed * sin(M_PI * shipAngle / 180.0);
        double missileYSpeed = -missileSpeed * cos(M_PI * shipAngle / 180.0);

        flyingObjects.push_back(new Missile(shipX,shipY,20,missileSpeed,shipAngle));

        missileLaunched = true;

        
    }

}*/

void Model::update() {

}

std::vector<FlyingObject*> Model::GetGameObjects() const {
    return flyingObjects;
}

bool Model::Collide(const FlyingObject& o1, const FlyingObject& o2) {
    double distance = sqrt(pow(o1.getX() - o2.getX(), 2) + pow(o1.getY() - o2.getY(), 2));
    double sumRadii = o1.getSize() + o2.getSize();

    if (distance < sumRadii)
    {
        return true;
    }
    else 
    {
        return false;
    }
}
