//
// Created by Admin on 10.06.2022.
//

#ifndef UNTITLED1_TEXTCONTROLLER_H
#define UNTITLED1_TEXTCONTROLLER_H

#include "PlanszaGracz.h"
#include "PlanszaKomputer.h"
#include "Wyswietlanie.h"


class TextController {
    PlanszaGracz & plansza1;
    PlanszaKomputer & plansza2;
    Wyswietlanie & okno;
public:
    TextController(PlanszaGracz & p1, PlanszaKomputer & p2, Wyswietlanie & win);
    void play();
};


#endif //UNTITLED1_TEXTCONTROLLER_H
