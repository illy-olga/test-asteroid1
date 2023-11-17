#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model.hpp"
#include "View.hpp"
#include "Framework.hpp"

class Controller {
private:
    Model* model ;
    View* view ;
    Framework* framework ; /*à réfléchir !! Attention mettre des pointeurs !*/

public:
    //Controller(Model m,View* v, Framework* f);
    Controller(int fps, int shipSize, int missileSize);
    ~Controller();
    Controller(Framework* fk);

    void lauchGame();
    //void updateView();

    void setScreenSize(int screenWidth, int screenHeight);

};

#endif
