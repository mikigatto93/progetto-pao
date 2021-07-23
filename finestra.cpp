#include "finestra.h"

Finestra::Finestra(unsigned int w, unsigned int h, double p,
                   QString ci, QString ce, QString apert,  double coeff_legno, double pb_legno, QString nome_legno,
                   Legno::Durezza d_legno, bool spaz_legno,
                   unsigned int n, unsigned int st, bool r, ChiusureEsterne ch,
                   double coeff_vetro, double pb_vetro, QString mod_vetro,
                   Vetro::Canalina can_vetro, Vetro::Categoria cat_vetro, Vetro::Gas gas_vetro, bool antisf_vetro):
    Serramento(w, h, p, ci, ce, apert, coeff_legno, pb_legno, nome_legno, d_legno, spaz_legno),
          num_ante(n), spessore_telaio(st),
          ribalta(r), chiusure(ch),
          tipologia_vetro(new Vetro(coeff_vetro, pb_vetro, mod_vetro, can_vetro, cat_vetro, gas_vetro, antisf_vetro))
            {}

Finestra::~Finestra() {
    delete tipologia_vetro;
}

Finestra::Finestra(const Finestra& f):Serramento(f) {
    num_ante = f.num_ante;
    spessore_telaio = f.spessore_telaio;
    ribalta = f.ribalta;
    chiusure = f.chiusure;
    tipologia_vetro = f.getTipologiaVetro()->clone();

}

Finestra& Finestra::operator=(const Finestra& f) {
    if (this != &f) {

        Serramento::operator=(f);
        delete tipologia_vetro;
        tipologia_vetro = f.getTipologiaVetro()->clone();
        num_ante = f.num_ante;
        spessore_telaio = f.spessore_telaio;
        ribalta = f.ribalta;
        chiusure = f.chiusure;

    }
    return *this;
}


unsigned int Finestra::getNumAnte() const {
    return num_ante;
}
unsigned int Finestra::getSpessoreTelaio() const {
    return spessore_telaio;
}
bool Finestra::Ribalta() const {
    return ribalta;
}
Finestra::ChiusureEsterne Finestra::getChiusureEsterne() const {
    return chiusure;
}

Vetro* Finestra::getTipologiaVetro() const {
    return tipologia_vetro;
}

bool Finestra::PortaFinestra() const {
    return getAltezza() > 1800;
}

void Finestra::setNumAnte(unsigned int n) {
    num_ante = n;
}

void Finestra::setSpessoreTelaio(unsigned int s) {
    spessore_telaio = s;
}

void Finestra::setRibalta(bool r) {
    ribalta = r;
}

void Finestra::setChiusureEsterne(ChiusureEsterne c) {
    chiusure = c;
}

void Finestra::setTipologiaVetro(Vetro* v) {
    delete tipologia_vetro;
    tipologia_vetro = v;
}



double Finestra::TrasmittanzaTermica() const {
    double ag = 0.7,  //area vetro
           af = 0.3;  //area telaio

    double ug = getTipologiaVetro()->CoeffTermico();
    double uf = getTipologiaLegno()->CoeffTermico();

    if (PortaFinestra()) {
        //cambio le aree in caso si tratti di una portafinestra
        ag = 0.8;
        af = 0.2;
    }

    if (spessore_telaio > 68) {
        ug *= 0.8;
        uf *= 0.8;
    }

    if (chiusure == tapparelle) {
        ug += 0.08;
        uf += 0.08;
    } else if (chiusure == scuri) {
        ug += 0.06;
        uf += 0.06;
    }

    return ag * ug + af * uf;
}

double Finestra::MetriQuadri() const {
    unsigned int w = getLarghezza();
    unsigned int h = getAltezza();

    if (chiusure == scuri) {
        w += 14;
        h += 18;
    } else if (chiusure == tapparelle) {
        w += 10;
        h += 10;
    }

    double r = (w * h) / 1000000.0;

    return (r < 1.5 ? 1.5 : r);
}

Finestra* Finestra::clone() const {
    return new Finestra(*this);
}

double Finestra::PrezzoFinale() const {
    double p_base = getPrezzoBase();
    p_base = p_base + getTipologiaLegno()->Prezzo() + getTipologiaVetro()->Prezzo();

    if (PortaFinestra())
        p_base += 30;
    if (spessore_telaio > 68)
        p_base += 120;
    if (num_ante > 1)
        p_base += 60;

    if (ribalta)
        p_base += 50;

    if (getColoreEsterno() != getColoreInterno())
        p_base += 70;

    return p_base * MetriQuadri();
}

void Finestra::Serialize(QJsonObject& json) const {
    json["id"] = "finestra";
    json["w"] = static_cast<int>(getLarghezza());
    json["h"] = static_cast<int>(getAltezza());
    json["prezzo_base"] = getPrezzoBase();
    json["colore_interno"] = getColoreInterno();
    json["colore_esterno"] = getColoreEsterno();
    json["apertura"] = getApertura();
    getTipologiaLegno()->Serialize(json);
    json["num_ante"] = static_cast<int>(num_ante);
    json["spessore_telaio"] = static_cast<int>(spessore_telaio);
    json["ribalta"] = ribalta;
    json["chiusure"] = chiusure;
    getTipologiaVetro()->Serialize(json);
}

QString Finestra::NomeProdotto() const {
    return (PortaFinestra() ? "PORTAFINESTRA" : "FINESTRA");
}
