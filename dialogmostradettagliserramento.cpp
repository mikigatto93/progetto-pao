#include "dialogmostradettagliserramento.h"

DialogMostraDettagliSerramento::DialogMostraDettagliSerramento(QWidget* parent):
    QDialog(parent, Qt::WindowCloseButtonHint)
{
    QVBoxLayout *mainLayout = new QVBoxLayout();
    setLayout(mainLayout);

    l1 = new QLabel("Dettagli serramento:");
    l2 = new QLabel;
    l2->setWordWrap(true);
    mainLayout->addWidget(l1);
    mainLayout->addWidget(l2);
    setWindowTitle("Visualizza dettagli");
    setModal(true);

}



void DialogMostraDettagliSerramento::dettagliScuro(Scuro* s, unsigned int quant)
{
    QString fin_est, fin_int;

    switch(s->getFinitureEsterne()) {
        case Scuro::Finiture::non_presenti:
        fin_est = "non presenti";
        break;
        case Scuro::Finiture::fughe_orizzontali:
        fin_est = "fughe orizzontali";
        break;
        case Scuro::Finiture::fughe_verticali:
        fin_est = "fughe verticali";
        break;
    }
    switch(s->getFinitureInterne()) {
        case Scuro::Finiture::non_presenti:
        fin_int = "non presenti";
        break;
        case Scuro::Finiture::fughe_orizzontali:
        fin_int = "fughe orizzontali";
        break;
        case Scuro::Finiture::fughe_verticali:
        fin_int = "fughe verticali";
        break;
    }
    l2->setText(
        "SCURO Altezza: " + QString::number(s->getAltezza()) + " Larghezza: " + QString::number(s->getLarghezza()) +
        " Numero ante: " + QString::number(s->getNumeroAnte()) + " e apertura " + s->getApertura() + ". " +
        "Costruito in legno " + s->getTipologiaLegno()->getNome() + (s->getTipologiaLegno()->Spazzolato() ? " spazzolato. " : " non spazzolato. ") +
        "Colore interno: " + s->getColoreInterno() + " e colore esterno: " + s->getColoreEsterno() + ". Finiture esterne: " +
        fin_est + " e finiture interne " + fin_int + ". " + "Metri quadri " +
        QString::number(s->MetriQuadri(), 'f', 2) + ", Trasmittanza termica "+ QString::number(s->TrasmittanzaTermica(), 'f', 3)+ " W/mq." +
        " Quantita: " + QString::number(quant) + " Prezzo unitario: " + QString::number(s->PrezzoFinale(), 'f', 2) + " € " +
        " Prezzo totale (non scontato): " +  QString::number(s->PrezzoFinale() * quant, 'f', 2) + " €"


    );




}

void DialogMostraDettagliSerramento::dettagliFinestra(Finestra* f, unsigned int quant) {
    QString chius_est, can_vetro, cat_vetro, gas_vetro;

    switch(f->getChiusureEsterne()) {
        case Finestra::ChiusureEsterne::non_presenti:
        chius_est = "non presenti";
        break;
        case Finestra::ChiusureEsterne::tapparelle:
        chius_est = "tapparelle";
        break;
        case Finestra::ChiusureEsterne::scuri:
        chius_est = "scuri";
        break;
    }


    switch(f->getTipologiaVetro()->getCanalina()) {
        case Vetro::Canalina::alluminio:
        can_vetro = "in alluminio";
        break;
        case Vetro::Canalina::acciaio:
        can_vetro = "in acciaio";
        break;
        case Vetro::Canalina::warm_edge:
        can_vetro = "warm edge";
        break;
    }

    switch(f->getTipologiaVetro()->getCategoria()) {
        case Vetro::Categoria::temperato:
        cat_vetro = "temperato";
        break;
        case Vetro::Categoria::stratificato:
        cat_vetro = "stratificato";
        break;
        case Vetro::Categoria::satinato:
        cat_vetro = "satinato";
        break;
    }


    switch(f->getTipologiaVetro()->getGasInterno()) {
        case Vetro::Gas::aria:
        gas_vetro = "aria";
        break;
        case Vetro::Gas::argon:
        gas_vetro = "argon";
        break;
        case Vetro::Gas::xeno:
        gas_vetro = "xeno";
        break;
    }



    l2->setText(

        ( f->PortaFinestra() ? QString("PORTAFINESTRA") : QString("FINESTRA") ) +
        " Altezza: " + QString::number(f->getAltezza()) + " Larghezza: " + QString::number(f->getLarghezza()) +
        " Numero ante: " + QString::number(f->getNumAnte()) + " apertura "+ f->getApertura() + ", spessore telaio:" + QString::number(f->getSpessoreTelaio(), 'f', 2) + (f->Ribalta()? " con " : " senza ") + "ribalta. " +
        "Costruita in legno " + f->getTipologiaLegno()->getNome() + (f->getTipologiaLegno()->Spazzolato() ? " spazzolato. " : " non spazzolato. ") +
        "Colore interno: " + f->getColoreInterno() + " e colore esterno: " + f->getColoreEsterno() + ". Vetro modello " +
        f->getTipologiaVetro()->getModello() + " " + (f->getTipologiaVetro()->isAntisfondamento() ? "antisfondamento" : "") + " " + cat_vetro + ", con camera interna riempita di " +
        gas_vetro + " e canalina " + can_vetro + ". " + "Metri quadri " + QString::number(f->MetriQuadri(), 'f', 2) +
        ", Trasmittanza termica " + QString::number(f->TrasmittanzaTermica(), 'f', 3) + " W/mq (chiusure esterne: "  + chius_est + ")."  + //desc
        " Quantita: " + QString::number(quant) + " Prezzo unitario: " + QString::number(f->PrezzoFinale(), 'f', 2) + " € " +
        " Prezzo totale (non scontato): " +  QString::number(f->PrezzoFinale() * quant, 'f', 2) + " €"

    );





}

void DialogMostraDettagliSerramento::dettagliPorta(Porta* p, unsigned int quant)
{
    QString modo_apert, serratura, cerniera;

    switch(p->getModoApertura()) {
        case Porta::ModoApertura::battente:
        modo_apert = "a battente";
        break;
        case Porta::ModoApertura::scorrevole:
        modo_apert = "scorrevole";
        break;

    }

    switch(p->getTipologiaSerratura()) {
        case Porta::Serratura::magnetica:
        serratura = "magnetica";
        break;
        case Porta::Serratura::standard:
        serratura = "standard";
        break;
        case Porta::Serratura::non_presente:
        serratura = "non presente";
        break;
    }

    switch(p->getTipologiaCerniere()) {
        case Porta::Cerniera::scomparsa:
        cerniera = "a scomparsa";
        break;
        case Porta::Cerniera::anuba:
        cerniera = "anuba";
        break;

    }

    l2->setText(



    "PORTA Altezza: " + QString::number(p->getAltezza()) + " Larghezza: " + QString::number(p->getLarghezza()) +"."+
                                 " Apertura " + modo_apert + " " + p->getApertura() + " con spessore " + QString::number(p->getSpessore(), 'f', 2) + ". " +
                                 "Costruita in legno " + p->getTipologiaLegno()->getNome() + (p->getTipologiaLegno()->Spazzolato() ? " spazzolato. " : " non spazzolato. ") +
                                 "Colore interno: " + p->getColoreInterno() + " e colore esterno: " + p->getColoreEsterno() + ". Cerniere " +
                                 cerniera + " e serratura " + serratura + ". " + "Metri quadri " +
                                 QString::number(p->MetriQuadri(), 'f', 2) + ", Trasmittanza termica "+ QString::number(p->TrasmittanzaTermica(), 'f', 3)+ " W/mq."  //desc
                                 + " Quantita: " + QString::number(quant) + " Prezzo unitario: " + QString::number(p->PrezzoFinale(), 'f', 2) + " € " +
                                " Prezzo totale (non scontato): " +  QString::number(p->PrezzoFinale() * quant, 'f', 2) + " €"
    );








}


