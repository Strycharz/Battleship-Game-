//
// Created by Admin on 10.06.2022.
//

#include "PlanszaGracz.h"
#include <time.h>
#include <iostream>

using namespace std;

PlanszaGracz::PlanszaGracz()
{

    for (int row = 0; row < 10; row++)
        for (int col = 0; col < 10; col++)
        {
            board[row][col].czyStatek = 0;
            board[row][col].czyOdkryte = 0;
        }
}

void PlanszaGracz::postawStatek(int row, int col)
{
    board[row][col].czyStatek = 1;
}


bool PlanszaGracz::czyMaStatek(int row, int col)
{
    if (board[row][col].czyStatek == 0)
    {
        return false;
    }

    return true;
}

char PlanszaGracz::getFieldInfo(int row, int col)
{
    if (board[row][col].czyStatek == 1 and board[row][col].czyOdkryte == 0)
        return 'x';
    if (board[row][col].czyOdkryte == 1 and board[row][col].czyStatek == 0)
        return '.';
    if (board[row][col].czyOdkryte == 1 and board[row][col].czyStatek == 1)
        return 'T';
    
    return 'n';
}

int PlanszaGracz::czyWszystkieStatki()
{
    int licznikStatkow = 0;
    for (int row = 0; row < 10; row++)
        for (int col = 0; col < 10; col++)
        {
            if (board[row][col].czyStatek == 1)
                licznikStatkow = licznikStatkow + 1;
        }
    //    cout <<licznikStatkow<<endl;
    return licznikStatkow;
}

bool PlanszaGracz::czyWszystkieStatkiTrafione()
{
    int licznikTrafionychStatkow = 0;
    for (int row = 0; row < 10; row++)
        for (int col = 0; col < 10; col++)
        {
            if (board[row][col].czyOdkryte == 1 and board[row][col].czyStatek == 1)
                licznikTrafionychStatkow++;
        }
    if (licznikTrafionychStatkow == 14)
        return true;
    else
        return false;
}

bool PlanszaGracz::czyPozaPlansza(int row, int col)
{
    if (row >= 10 or col >= 10)
        return true;

    if (row < 0 or col < 0)
        return true;

    return false;
}

void PlanszaGracz::strzalBota()
{
    srand(time(NULL));

    int row = rand() % 10;
    int col = rand() % 10;

    if (board[row][col].czyOdkryte == 1)
    {
        while (true)
        {
            row = rand() % 10;
            col = rand() % 10;
            if (board[row][col].czyOdkryte == 1)
            {
                continue;
            }
            else
                break;
        }
    }

    int kierunek = rand() % 4;
    if (board[row][col].czyOdkryte == 0)
    {

        board[row][col].czyOdkryte = true;

        if (board[row][col].czyStatek == 1)
        {
            switch (kierunek)
            {
            case 0: // prawo
                for (int b = 0; b < 5; b++)
                {
                    if (board[row + b][col].czyStatek == true)
                    {
                        if (czyPozaPlansza(row + b, col) == false)
                            board[row + b][col].czyOdkryte = true;
                        else
                            break;
                    } else {
                        break;
                    }
                }
                break;
            case 1: // lewo
                for (int b = 0; b < 5; b++)
                {
                    if (board[row - b][col].czyStatek == true)
                    {
                        if (czyPozaPlansza(row - b, col) == false)
                            board[row - b][col].czyOdkryte = true;
                        else 
                            break;
                            
                    } else {
                        break;
                    }
                }
                break;
            case 2: // dol
                for (int b = 0; b < 5; b++)
                {
                    if (board[row][col + b].czyStatek == true)
                    {
                        if (czyPozaPlansza(row, col + b) == false)
                            board[row][col + b].czyOdkryte = true;
                        else 
                            break;
                    } else {
                        break;
                    }
                }
                break;
            case 3: // gora
                for (int b = 0; b < 5; b++)
                {
                    if (board[row][col - b].czyStatek == true)
                    {
                        if (czyPozaPlansza(row, col - b) == false)
                            board[row][col - b].czyOdkryte = true;
                        else 
                            break;
                    } else {
                        break;
                    }
                }
                break;
            }
            //            cout << row << "sa " << col << endl;

            strzalBota();
        }
    }
}
