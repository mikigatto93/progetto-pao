#ifndef MATERIALE_H
#define MATERIALE_H

#include "baseitem.h"

class Materiale : public BaseItem
{
public:
    Materiale(double, double);

    virtual double CoeffTermico() const = 0;
    virtual double Prezzo() const = 0;

    double getPrezzoBase() const;
    double getCoeffTermicoBase() const;

    void setPrezzoBase(double);
    void setCoeffTermicoBase(double);


private:
    double coeff_termico_base, prezzo_base;
};

#endif // MATERIALE_H
