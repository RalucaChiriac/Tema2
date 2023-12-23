#ifndef ABONAMENTSTUDENT_H_INCLUDED
#define ABONAMENTSTUDENT_H_INCLUDED

#include "Abonament.h"

class AbonamentStudent : public Abonament {
private:
    int numarLegitimatie;
    static int numarAbonamenteStudent;

public:
    AbonamentStudent(float baza, int idClient, int numarLegitimatie);
    AbonamentStudent(const AbonamentStudent& other);
    AbonamentStudent& operator=(const AbonamentStudent& other);
    ~AbonamentStudent() override;

    void afisareDetalii() const override;
    void calculeazaPret(float vechime) override;
    void afisareTip() const override;
    Abonament* clone() const override;

    static int getNumarAbonamenteStudent();


};


#endif // ABONAMENTSTUDENT_H_INCLUDED
