#include "vetro.h"

Vetro::Vetro(double coeff, double pb, QString mod, Canalina can, Categoria cat, Gas g, bool as):
            Materiale(coeff, pb), modello(mod), canalina(can),
            categoria(cat), gas_interno(g), antisfondamento(as) {}


QString Vetro::getModello() const {
    return modello;
}
Vetro::Canalina Vetro::getCanalina() const {
    return canalina;
}
Vetro::Categoria Vetro::getCategoria() const {
    return categoria;
}
bool Vetro::isAntisfondamento() const {
    return antisfondamento;
}

void Vetro::setModello(QString mod) {
    modello = mod;
}
void Vetro::setCanalina(Canalina can) {
    canalina = can;
}
void Vetro::setCategoria(Categoria cat) {
    categoria = cat;
}
void Vetro::setAntisfondamento(bool as) {
    antisfondamento = as;
}

void Vetro::setGasInterno(Gas g) {
    gas_interno = g;
}

Vetro::Gas Vetro::getGasInterno() const {
    return gas_interno;
}

Vetro* Vetro::clone() const {
    return new Vetro(*this);
}

double Vetro::CoeffTermico() const {
    double c = getCoeffTermicoBase();
    //riduzioni rispetto al valore base dovute al gas
    //della camera interna
    if (gas_interno == aria)
        c *= 0.97 ; //-3%
    else if (gas_interno == argon)
        c *= 0.75;
    else //xeno
        c *= 0.73;

    // modifiche dovute alla canalina utilizzata
    if (canalina == alluminio)
        c += 0.11;
    else if (canalina == acciaio)
        c += 0.06;
    else // warm_edge
        c += 0.044;

    return c;
}

double Vetro::Prezzo() const {
    double p = getPrezzoBase();
    //sovrapprezzo gas inerti
    if (gas_interno == xeno)
        p += 3; //-3%
    else if (gas_interno == argon)
        p += 4;

    //sovrapprezzo canaline non standard
    if (canalina == warm_edge)
        p += 3;
    else if (canalina == acciaio)
        p += 2;

    if (categoria == stratificato)
        p += 1.5;
    if (categoria == satinato)
        p += 3;


    return p;
}

void Vetro::Serialize(QJsonObject& json) const {

    json["coeff_termico_base_vetro"] = getCoeffTermicoBase();
    json["prezzo_base_vetro"] = getPrezzoBase();
    json["modello_vetro"] = modello;
    json["canalina_vetro"] = canalina;
    json["categoria_vetro"] = categoria;
    json["gas_interno_vetro"] = gas_interno;
    json["antisfondamento_vetro"] = antisfondamento;


}
