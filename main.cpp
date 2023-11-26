#include "include/ManagerClienti.h"
#include "src/ManagerClienti.cpp"
#include "include/AbonamentSimplu.h"
#include "include/AbonamentPremium.h"
#include "include/AbonamentStudent.h"

int main() {
    ManagerClienti manager;

    int optiune;
    do {
        std::cout << "\nMeniu:\n";
        std::cout << "1. Adaugare client (cu abonament)\n";
        std::cout << "2. Stergere client\n";
        std::cout << "3. Listare clienti\n";
        std::cout << "4. Schimbare abonament pentru un client\n";
        std::cout << "5. Resetare program\n";
        std::cout << "6. Inchidere\n";
        std::cout << "Alegerea dumneavoastra: ";
        std::cin >> optiune;

        switch (optiune) {
            case 1:
                manager.adaugaClient();
                break;
            case 2: {
                std::cout << "Introduceti numele clientului de sters: ";
                std::string numeClient;
                std::cin >> numeClient;
                manager.stergeClient(numeClient);
                break;
            }
            case 3:
                manager.listeazaClienti();
                break;
            case 4: {
                std::cout << "Introduceti numele clientului pentru schimbare abonament: ";
                std::string numeClient;
                std::cin >> numeClient;

                std::cout << "Alegeti tipul de abonament (1. Simplu / 2. Premium / 3. Student): ";
                int tipAbonament;
                std::cin >> tipAbonament;

                float pretAbonament;
                std::cout << "Introduceti pretul abonamentului: ";
                std::cin >> pretAbonament;

                manager.schimbaAbonament(numeClient, tipAbonament, pretAbonament);
                break;
            }
            case 5:
                manager.reseteazaProgram();
                break;
            case 6:
                std::cout << "Programul se inchide.\n";
                break;
            default:
                std::cout << "Optiune invalida. Va rugam alegeti o optiune valida.\n";
                break;
        }

    } while (optiune != 6);

    return 0;
}
