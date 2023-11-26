#ifndef ABONAMENT_H_INCLUDED
#define ABONAMENT_H_INCLUDED

#include <iostream>
#include "MyExceptions.h"

class Abonament {
public:
    Abonament(const std::string& numeClient, const std::string& codClient);
    Abonament(const Abonament& other);
    Abonament& operator=(const Abonament& other);
    virtual ~Abonament();

    virtual void afisareDetalii() const = 0;
    virtual void calculeazaPret() const = 0;
    virtual Abonament* clone() const = 0;

    static void afiseazaInformatiiStatice();
    static int getNumarAbonamenteActive();

protected:
    std::string numeClient;
    std::string codClient;

private:
    static int numarAbonamenteActive;
};

#endif // ABONAMENT_H_INCLUDED
