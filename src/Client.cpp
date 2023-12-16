#include "../include/Client.h"

Client::Client(const std::string& nume, int codClient, Abonament* abonament, float vechime) : nume(nume), codClient(codClient), vechime(vechime), abonament(abonament->clone())
{
    if (vechime < 0)
    {
        throw ExceptieNumar();
    }
    if (codClient < 0)
    {
        throw ExceptieNumar();
    }
}

Client::Client(const Client& other) : nume(other.nume), codClient(other.codClient), vechime(other.vechime), abonament(other.abonament)
{}

Client& Client::operator=(const Client& other)
{
    if (this != &other)
    {
        nume = other.nume;
        vechime = other.vechime;


        if (other.abonament)
        {
            abonament = other.abonament->clone();
        }
        else
        {
            abonament = nullptr;
        }
    }
    return *this;
}

Client::~Client()
{
    delete abonament;
}

void Client::setAbonament(Abonament* abon)
{
    abonament = abon;
}

const Abonament* Client::getAbonament() const
{
    return abonament;
}

void Client::eliminaAbonament()
{
    delete abonament;
    abonament = nullptr;
}

float Client::getVechime() const
{
    return vechime;
}

int Client::getId() const
{
    return codClient;
}

std::string Client::getNume() const
{
    return nume;
}
