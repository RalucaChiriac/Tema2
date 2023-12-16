#include "../include/AbonamentStudent.h"

int AbonamentStudent::numarAbonamenteStudent = 0;

AbonamentStudent::AbonamentStudent(float baza, int idClient, int numarLegitimatie)
    : Abonament(baza, idClient), numarLegitimatie(numarLegitimatie) {
    if (numarLegitimatie> 1000) {
        throw ExceptieNumar();
    }
    ++numarAbonamenteStudent;
}

AbonamentStudent::AbonamentStudent(const AbonamentStudent& other)
    : Abonament(other), numarLegitimatie(other.numarLegitimatie) {
    ++numarAbonamenteStudent;
}

AbonamentStudent& AbonamentStudent::operator=(const AbonamentStudent& other) {
    if (this != &other) {
        Abonament::operator=(other);
        numarLegitimatie = other.numarLegitimatie;
    }
    return *this;
}

AbonamentStudent::~AbonamentStudent() {
    --numarAbonamenteStudent;
}

void AbonamentStudent::afisareDetalii() const {
    std::cout << "Abonament student\n";
    std::cout << "Pretul platit: " << get_pret() << "\n";
    std::cout << "Numar legitimatie: " << numarLegitimatie << "\n";
}

void AbonamentStudent::calculeazaPret(float vechime)  {

    vechime = 0;
    if (numarLegitimatie % 10 == 1) {
        pret = getBaza() - 0.1 * getBaza();
    } else if (numarLegitimatie % 10 == 2) {
        pret = getBaza() - 0.15 * getBaza();
    } else {
        pret = getBaza();
    }
}

Abonament* AbonamentStudent::clone() const {
    return new AbonamentStudent(*this);
}

int AbonamentStudent::getNumarAbonamenteStudent() {
    return numarAbonamenteStudent;
}
