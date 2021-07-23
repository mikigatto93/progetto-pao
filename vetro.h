#ifndef VETRO_H
#define VETRO_H

#include "materiale.h"
#include <QString>

class Vetro : public Materiale
{
public:
    enum Canalina {
        alluminio, acciaio, warm_edge
    };

    enum Categoria {
        temperato, stratificato, satinato
    };

    enum Gas {
        aria, argon, xeno
    };

    Vetro(double, double,
          QString, Canalina, Categoria, Gas, bool);

    QString getModello() const;
    Canalina getCanalina() const;
    Categoria getCategoria() const;
    Gas getGasInterno() const;
    bool isAntisfondamento() const;


    void setModello(QString);
    void setCanalina(Canalina);
    void setCategoria(Categoria);
    void setGasInterno(Gas);
    void setAntisfondamento(bool);


    Vetro* clone() const override;
    void Serialize(QJsonObject&) const override;
    double CoeffTermico() const override;
    double Prezzo() const override;

private:
    QString modello;
    Canalina canalina;
    Categoria categoria;
    Gas gas_interno;
    bool antisfondamento;

};

#endif // VETRO_H
