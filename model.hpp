#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include "flyingObject.hpp"
#include "spaceship.hpp"
#include "asteroid.hpp"
#include "missile.hpp"
#include "framework.hpp"
#include <random>

class Model {
private:
    Spaceship* spaceship;
    Missile* missile;

    Asteroid* asteroid;
    std::vector<FlyingObject*> flyingObjects;
    std::uniform_int_distribution<int> angleDist;

    bool missileLaunched;

    static bool Collide(const FlyingObject& o1, const FlyingObject& o2);

    std::vector<Asteroid*> asteroids;

public:
    Model(Framework* framework);
    ~Model();

    void UpdateAction(int action);
    void UpdateData(Framework* framework);

    std::vector<FlyingObject *> getFlyingObjects() const;
    void moveShipLeft();
    void moveShipRight();
    void fireMissile();
    void update();
    std::vector<FlyingObject*> GetGameObjects() const;
    
    void setScreenSize(int screenWidth, int screenHeight);

    void FireMissile();

    bool CheckShipAsteroidCollision();
    bool CheckMissileAsteroidCollision();

    Spaceship* getSpaceship() const {
        return spaceship;
    }
    Missile* getMissile() const {
        return missile;
    }
    Asteroid* getAsteroid() const {
        return asteroid;
    }

    bool CheckMissileAsteroidCollision(Missile* missile, Asteroid* asteroid);
    bool CheckAsteroidSpaceshipCollision(Asteroid* asteroid, Spaceship* spaceship);

};

#endif




