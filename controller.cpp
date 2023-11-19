#include "controller.hpp"
#include "view.hpp"
#include "model.hpp"
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

        /*int gameResult = model->UpdateData(framework);

        if (gameResult == 1) {
            std::cout << "Victoire ! Tous les astéroïdes ont été détruits." << std::endl;
            break;
        } else if (gameResult == -1) {
            std::cout << "Défaite ! Collision avec le vaisseau ayant son bouclier à 0." << std::endl;
            break;
        }*/

        model->UpdateData(framework);
        std::vector<FlyingObject*> gameObjects = model->getFlyingObjects();
        view->Actualise_Affichage(gameObjects, framework);
        
    }
}





