#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.hpp"
#include "view.hpp"
#include "framework.hpp"

class Controller {
private:
    Model* model ;
    View* view ;
    Framework* framework ; /*à réfléchir !! Attention mettre des pointeurs !*/

public:
    
    Controller(int fps, int shipSize, int missileSize);
    ~Controller();
    Controller(Framework* fk);

    void lauchGame();

    void setScreenSize(int screenWidth, int screenHeight);

};

#endif
