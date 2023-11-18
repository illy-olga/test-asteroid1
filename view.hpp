#ifndef VIEW_H
#define VIEW_H

#include <vector>
#include "FlyingObject.hpp"
#include "Model.hpp"
#include "framework.hpp"

class View {
private:
    SDL_Texture* textureShip;
    SDL_Texture* textureAsteroid;
    SDL_Texture* textureMissile;

    //std::vector<Sprite> sprites;
public:
    View();
    ~View();
    void Actualise_Affichage( std::vector<FlyingObject *> flyingObjects, Framework* framework);
    
};

#endif
