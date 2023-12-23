#ifndef ABONAMENTPREMIUM_H_INCLUDED
#define ABONAMENTPREMIUM_H_INCLUDED

#include "Abonament.h"

class AbonamentPremium : public Abonament {
private:
    bool serviciuSupport;
    static int numarAbonamentePremium;

protected:
    void afisareTip() const override;

public:
    AbonamentPremium(float baza, int idClient, bool serviciuSupport);
    AbonamentPremium(const AbonamentPremium& other);
    AbonamentPremium& operator=(const AbonamentPremium& other);
    ~AbonamentPremium() override;

    void afisareDetalii() const override;
    void calculeazaPret(float vechime) override;
    Abonament* clone() const override;

    static int getNumarAbonamentePremium();


};

#endif // ABONAMENTPREMIUM_H_INCLUDED
