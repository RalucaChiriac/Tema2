#ifndef ABONAMENTSTUDENT_H_INCLUDED
#define ABONAMENTSTUDENT_H_INCLUDED

#include "Abonament.h"

class AbonamentStudent : public Abonament {
public:
    AbonamentStudent(const std::string& numeClient, const std::string& codClient, float pret);
    AbonamentStudent(const AbonamentStudent& other);
    AbonamentStudent& operator=(const AbonamentStudent& other);
    ~AbonamentStudent() override;

    void afisareDetalii() const override;
    void calculeazaPret() const override;
    Abonament* clone() const override;
    static int getNumarAbonamenteStudent();

private:
    float pret;
    static int numarAbonamenteStudent;
};


#endif // ABONAMENTSTUDENT_H_INCLUDED
