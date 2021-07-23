#ifndef MODEL_H
#define MODEL_H

#include <map>
#include <QString>
#include "slist.h"
#include "deepprt.h"
#include "legno.h"
#include "vetro.h"
#include "serramento.h"
#include "finestra.h"
#include "preventivo.h"


class Model
{
public:
    Model();
    void setPreventivoCorrente(Preventivo*);
    void serializePreventivo(QJsonObject&);



    unsigned int getNumeroProdotti() const;
    double getTotalePreventivoFinale() const;
    QString getCommessaPreventivo() const;
    void setCommessaPreventivo(QString);
    QDate getDataPreventivo() const;
    void setDataPreventivo(QDate);
    void setScontoPreventivo(double);
    double getScontoPreventivo() const;

    void aggiungiArticoloPreventivo(Serramento*, unsigned int);
    bool rimuoviArticoloPreventivo(unsigned int);
    bool scambiaPosizioneArticoloPreventivo(unsigned int, unsigned int);

    std::pair<Serramento*, unsigned int> getArticoloPreventivo(unsigned int) const;

    bool modificaArticoloPreventivo(unsigned int, Serramento*, unsigned int);



private:
    Preventivo* preventivo;
    double sconto_preventivo;
};

#endif // MODEL_H
