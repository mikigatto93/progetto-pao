#ifndef PREVENTIVO_H
#define PREVENTIVO_H

#include <QString>
#include <QDate>
#include <QJsonObject>
#include "slist.h"
#include "serramento.h"
#include "deepprt.h"

class Preventivo
{
private:
    double totale;
    QString commessa;
    QDate data;

    SList<DeepPtr<Serramento>> prodotti;
    SList<unsigned int> quantita;
    void calcola_tot();

public:

    void Serialize(QJsonObject&) const;

    Preventivo(QString, QDate);

    double getTotale() const;
    void setTotale(double newTotale);

    QString getCommessa() const;
    void setCommessa(QString newCommessa);

    QDate getData() const;
    void setData(QDate newData);

    unsigned int getNumeroProdotti() const;

    const SList<DeepPtr<Serramento>> getProdotti() const;
    const SList<int> getQuantita() const;

    std::pair<Serramento*, unsigned int> getArticolo(unsigned int) const;

    void aggiungiArticolo(Serramento*, unsigned int);

    bool rimuoviArticolo(unsigned int);

    bool scambiaPosizione(unsigned int, unsigned int);

};

#endif // PREVENTIVO_H
