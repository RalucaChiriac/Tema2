#include "../include/Abonament.h"
#include "../include/ManagerClienti.h"

int Abonament::numarAbonamente = 0;

Abonament::Abonament(float baza, int idClient) : baza(baza), idClient(idClient), manager(nullptr), pret(0.0){
    if (baza < 0)
    {
        throw ExceptieNumar();
    }
    if (idClient < 0)
    {
        throw ExceptieNumar();
    }
    numarAbonamente++;
}

Abonament::Abonament(const Abonament& other) : baza(other.baza), idClient(other.idClient), manager(nullptr), pret(other.pret) {
    numarAbonamente++;
}

Abonament& Abonament::operator=(const Abonament& other) {
    if (this != &other) {
        baza = other.baza;
        idClient = other.idClient;
        pret = other.pret;
        manager = other.manager;
    }
    return *this;
}

Abonament::~Abonament() {
    numarAbonamente--;
}

float Abonament::getBaza() const {
    return baza;
}
void Abonament::setBaza(float bazaSetata)
{
    this->baza = bazaSetata;
}

int Abonament::getIdClient() const {
    return idClient;
}

void Abonament::set_pret(float pret_setat)
{
    pret = pret_setat;
}

float Abonament::getVechime()
{
    for (auto& client : manager->getterClienti()) {
        if (client->getId() == idClient) {
            return client->getVechime();
        }
            }
    return 0.0;
}

int Abonament::getter_AbonamenteTotale()
{
    return numarAbonamente;
}

float Abonament::get_pret() const
{
    return pret;
}

void Abonament::setter_manager(ManagerClienti* man)
{
    manager = man;
}
