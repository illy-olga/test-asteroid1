#include "asteroid.hpp"
#include "missile.hpp"
#include "spaceship.hpp"
#include <vector>
#include "model.hpp"
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
        
        vector<FlyingObject *> v(asteroids.begin(), asteroids.end());
        
        flyingObjects.push_back(new Asteroid(coordDistX(gen), coordDistY(gen), random_size,2, randomAngle));

    }

}

std::vector<FlyingObject*> Model::getFlyingObjects() const {
    std::vector<FlyingObject*> allObjects(flyingObjects.begin(), flyingObjects.end());
    allObjects.insert(allObjects.end(), asteroids.begin(), asteroids.end());
    return allObjects;
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

void Model::UpdateData(Framework* framework){
    for (FlyingObject* object : flyingObjects ) 
    {
       
        
        object->move(framework->GetScreenWidth(),framework->GetScreenHeight());

       if (object->GetTypeName() == "Missile" && object->getX() > framework->GetScreenWidth()) {
            missileLaunched = false;
            }


        if (object->GetTypeName() == "Asteroid" && Spaceship::Collide(*spaceship, *object)) {
            
            if (!spaceship->GetInvincible()) {
                
                spaceship->SetShieldLevel(spaceship->GetShieldLevel() - 0.1);
                spaceship->SetInvincibleFor(2.0); 
            }
        }

        if (Spaceship* spaceship = dynamic_cast<Spaceship*>(object)) {
        if (!spaceship->GetInvincible() && Collide(*spaceship, *asteroid)) {
            spaceship->SetShieldLevel(spaceship->GetShieldLevel() - 0.1); 
            spaceship->SetInvincibleFor(3.0); 

            if (spaceship->GetShieldLevel() <= 0.0) {
                
            }


            for (Asteroid* asteroid : asteroids) {
            
            if (Spaceship* spaceship = dynamic_cast<Spaceship*>(object)) {
                if (!spaceship->GetInvincible() && Collide(*spaceship, *asteroid)) {
                    spaceship->SetShieldLevel(spaceship->GetShieldLevel() - 0.1);
                    spaceship->SetInvincibleFor(3.0);

                    if (spaceship->GetShieldLevel() <= 0.0) {
                        
                    }
                }
            }

            
            if (Missile* missile = dynamic_cast<Missile*>(object)) {
                if (Collide(*missile, *asteroid)) {
                    
                }
            }
        }
        
    for (auto it = flyingObjects.begin(); it != flyingObjects.end(); ) {
        FlyingObject* object = *it;

        for (auto asteroidIt = asteroids.begin(); asteroidIt != asteroids.end(); ) {
            Asteroid* asteroid = *asteroidIt;

            if (Missile* missile = dynamic_cast<Missile*>(object)) {

                if (Collide(*missile, *asteroid)) {
                  
                    Asteroid* newAsteroid = asteroid->Explode(missile->getSpeed() * sin(M_PI * missile->getAngle() / 180.0),
                                           -missile->getSpeed() * cos(M_PI * missile->getAngle() / 180.0));

                    if (newAsteroid != nullptr) {
                        
                        flyingObjects.push_back(newAsteroid);
                    }

                    
                    if (asteroid->GetExplosionsLeft() <= 0) {
                        delete asteroid;
                        asteroidIt = asteroids.erase(asteroidIt);
                        continue; 
                    }
                }
            }

            ++asteroidIt;
        }

        ++it;
                }
            }
        }
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

void Model::moveShipLeft() {

}

void Model::moveShipRight() {

}

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

