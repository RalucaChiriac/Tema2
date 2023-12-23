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

void ManagerClienti::afiseazaMeniu() const
{
    std::cout << "\nMeniu:\n";
    std::cout << "1. Adaugare client (cu abonament)\n";
    std::cout << "2. Stergere client\n";
    std::cout << "3. Listare clienti\n";
    std::cout << "4. Schimbare abonament pentru un client\n";
    std::cout << "5. Statistica privind numarul abonamentelor\n";
    std::cout << "6. Resetare program\n";
    std::cout << "7. Inchidere\n";
    std::cout << "Alegerea dumneavoastra: ";
}

void ManagerClienti::adaugaClient()
{
    std::cout << "Introduceti numele clientului: ";
    std::string numeClient;
    std::cin >> numeClient;

    std::cout << "Introduceti id-ul clientului: ";
    int codClient;
    std::cin >> codClient;

    std::cout << "Introduceti vechimea clientului: ";
    float vechime;
    std::cin >> vechime;

    std::cout << "Alegeti tipul de abonament (1. Simplu / 2. Premium / 3. Student): ";
    int tipAbonament;
    std::cin >> tipAbonament;
    Abonament* abonament = nullptr;

    switch (tipAbonament)
    {
    case 1:
    {
        float bazaSimplu = 13.03F;
        abonament = new AbonamentSimplu(bazaSimplu, codClient);
        break;
    }
    case 2:
    {
        float bazaPremium = 21.56F;
        std::cout << "Doriti Support 24/7 ? Se percepe inca o taxa de 12 lei in plus! Raspuns: DA/NU"<<'\n';
        std::string raspuns;
        std::cin >> raspuns;
        if (raspuns == "DA")
            abonament = new AbonamentPremium(bazaPremium, codClient, true);
        else
            abonament = new AbonamentPremium(bazaPremium, codClient, false);
        break;
    }
    case 3:
    {
        std::cout << "Introduceti numarul Legitimatiei de Student: ( >0 )";
        int numar;
        std::cin >> numar;
        float bazaStudent = 13.0F;
        abonament = new AbonamentStudent(bazaStudent, codClient, numar);
        break;
    }
    default:
        std::cout << "Tip de abonament invalid.\n";
        return;
    }
    abonament->calculeazaPret(vechime);

    Client client = Client(numeClient, codClient, abonament, vechime);
    clienti.push_back(client);
    delete abonament;
    std::cout<<'\n';
    std::cout<<'\n';
    std::cout<<'\n';
    std::cout << "Clientul a fost adaugat cu succes.\n";
}

void ManagerClienti::stergeClient(const std::string& numeClient)
{
    auto it = std::remove_if(clienti.begin(), clienti.end(), [numeClient](const Client& client)
    {
        return client.getNume() == numeClient;
    });

    if (it != clienti.end())
    {

        clienti.erase(it, clienti.end());
        std::cout << "Clientul a fost sters cu succes.\n";
    }
    else
        throw ExceptieClientInexistent();
}


void ManagerClienti::listeazaClienti() const
{
    std::cout << "Lista de clienti:\n";
    for (const auto& client : clienti)
    {
        std::cout << "Nume: " << client.getNume() << ", Cod: " << client.getId() << " , Vechime: "<<client.getVechime() << "\n";
        client.getAbonament()->afisareDetalii();
        std::cout << "\n";
    }
}


Client& ManagerClienti::getterClient(int codClient)
{
    for (auto& client : clienti)
    {
        if (client.getId() == codClient)
        {
            return client;
        }
    }
    throw ExceptieClientInexistent();
}


void ManagerClienti::schimbaAbonament(const std::string& numeClient, int tipAbonament)
{

    for (auto& client : clienti)
    {
        if (client.getNume() == numeClient)
        {
            //delete client.getAbonament();
            //std::cout<<"Debugger"<<std::endl;
            Abonament* abonament = nullptr;
            switch (tipAbonament)
            {
            case 1:
            {
                float bazaSimplu = 13.03F;
                abonament = new AbonamentSimplu(bazaSimplu, client.getId());
                break;
            }

            case 2:
            {
                float bazaPremium = 21.56F;
                std::cout << "Doriti Support 24/7 ? Se percepe inca o taxa de 12 lei in plus! Raspuns: DA/NU"<<'\n';
                std::string raspuns;
                std::cin >> raspuns;
                if (raspuns == "DA")
                    abonament = new AbonamentPremium(bazaPremium, client.getId(), true);
                else
                    abonament = new AbonamentPremium(bazaPremium, client.getId(), false);
                break;
            }
            case 3:
            {
                float bazaStudent = 13.0F;
                std::cout << "Introduceti numarul Legitimatiei de Student: ( >0 )";
                int numar;
                std::cin >> numar;
                abonament = new AbonamentStudent(bazaStudent, client.getId(), numar);
                break;
            }
            default:
                std::cout << "Tip de abonament invalid.\n";
                return;
            }
            abonament->setter_manager(this);
            abonament->calculeazaPret(client.getVechime());
            client.setAbonament(abonament);
            //delete abonament;

            std::cout << "Abonamentul pentru -- " << numeClient << " -- a fost schimbat cu succes.\n";
            return;
        }
    }
    throw ExceptieClientInexistent();
}

void ManagerClienti::reseteazaProgram()
{
    clienti.clear();
    std::cout << "Programul a fost resetat cu succes.\n";
}

std::vector<Client>& ManagerClienti::getterClienti()
{
    return clienti;
}

void ManagerClienti::afiseazaStatistica() const
{
    std::cout<<"   Statistica: "<<"\n";
    std::cout<<"Numar total de abonamente: "<<Abonament::getter_AbonamenteTotale()<<'\n';
    std::cout<<"Numar de abonamente Simple: "<<AbonamentSimplu::getNumarAbonamenteSimplu()<<'\n';
    std::cout<<"Numar de abonamente Premium: "<<AbonamentPremium::getNumarAbonamentePremium()<<'\n';
    std::cout<<"Numar de abonamente de Student: "<<AbonamentStudent::getNumarAbonamenteStudent()<<'\n';
}
