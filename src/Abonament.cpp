#include "../include/Abonament.h"
#include "../include/ManagerClienti.h"

int Abonament::numarAbonamente = 0;

Abonament::Abonament(float baza, int idClient) : baza(baza), idClient(idClient), pret(0.0){
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

Abonament::Abonament(const Abonament& other) : baza(other.baza), idClient(other.idClient), manager(other.manager), pret(other.pret) {
    numarAbonamente++;
}

Abonament& Abonament::operator=(const Abonament& other) {
    if (this != &other) {
        baza = other.baza;
        idClient = other.idClient;
        pret = other.pret;
    }
    return *this;
}

Abonament::~Abonament() {
    numarAbonamente--;
}

float Abonament::getVechime(int codClient) {

    if (auto man = manager.lock())
        return man->findClient(codClient).getVechime();
    else
    {
        throw ExceptieManagerInexistent();
    }

}

int Abonament::getter_AbonamenteTotale()
{
    return numarAbonamente;
}

void Abonament::setter_manager(std::shared_ptr<ManagerClienti> man)
{
   std::weak_ptr<ManagerClienti> my_ptr = man;
   manager = my_ptr;
}
