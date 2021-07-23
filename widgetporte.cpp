#include "widgetporte.h"

WidgetPorte::WidgetPorte(const Model* _model): WidgetItemGenerico(nullptr), model(_model)
{

    QGridLayout *mainLayout = new QGridLayout;
    setLayout(mainLayout);

    //topleft
    QGroupBox *topleft = new QGroupBox();
    QGridLayout *topleftLayout = new QGridLayout;
    l0 = new QLabel("Prezzo base (€/mq)");
    l1 = new QLabel("Larghezza (mm)");
    l2 = new QLabel("Altezza (mm)");

    le0 = new QLineEdit();
    le1 = new QLineEdit();
    le2 = new QLineEdit();
    le1->setMaxLength(4);
    le2->setMaxLength(4);



    topleft->setLayout(topleftLayout);

    topleftLayout->addWidget(l1, 0, 0);
    topleftLayout->addWidget(l2, 1, 0);
    topleftLayout->addWidget(le1, 0, 1);
    topleftLayout->addWidget(le2, 1, 1);
    topleftLayout->addWidget(l0, 2, 0);
    topleftLayout->addWidget(le0, 2, 1);
    mainLayout->addWidget(topleft, 0, 0);

    //bottomleft
    QGroupBox *bottomleft = new QGroupBox();
    QGridLayout *bottomleftLayout = new QGridLayout;
    l3 = new QLabel("Colore interno");
    l4 = new QLabel("Colore esterno");
    l14 = new QLabel("Spessore");

    cb1 = new QComboBox();
    cb2 = new QComboBox();

    sp1 = new QSpinBox();
    sp1->setValue(40);
    sp1->setMaximum(50);
    sp1->setMinimum(40);
    sp1->setSingleStep(5);
    //popolamento combobox

    cb1->addItem("RAL9010");
    cb2->addItem("RAL9010");
    cb1->addItem("RAL3010");
    cb2->addItem("RAL3010");
    cb1->addItem("RAL6009");
    cb2->addItem("RAL6009");
    cb1->addItem("RAL7040");
    cb2->addItem("RAL7040");

    bottomleft->setLayout(bottomleftLayout);

    bottomleftLayout->addWidget(l3, 0, 0);
    bottomleftLayout->addWidget(l4, 1, 0);
    bottomleftLayout->addWidget(cb1, 0, 1);
    bottomleftLayout->addWidget(cb2, 1, 1);
    bottomleftLayout->addWidget(l14, 2, 0);
    bottomleftLayout->addWidget(sp1, 2, 1);
    mainLayout->addWidget(bottomleft, 1, 0);

    //topright
    QGroupBox *topright = new QGroupBox();
    QGridLayout *toprightLayout = new QGridLayout;
    l5 = new QLabel("Modo apertura");
    l6 = new QLabel("Serratura");
    l7 = new QLabel("Apertura");
    l8 = new QLabel("Cerniera");

    cb3 = new QComboBox();
    cb4 = new QComboBox();
    cb5 = new QComboBox();
    cb6 = new QComboBox();
    //popolamento combobox


    cb3->addItem("Battente");
    cb3->addItem("Scorrevole");

    cb4->addItem("Standard");
    cb4->addItem("Magnetica");
    cb4->addItem("Non presente");

    cb5->addItem("Destra");
    cb5->addItem("Sinistra");
    cb6->addItem("Scomparsa");
    cb6->addItem("Anuba");



    topright->setLayout(toprightLayout);

    toprightLayout->addWidget(l5, 0, 0);
    toprightLayout->addWidget(l6, 1, 0);
    toprightLayout->addWidget(cb3, 0, 1);
    toprightLayout->addWidget(cb4, 1, 1);
    toprightLayout->addWidget(l7, 2, 0);
    toprightLayout->addWidget(l8, 3, 0);
    toprightLayout->addWidget(cb5, 2, 1);
    toprightLayout->addWidget(cb6, 3, 1);
    mainLayout->addWidget(topright, 0, 1);


    //bottomright
    QGroupBox *bottomright = new QGroupBox();
    QGridLayout *bottomrightLayout = new QGridLayout;

    l9 = new QLabel("Crea un nuovo legno:");
    l10 = new QLabel("Coeff. termico (W/mq)");
    l11 = new QLabel("Prezzo base (€/mq)");
    l12 = new QLabel("Nome legno");
    l13 = new QLabel("Durezza");
    spazzlegno = new QCheckBox("Spazzolatura");
    dsp1 = new QDoubleSpinBox();
    dsp1->setMaximum(4);
    dsp1->setMinimum(0.1);
    dsp1->setValue(1.0);
    dsp1->setDecimals(1);
    dsp1->setSingleStep(0.1);
    le4 = new QLineEdit();
    le5 = new QLineEdit();
    cb8 = new QComboBox();

    bottomright->setLayout(bottomrightLayout);


    bottomrightLayout->addWidget(l9, 1, 0);
    bottomrightLayout->addWidget(l10, 2, 0);
    bottomrightLayout->addWidget(l11, 3, 0);
    bottomrightLayout->addWidget(l12, 4, 0);
    bottomrightLayout->addWidget(l13, 5, 0);
    bottomrightLayout->addWidget(spazzlegno, 6, 0);
    bottomrightLayout->addWidget(dsp1, 2, 1);
    bottomrightLayout->addWidget(le4, 3, 1);
    bottomrightLayout->addWidget(le5, 4, 1);
    bottomrightLayout->addWidget(cb8, 5, 1);

    cb8->addItem("Tenero");
    cb8->addItem("Duro");

    mainLayout->addWidget(bottomright, 1, 1);



}


bool WidgetPorte::verificaDati() const {
    // verifica che tutti i qline edit siano non vuoti

    bool test1 = le0->text() != "" && le1->text() != "" && le2->text() != "" &&
                 le4->text() != "" && le5->text() != "";
    QRegExp *misure = new QRegExp("[0-9]*");
    QRegExp *prezzi = new QRegExp("[0-9]+(\\.|,)[0-9][0-9]|[0-9]+");
    //verifica che le misure siano solo interi
    bool test2 = misure->exactMatch(le1->text()) &&
                 misure->exactMatch(le2->text());
    //verifica che i prezzi siano nella forma giusta
    bool test3 = prezzi->exactMatch(le0->text()) &&
                 prezzi->exactMatch(le4->text()) ;
    delete misure;
    delete prezzi;
    if (!test1)
        showWarning("Attenzione ci sono dei campi ancora vuoti.");
    else if (!test2)
        showWarning("Attenzione le dimensioni inserite non sono corrette,\n vanno inseriti solo numeri");
    else if (!test3)
        showWarning("Attenzione i prezzi inseriti non sono corretti,\n possono solo essere numeri interi o con al massimo 2 cifre decimali");


    return test1 && test2 && test3;

}

void WidgetPorte::generaProdotto(Porta*& p ) const {
    //assumendo che venga chiamata dopo verificaDati() ritorna
    //una corretta istanza dello specifico prodotto

    Legno::Durezza dur;
    Porta::ModoApertura mod_apert;
    Porta::Serratura tipo_serr;
    Porta::Cerniera cerniere;

    switch(cb8->currentIndex()) {
        case 0:
        dur = Legno::Durezza::tenero;
        break;
        case 1:
        dur = Legno::Durezza::duro;
        break;
    }

    switch(cb3->currentIndex()) {
        case 0:
        mod_apert = Porta::ModoApertura::battente;
        break;
        case 1:
        mod_apert = Porta::ModoApertura::scorrevole;
        break;
    }

    switch(cb4->currentIndex()) {
        case 0:
        tipo_serr = Porta::Serratura::standard;
        break;
        case 1:
        tipo_serr = Porta::Serratura::magnetica;
        break;
        case 2:
        tipo_serr = Porta::Serratura::non_presente;
        break;
    }

    switch(cb5->currentIndex()) {
        case 0:
        cerniere = Porta::Cerniera::scomparsa;
        break;
        case 1:
        cerniere = Porta::Cerniera::anuba;
        break;

    }


    p = new Porta(le1->text().toUInt(), //larghezza
                        le2->text().toUInt(), //lunghezza
                        le0->text().toDouble(), //prezzo
                        cb1->currentText(), //colore interno
                        cb2->currentText(), //colore esterno
                        cb5->currentText(), //apertura
                        dsp1->value(), //coeff
                        le4->text().toDouble(),//prezzo
                        le5->text(), //nome
                        dur, //durezza
                        spazzlegno->isChecked(),
                        sp1->text().toDouble(),
                        mod_apert,
                        tipo_serr,
                        cerniere
                     );
}

void WidgetPorte::resetCampi() {
    le0->clear();
    le1->clear();
    le2->clear();
    le4->clear();

    le5->clear();
    cb1->setCurrentIndex(0);
    cb2->setCurrentIndex(0);
    cb3->setCurrentIndex(0);
    cb4->setCurrentIndex(0);
    cb5->setCurrentIndex(0);
    cb6->setCurrentIndex(0);

    cb8->setCurrentIndex(0);
    sp1->setValue(40);
    dsp1->setValue(1.0);

    spazzlegno->setCheckState(Qt::Unchecked);
}

void WidgetPorte::riempiCampi(const Porta* p) {
    le0->setText(QString::number(p->getPrezzoBase(), 'f', 2));
    le1->setText(QString::number(p->getLarghezza()));
    le2->setText(QString::number(p->getAltezza()));
    le4->setText(QString::number(p->getTipologiaLegno()->getPrezzoBase()));

    le5->setText(p->getTipologiaLegno()->getNome());

    cb1->setCurrentIndex(cb1->findText(p->getColoreInterno()));

    cb2->setCurrentIndex(cb2->findText(p->getColoreEsterno()));
    cb3->setCurrentIndex(p->getModoApertura());
    cb4->setCurrentIndex(p->getTipologiaSerratura());
    cb5->setCurrentIndex(cb5->findText(p->getApertura()));
    cb6->setCurrentIndex(p->getTipologiaCerniere());
    cb8->setCurrentIndex(p->getTipologiaLegno()->getDurezza());

    sp1->setValue(p->getSpessore());
    dsp1->setValue(p->getTipologiaLegno()->CoeffTermico());

    spazzlegno->setCheckState((p->getTipologiaLegno()->Spazzolato()? Qt::Checked : Qt::Unchecked));

}
