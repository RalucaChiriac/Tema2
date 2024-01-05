#include "include/ManagerClienti.h"
#include "src/ManagerClienti.cpp"
#include "include/AbonamentSimplu.h"
#include "include/AbonamentPremium.h"
#include "include/AbonamentStudent.h"
#include <limits>

int main()
{
    ManagerClienti manager;

    int optiune;
    do
    {
        manager.afiseazaMeniu();
        std::cin >> optiune;


        for (int i=0; i<10; i++)
            std::cout<<std::endl;

        try
        {
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Va rugam introduceti un numar valabil!" << std::endl;
                continue;
            }
            if (optiune<1 || optiune > 7)
            {
                std::cout<<"Introduceti va rugam o optiune valida!"<<std::endl;
                continue;
            }

            switch (optiune)
            {
            case 1:
            {
                manager.adaugaClient();
                break;
            }

            case 2:
            {
                std::cout << "Introduceti numele clientului de sters: ";
                std::string numeClient;
                std::cin >> numeClient;
                manager.stergeClient(numeClient);
                break;
            }

            case 3:
                manager.listeazaClienti();
                break;

            case 4:
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
        }
        catch (const ExceptieGenerala& e)
        {
            std::cerr << "\n\nEroare: " << e.what() << std::endl;
            continue;
        }

        for (int i=0; i<10; i++)
            std::cout<<std::endl;

    }
    while (optiune != 7);

    return 0;
}
