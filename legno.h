#ifndef LEGNO_H
#define LEGNO_H

#include "materiale.h"
#include <QString>

class Legno : public Materiale
{
public:
    enum Durezza {
        tenero=0,  duro
    };

    Legno(double, double,
          QString, Durezza, bool);

    QString getNome() const;
    Durezza getDurezza() const;
    bool Spazzolato() const;

    void setNome(QString);
    void setDurezza(Durezza);
    void setSpazzolato(bool);
    Legno* clone() const override;
    void Serialize(QJsonObject&) const override;
    double CoeffTermico() const override;
    double Prezzo() const override;

private:
    QString nome;
    Durezza durezza;
    bool spazzolatura;

};

#endif // LEGNO_H
