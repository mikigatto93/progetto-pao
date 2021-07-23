#include "porta.h"

Porta::Porta(unsigned int w, unsigned int h, double p,
             QString ci, QString ce, QString apert,
             double coeff_legno, double pb_legno, QString nome_legno,
             Legno::Durezza d_legno, bool spaz_legno,
             double sp,  ModoApertura ma, Serratura ser, Cerniera cer):

    Serramento(w, h, p, ci, ce, apert, coeff_legno, pb_legno, nome_legno, d_legno, spaz_legno),
    spessore(sp), modo_apertura(ma),
    tipologia_serratura(ser), tipologia_cerniera(cer) {}


Porta::Porta(const Porta& p):Serramento(p) {
     spessore = p.spessore;
     modo_apertura = p.modo_apertura;
     tipologia_serratura = p.tipologia_serratura;
     tipologia_cerniera = p.tipologia_cerniera;
}

Porta& Porta::operator=(const Porta& p) {
    if (this != &p) {
        Serramento::operator=(p);
        spessore = p.spessore;
        modo_apertura = p.modo_apertura;
        tipologia_serratura = p.tipologia_serratura;
        tipologia_cerniera = p.tipologia_cerniera;
    }
    return *this;
}

double Porta::getSpessore() const {
    return spessore;
}
Porta::ModoApertura Porta::getModoApertura() const {
    return modo_apertura;
}
Porta::Serratura Porta::getTipologiaSerratura() const {
    return tipologia_serratura;
}
Porta::Cerniera Porta::getTipologiaCerniere() const {
    return tipologia_cerniera;
}

void Porta::getSpessore(double sp) {
    spessore = sp;
}
void Porta::getModoApertura(ModoApertura ma) {
    modo_apertura = ma;
}
void Porta::getTipologiaSerratura(Serratura ts) {
    tipologia_serratura = ts;
}
void Porta::getTipologiaCerniere(Cerniera c) {
    tipologia_cerniera = c;
}

double Porta::TrasmittanzaTermica() const {
    double c = getTipologiaLegno()->CoeffTermico();

    if (spessore > 40)
        c *= 0.90;

    if (modo_apertura == scorrevole)
        c = c * 0.93 - 0.12;

    return c;
}

double Porta::MetriQuadri() const {
    double r = getAltezza() * getLarghezza();
    r = r / 1000000.0;
    return (r < 1.5 ?  1.5 : r);
}

Porta* Porta::clone() const {
    return new Porta(*this);
}

double Porta::PrezzoFinale() const {
    double p_base = getPrezzoBase();
    p_base += getTipologiaLegno()->Prezzo();

    if (modo_apertura == scorrevole)
        p_base += 60;

    if (tipologia_serratura == standard)
        p_base += 15;
    else if (tipologia_serratura == magnetica)
        p_base += 20;

    if (tipologia_cerniera == scomparsa)
        p_base += 30;
    //anuba e battente sono le sclte standard e non comportano variazioni di prezzo

    if (getColoreEsterno() != getColoreEsterno())
        p_base += 40;

    if (spessore > 40) //porta non standard
        p_base += 25;

    return MetriQuadri() * p_base;
}

void Porta::Serialize(QJsonObject& json) const {
    json["id"] = "porta";
    json["w"] = static_cast<int>(getLarghezza());
    json["h"] = static_cast<int>(getAltezza());
    json["prezzo_base"] = getPrezzoBase();
    json["colore_interno"] = getColoreInterno();
    json["colore_esterno"] = getColoreEsterno();
    json["apertura"] = getApertura();
    getTipologiaLegno()->Serialize(json);
    json["spessore"] = spessore;
    json["modo_apertura"] = modo_apertura;
    json["tipologia_serratura"] = tipologia_serratura;
    json["tipologia_cerniera"] = tipologia_cerniera;
}

QString Porta::NomeProdotto() const {
    return "PORTA";
}

