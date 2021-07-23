#ifndef DIALOGMOSTRADETTAGLISERRAMENTO_H
#define DIALOGMOSTRADETTAGLISERRAMENTO_H
#include "model.h"
#include "scuro.h"
#include "porta.h"
#include "finestra.h"
#include <QDialog>
#include <QWidget>
#include <QListWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QGroupBox>

class DialogMostraDettagliSerramento : public QDialog
{
private:

   QLabel *l1, *l2;


public:
    DialogMostraDettagliSerramento(QWidget* =nullptr);

    void dettagliFinestra(Finestra* f, unsigned int quant);
    void dettagliPorta   (Porta* p, unsigned int quant);
    void dettagliScuro   (Scuro* s, unsigned int quant);

};

#endif // DIALOGMOSTRADETTAGLISERRAMENTO_H
