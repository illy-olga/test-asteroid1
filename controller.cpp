#include "Controller.hpp"
#include "View.hpp"
#include "Model.hpp"
#include "framework.hpp"



Controller::Controller(int fps, int shipSize, int missileSize){
    framework = new Framework(fps, shipSize,missileSize);
    model = new Model(framework);
    view = new View();
}

Controller::~Controller(){
    delete model;
    delete view;
    delete framework;
}

void Controller::lauchGame(){
    while(true){
        int action = framework->GetInput();

        model->UpdateAction(action);
        model->UpdateData(framework);

        std::vector<FlyingObject*> gameObjects = model->getFlyingObjects();
        view->Actualise_Affichage(gameObjects, framework);



    }
}




