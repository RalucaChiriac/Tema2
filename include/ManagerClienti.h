#ifndef MANAGERCLIENTI_H_INCLUDED
#define MANAGERCLIENTI_H_INCLUDED

#include "Client.h"
#include <vector>

class ManagerClienti {
public:
    // Adaugare client cu abonament
    void adaugaClient();

    // stergere client
    void stergeClient(const std::string& numeClient);

    // Listare clienti
    void listeazaClienti() const;

    // Schimbare abonament pentru un client
    void schimbaAbonament(const std::string& numeClient, int tipAbonament, float pretAbonament);

    // Resetare program
    void reseteazaProgram();

private:
    std::vector<Client*> clienti;
};

#endif // MANAGERCLIENTI_H_INCLUDED
