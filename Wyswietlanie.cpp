//
// Created by Admin on 10.06.2022.
//

#include "Wyswietlanie.h"

#include <iostream>

Wyswietlanie::Wyswietlanie(PlanszaGracz &p1, PlanszaKomputer &p2) : plansza1(p1), plansza2(p2){
//    display();
}


void Wyswietlanie::display() {
    std::cout<<"PLANSZA GRACZA"<<std::endl;
    for(int row=0; row<10; row++)
    {
        for(int col=0; col<10; col++)
        {
            std::cout<<plansza1.getFieldInfo(row,col)<<" ";
        }
            std::cout<<std::endl;
    }
    std::cout<<"PLANSZA BOTA"<<std::endl;
    for(int row=0; row<10; row++)
    {
        for(int col=0; col<10; col++)
        {
            std::cout<<plansza2.getFieldInfo(row,col)<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"---------------------------"<<std::endl;
}

