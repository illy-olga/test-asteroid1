#include <iostream>
#include "framework.hpp"
#include "asteroid.hpp"
#include "missile.hpp"
#include "spaceship.hpp"
#include "model.hpp"
#include "view.hpp"
#include "controller.hpp"

using namespace std;

int WinMain(int argc, char* argv[])
{
        std::cout << "Hello World!" << std::endl;
        Controller* controller = new Controller(60,100,80);
        controller->lauchGame();

        return 0;     
}
