#include "../include/AbonamentSimplu.h"
#include "../include/Abonament.h"
#include "Abonament.cpp"

int AbonamentSimplu::numarAbonamenteSimplu = 0;

AbonamentSimplu::AbonamentSimplu(float baza, int idClient) : Abonament(baza, idClient) {
    numarAbonamenteSimplu++;
}

AbonamentSimplu::AbonamentSimplu(const AbonamentSimplu& other)
    : Abonament(other) {
    ++numarAbonamenteSimplu;
}

AbonamentSimplu& AbonamentSimplu::operator=(const AbonamentSimplu& other) {
    if (this != &other) {
        Abonament::operator=(other);
    }
    return *this;
}

AbonamentSimplu::~AbonamentSimplu() {
    --numarAbonamenteSimplu;
}


void AbonamentSimplu::afisareDetalii() const {
    afisareTip();
    std::cout << "Pretul platit: " << pret << "\n";
}

void AbonamentSimplu::calculeazaPret(float vechime = -1) {

    if (vechime == -1)
        pret = baza - 0.4 * getVechime(this->idClient);
    else
        pret = baza - 0.4 * vechime;
}

Abonament* AbonamentSimplu::clone() const {
    return new AbonamentSimplu(*this);
}

void AbonamentSimplu::afisareTip() const
{
    std::cout<<"Tip: Abonament Simplu"<<std::endl;
}

int AbonamentSimplu::getNumarAbonamenteSimplu() {
    return numarAbonamenteSimplu;
}
