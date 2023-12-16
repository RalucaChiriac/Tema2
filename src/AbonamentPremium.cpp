#include "../include/AbonamentPremium.h"

int AbonamentPremium::numarAbonamentePremium = 0;

AbonamentPremium::AbonamentPremium(float baza, int idClient, bool serviciuSupport)
    : Abonament(baza, idClient), serviciuSupport(serviciuSupport) {
    ++numarAbonamentePremium;
}

AbonamentPremium::AbonamentPremium(const AbonamentPremium& other)
    : Abonament(other), serviciuSupport(other.serviciuSupport) {
    ++numarAbonamentePremium;
}

AbonamentPremium& AbonamentPremium::operator=(const AbonamentPremium& other) {
    if (this != &other) {
        Abonament::operator=(other);
        serviciuSupport = other.serviciuSupport;
    }
    return *this;
}

AbonamentPremium::~AbonamentPremium() {
    --numarAbonamentePremium;
}

void AbonamentPremium::afisareDetalii() const {
    std::cout << "Abonament premium\n";
    std::cout << "Pretul platit: " << get_pret() << "\n";
    std::cout << "Serviciu support 24/7: " << (serviciuSupport ? "Da" : "Nu") << "\n";
}

void AbonamentPremium::calculeazaPret(float vechime = -1) {

    if (vechime == -1)
     {
        if (serviciuSupport) {
            pret = getBaza() - 0.5 * getVechime() + 12;
        }
        else {
            pret = getBaza() - 0.5 * getVechime();
        }
     }
     else
     {
         if (serviciuSupport) {
            pret = getBaza() - 0.5 * vechime + 12;
        }
        else {
            pret = getBaza() - 0.5 * vechime;
        }
     }
}

Abonament* AbonamentPremium::clone() const {
    return new AbonamentPremium(*this);
}

int AbonamentPremium::getNumarAbonamentePremium() {
    return numarAbonamentePremium;
}
