#include "mainwindow.h"
#include "dialogprodotti.h"
#include "qfiledialog.h"


void MainWindow::makeTopBar(QVBoxLayout* mainLayout)
{
    QHBoxLayout* topBarLayout = new QHBoxLayout;

    apri = new QToolButton();
    nuovo = new QToolButton();
    salva = new QToolButton();

    topBarLayout->addWidget(apri);
    topBarLayout->addWidget(nuovo);
    topBarLayout->addWidget(salva);


    apri->setIcon(QIcon(":icon/res/apri_icon.png"));
    apri->setText("Apri");
    apri->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    apri->setIconSize(QSize(60, 60));

    nuovo->setIcon(QIcon(":icon/res/nuovo_icon.png"));
    nuovo->setText("Nuovo");
    nuovo->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    nuovo->setIconSize(QSize(60, 60));

    salva->setIcon(QIcon(":icon/res/salva_icon.png"));
    salva->setText("Salva");
    salva->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    salva->setIconSize(QSize(60, 60));
    salva->setDisabled(true);// appena aperto non ci sono preventivi da salvare
    topBarLayout->setAlignment(Qt::AlignLeft);

    mainLayout->addLayout(topBarLayout);

    connect(nuovo, SIGNAL(clicked()), this, SLOT(nuovoPreventivo()) );
    connect(salva, SIGNAL(clicked()), this, SLOT(salvaPreventivo()) );
    connect(apri, SIGNAL(clicked()), this, SLOT(apriPreventivo()) );


}

void MainWindow::makeIntestazione(QVBoxLayout * mainLayout) {
    QGroupBox *intestazione = new QGroupBox;
    QGridLayout *layoutintest = new QGridLayout;
    QHBoxLayout *buttonlayout = new QHBoxLayout;

    l1 = new QLabel("Data:");
    l2 = new QLabel("Commessa:");
    l3 = new QLabel("Numero articoli:");
    l4 = new QLabel("Sconto applicato: ");
    l5 = new QLabel("Totale (IVA esclusa):");
    but1 = new QPushButton("Modifica intestazione");
    but2 = new QPushButton("Aggiungi articolo");
    but3 = new QPushButton("Rimuovi Articolo");
    but4 = new QPushButton("Modifica articolo");
    but5 = new QPushButton("Chiudi Preventivo");
    but6 = new QPushButton("Modifica sconto");

    but1->setMaximumWidth(200);
    but2->setMaximumWidth(200);
    but3->setMaximumWidth(200);
    but4->setMaximumWidth(200);
    but5->setMaximumWidth(200);
    but6->setMaximumWidth(200);
    but1->setDisabled(true);
    but2->setDisabled(true);
    but3->setDisabled(true);
    but4->setDisabled(true);
    but5->setDisabled(true);
    but6->setDisabled(true);

    layoutintest->addWidget(l1, 0, 0);
    layoutintest->addWidget(l2, 1, 0);
    layoutintest->addWidget(l3, 2, 0);
    layoutintest->addWidget(l4, 3, 0);
    layoutintest->addWidget(l5, 4, 0);
    layoutintest->addWidget(but1, 5, 0);
    layoutintest->addWidget(but6, 6, 0);

    buttonlayout->addWidget(but2);
    buttonlayout->addWidget(but3);
    buttonlayout->addWidget(but4);
    buttonlayout->addWidget(but5);

    layoutintest->addLayout(buttonlayout, 5, 1);
    intestazione->setLayout(layoutintest);

    mainLayout->addWidget(intestazione);

    connect( but1, SIGNAL(clicked()), this, SLOT(mostraDialogModificaIntestazione()) );
    connect( but2, SIGNAL(clicked()), this, SLOT(mostraDialogArticoliAggiungi()) );
    connect( but3, SIGNAL(clicked()), this, SLOT(rimuoviProdotto()) );
    connect( but5, SIGNAL(clicked()), this, SLOT(chiudiPreventivo()) );
    connect( but6, SIGNAL(clicked()), this, SLOT(modificaSconto()) );
    connect( but4, SIGNAL(clicked()), this, SLOT(mostraDialogArticoliModifica()) );


}

void MainWindow::updateIntestazione(bool isCloseClicked) {
    if (!isCloseClicked) {
        QDate data = model->getDataPreventivo();
        QString commessa = model->getCommessaPreventivo();
        unsigned int num_articoli = model->getNumeroProdotti();

        l1->setText("Data: " + data.toString("dd.MM.yyyy"));
        l2->setText("Commessa: " + commessa);
        l3->setText("Numero articoli: " + QString::number(num_articoli));
        l4->setText("Sconto applicato: " + QString::number(model->getScontoPreventivo(), 'f', 2) + "%");
        l5->setText( "Totale (IVA esclusa): " + QString::number(model->getTotalePreventivoFinale(), 'f', 2) + " €" );
        but1->setDisabled(false);
        but2->setDisabled(false);
        but3->setDisabled(false);
        but4->setDisabled(false);
        but5->setDisabled(false);
        but6->setDisabled(false);
        salva->setDisabled(false);
    } else {

        l1->setText("Data: " );
        l2->setText("Commessa: ");
        l3->setText("Numero articoli: ");
        l4->setText("Sconto applicato: ");
        l5->setText( "Totale (IVA esclusa): ");
        but1->setDisabled(true);
        but2->setDisabled(true);
        but3->setDisabled(true);
        but4->setDisabled(true);
        but5->setDisabled(true);
        but6->setDisabled(true);
        salva->setDisabled(true);

    }
}

void MainWindow::updatePreventivo(bool isCloseClicked)
{
    if (!isCloseClicked) {

        table->clearContents();
        table->setRowCount(0);
        l3->setText("Numero articoli: " + QString::number(model->getNumeroProdotti()));
        l5->setText( "Totale (IVA esclusa): " + QString::number(model->getTotalePreventivoFinale(), 'f', 2) + " €" );


        for (unsigned int i = 0; i < model->getNumeroProdotti(); ++i) {

            std::pair<Serramento*, unsigned int> articolo = model->getArticoloPreventivo(i);
            Serramento* p = articolo.first;
            unsigned int quant = articolo.second;

            table->insertRow(i);
            table->setRowHeight(i, 100);
            table->setItem(i, 0, new QTableWidgetItem(p->NomeProdotto()));
            table->item(i, 0)->setTextAlignment(Qt::AlignCenter);

            table->setItem(i, 1, new QTableWidgetItem("Altezza: " + QString::number(p->getAltezza()) + " Larghezza: " + QString::number(p->getLarghezza()) + "\n" +
                                                      " Apertura " + p->getApertura() + ", Colore interno: " + p->getColoreInterno() + ",  Colore esterno: " + p->getColoreEsterno() + "\n" +
                                                      " Legno: " + p->getTipologiaLegno()->getNome() + (p->getTipologiaLegno()->Spazzolato() ? " spazzolato. " : " non spazzolato. ") +"\n"+
                                                      " Colore interno: " + p->getColoreInterno() + " e colore esterno: " + p->getColoreEsterno() + "\n" +
                                                      "Metri quadri " + QString::number(p->MetriQuadri(), 'f', 2) + ", Trasmittanza termica "+ QString::number(p->TrasmittanzaTermica(), 'f', 3)+ " W/mq." )); //desc

            table->setItem(i, 2, new QTableWidgetItem(QString::number(quant)) ); //quantita
            table->setItem(i, 3, new QTableWidgetItem(QString::number(p->PrezzoFinale(), 'f', 2) + " €" )); //prezzo unit
            table->setItem(i, 4, new QTableWidgetItem(QString::number(p->PrezzoFinale() * quant, 'f', 2) + " €" )); //prezzo tot


            table->item(i, 1)->setTextAlignment(Qt::AlignCenter);
            table->item(i, 2)->setTextAlignment(Qt::AlignCenter);
            table->item(i, 3)->setTextAlignment(Qt::AlignCenter);
            table->item(i, 4)->setTextAlignment(Qt::AlignCenter);

            table->item(i, 0)->setFlags(table->item(i, 0)->flags() & ~Qt::ItemIsSelectable);
            table->item(i, 1)->setFlags(table->item(i, 1)->flags() & ~Qt::ItemIsSelectable);
            table->item(i, 2)->setFlags(table->item(i, 2)->flags() & ~Qt::ItemIsSelectable);
            table->item(i, 3)->setFlags(table->item(i, 3)->flags() & ~Qt::ItemIsSelectable);
            table->item(i, 4)->setFlags(table->item(i, 4)->flags() & ~Qt::ItemIsSelectable);




        }
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    } else {

        table->clearContents();
        table->setRowCount(0);


    }
}

MainWindow::MainWindow(const Model *_model, Controller* _controller, QWidget *parent)
    : QWidget(parent), model(_model), controller(_controller), table(new QTableWidget(this)), dialogGestioneProdotti(new DialogProdotti(model, controller, this)),
      dialogoModificaIntest(new DialogModificaIntestazione(model, controller, this)),
      dialogDettagliSerramento(new DialogMostraDettagliSerramento(this))
{

    QVBoxLayout* mainLayout = new QVBoxLayout;

    makeTopBar(mainLayout);
    makeIntestazione(mainLayout);

    QSplitter *sep = new QSplitter(this);
    mainLayout->addWidget(sep);

    table->setColumnCount(5);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);


    QStringList labels;
    labels.append("Serramento");
    labels.append("Descrizione");
    labels.append("Quantita'");
    labels.append("Prezzo unitario");
    labels.append("Prezzo totale");

    table->setHorizontalHeaderLabels(labels);

    QHeaderView* header = table->horizontalHeader();
    header->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(1, QHeaderView::Stretch);
    header->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    header->setSectionResizeMode(4, QHeaderView::ResizeToContents);

    mainLayout->addWidget(table);
    setLayout(mainLayout);

    setWindowIcon(QIcon(":icon/res/logo.jpg"));

    connect(table, SIGNAL(cellClicked(int,int)), this, SLOT(mostraDettagliSerramento(int,int)));

}

void MainWindow::showWarning(QString s) const {

    QMessageBox *mb = new QMessageBox();
    mb->setAttribute(Qt::WA_DeleteOnClose);
    mb->setIcon(QMessageBox::Warning);
    mb->setWindowTitle("Attenzione!");
    mb->setText(s);
    mb->show();

}

void MainWindow::mostraDialogArticoliAggiungi() {
    dialogGestioneProdotti->setTitolo("Aggiungi articolo");
    dialogGestioneProdotti->resetCampi();
    dialogGestioneProdotti->modalitaModifica(false);
    dialogGestioneProdotti->show();

}

void MainWindow::rimuoviProdotto() {
    if (model->getNumeroProdotti() == 0) {
        showWarning("Non ci sono articoli da rimuovere");
    } else {
        bool ok;
        unsigned int index = QInputDialog::getInt(this, "Rimuovi articolo", "Inserisci indice dell'articolo da rimuovere",
                                                 1, 1, model->getNumeroProdotti(), 1, &ok, Qt::WindowCloseButtonHint);
        if (ok)
            controller->rimuoviArticolo(index-1);
    }
}

void MainWindow::mostraDialogModificaIntestazione() {

    dialogoModificaIntest->riempiCampi(model->getDataPreventivo(), model->getCommessaPreventivo());
    dialogoModificaIntest->show();

}

void MainWindow::chiudiPreventivo() {
    auto ok = QMessageBox::warning(this, "Attenzione!", "Il preventivo sta per essere chiuso,\n assicurati che sia salvato altrimenti i dati andranno persi.",
                          QMessageBox::Ok|QMessageBox::Cancel);

    if (ok == QMessageBox::Ok)
        controller->setPreventivo(nullptr);

}

void MainWindow::modificaSconto() {
    bool ok;
    double sconto = QInputDialog::getDouble(this, "Modifica Sconto", "Inserisci lo sconto (puoi usare le frecce o scriverlo)",
                                             model->getScontoPreventivo(), 0, 100, 2, &ok, Qt::WindowCloseButtonHint);
    if (ok)
        controller->applicaSconto(sconto);
}

void MainWindow::nuovoPreventivo() {

    auto ok = QMessageBox::warning(this, "Attenzione!", "Verra' creato un nuovo preventivo, eventuali dati non salvati andranno persi.",
                          QMessageBox::Ok|QMessageBox::Cancel);

    if(ok == QMessageBox::Ok) {
        QDate oggi = QDate::currentDate();
        controller->setPreventivo(new Preventivo("Nuovo preventivo del "+ oggi.toString("dd.MM.yyyy"), oggi));
    }

}

void MainWindow::mostraDialogArticoliModifica() {
    if (model->getNumeroProdotti() == 0) {
        showWarning("Operazione impossibile, non ci sono prodotti da modificare!");
    } else {
        bool ok;
        unsigned int index = QInputDialog::getInt(this, "Modifica articolo", "Inserisci indice dell'articolo da modificare",
                                                 1, 1, model->getNumeroProdotti(), 1, &ok, Qt::WindowCloseButtonHint);
        index = index-1;

        if (ok) {
            DialogProdotti::Tabs tipo;

            if (table->item(index, 0)->text() == "SCURO" )
                tipo = DialogProdotti::Tabs::scuri;
            if (table->item(index, 0)->text() == "FINESTRA" ||
                table->item(index, 0)->text() == "PORTAFINESTRA")
                tipo = DialogProdotti::Tabs::finestre;
            if (table->item(index, 0)->text() == "PORTA" )
                tipo = DialogProdotti::Tabs::porte;

            dialogGestioneProdotti->setTitolo("Modifica articolo");
            dialogGestioneProdotti->riempiCampiModifica(tipo, model->getArticoloPreventivo(index));
            dialogGestioneProdotti->setTabDaVisualizzare(tipo);
            dialogGestioneProdotti->modalitaModifica(true, index);
            dialogGestioneProdotti->show();
        }
    }
}

void MainWindow::mostraDettagliSerramento(int row, int col) {

    if (col != 1) return;


    std::pair<Serramento*, unsigned int> art = model->getArticoloPreventivo(row);
    Serramento* ser = art.first;

    if (dynamic_cast<Scuro*>(ser)) {

        dialogDettagliSerramento->dettagliScuro(dynamic_cast<Scuro*>(ser), art.second);

    } else if (dynamic_cast<Porta*>(ser)) {

        dialogDettagliSerramento->dettagliPorta(dynamic_cast<Porta*>(ser), art.second);

    } else if (dynamic_cast<Finestra*>(ser)) {

        dialogDettagliSerramento->dettagliFinestra(dynamic_cast<Finestra*>(ser), art.second);
    }


    dialogDettagliSerramento->show();


}

bool MainWindow::onClose() {
    auto ok = QMessageBox::warning(this, "Attenzione!", "Il programma sta per essere chiuso, se non hai salvato tutti i dati andranno persi, sei sicuro di voler continuare?",
                          QMessageBox::Ok|QMessageBox::Cancel);

    if (ok == QMessageBox::Ok) {
        controller->setPreventivo(nullptr);
        return true;
    }
    else return false;
}

void MainWindow::salvaPreventivo() {

   QString filename = QFileDialog::getSaveFileName(this, "Salva preventivo",
                                "",
                               "JSON files (*.json)");
   if (!filename.isEmpty()) {
       controller->salvaPreventivo(filename);
       QMessageBox::information(this, "Info", "Il preventivo è stato salvato correttamente!", QMessageBox::Ok);
   }

}

void MainWindow::apriPreventivo() {
    auto ok = QMessageBox::warning(this, "Attenzione!", "Se apri un nuovo preventivo, eventuali dati non salvati andranno persi, vuoi continuare ?",
                              QMessageBox::Ok|QMessageBox::Cancel);

        if(ok == QMessageBox::Ok) {
            QString filename = QFileDialog::getOpenFileName(this, "Apri preventivo",
                                         "",
                                        "Any files (*);;JSON files (*.json)");
            if (!filename.isEmpty())
                controller->apriPreventivo(filename);
        }



}

void MainWindow::closeEvent( QCloseEvent* event )
{
    if(onClose())
        event->accept();
    else
        event->ignore();
}
