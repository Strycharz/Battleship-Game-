//
// Created by Admin on 10.06.2022.
//

#ifndef UNTITLED1_WYSWIETLANIE_H
#define UNTITLED1_WYSWIETLANIE_H

#include "PlanszaGracz.h"
#include "PlanszaKomputer.h"

class Wyswietlanie {
    PlanszaGracz &plansza1;
    PlanszaKomputer &plansza2;
public:
    Wyswietlanie(PlanszaGracz &p1 , PlanszaKomputer & p2);
    void display();
};


#endif //UNTITLED1_WYSWIETLANIE_H
