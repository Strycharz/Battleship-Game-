#include "Menu.h"

#include <iostream>
#include "Input.h"

#include <SFML/Graphics.hpp>

using namespace std;
Menu::Menu(float width, float height, PlanszaGracz &p1, PlanszaKomputer &p2, SFMLview &v) : plansza1(p1), plansza2(p2), view(v)
{
    if (!font.loadFromFile("../arial.ttf"))
    {
        cout << " blad pliku arial.tft" << endl;
        abort();
    }

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Green);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Options");
    menu[1].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    selectedItemIndex = 0;
    Logika();
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Green);
    }
}

void Menu::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Green);
    }
}

void Menu::Logika()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Statki - Menu");

    while (window.isOpen())
    {
        sf::Event event;

        input.update();

        if (input.isKeyUp(Input::Key::UP))
            MoveUp();

        if (input.isKeyUp(Input::Key::DOWN))
            MoveDown();

        if (input.isKeyPressed(Input::Key::RETURN))
        {
            switch (GetPressedItem())
            {
            case 0:
                window.close();
                view.wyswietlanie(plansza1, plansza2);

                break;
            case 1:
                std::cout << "Option button has been pressed" << std::endl;
                break;
            case 2:
                window.close();
                break;
            }
        }

        window.clear();

        draw(window);

        window.display();
    }
}