#ifndef ABONAMENT_H_INCLUDED
#define ABONAMENT_H_INCLUDED

#include <iostream>
#include "MyExceptions.h"
#include <memory>


class ManagerClienti;

class Abonament {
protected:
    float baza;
    int idClient;
    std::weak_ptr<ManagerClienti> manager;
    float pret;
    static int numarAbonamente;
    virtual void afisareTip() const = 0;
    virtual void afisareDetalii() const = 0;

public:
    Abonament(float baza, int idClient);
    Abonament(const Abonament& other);
    Abonament& operator=(const Abonament& other);
    virtual ~Abonament();

    friend std::ostream& operator<<(std::ostream& os, const Abonament& st) {
        st.afisareDetalii();
        return os;
    }

    virtual void calculeazaPret(float vechime = -1) = 0;
    virtual Abonament* clone() const = 0;

    static int getter_AbonamenteTotale();
    float getVechime(int codClient);
    void setter_manager (std::shared_ptr<ManagerClienti> man);
};

#endif // ABONAMENT_H_INCLUDED
