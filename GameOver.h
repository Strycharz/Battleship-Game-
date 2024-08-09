
#pragma once
#include "SFML/Graphics.hpp"


#include "PlanszaKomputer.h"
#include "PlanszaGracz.h"
#include "Input.h"


#define MAX_NUMBER_OF_ITEMS 3

class GameOver
{
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];


    PlanszaGracz & plansza1;
    PlanszaKomputer & plansza2;

    Input input;

    void init(bool wygrales);

    float width;
    float height;

public:
    GameOver(float width, float height,PlanszaGracz & p1,PlanszaKomputer & p2);
    ~GameOver();

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }
    void Logika(bool wygrales);



};