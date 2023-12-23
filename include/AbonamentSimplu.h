#ifndef ABONAMENTSIMPLU_H_INCLUDED
#define ABONAMENTSIMPLU_H_INCLUDED

#include "Abonament.h"

class AbonamentSimplu : public Abonament {
private:
    static int numarAbonamenteSimplu;

public:
    AbonamentSimplu(float baza, int idClient);
    AbonamentSimplu(const AbonamentSimplu& other);
    AbonamentSimplu& operator=(const AbonamentSimplu& other);
    ~AbonamentSimplu() override;

    void afisareDetalii() const override;
    void afisareTip() const override;
    void calculeazaPret(float vechime) override;
    Abonament* clone() const override;
    static int getNumarAbonamenteSimplu();


};

#endif // ABONAMENTSIMPLU_H_INCLUDED
