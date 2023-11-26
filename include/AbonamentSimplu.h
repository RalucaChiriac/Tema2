#ifndef ABONAMENTSIMPLU_H_INCLUDED
#define ABONAMENTSIMPLU_H_INCLUDED

#include "Abonament.h"

class AbonamentSimplu : public Abonament {
public:
    AbonamentSimplu(const std::string& numeClient, const std::string& codClient, float pret);
    AbonamentSimplu(const AbonamentSimplu& other);
    AbonamentSimplu& operator=(const AbonamentSimplu& other);
    ~AbonamentSimplu() override;

    void afisareDetalii() const override;
    void calculeazaPret() const override;
    Abonament* clone() const override;
    static void functieStaticaSimpla();
    static int getNumarAbonamenteSimplu();

private:
    float pret;
    static int numarAbonamenteSimplu;
};

#endif // ABONAMENTSIMPLU_H_INCLUDED
