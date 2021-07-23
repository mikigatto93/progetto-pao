#include "widgetfinestre.h"

WidgetFinestre::WidgetFinestre(const Model* _model): WidgetItemGenerico(nullptr), model(_model)
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
    l14 = new QLabel("Spessore telaio (mm)");

    cb1 = new QComboBox();
    cb2 = new QComboBox();
    cb0 = new QComboBox();

    //popolamento combobox
    cb0->addItem("68");
    cb0->addItem("92");
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
    bottomleftLayout->addWidget(cb0, 2, 1);
    mainLayout->addWidget(bottomleft, 1, 0);

    //topright
    QGroupBox *topright = new QGroupBox();
    QGridLayout *toprightLayout = new QGridLayout;
    l5 = new QLabel("Chiusure esterne");
    l7 = new QLabel("Apertura");
    l8 = new QLabel("Numero ante");

    cb3 = new QComboBox();
    ribal = new QCheckBox("Ribalta");
    cb5 = new QComboBox();
    cb6 = new QComboBox();
    //popolamento combobox


    cb3->addItem("Non presenti");
    cb3->addItem("Tapparelle");
    cb3->addItem("Scuri");


    cb5->addItem("Destra");
    cb5->addItem("Sinistra");

    cb6->addItem("1");
    cb6->addItem("2");
    cb6->addItem("3");


    topright->setLayout(toprightLayout);

    toprightLayout->addWidget(ribal, 0, 0);
    toprightLayout->addWidget(l5, 1, 0);
    //toprightLayout->addWidget(l6, 1, 0);
    toprightLayout->addWidget(cb3, 1, 1);

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

    //bottom
    QGroupBox *bottom = new QGroupBox();
    QGridLayout *bottomLayout = new QGridLayout;
    l15 = new QLabel("Crea un nuovo vetro:");
    l16 = new QLabel("Coeff. termico (W/mq)");
    l17 = new QLabel("Prezzo base (€/mq)");
    l18 = new QLabel("Modello vetro");
    l19 = new QLabel("Canalina");
    l20 = new QLabel("Categoria");
    l21 = new QLabel("Gas interno");
    antisfondamento = new QCheckBox("Antisfondamento");
    dsp2 = new QDoubleSpinBox();
    dsp2->setMaximum(4);
    dsp2->setMinimum(0.1);
    dsp2->setValue(1.0);
    dsp2->setDecimals(1);
    dsp2->setSingleStep(0.1);

    le7 = new QLineEdit();
    le8 = new QLineEdit();
    cb10 = new QComboBox();
    cb11 = new QComboBox();
    cb12 = new QComboBox();

    dsp2->setMaximumWidth(150);
    le7->setMaximumWidth(150);
    le8->setMaximumWidth(150);

    //popolamento combobox
    cb10->addItem("Alluminio");
    cb10->addItem("Acciaio");
    cb10->addItem("Warm Edge");

    cb11->addItem("Temperato");
    cb11->addItem("Stratificato");
    cb11->addItem("Satinato");

    cb12->addItem("Aria");
    cb12->addItem("Argon");
    cb12->addItem("Xeno");

    bottom->setLayout(bottomLayout);
    bottomLayout->addWidget(l15, 0, 0, 1, 2);
    bottomLayout->addWidget(l16, 1, 0);
    bottomLayout->addWidget(l17, 2, 0);
    bottomLayout->addWidget(l18, 3, 0);
    bottomLayout->addWidget(antisfondamento, 4, 0);
    bottomLayout->addWidget(dsp2, 1, 1);
    bottomLayout->addWidget(le7, 2, 1);
    bottomLayout->addWidget(le8, 3, 1);
    bottomLayout->addWidget(l19, 1, 2);
    bottomLayout->addWidget(l20, 2, 2);
    bottomLayout->addWidget(l21, 3, 2);
    bottomLayout->addWidget(cb10, 1, 3);
    bottomLayout->addWidget(cb11, 2, 3);
    bottomLayout->addWidget(cb12, 3, 3);

    mainLayout->addWidget(bottom, 2, 0, 1, 2);


}




bool WidgetFinestre::verificaDati() const {

    bool test1 = le0->text() != "" && le1->text() != "" && le2->text() != "" &&
                 le4->text() != "" && le5->text() != "" &&
                 le7->text() != "" && le8->text() != "";
    QRegExp *misure = new QRegExp("[0-9]*");
    QRegExp *prezzi = new QRegExp("[0-9]+(\\.|,)[0-9][0-9]|[0-9]+");
    //verifica che le misure siano solo interi
    bool test2 = misure->exactMatch(le1->text()) &&
                 misure->exactMatch(le2->text());
    //verifica che i prezzi siano nella forma giusta
    bool test3 = prezzi->exactMatch(le0->text()) &&
                prezzi->exactMatch(le4->text())  &&
                prezzi->exactMatch(le7->text());

    if (!test1)
        showWarning("Attenzione ci sono dei campi ancora vuoti.");
    else if (!test2)
        showWarning("Attenzione le dimensioni inserite non sono corrette\n, vanno inseriti solo numeri");
    else if (!test3)
        showWarning("Attenzione i prezzi inseriti non sono corretti\n, possono solo essere numeri interi o con al massimo 2 cifre decimali");

    delete misure;
    delete prezzi;

    return test1 && test2 && test3;

}

void WidgetFinestre::generaProdotto(Finestra*& f) const {

    //assumendo che venga chiamata dopo verificaDati() ritorna
    //una corretta istanza dello specifico prodotto
    Legno::Durezza dur;
    Vetro::Canalina can_vetro;
    Vetro::Categoria cat_vetro;
    Vetro::Gas gas_interno;
    Finestra::ChiusureEsterne chius_est;

    switch(cb3->currentIndex()) {
        case 0:
        chius_est = Finestra::ChiusureEsterne::non_presenti;
        break;
        case 1:
        chius_est = Finestra::ChiusureEsterne::tapparelle;
        break;
        case 2:
        chius_est = Finestra::ChiusureEsterne::scuri;
        break;
    }

    switch(cb8->currentIndex()) {
        case 0:
        dur = Legno::Durezza::tenero;
        break;
        case 1:
        dur = Legno::Durezza::duro;
        break;
    }

    switch(cb10->currentIndex()) {
        case 0:
        can_vetro = Vetro::Canalina::alluminio;
        break;
        case 1:
        can_vetro = Vetro::Canalina::acciaio;
        break;
        case 2:
        can_vetro = Vetro::Canalina::warm_edge;
        break;
    }

    switch(cb11->currentIndex()) {
        case 0:
        cat_vetro = Vetro::Categoria::temperato;
        break;
        case 1:
        cat_vetro = Vetro::Categoria::stratificato;
        break;
        case 2:
        cat_vetro = Vetro::Categoria::satinato;
        break;
    }

    switch(cb12->currentIndex()) {
        case 0:
        gas_interno = Vetro::Gas::aria;
        break;
        case 1:
        gas_interno = Vetro::Gas::argon;
        break;
        case 2:
        gas_interno = Vetro::Gas::xeno;
        break;

    }

    f = new Finestra(le1->text().toUInt(), //larghezza
                        le2->text().toUInt(), //lunghezza
                        le0->text().toDouble(), //prezzo
                        cb1->currentText(), //colore interno
                        cb2->currentText(), //colore esterno
                        cb5->currentText(), //apertura
                        dsp1->value(), //coeff
                        le4->text().toDouble(),//prezzo
                        le5->text(), //nome
                        dur, //durezza
                        spazzlegno->isChecked(),//legno,
                        cb6->currentText().toUInt(), //NUM ANTE
                        cb0->currentText().toDouble(),//SPESSORE TELAIO
                        ribal->isChecked(), //RIBALTA
                        chius_est,
                        dsp1->value(), //coeff
                        le4->text().toDouble(),//prezzo
                        le5->text(), //modello
                        can_vetro,
                        cat_vetro,
                        gas_interno,
                        antisfondamento->isChecked()
                     );

}
void WidgetFinestre::resetCampi() {
    le0->clear();
    le1->clear();
    le2->clear();
    le4->clear();
    le5->clear();
    le7->clear();
    le8->clear();

    cb0->setCurrentIndex(0);
    cb1->setCurrentIndex(0);
    cb2->setCurrentIndex(0);
    cb3->setCurrentIndex(0);
    cb5->setCurrentIndex(0);
    cb6->setCurrentIndex(0);

    cb8->setCurrentIndex(0);

    cb10->setCurrentIndex(0);
    cb11->setCurrentIndex(0);
    cb12->setCurrentIndex(0);
    dsp1->setValue(1.0);
    dsp2->setValue(1.0);

    spazzlegno->setCheckState(Qt::Unchecked);

    ribal->setCheckState(Qt::Unchecked);

    antisfondamento->setCheckState(Qt::Unchecked);


}

void WidgetFinestre::riempiCampi(const Finestra * f) {

    le0->setText(QString::number(f->getPrezzoBase(), 'f', 2));
    le1->setText(QString::number(f->getLarghezza()));
    le2->setText(QString::number(f->getAltezza()));
    le4->setText(QString::number(f->getTipologiaLegno()->getPrezzoBase()));
    le5->setText(f->getTipologiaLegno()->getNome());
    le7->setText(QString::number(f->getTipologiaVetro()->getPrezzoBase()));
    le8->setText(f->getTipologiaVetro()->getModello());

    cb0->setCurrentIndex(cb0->findText(QString::number(f->getSpessoreTelaio())));
    cb1->setCurrentIndex(cb1->findText(f->getColoreInterno()));

    cb2->setCurrentIndex(cb2->findText(f->getColoreEsterno()));
    cb3->setCurrentIndex(f->getChiusureEsterne());
    cb5->setCurrentIndex(cb5->findText(f->getApertura()));
    cb6->setCurrentIndex(cb6->findText(QString::number(f->getNumAnte())));
    cb8->setCurrentIndex(f->getTipologiaLegno()->getDurezza());
    cb10->setCurrentIndex(f->getTipologiaVetro()->getCanalina());
    cb11->setCurrentIndex(f->getTipologiaVetro()->getCategoria());
    cb12->setCurrentIndex(f->getTipologiaVetro()->getGasInterno());

    dsp1->setValue(f->getTipologiaLegno()->CoeffTermico());
    dsp2->setValue(f->getTipologiaVetro()->CoeffTermico());

    spazzlegno->setCheckState((f->getTipologiaLegno()->Spazzolato()? Qt::Checked : Qt::Unchecked));
    antisfondamento->setCheckState((f->getTipologiaVetro()->isAntisfondamento()? Qt::Checked : Qt::Unchecked));

}
