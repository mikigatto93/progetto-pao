#ifndef SERRAMENTO_H
#define SERRAMENTO_H

#include "baseitem.h"
#include "legno.h"
#include <QString>


class Serramento: public BaseItem
{
private:

    unsigned int altezza, larghezza;
    double prezzo_base;
    QString colore_interno,
            colore_esterno,
            apertura;

    Legno* tipologia_legno;


public:
    Serramento(unsigned int, unsigned int, double,
             QString, QString, QString,
               double, double, QString, Legno::Durezza, bool);

    ~Serramento();
    Serramento(const Serramento&);
    Serramento& operator=(const Serramento&);

    virtual double PrezzoFinale() const = 0;
    virtual QString NomeProdotto() const = 0;
    virtual double TrasmittanzaTermica() const = 0;
    virtual double MetriQuadri() const = 0;
    virtual Serramento* clone() const = 0;

    unsigned int getAltezza() const;
    unsigned int getLarghezza() const;


    void setAltezza(unsigned int);
    void setLarghezza(unsigned int);
    void setId(QString);
    void setPrezzoBase(double);

    double getPrezzoBase() const;
    QString getColoreInterno() const;
    QString getColoreEsterno() const;

    Legno* getTipologiaLegno() const;
    QString getApertura() const;

    void setColoreInterno(QString);
    void setColoreEsterno(QString);

    void setTipologiaLegno(Legno*);
    void setApertura(QString);


};

#endif // SERRAMENTO_H
