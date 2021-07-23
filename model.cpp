#include "model.h"

Model::Model():preventivo(nullptr), sconto_preventivo(0) {}

void Model::setPreventivoCorrente(Preventivo* p) {
    delete preventivo;
    preventivo = p;
}

void Model::serializePreventivo(QJsonObject& json) {

    preventivo->Serialize(json);
}


unsigned int Model::getNumeroProdotti() const {
    return preventivo->getNumeroProdotti();
}
double Model::getTotalePreventivoFinale() const {
    return preventivo->getTotale() * (1 - sconto_preventivo/100) ;
}

QString Model::getCommessaPreventivo() const {
    return preventivo->getCommessa();
}

void Model::setCommessaPreventivo(QString com) {
    preventivo->setCommessa(com);
}

QDate Model::getDataPreventivo() const {
    return preventivo->getData();
}

void Model::setDataPreventivo(QDate d) {
    if (preventivo == nullptr) return;
    return preventivo->setData(d);
}

void Model::aggiungiArticoloPreventivo(Serramento* p, unsigned int q) {
    if (preventivo == nullptr) return ;
    preventivo->aggiungiArticolo(p, q);
}

bool Model::rimuoviArticoloPreventivo(unsigned int i) {
    if (preventivo == nullptr) return false;
    return preventivo->rimuoviArticolo(i);
}

bool Model::scambiaPosizioneArticoloPreventivo(unsigned int i, unsigned int j) {
    if (preventivo == nullptr) return false;
    return preventivo->scambiaPosizione(i, j);
}

void Model::setScontoPreventivo(double s) {
    sconto_preventivo = s;
}

std::pair<Serramento*, unsigned int> Model::getArticoloPreventivo(unsigned int i) const {
    if (preventivo == nullptr) return std::pair<Serramento*, unsigned int>(nullptr, 0);
    return preventivo->getArticolo(i);
}

bool Model::modificaArticoloPreventivo(unsigned int i, Serramento* p, unsigned int quant) {
    if (preventivo == nullptr) return false;
    preventivo->aggiungiArticolo(p, quant); // aggiungo il nuovo prodotto alla fine
    return
        preventivo->scambiaPosizione(i, preventivo->getNumeroProdotti()-1) &&
        preventivo->rimuoviArticolo(preventivo->getNumeroProdotti()-1);

}

double Model::getScontoPreventivo() const {
    return sconto_preventivo;
}



