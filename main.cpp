
#include "SFML/Graphics.hpp"

#include "SFML/Window.hpp"

#include <iostream>
#include "PlanszaGracz.h"
#include "PlanszaKomputer.h"

#include "Wyswietlanie.h"
#include "TextController.h"
#include "SFMLview.h"
#include "Menu.h"
#include "GameOver.h"

#include <cmath>



int main() {
    PlanszaGracz planszaGracz;
    PlanszaKomputer planszaKomputer;


    GameOver gameover(800, 600,planszaGracz, planszaKomputer);

    SFMLview view(planszaGracz, planszaKomputer,gameover);

    Menu menu(800, 600, planszaGracz,planszaKomputer,view);



    return 0;
}


