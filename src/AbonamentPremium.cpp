#include "../include/AbonamentPremium.h"

int AbonamentPremium::numarAbonamentePremium = 0;

AbonamentPremium::AbonamentPremium(const std::string& numeClient, const std::string& codClient, float pret)
    : Abonament(numeClient, codClient), pret(pret) {
    if (pret < 0) {
        throw PretInvalidException();
    }
    ++numarAbonamentePremium;
}

AbonamentPremium::AbonamentPremium(const AbonamentPremium& other)
    : Abonament(other), pret(other.pret) {
    ++numarAbonamentePremium;
}

AbonamentPremium& AbonamentPremium::operator=(const AbonamentPremium& other) {
    if (this != &other) {
        Abonament::operator=(other);
        pret = other.pret;
    }
    return *this;
}

AbonamentPremium::~AbonamentPremium() {
    --numarAbonamentePremium;
}

void AbonamentPremium::afisareDetalii() const {
    std::cout << "Abonament premium pentru " << numeClient << " (Cod client: " << codClient << ")\n";
    std::cout << "Pret: " << pret << "\n";
}

void AbonamentPremium::calculeazaPret() const {
    if (pret < 0) {
        throw PretInvalidException();
    }
    // Implementați logica de calculare a prețului pentru un abonament premium
}

Abonament* AbonamentPremium::clone() const {
    return new AbonamentPremium(*this);
}

int AbonamentPremium::getNumarAbonamentePremium() {
    return numarAbonamentePremium;
}
