//
// Created by Admin on 10.06.2022.
//

#ifndef UNTITLED1_PLANSZAKOMPUTER_H
#define UNTITLED1_PLANSZAKOMPUTER_H

struct poleK{
    bool czyOdkryte;
    bool czyStatek;
};

class PlanszaKomputer {
    poleK board[10][10];
public:
    PlanszaKomputer();
    void ustawStatki();
    char getFieldInfo(int row, int col);
    void ustawStrzal(int row, int col);
    bool czyTrafiony(int row, int col);

    bool czyWszystkieStatkiTrafione();
    bool czyOdkryte(int row, int col);
};


#endif //UNTITLED1_PLANSZAKOMPUTER_H
