#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "model.h"
#include "controller.h"
#include "scuro.h"
#include "porta.h"
#include "finestra.h"

#include "dialogprodotti.h"
#include "dialogmodificaintestazione.h"
#include "dialogmostradettagliserramento.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QToolButton>
#include <QTableWidget>
#include <QSplitter>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QGroupBox>
#include <QInputDialog>
#include <QDate>
#include <QCloseEvent>

class MainWindow : public QWidget
{
    Q_OBJECT
private:

    void makeTopBar(QVBoxLayout*);
    void makeIntestazione(QVBoxLayout*);


    const Model* model;
    Controller* controller;
    QTableWidget *table;
    DialogProdotti *dialogGestioneProdotti;
    DialogModificaIntestazione *dialogoModificaIntest;
    DialogMostraDettagliSerramento *dialogDettagliSerramento;
    QLabel *l1, *l2, *l3, *l4, *l5;
    QToolButton *apri;
    QToolButton *nuovo;
    QToolButton *salva;
    QPushButton *but1, *but2, *but3, *but4, *but5, *but6;


public:
    MainWindow(const Model*, Controller*, QWidget *parent = nullptr);
    void showWarning(QString) const;
    virtual void closeEvent(QCloseEvent*);  //deve essere virtual

public slots:
    void mostraDialogArticoliAggiungi();
    void mostraDialogModificaIntestazione();
    void mostraDialogArticoliModifica();
    void rimuoviProdotto();
    void updateIntestazione(bool);
    void updatePreventivo(bool);
    void chiudiPreventivo();
    void modificaSconto();
    void nuovoPreventivo();
    void mostraDettagliSerramento(int, int);
    void salvaPreventivo();
    void apriPreventivo();
    bool onClose();

};
#endif // MAINWINDOW_H
