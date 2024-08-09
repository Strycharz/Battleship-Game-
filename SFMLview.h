//
// Created by Admin on 10.06.2022.
//

#ifndef UNTITLED1_SFMLVIEW_H
#define UNTITLED1_SFMLVIEW_H

#include "PlanszaGracz.h"
#include "PlanszaKomputer.h"
#include "GameOver.h"

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Input.h"


#include <array>
#include <vector>

using namespace std;
using namespace sf;

class SFMLview {

    PlanszaGracz & plansza1;
    PlanszaKomputer & plansza2;

    GameOver & over;

    Input input;


    void aktualizacjaPola(int row, int col);

    void aktywujPlansze();
    sf::RectangleShape Tablica[10][10];
    sf::RectangleShape Tablica2[10][10];
public:



   explicit SFMLview(PlanszaGracz & p1,PlanszaKomputer & p2, GameOver & ov);
    sf::Vector2i localPosition;
    void RysujPlansze(sf::RenderWindow & win);

    void wyswietlanie(PlanszaGracz & p1,PlanszaKomputer & p2);






};


#endif //UNTITLED1_SFMLVIEW_H
