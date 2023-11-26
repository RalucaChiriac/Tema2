#include "../include/Abonament.h"

int Abonament::numarAbonamenteActive = 0;

Abonament::Abonament(const std::string& numeClient, const std::string& codClient)
    : numeClient(numeClient), codClient(codClient) {
    ++numarAbonamenteActive;
}

Abonament::Abonament(const Abonament& other)
    : numeClient(other.numeClient), codClient(other.codClient) {
    ++numarAbonamenteActive;
}

Abonament& Abonament::operator=(const Abonament& other) {
    if (this != &other) {
        numeClient = other.numeClient;
        codClient = other.codClient;
    }
    return *this;
}

Abonament::~Abonament() {
    --numarAbonamenteActive;
}

void Abonament::afiseazaInformatiiStatice() {
    std::cout << "Numarul total de abonamente active: " << getNumarAbonamenteActive() << "\n";
}

int Abonament::getNumarAbonamenteActive() {
    return numarAbonamenteActive;
}
