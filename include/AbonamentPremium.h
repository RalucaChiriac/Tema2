#ifndef ABONAMENTPREMIUM_H_INCLUDED
#define ABONAMENTPREMIUM_H_INCLUDED

#include "Abonament.h"

class AbonamentPremium : public Abonament {
public:
    AbonamentPremium(const std::string& numeClient, const std::string& codClient, float pret);
    AbonamentPremium(const AbonamentPremium& other);
    AbonamentPremium& operator=(const AbonamentPremium& other);
    ~AbonamentPremium() override;

    void afisareDetalii() const override;
    void calculeazaPret() const override;
    Abonament* clone() const override;
    static int getNumarAbonamentePremium();

private:
    float pret;
    static int numarAbonamentePremium;
};

#endif // ABONAMENTPREMIUM_H_INCLUDED
