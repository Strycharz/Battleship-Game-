//
// Created by Admin on 10.06.2022.
//

#include "TextController.h"
#include <iostream>
using namespace std;


TextController::TextController(PlanszaGracz &p1, PlanszaKomputer &p2, Wyswietlanie &win) : plansza1(p1), plansza2(p2), okno(win){
play();
}

void TextController::play() {
    int x,y;
    int a=0;

    while(a<5){
        cout <<"Podaj kordy" <<endl;
        cin>>x>>y;
        plansza1.postawStatek(x,y);
        system("cls");
        okno.display();
        a++;
    }
    system("cls");
    okno.display();

    cout<<"Strzel gdzies: "<<endl;
    cin>>x>>y;
    plansza2.ustawStrzal(x,y);
    okno.display();
    plansza1.strzalBota();
    okno.display();
}