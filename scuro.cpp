#include "scuro.h"


Scuro::Scuro(unsigned int w, unsigned int h, double p,
             QString ci, QString ce,  QString apert, double coeff_legno, double pb_legno, QString nome_legno,
             Legno::Durezza d_legno, bool spaz_legno,
             unsigned int n, Finiture fe, Finiture fi):
    Serramento(w, h, p, ci, ce, apert, coeff_legno, pb_legno, nome_legno, d_legno, spaz_legno),
    num_ante(n), finiture_esterne(fe),
    finiture_interne(fi) {}


Scuro::Scuro(const Scuro& s): Serramento(s) {
    num_ante = s.num_ante;
    finiture_esterne = s.finiture_esterne;
    finiture_interne = s.finiture_interne;
}

Scuro& Scuro::operator=(const Scuro& s) {
    if (this != &s) {
        Serramento::operator=(s);
        num_ante = s.num_ante;
        finiture_esterne = s.finiture_esterne;
        finiture_interne = s.finiture_interne;

    }

    return *this;
}

unsigned int Scuro::getNumeroAnte() const {
    return num_ante;
}

Scuro::Finiture Scuro::getFinitureEsterne() const {
    return finiture_esterne;
}

Scuro::Finiture Scuro::getFinitureInterne() const {
    return finiture_interne;
}

void Scuro::setNumeroAnte(unsigned int n) {
    num_ante = n;
}

void Scuro::setFinitureEsterne(Finiture f) {
    finiture_esterne = f;
}

void Scuro::setFinitureInterne(Finiture f) {
    finiture_interne = f;
}

double Scuro::TrasmittanzaTermica() const {
    return 0.55 * getTipologiaLegno()->CoeffTermico() + 0.1;
}

double Scuro::MetriQuadri() const {
    double r = getAltezza() * getLarghezza();
    r = r / 1000000.0;
    return (r < 1.5 ?  1.5 : r);
}

Scuro* Scuro::clone() const {
    return new Scuro(*this);
}

double Scuro::PrezzoFinale() const {
    double p_base = getPrezzoBase();
    double mq = MetriQuadri();
    p_base += getTipologiaLegno()->Prezzo();

    if (finiture_esterne == fughe_orizzontali ||
        finiture_esterne == fughe_verticali)
        p_base += 10;

    if (finiture_interne == fughe_verticali ||
        finiture_interne == fughe_orizzontali)
        p_base += 10;

    if (finiture_esterne != finiture_interne &&
        finiture_esterne != non_presenti && finiture_interne != non_presenti)
        p_base += 5;

    if (getColoreEsterno() != getColoreEsterno())
        p_base += 30;


    return p_base * mq;
}


void Scuro::Serialize(QJsonObject& json) const {
    json["id"] = "scuro";
    json["w"] = static_cast<int>(getLarghezza());
    json["h"] = static_cast<int>(getAltezza());
    json["prezzo_base"] = getPrezzoBase();
    json["colore_interno"] = getColoreInterno();
    json["colore_esterno"] = getColoreEsterno();
    json["apertura"] = getApertura();
    getTipologiaLegno()->Serialize(json);
    json["num_ante"] = static_cast<int>(num_ante);
    json["finiture_esterne"] = finiture_esterne;
    json["finiture_interne"] = finiture_interne;


}

QString Scuro::NomeProdotto() const {
    return "SCURO";
}
