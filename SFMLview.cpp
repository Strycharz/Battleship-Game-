//
// Created by Admin on 10.06.2022.
//


#include "SFMLview.h"

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <math.h>

using namespace std;

SFMLview::SFMLview(PlanszaGracz &p1, PlanszaKomputer &p2, GameOver &ov) : plansza1(p1), plansza2(p2), over(ov)
{
    aktywujPlansze();
}

void SFMLview::aktywujPlansze()
{

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
        {
            Tablica[i][j].setSize(sf::Vector2f(20, 20));
            Tablica[i][j].setFillColor(sf::Color::Cyan);
            Tablica[i][j].setOutlineColor(sf::Color::Blue);
            Tablica[i][j].setOutlineThickness(3);
            Tablica[i][j].setPosition(50 + 30 * i, 50 + 30 * j);
        }

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
        {
            Tablica2[i][j].setSize(sf::Vector2f(20, 20));
            Tablica2[i][j].setFillColor(sf::Color::Cyan);
            Tablica2[i][j].setOutlineColor(sf::Color::Red);
            Tablica2[i][j].setOutlineThickness(3);
            Tablica2[i][j].setPosition(450 + 30 * i, 50 + 30 * j);
        }
}

void SFMLview::RysujPlansze(sf::RenderWindow &win)
{
    // tu robimy rysowanie planszy na podstawie zawartości "board"
    for (int wiersz = 0; wiersz < 10; wiersz++)
    {
        for (int kolumna = 0; kolumna < 10; kolumna++)
        {
            aktualizacjaPola(wiersz, kolumna);
            //                win.draw(sprites[wiersz][kolumna]);
            win.draw(Tablica[wiersz][kolumna]);
            win.draw(Tablica2[wiersz][kolumna]);
        }
    }
}

void SFMLview::aktualizacjaPola(int row, int col)
{
    char stan_pola1 = plansza1.getFieldInfo(row, col);

    char stan_pola2 = plansza2.getFieldInfo(row, col);

    switch (stan_pola1)
    {
    case '~':
        //            cout << row <<endl;
        //            cout << col <<endl;
        ////            sprites[row][col].setTexture(buttonTextures[0]);
        Tablica[row][col].setFillColor(sf::Color::White);
        break;
        //--------------
    case '.':
        Tablica[row][col].setFillColor(sf::Color::Blue);
        //            sprites[row][col].setTexture(buttonTextures[1]);
        break;
        //--------------
    case 'x':
        Tablica[row][col].setFillColor(sf::Color::Green);
        //            sprites[row][col].setTexture(buttonTextures[2]);
        break;
        //--------------
    case 'T':
        Tablica[row][col].setFillColor(sf::Color::Red);
        //            sprites[row][col].setTexture(buttonTextures[2]);
        break;
        //--------------
    default:
        //            return;
        break;
    }

    switch (stan_pola2)
    {
    case '~':
        //            cout << row <<endl;
        //            cout << col <<endl;
        ////            sprites[row][col].setTexture(buttonTextures[0]);
        Tablica2[row][col].setFillColor(sf::Color::White);
        break;
        //--------------
    case '.':
        Tablica2[row][col].setFillColor(sf::Color::Blue);
        //            sprites[row][col].setTexture(buttonTextures[1]);
        break;
        //--------------
    case 'x':
        Tablica2[row][col].setFillColor(sf::Color::Red);
        //            sprites[row][col].setTexture(buttonTextures[2]);
        break;
        //--------------
    default:
        return;
        break;
    }
}

bool czyMyszPozaMapa(int row, int col)
{

    if (row >= 10 or col >= 10)
        return true;

    if (row < 0 or col < 0)
        return true;

    return false;
}

void SFMLview::wyswietlanie(PlanszaGracz &p1, PlanszaKomputer &p2)
{
    //    PlanszaGracz planszaGracz;
    //    PlanszaKomputer planszaKomputer;
    //
    //    SFMLview view(planszaGracz, planszaKomputer);

    //    MinesweeperBoard board(10, 10, EASY);
    //    MSSFMLView view(board);
    //    board.debug_display();

    sf::RenderWindow window(sf::VideoMode(800, 600), "Statki");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;
        input.update();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        localPosition = sf::Mouse::getPosition(window);
        // if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (input.isKeyUp(Input::Key::MOUSE_LEFT))
        {
            int wiersz = ceil((localPosition.x - 50) / 30);
            int kolumna = ceil((localPosition.y - 50) / 30);
            //            cout <<wiersz <<" "<< kolumna <<endl;

            int wiersz2 = ceil((localPosition.x - 450) / 30);
            int kolumna2 = ceil((localPosition.y - 50) / 30);
            //            cout <<wiersz2 <<" "<< kolumna2 <<endl;

            if (czyMyszPozaMapa(wiersz, kolumna) == false)
            {
                if (p1.czyWszystkieStatki() != 14)
                    if(!p1.czyMaStatek(wiersz, kolumna))
                        p1.postawStatek(wiersz, kolumna);
            }

            if (czyMyszPozaMapa(wiersz2, kolumna2) == false)
            {
                if (p1.czyWszystkieStatki() == 14)
                {
                    if(!p2.czyOdkryte(wiersz2, kolumna2))
                    {
                        p2.ustawStrzal(wiersz2, kolumna2);
                        if(!p2.czyTrafiony(wiersz2, kolumna2))
                            p1.strzalBota();
                    }
                }
            }
        }

        if (p2.czyWszystkieStatkiTrafione())
        {
            window.close();
            // przepraszam :d
            over.Logika(true);
        }

        if(p1.czyWszystkieStatkiTrafione())
        {
            window.close();
            // przepraszam :d
            over.Logika(false);
        }

        window.clear();
        RysujPlansze(window);
        window.display();
    }
}