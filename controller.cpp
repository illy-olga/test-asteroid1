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

        /*if (!model->IsMissileLaunched()) {
            model->FireMissile();
        }*/
        //int updateResult = model->UpdateData(framework);
        model->UpdateData(framework);
        std::vector<FlyingObject*> gameObjects = model->getFlyingObjects();
        view->Actualise_Affichage(gameObjects, framework);
        
        //model->ResetMissileStatus();
        
        /*if (updateResult == 1) {
            std::cout << "Vous avez gagné ! Le jeu est terminé." << std::endl;
            break;
        } else if (updateResult == -1) {
            std::cout << "Vous avez perdu ! Le jeu est terminé." << std::endl;
            break;
        }*/
        
        
        
        /*int gameResult = model->UpdateData(framework);

        

        if (gameResult == 1) {
            // Victoire
            std::cout << "Victoire ! Tous les astéroïdes ont été détruits." << std::endl;
            exit(0);  // Quitte le programme
        } else if (gameResult == -1) {
            // Défaite
            std::cout << "Défaite ! Collision avec le vaisseau ayant son bouclier à 0." << std::endl;
            exit(0);  // Quitte le programme
        }*/


    }
}





