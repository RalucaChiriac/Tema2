#include <fstream>
#include <iostream>
#include "include/ManagerClienti.h"
#include "include/MyExceptions.h"

int main()
{
    auto manager = std::make_shared<ManagerClienti>();

    // Open the file for reading
    std::ifstream inputFile("tastatura.txt");

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file 'tastatura.txt'" << std::endl;
        return 1;
    }

    int optiune;

    do
    {
        manager->afiseazaMeniu();
        // Read from the file instead of std::cin
        inputFile >> optiune;

        for (int i = 0; i < 10; i++)
            std::cout << std::endl;

        try
        {
            if (inputFile.fail())
            {
                inputFile.clear();
                inputFile.ignore(10000, '\n'); // Use a large number as the limit

                std::cout << "Va rugam introduceti un numar valabil!" << std::endl;
                continue;
            }

            if (optiune < 1 || optiune > 7)
            {
                std::cout << "Introduceti va rugam o optiune valida!" << std::endl;
                continue;
            }

            switch (optiune)
            {
            case 1:
            {
                manager->adaugaClient();
                break;
            }

            case 2:
            {
                std::cout << "Introduceti numele clientului de sters: ";
                std::string numeClient;
                inputFile >> numeClient;
                manager->stergeClient(numeClient);
                break;
            }

            case 3:
                manager->listeazaClienti();
                break;

            case 4:
            {
                std::cout << "Introduceti numele clientului pentru schimbare abonament: ";
                std::string numeClient;
                inputFile >> numeClient;

                std::cout << "Alegeti tipul de abonament (1. Simplu / 2. Premium / 3. Student): ";
                int tipAbonament;
                inputFile >> tipAbonament;

                manager->schimbaAbonament(numeClient, tipAbonament);
                break;
            }

            case 5:
            {
                manager->afiseazaStatistica();
                break;
            }

            case 6:
                manager->reseteazaProgram();
                break;

            case 7:
                std::cout << "Programul se inchide.\n";
                break;

            default:
                std::cout << "Optiune invalida. Va rugam alegeti o optiune valida.\n";
                break;
            }

        }
        catch (const ExceptieGenerala &e)
        {
            std::cerr << "\n\nEroare: " << e.what() << std::endl;
            continue;
        }

        for (int i = 0; i < 10; i++)
            std::cout << std::endl;

    } while (optiune != 7);

    // Close the file
    inputFile.close();

    return 0;
}
