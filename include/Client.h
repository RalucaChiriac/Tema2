#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include <string>
#include "Abonament.h"

class Client {
public:
    Client(const std::string& numeClient, const std::string& codClient, Abonament* abonament);
    ~Client();

    const std::string& getNumeClient() const;
    const std::string& getCodClient() const;
    const Abonament* getAbonament() const;

    void setAbonament(Abonament* abonament1);

private:
    std::string numeClient;
    const std::string codClient;
    Abonament* abonament;
};

#endif // CLIENT_H_INCLUDED
