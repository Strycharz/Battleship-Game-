#include "GameOver.h"

#include <iostream>
#include <time.h>
#include <SFML/Graphics.hpp>

using namespace std;
GameOver::GameOver(float width, float height, PlanszaGracz &p1, PlanszaKomputer &p2) : plansza1(p1), plansza2(p2), width(width), height(height)
{
    if (!font.loadFromFile("../arial.ttf"))
    {
        cout << "Blad wczytania fontu" << endl;
        abort();
    }

    selectedItemIndex = 0;
}

GameOver::~GameOver()
{
}

void GameOver::init(bool wygrales)
{
    menu[0].setFont(font);
    if(wygrales)
    {
        menu[0].setFillColor(sf::Color::Green);
        menu[0].setString("Win!!!");
    } else
    {
        menu[0].setFillColor(sf::Color::Red);
        menu[0].setString("Game Over");
    }
    menu[0].setCharacterSize(50);
    menu[0].setPosition(sf::Vector2f(width / 4, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    srand(time(NULL));
    int wynik = rand() % 50 + 300;
    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Punkty: ");
    menu[1].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString(to_string(wynik));
    menu[2].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
}

void GameOver::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}

void GameOver::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Green);
    }
}

void GameOver::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Green);
    }
}

void GameOver::Logika(bool wygrales)
{
    init(wygrales);
    sf::RenderWindow window(sf::VideoMode(600, 600), "Statki - Game Over");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        input.update();

        if (input.isKeyPressed(Input::Key::RETURN))
        {
            window.close();
        }

        window.clear();

        draw(window);

        window.display();
    }
}