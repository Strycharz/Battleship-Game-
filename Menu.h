
#pragma once
#include "SFML/Graphics.hpp"


#include "PlanszaKomputer.h"
#include "PlanszaGracz.h"
#include "SFMLview.h"
#include "Input.h"

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];


    PlanszaGracz & plansza1;
    PlanszaKomputer & plansza2;
    SFMLview & view;

    Input input;

public:
    Menu(float width, float height,PlanszaGracz & p1,PlanszaKomputer & p2, SFMLview & v);
    ~Menu();

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }
    void Logika();



};