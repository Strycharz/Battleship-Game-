//
// Created by Admin on 10.06.2022.
//

#ifndef UNTITLED1_PLANSZAGRACZ_H
#define UNTITLED1_PLANSZAGRACZ_H

struct Pole{
    bool czyOdkryte;
    bool czyStatek;
};

class PlanszaGracz{
    Pole board[10][10];

public:
    PlanszaGracz();

    void postawStatek(int row, int col);
    char getFieldInfo(int row, int col);
    int czyWszystkieStatki();
    void strzalBota();

    bool czyWszystkieStatkiTrafione();

    bool czyPozaPlansza(int row, int col);
    bool czyMaStatek(int row, int col);

};


#endif //UNTITLED1_PLANSZAGRACZ_H
