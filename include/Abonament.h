#ifndef ABONAMENT_H_INCLUDED
#define ABONAMENT_H_INCLUDED

#include <iostream>
#include "MyExceptions.h"
#include "ManagerClienti.h"

class ManagerClienti;

class Abonament {
protected:
    float baza;
    int idClient;
    ManagerClienti* manager;
    float pret;
    static int numarAbonamente;

public:
    Abonament(float baza, int idClient);
    Abonament(const Abonament& other);
    Abonament& operator=(const Abonament& other);
    virtual ~Abonament();

    virtual void afisareDetalii() const = 0;
    virtual void calculeazaPret(float vechime = -1) = 0;
    virtual Abonament* clone() const = 0;

    int getIdClient() const;
    float getBaza() const;
    void setBaza(float bazaSetata);

    void set_pret(float pret_setat);
    float get_pret() const;
    static int getter_AbonamenteTotale();
    float getVechime();
    void setter_manager ( ManagerClienti* man);


};

#endif // ABONAMENT_H_INCLUDED
