#ifndef FINESTRA_H
#define FINESTRA_H

#include "serramento.h"
#include "vetro.h"
#include "legno.h"
#include <QString>

class Finestra : public Serramento
{
public:
    enum ChiusureEsterne {
        non_presenti, tapparelle, scuri
    };

    Finestra(unsigned int, unsigned int, double, QString, QString, QString, double, double, QString, Legno::Durezza, bool,
             unsigned int, unsigned int, bool, ChiusureEsterne, double, double,
             QString, Vetro::Canalina, Vetro::Categoria, Vetro::Gas, bool);
    ~Finestra();
    Finestra(const Finestra&);
    Finestra& operator=(const Finestra&);

    virtual double TrasmittanzaTermica() const override;
    virtual double MetriQuadri() const override;
    virtual Finestra* clone() const override;
    virtual double PrezzoFinale() const override;
    virtual void Serialize(QJsonObject&) const override;
    virtual QString NomeProdotto() const override;

    unsigned int getNumAnte() const;
    unsigned int getSpessoreTelaio() const;
    bool Ribalta() const;
    ChiusureEsterne getChiusureEsterne() const;
    Vetro* getTipologiaVetro() const;
    bool PortaFinestra() const;

    void setNumAnte(unsigned int);
    void setSpessoreTelaio(unsigned int);
    void setRibalta(bool);
    void setChiusureEsterne(ChiusureEsterne);
    void setTipologiaVetro(Vetro*);


private:
    unsigned int num_ante;
    unsigned int spessore_telaio;
    bool ribalta;
    ChiusureEsterne chiusure;
    Vetro* tipologia_vetro;


};

#endif // FINESTRA_H
