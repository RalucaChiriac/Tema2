#include "../include/ManagerClienti.h"
#include "../include/Abonament.h"
#include "../include/AbonamentPremium.h"
#include "../include/AbonamentSimplu.h"
#include "../include/AbonamentStudent.h"
#include "../include/Client.h"
#include "AbonamentSimplu.cpp"
#include "AbonamentStudent.cpp"
#include "AbonamentPremium.cpp"
#include "Client.cpp"
#include "../include/MyExceptions.h"
#include <iostream>
#include <algorithm>

void ManagerClienti::adaugaClient()
{
    std::cout << "Introduceti numele clientului: ";
    std::string numeClient;
    std::cin >> numeClient;

    std::cout << "Introduceti codul clientului: ";
    std::string codClient;
    std::cin >> codClient;

    std::cout << "Alegeti tipul de abonament (1. Simplu / 2. Premium / 3. Student): ";
    int tipAbonament;
    std::cin >> tipAbonament;

    Abonament* abonament = nullptr;
    float pretAbonament;

    switch (tipAbonament) {
        case 1:
            std::cout << "Introduceti pretul abonamentului simplu: ";
            std::cin >> pretAbonament;
            abonament = new AbonamentSimplu(numeClient, codClient, pretAbonament);
            break;
        case 2:
            std::cout << "Introduceti pretul abonamentului premium: ";
            std::cin >> pretAbonament;
            abonament = new AbonamentPremium(numeClient, codClient, pretAbonament);
            break;
        case 3:
            std::cout << "Introduceti pretul abonamentului de student: ";
            std::cin >> pretAbonament;
            abonament = new AbonamentStudent(numeClient, codClient, pretAbonament);
            break;
        default:
            std::cout << "Tip de abonament invalid.\n";
            return;
    }

    Client* client = new Client(numeClient, codClient, abonament);
    clienti.push_back(client);
    std::cout << "Clientul a fost adaugat cu succes.\n";
}

void ManagerClienti::stergeClient(const std::string& numeClient) {
    auto it = std::remove_if(clienti.begin(), clienti.end(), [numeClient](const Client* client) {
        return client->getNumeClient() == numeClient;
    });

    if (it != clienti.end()) {
        delete *it; // Eliberăm memoria alocată pentru client
        clienti.erase(it, clienti.end());
        std::cout << "Clientul a fost sters cu succes.\n";
    } else {
        std::cout << "Clientul nu a fost gasit.\n";
    }
}

void ManagerClienti::listeazaClienti() const {
    std::cout << "Lista de clienti:\n";
    for (const auto& client : clienti) {
        std::cout << "Nume: " << client->getNumeClient() << ", Cod: " << client->getCodClient() << "\n";
        client->getAbonament()->afisareDetalii();
        std::cout << "\n";
    }
}

void ManagerClienti::schimbaAbonament(const std::string& numeClient, int tipAbonament, float pretAbonament) {
    for (auto& client : clienti) {
        if (client->getNumeClient() == numeClient) {
            delete client->getAbonament(); // Eliberăm memoria alocată pentru abonamentul existent

            Abonament* abonament = nullptr;
            switch (tipAbonament) {
                case 1:
                    abonament = new AbonamentSimplu(numeClient, client->getCodClient(), pretAbonament);
                    break;
                case 2:
                    abonament = new AbonamentPremium(numeClient, client->getCodClient(), pretAbonament);
                    break;
                case 3:
                    abonament = new AbonamentStudent(numeClient, client->getCodClient(), pretAbonament);
                    break;
                default:
                    std::cout << "Tip de abonament invalid.\n";
                    return;
            }

            client->setAbonament(abonament);
            std::cout << "Abonamentul pentru " << numeClient << " a fost schimbat cu succes.\n";
            return;
        }
    }
    std::cout << "Clientul nu a fost gasit.\n";
}

void ManagerClienti::reseteazaProgram() {
    for (const auto& client : clienti) {
        delete client; // Eliberăm memoria alocată pentru fiecare client
    }
    clienti.clear();
    std::cout << "Programul a fost resetat cu succes.\n";
}
