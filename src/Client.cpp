#include "../include/Client.h"

Client::Client(const std::string& numeClient, const std::string& codClient, Abonament* abonament)
    : numeClient(numeClient), codClient(codClient), abonament(abonament) {}

Client::~Client() {
    delete abonament;
}

const std::string& Client::getNumeClient() const {
    return numeClient;
}

const std::string& Client::getCodClient() const {
    return codClient;
}

const Abonament* Client::getAbonament() const {
    return abonament;
}

void Client::setAbonament(Abonament* abonament1) {
    this->abonament = abonament1;
}
