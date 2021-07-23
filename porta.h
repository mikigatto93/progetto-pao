#ifndef PORTA_H
#define PORTA_H

#include "serramento.h"
#include<QString>

class Porta : public Serramento
{
public:
    enum ModoApertura {
        battente, scorrevole
    };

    enum Serratura {
        standard, magnetica, non_presente
    };

    enum Cerniera {
        scomparsa, anuba
    };

    Porta(unsigned int, unsigned int, double,
          QString, QString, QString, double, double, QString, Legno::Durezza, bool,
          double,  ModoApertura, Serratura, Cerniera
          );

    ~Porta() = default;
    Porta(const Porta&);
    Porta& operator=(const Porta&);

    virtual double TrasmittanzaTermica() const override;
    virtual double MetriQuadri() const override;
    virtual Porta* clone() const override;
    virtual double PrezzoFinale() const override;
    virtual void Serialize(QJsonObject&) const override;
    virtual QString NomeProdotto() const override;

    double getSpessore() const;
    ModoApertura getModoApertura() const;
    Serratura getTipologiaSerratura() const;
    Cerniera getTipologiaCerniere() const;

    void getSpessore(double);
    void getModoApertura(ModoApertura);
    void getTipologiaSerratura(Serratura);
    void getTipologiaCerniere(Cerniera);


private:
    double spessore;
    ModoApertura modo_apertura;
    Serratura tipologia_serratura;
    Cerniera tipologia_cerniera;

};

#endif // PORTA_H
