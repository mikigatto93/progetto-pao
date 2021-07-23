#include "legno.h"

Legno::Legno(double coeff, double pb, QString _nome, Durezza d, bool spaz):
    Materiale(coeff, pb), nome(_nome), durezza(d), spazzolatura(spaz) {}

QString Legno::getNome() const {
    return nome;
}
Legno::Durezza Legno::getDurezza() const {
    return durezza;
}
bool Legno::Spazzolato() const {
    return spazzolatura;
}

void Legno::setNome(QString n) {
    nome = n;
}
void Legno::setDurezza(Durezza d) {
    durezza = d;
}
void Legno::setSpazzolato(bool s) {
    spazzolatura = s;
}

Legno* Legno::clone() const {
    return new Legno(*this);
}

double Legno::CoeffTermico() const {
    double ctb = getCoeffTermicoBase();
    if (durezza == tenero)
        ctb = (ctb * 0.85) + 0.2;
    else // duro
        ctb += 0.5;
    return ctb;
}

double Legno::Prezzo() const {
    double pb = getPrezzoBase();
    if (durezza == duro)
        pb += 10.0; //sovrapprezzo legno duro

    if (spazzolatura)
        pb += 25.0; //sovrapprezzo spazzolatura

    return pb;
}

void Legno::Serialize(QJsonObject& json) const {

    json["coeff_termico_base_legno"] = getCoeffTermicoBase();
    json["prezzo_base_legno"] = getPrezzoBase();
    json["nome_legno"] = nome;
    json["durezza_legno"] = durezza;
    json["spazzolatura_legno"] = spazzolatura;

}

