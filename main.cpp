#include "include/ManagerClienti.h"
#include "src/ManagerClienti.cpp"
#include "include/AbonamentSimplu.h"
#include "include/AbonamentPremium.h"
#include "include/AbonamentStudent.h"

int main()
{
    ManagerClienti manager;

    int optiune;
    do
    {
        manager.afiseazaMeniu();
        std::cin >> optiune;
        if (optiune<1 || optiune > 7)
        {
            std::cout<<"Introduceti va rugam o optiune valida!"<<std::endl;
            exit(-1);
        }
        for (int i=0; i<10; i++)
            std::cout<<std::endl;

        switch (optiune)
        {
        case 1:
        {
            try
            {
                manager.adaugaClient();
                break;
            }
            catch (const ExceptieGenerala& e)
            {
                std::cerr << "\n\nEroare: " << e.what() << std::endl;
                break;
            }
        }

        case 2:
        {
            try
            {
                std::cout << "Introduceti numele clientului de sters: ";
                std::string numeClient;
                std::cin >> numeClient;
                manager.stergeClient(numeClient);
                break;
            }
            catch (const ExceptieGenerala& e)
            {
                std::cerr << "\n\nEroare: " << e.what() << std::endl;
                break;
            }
        }

        case 3:
            manager.listeazaClienti();
            break;

        case 4:
        {
            try
            {
                std::cout << "Introduceti numele clientului pentru schimbare abonament: ";
                std::string numeClient;
                std::cin >> numeClient;

                std::cout << "Alegeti tipul de abonament (1. Simplu / 2. Premium / 3. Student): ";
                int tipAbonament;
                std::cin >> tipAbonament;

                manager.schimbaAbonament(numeClient, tipAbonament);
                break;
            }
            catch (const ExceptieGenerala& e)
            {
                std::cerr << "\n\nEroare: " << e.what() << std::endl;
                break;
            }
        }

        case 5:
        {
            manager.afiseazaStatistica();
            break;
        }

        case 6:
            manager.reseteazaProgram();
            break;
        case 7:
            std::cout << "Programul se inchide.\n";
            break;

        default:
            std::cout << "Optiune invalida. Va rugam alegeti o optiune valida.\n";
            break;
        }

        for (int i=0; i<10; i++)
            std::cout<<std::endl;

    }
    while (optiune != 7);

    return 0;
}
