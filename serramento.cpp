#include "serramento.h"

Serramento::Serramento( unsigned int w, unsigned int h, double p,
                   QString ci, QString ce, QString apert,
                        double coeff_legno, double pb_legno, QString nome_legno,
                        Legno::Durezza d_legno, bool spaz_legno):
    BaseItem(), altezza(h), larghezza(w), prezzo_base(p),
    colore_interno(ci), colore_esterno(ce), apertura(apert),
    tipologia_legno(new Legno(coeff_legno, pb_legno, nome_legno, d_legno, spaz_legno))
{}

Serramento::~Serramento() {
    delete tipologia_legno;
}

Serramento::Serramento(const Serramento& s) {

    altezza = s.altezza;
    larghezza = s.larghezza;
    prezzo_base = s.prezzo_base;
    colore_interno = s.colore_interno;
    colore_esterno = s.colore_esterno;
    apertura = s.apertura;
    tipologia_legno = s.getTipologiaLegno()->clone();
}

Serramento& Serramento::operator=(const Serramento& s) {

    if (this != &s) {
        delete tipologia_legno;
        tipologia_legno = s.getTipologiaLegno()->clone();
        altezza = s.altezza;
        larghezza = s.larghezza;
        prezzo_base = s.prezzo_base;
        colore_interno = s.colore_interno;
        colore_esterno = s.colore_esterno;
        apertura = s.apertura;
    }
    return *this;

}

unsigned int Serramento::getAltezza() const {
    return altezza;
}

unsigned int Serramento::getLarghezza() const {
    return larghezza;
}

double Serramento::getPrezzoBase() const {
    return prezzo_base;
}


void Serramento::setAltezza(unsigned int h) {
    altezza = h;
}

void Serramento::setLarghezza(unsigned int w) {
    larghezza = w;
}

void Serramento::setPrezzoBase(double p) {
    prezzo_base = p;
}


QString Serramento::getColoreInterno() const {
    return colore_interno;
}

QString Serramento::getColoreEsterno() const {
    return colore_esterno;
}


Legno* Serramento::getTipologiaLegno() const {
    return tipologia_legno;
}

QString Serramento::getApertura() const {
    return apertura;
}

void Serramento::setColoreInterno(QString s) {
    colore_interno = s;
}

void Serramento::setColoreEsterno(QString s) {
    colore_esterno = s;
}


void Serramento::setTipologiaLegno(Legno* l) {
    delete tipologia_legno;
    tipologia_legno = l;
}

void Serramento::setApertura(QString s) {
    apertura = s;
}
