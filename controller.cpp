#include "controller.h"
#include "mainwindow.h"
#include "controller.h"
#include "preventivojsonreader.h"
#include <QJsonDocument>
#include "qfile.h"

Controller::Controller(QObject *parent) : QObject(parent) {}


void Controller::setModel(Model* m) {
    model = m;
}

void Controller::setView(MainWindow* w) {
    view = w;
}

void Controller::setPreventivo(Preventivo* p) {
    model->setPreventivoCorrente(p);
    bool nessunPreven = (p == nullptr);  //non mostrare nessun preventivo se è stato premiuto chiudi preventivo
    view->updateIntestazione(nessunPreven);
    view->updatePreventivo(nessunPreven);
}

void Controller::applicaSconto(double sconto) {
    model->setScontoPreventivo(sconto);
    view->updateIntestazione(false);
}

void Controller::modificaData(QDate d) {
    model->setDataPreventivo(d);
    view->updateIntestazione(false);
}

void Controller::modificaCommessa(QString comm) {
    model->setCommessaPreventivo(comm);
    view->updateIntestazione(false);
}

void Controller::aggiungiArticolo(Serramento* p, unsigned int quant) {
    model->aggiungiArticoloPreventivo(p, quant);
    view->updatePreventivo(false);
}


void Controller::rimuoviArticolo(unsigned int index) {

     bool res = model->rimuoviArticoloPreventivo(index);
     if (!res)
         view->showWarning("L'indice inserito non è corretto, operazione non eseguita");
     else
         view->updatePreventivo(false);
}

void Controller::modificaArticolo(unsigned int index, Serramento* p, unsigned int quant) {
    bool res = model->modificaArticoloPreventivo(index, p, quant);
    if (!res)
        view->showWarning("L'indice inserito non è corretto, operazione non eseguita");
    else
         view->updatePreventivo(false);
}


void Controller::salvaPreventivo(QString path) const {
    QFile file(path);

        if (!file.open(QIODevice::WriteOnly))
            view->showWarning("Errore apertura file: " + file.errorString());

        else {
            QJsonObject dati;
            model->serializePreventivo(dati);
            file.write(QJsonDocument(dati).toJson());
        }


}

void Controller::apriPreventivo(QString path) {

    PreventivoJsonReader reader(path);
    Preventivo *p = reader.read();

    if (p == nullptr)
        view->showWarning("Errore nella lettura del file.");
    else
        setPreventivo(p);

}






