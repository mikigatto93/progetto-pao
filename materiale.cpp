#include "materiale.h"

Materiale::Materiale(double coeff, double pb): coeff_termico_base(coeff), prezzo_base(pb) {}

double Materiale::getPrezzoBase() const {
    return prezzo_base;
}
double Materiale::getCoeffTermicoBase() const {
    return coeff_termico_base;
}

void Materiale::setPrezzoBase(double pb) {
    prezzo_base = pb;
}
void Materiale::setCoeffTermicoBase(double ct) {
    coeff_termico_base = ct;
}

