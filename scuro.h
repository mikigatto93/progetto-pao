#ifndef SCURO_H
#define SCURO_H

#include "serramento.h"
#include <QString>

class Scuro : public Serramento
{
public:
    enum Finiture {
        non_presenti=0, fughe_orizzontali, fughe_verticali
    };

    Scuro(unsigned int, unsigned int, double, QString, QString, QString,
          double, double, QString, Legno::Durezza, bool,
          unsigned int, Finiture, Finiture );
    ~Scuro() = default;
    Scuro(const Scuro&);
    Scuro& operator=(const Scuro&);
    virtual double TrasmittanzaTermica() const override;
    virtual double MetriQuadri() const override;
    virtual Scuro* clone() const override;
    virtual double PrezzoFinale() const override;
    virtual void Serialize(QJsonObject&) const override;
    virtual QString NomeProdotto() const override;

    unsigned int getNumeroAnte() const;
    Finiture getFinitureEsterne() const;
    Finiture getFinitureInterne() const;


    void setNumeroAnte(unsigned int);
    void setFinitureEsterne(Finiture);
    void setFinitureInterne(Finiture);


private:
    unsigned int num_ante;
    Finiture finiture_esterne, finiture_interne;

};

#endif // SCURO_H
