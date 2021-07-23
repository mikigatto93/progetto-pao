#include "preventivo.h"

Preventivo::Preventivo(QString _commessa, QDate _data):
    commessa(_commessa), data(_data) {
    calcola_tot();
}

void Preventivo::calcola_tot() {
    double somma = 0.0;
    auto itp = prodotti.begin();
    auto itq = quantita.begin();

    while (itp != prodotti.end() && itq != quantita.end()) {
        somma += (*itp)->PrezzoFinale() * (*itq);
        ++itp;
        ++itq;
    }

    totale = somma;
}

double Preventivo::getTotale() const
{
    return totale;
}

void Preventivo::setTotale(double newTotale)
{
    totale = newTotale;
}

QString Preventivo::getCommessa() const
{
    return commessa;
}

unsigned int Preventivo::getNumeroProdotti() const {
    return prodotti.Size();
}

void Preventivo::setCommessa(QString newCommessa)
{
    commessa = newCommessa;
}

QDate Preventivo::getData() const
{
    return data;
}

void Preventivo::setData(QDate newData)
{
    data = newData;
}

const SList<DeepPtr<Serramento>> Preventivo::getProdotti() const {
    return prodotti;
}

void Preventivo::aggiungiArticolo(Serramento* p, unsigned int q) {
    prodotti.pushBack(DeepPtr<Serramento>(p));
    quantita.pushBack(q);
    calcola_tot();

}

std::pair<Serramento*, unsigned int> Preventivo::getArticolo(unsigned int i) const {
    if (i < getNumeroProdotti()) {
        return std::pair<Serramento*, unsigned int>(
                    (prodotti.get(i)).get(),
                    quantita.get(i));
    } else {
        return std::pair<Serramento*, unsigned int>(nullptr, 0);
    }
}

bool Preventivo::rimuoviArticolo(unsigned int i) {
    bool ris1 = prodotti.RemoveAt(i),
         ris2 = quantita.RemoveAt(i);
    if (ris1 && ris2) calcola_tot();

    return ris1 && ris2;
}

bool Preventivo::scambiaPosizione(unsigned int i, unsigned int j) {
    return prodotti.Swap(i, j) && quantita.Swap(i, j);
}

void Preventivo::Serialize(QJsonObject& json) const {
    //https://doc.qt.io/qt-5/qjsonobject.html#QJsonObject-1
    json["dati_preventivo"] = QJsonObject{
        {"commessa", commessa},
        {"data", data.toJulianDay()},
        {"num_articoli", static_cast<int>(getNumeroProdotti())}
    };

    auto itp = prodotti.begin();
    auto itq = quantita.begin();
    int i = 0;

    while (itp != prodotti.end() && itq != quantita.end()) {
        QJsonObject articolo;

        (*itp)->Serialize(articolo);

        articolo["quantita"] = static_cast<int>(*itq);

        json[QString::number(i)] = articolo;

        ++itp;
        ++itq;
        ++i;
    }
}

