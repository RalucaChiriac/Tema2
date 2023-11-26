#include "../include/AbonamentStudent.h"

int AbonamentStudent::numarAbonamenteStudent = 0;

AbonamentStudent::AbonamentStudent(const std::string& numeClient, const std::string& codClient, float pret)
    : Abonament(numeClient, codClient), pret(pret) {
    if (pret < 0) {
        throw PretInvalidException();
    }
    ++numarAbonamenteStudent;
}

AbonamentStudent::AbonamentStudent(const AbonamentStudent& other)
    : Abonament(other), pret(other.pret) {
    ++numarAbonamenteStudent;
}

AbonamentStudent& AbonamentStudent::operator=(const AbonamentStudent& other) {
    if (this != &other) {
        Abonament::operator=(other);
        pret = other.pret;
    }
    return *this;
}

AbonamentStudent::~AbonamentStudent() {
    --numarAbonamenteStudent;
}

void AbonamentStudent::afisareDetalii() const {
    std::cout << "Abonament student pentru " << numeClient << " (Cod client: " << codClient << ")\n";
    std::cout << "Pret: " << pret << "\n";
}

void AbonamentStudent::calculeazaPret() const {
    if (pret < 0) {
        throw PretInvalidException();
    }
    // Implementați logica de calculare a prețului pentru un abonament de student
}

Abonament* AbonamentStudent::clone() const {
    return new AbonamentStudent(*this);
}

int AbonamentStudent::getNumarAbonamenteStudent() {
    return numarAbonamenteStudent;
}
