#include "../include/AbonamentSimplu.h"
#include "../include/Abonament.h"
#include "Abonament.cpp"

int AbonamentSimplu::numarAbonamenteSimplu = 0;

AbonamentSimplu::AbonamentSimplu(const std::string& numeClient, const std::string& codClient, float pret)
    : Abonament(numeClient, codClient), pret(pret) {
    if (pret < 0) {
        throw PretInvalidException();
    }
    ++numarAbonamenteSimplu;
}

AbonamentSimplu::AbonamentSimplu(const AbonamentSimplu& other)
    : Abonament(other), pret(other.pret) {
    ++numarAbonamenteSimplu;
}

AbonamentSimplu& AbonamentSimplu::operator=(const AbonamentSimplu& other) {
    if (this != &other) {
        Abonament::operator=(other);
        pret = other.pret;
    }
    return *this;
}

AbonamentSimplu::~AbonamentSimplu() {
    --numarAbonamenteSimplu;
}

void AbonamentSimplu::afisareDetalii() const {
    std::cout << "Abonament simplu pentru " << numeClient << " (Cod client: " << codClient << ")\n";
    std::cout << "Pret: " << pret << "\n";
}

void AbonamentSimplu::calculeazaPret() const {
    if (pret < 0) {
        throw PretInvalidException();
    }
}

Abonament* AbonamentSimplu::clone() const {
    return new AbonamentSimplu(*this);
}


int AbonamentSimplu::getNumarAbonamenteSimplu() {
    return numarAbonamenteSimplu;
}
