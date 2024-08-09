//
// Created by Admin on 10.06.2022.
//

#include "PlanszaKomputer.h"
#include <time.h>
#include <random>
#include <iostream>
PlanszaKomputer::PlanszaKomputer() {
    for(int row=0; row<10; row++)
        for(int col=0; col<10; col++)
        {
            board[row][col].czyStatek=0;
            board[row][col].czyOdkryte=0;
        }
    ustawStatki();
}

bool PlanszaKomputer::czyOdkryte(int row, int col)
{
    if(board[row][col].czyOdkryte == 0)
    {
        return false;
    }

    return true;
}


bool czyPozaMapa(int row, int col){
    if(row >= 10 or col >= 10)
        return true;
    else
        return false;
}

void PlanszaKomputer::ustawStatki() {
    srand(time(NULL));
    
    bool czyDobrzeRozlozone=false;
    int licznikStatkow=0;

    int miejsceX = rand() %10;
    int miejsceY = rand() %10;




    while(czyDobrzeRozlozone == false) {
        for (int i = 0; i < 5; i++) { //statek 5
            if (czyPozaMapa(miejsceX + i, miejsceY) == false) {
                board[miejsceX + i][miejsceY].czyStatek = 1;
//                std::cout <<miejsceX+i <<" " << miejsceY <<std::endl;
            }

        }

        miejsceX = rand() % 10;
        miejsceY = rand() % 10;

        for (int i = 0; i < 4; i++) { //statek 4
            if (czyPozaMapa(miejsceX, miejsceY + i) == false)
                board[miejsceX][miejsceY + i].czyStatek = 1;
        }

        miejsceX = rand() % 10;
        miejsceY = rand() % 10;

        for (int i = 0; i < 3; i++) { //statek 3
            if (czyPozaMapa(miejsceX + i, miejsceY) == false)
                board[miejsceX + i][miejsceY].czyStatek = 1;
        }

        miejsceX = rand() % 10;
        miejsceY = rand() % 10;

        for (int i = 0; i < 2; i++) { //statek 2
            if (czyPozaMapa(miejsceX + i, miejsceY) == false)
                board[miejsceX + i][miejsceY].czyStatek = 1;
        }

        for (int row = 0; row < 10; row++)
            for (int col = 0; col < 10; col++) {
                if (board[row][col].czyStatek == 1)
                    licznikStatkow = licznikStatkow + 1;
//                std::cout << licznikStatkow << std::endl;
            }

        if(licznikStatkow == 14)
            czyDobrzeRozlozone=true;
        else
            czyDobrzeRozlozone=false;

        if (czyDobrzeRozlozone==false) {
            licznikStatkow = 0;
            for (int row = 0; row < 10; row++)
                for (int col = 0; col < 10; col++)
                    board[row][col].czyStatek = 0;
        }
    }

}

char PlanszaKomputer::getFieldInfo(int row, int col) {
    if(board[row][col].czyOdkryte == 0)
        return '~';
    if(board[row][col].czyOdkryte == 1 and board[row][col].czyStatek == 1)
        return 'x';
    if(board[row][col].czyOdkryte == 1 and board[row][col].czyStatek == 0)
        return '.';
}

void PlanszaKomputer::ustawStrzal(int row, int col) {
    board[row][col].czyOdkryte = 1;

}

bool PlanszaKomputer::czyTrafiony(int row, int col) {
    if(board[row][col].czyStatek && board[row][col].czyOdkryte)
        return true;
    else
        return false;
}

bool PlanszaKomputer::czyWszystkieStatkiTrafione() {
    int licznikTrafionychStatkow=0;
    for(int row=0; row<10; row++)
        for(int col=0; col<10; col++){
            if(board[row][col].czyOdkryte == 1 and board[row][col].czyStatek == 1)
                licznikTrafionychStatkow++;
        }
    if(licznikTrafionychStatkow == 14)
        return true;
    else
        return false;
}
