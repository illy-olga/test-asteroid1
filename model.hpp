#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "FlyingObject.hpp"
#include "Spaceship.hpp"
#include "Asteroid.hpp"
#include "missile.hpp"
#include "framework.hpp"

class Model {
private:
    Spaceship* spaceship;
    Missile* missile;
    Asteroid* asteroid;
    std::vector<FlyingObject*> flyingObjects;
public:
    Model(Framework* framework);
    ~Model();

    void UpdateAction(int action);
    
    void UpdateData(Framework* framework);
    std::vector<FlyingObject *> getFlyingObjects() const;
    std::vector<FlyingObject*> GetGameObjects() const;
    
    void setScreenSize(int screenWidth, int screenHeight);

    //Spaceship& getSpaceship() const { return *spaceship;}
    void moveShipLeft();
    void moveShipRight();
    void fireMissile();
    void update();

    Spaceship* getSpaceship() const {
        return spaceship;
    }
    Missile* getMissile() const {
        return missile;
    }
    Asteroid* getAsteroid() const {
        return asteroid;
    }
    
};

#endif

