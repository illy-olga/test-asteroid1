#include <iostream>
#include "framework.hpp"
#include "Asteroid.hpp"
#include "missile.hpp"
#include "Spaceship.hpp"
#include "Model.hpp"
#include "View.hpp"
#include "Controller.hpp"

using namespace std;

int WinMain(int argc, char* argv[])
{
        std::cout << "Hello World!" << std::endl;
        Controller* controller = new Controller(20,45,10);
        controller->lauchGame();

        return 0;     
}
