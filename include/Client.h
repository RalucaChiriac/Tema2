#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include <string>
#include "Abonament.h"

class Client {
private:
    std::string nume;
    const int codClient;
    float vechime;
    Abonament* abonament;

public:
    Client(const std::string& nume, int codClient, Abonament* abonament, float vechime);
    Client(const Client& other);
    Client& operator=(const Client& other);
    ~Client();

    friend std::ostream& operator<<(std::ostream& os, const Client& st) {
        os << "Nume: " << st.getNume() << ", Cod: " << st.getId() << " , Vechime: "<<st.getVechime() << "\n";
        os <<*st.abonament;
        return os;
    }

    void setAbonament(Abonament* abon);
    float getVechime() const;
    std::string getNume() const;
    int getId() const;
};

#endif // CLIENT_H_INCLUDED
