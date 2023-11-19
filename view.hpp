#ifndef VIEW_H
#define VIEW_H
#include <vector>
#include "flyingObject.hpp"
#include "model.hpp"
#include "framework.hpp"

class View {
private:
    SDL_Texture* textureShip;
    SDL_Texture* textureAsteroid;
    SDL_Texture* textureMissile;

public:
    View();
    ~View();
    void Actualise_Affichage( std::vector<FlyingObject *> flyingObjects, Framework* framework);
    
};

#endif
