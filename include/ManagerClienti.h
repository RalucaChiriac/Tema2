#ifndef MANAGERCLIENTI_H_INCLUDED
#define MANAGERCLIENTI_H_INCLUDED

#include "Client.h"
#include <vector>

class ManagerClienti : public std::enable_shared_from_this<ManagerClienti>
{
private:
    std::vector<Client> clienti;

public:
    // Adaugare client cu abonament
    void adaugaClient();

    // stergere client
    void stergeClient(const std::string& numeClient);

    // Listare clienti
    void listeazaClienti() const;

    // Schimbare abonament pentru un client
    void schimbaAbonament(const std::string& numeClient, int tipAbonament);

    // Resetare program
    void reseteazaProgram() ;

    // Statistica abonamente
    void afiseazaStatistica() const;

    Client& findClient(int codClient);

    // afiseaza meniul
    void afiseazaMeniu() const;

    ~ManagerClienti()
    {}

    ManagerClienti() {}

};

#endif // MANAGERCLIENTI_H_INCLUDED
