#include "dialogprodotti.h"


DialogProdotti::DialogProdotti(const Model* _model, Controller* _controller, QWidget* parent):
    QDialog(parent, Qt::WindowCloseButtonHint), model(_model), controller(_controller), modalita(false), indiceArticoloDaModificare(-1)
{

    QVBoxLayout *mainLayout = new QVBoxLayout;

    tabs = new QTabWidget(this);
    QHBoxLayout *buttonboxlayout = new QHBoxLayout;
    ok = new QPushButton("Ok");
    cancella = new QPushButton("Cancella");
    ok->setMaximumWidth(80);
    cancella->setMaximumWidth(80);

    buttonboxlayout->addWidget(ok);
    buttonboxlayout->addWidget(cancella);

    tab_scuri = new WidgetScuri(model);
    tab_finestre = new WidgetFinestre(model);
    tab_porte = new WidgetPorte(model);



    tabs->insertTab(Tabs::scuri, tab_scuri, "Scuro");
    tabs->insertTab(Tabs::finestre, tab_finestre, "Finestra");
    tabs->insertTab(Tabs::porte, tab_porte, "Porta");

    quant = new QSpinBox;
    l1 = new QLabel("Quantita' :");
    quant->setValue(1);
    quant->setMinimum(1);
    quant->setMaximumWidth(100);

    mainLayout->addWidget(tabs);
    mainLayout->addWidget(l1);
    mainLayout->addWidget(quant);
    mainLayout->addLayout(buttonboxlayout);
    setLayout(mainLayout);



    connect(ok, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancella, SIGNAL(clicked()), this, SLOT(reject()));

    layout()->setSizeConstraint(QLayout::SetFixedSize);
    setModal(true);
}

void DialogProdotti::setTitolo(QString titolo) {
    setWindowTitle(titolo);
}

void DialogProdotti::setTabDaVisualizzare(Tabs tab) {
    tabs->setCurrentIndex(tab);
}

void DialogProdotti::accept() {
    if (!modalita) {
        switch(tabs->currentIndex()) {
            case Tabs::scuri:
                if(tab_scuri->verificaDati()) {
                    Scuro* s;
                    tab_scuri->generaProdotto(s);
                    controller->aggiungiArticolo(
                                s,
                                quant->value());
                    delete s;  //viene copiato
                } else return;

            break;
            case Tabs::finestre:
                if(tab_finestre->verificaDati()) {
                    Finestra* f;
                    tab_finestre->generaProdotto(f);
                    controller->aggiungiArticolo(
                                f,
                                quant->value());
                    delete f;
                } else return;

            break;

            case Tabs::porte:
                if(tab_porte->verificaDati()) {
                    Porta* p ;
                    tab_porte->generaProdotto(p);
                    controller->aggiungiArticolo(
                                p,
                                quant->value());

                    delete p;
                } else return;

            break;

        }
    } else {
        switch(tabs->currentIndex()) {
            case Tabs::scuri:
                if(tab_scuri->verificaDati()) {
                    Scuro* s;
                    tab_scuri->generaProdotto(s);
                    controller->modificaArticolo(indiceArticoloDaModificare,
                                s,
                                quant->value());
                    delete s;
                } else return;
            break;
            case Tabs::finestre:
                if(tab_finestre->verificaDati()) {
                    Finestra* f;
                    tab_finestre->generaProdotto(f);
                    controller->modificaArticolo(indiceArticoloDaModificare,
                                f,
                                quant->value());
                    delete f;
                } else return;

            break;

            case Tabs::porte:
                if(tab_porte->verificaDati()) {
                    Porta* p;
                    tab_porte->generaProdotto(p);
                    controller->modificaArticolo(indiceArticoloDaModificare,
                                p,
                                quant->value());
                    delete p;
                } else return;

            break;

        }
    }
        QDialog::accept();

}

void DialogProdotti::resetCampi() {

    tabs->setTabEnabled(Tabs::scuri, true);
    tabs->setTabEnabled(Tabs::finestre, true);
    tabs->setTabEnabled(Tabs::porte, true);

    tab_scuri->resetCampi();
    tab_finestre->resetCampi();
    tab_porte->resetCampi();

    quant->setValue(1);


}

void DialogProdotti::riempiCampiModifica(Tabs tab, std::pair<Serramento*, unsigned int> articolo) {
    quant->setValue(articolo.second);

    if (tab == Tabs::scuri) {
        tabs->setTabEnabled(Tabs::scuri, true);
        tabs->setTabEnabled(Tabs::finestre, false);
        tabs->setTabEnabled(Tabs::porte, false);

        tab_scuri->riempiCampi(static_cast<Scuro*>(articolo.first));
    } else if (tab == Tabs::porte) {
        tabs->setTabEnabled(Tabs::scuri, false);
        tabs->setTabEnabled(Tabs::finestre, false);
        tabs->setTabEnabled(Tabs::porte, true);

        tab_porte->riempiCampi(static_cast<Porta*>(articolo.first));
    } else if (tab == Tabs::finestre) {
        tabs->setTabEnabled(Tabs::scuri, false);
        tabs->setTabEnabled(Tabs::finestre, true);
        tabs->setTabEnabled(Tabs::porte, false);

        tab_finestre->riempiCampi(static_cast<Finestra*>(articolo.first));
    }

}

void DialogProdotti::modalitaModifica(bool m, int index) {
    if (m) {
        modalita = true;
        indiceArticoloDaModificare = index;
    } else {
        modalita = false;
        indiceArticoloDaModificare = -1;
    }
}
