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
                maxX = framework->GetScreenWidth() /3;
                maxY= 2 * (framework->GetScreenHeight() /3);
                break;

            case 6:
                minX = 0;
                minY = 2 * (framework->GetScreenHeight() /3);
                maxX = framework->GetScreenWidth() /3;
                maxY= framework->GetScreenHeight() /3;
                break;

            default:
                break;

        }

        std::uniform_real_distribution<double> coordDistX(minX,maxX);
        std::uniform_real_distribution<double> coordDistY(minY,maxY);

        std::uniform_real_distribution<double> randomSize(50,200);
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

















/*void Model::generateRandomAsteroidPosition(){
    std::default_random_engine generator(static_cast<unsigned>(time(0)));
    std::uniform_int_distribution<int> zoneDistribution(0,7);
    int selectedZone = zoneDistribution(generator);

    int minX, maxX,minY,maxY;
    switch(selectedZone) {
        case 0:
            minX = 0;
            maxX = framework->GetScreenWidth()/3;
            minY = 0;
            maxY = framework->GetScreenHeight()/2;
            break;

    
    }

    std::uniform_real_distribution<double> xDistribution(minX, maxX);
    std::uniform_real_distribution<double> yDistribution(minY, maxY);

    asteroid->setX(xDistribution(generator));
    asteroid->setY(yDistribution(generator));

double Model::generateRandomAngle() {
    std::default_random_engine generator(static_cast<unsigned>(time(0)));
    std::uniform_real_distribution<double> angleDistribution(-180.0, 180.0);
    return angleDistribution(generator);
} */








/*void Model::IniatialisationAsteroid() {
    std::mt19937 rng(std::random_device{}());

    std::uniform_int_distribution<int> zoneDistribution(0,7);
    int selectedZone = zoneDistribution(rng);



    int minX = (selectedZone % 3) * (framework->GetScreenWidth()/3);
    int maxX = minX + (framework->GetScreenWidth() / 3);
    int minY = (selectedZone / 3) * (framework->GetScreenHeight()/3);
    int maxY = minY + (framework->GetScreenHeight() / 3);
    
    std::uniform_real_distribution<double> xDistribution(minX,maxX);
    std::uniform_real_distribution<double> yDistribution(minY,maxY);

    double randomX = xDistribution(rng);
    double randomY = yDistribution(rng);
    
    asteroid->setX(randomX);
    asteroid->setY(randomY);

    std::uniform_real_distribution<double> angleDistribution(-180,180);
    double randomAngle = angleDistribution(rng);

    double xSpeed = asteroid->getSpeed() * sin(M_PI * randomAngle /180);
    double ySpeed = asteroid->getSpeed() * cos(M_PI * randomAngle /180);

    //Asteroid* asteroid = new Asteroid();
    asteroid->setSpeed(xSpeed);
    asteroid->setSpeed(ySpeed);

}*/


/*
void Model::CreateRandomAsteroid() {

    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());

    std::uniform_int_distribution<int> zoneDistribution(0,7);
    int selectedZone = zoneDistribution(generator);

    double minX, maxX, minY, maxY;

    std::uniform_real_distribution<double> coordDistributionX(minX,maxX);
    std::uniform_int_distribution<double> coordDistributionY(minY,maxY);

    double asteroidX = coordDistributionX(generator);
    double asteroidY = coordDistributionY(generator);


}*/


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
