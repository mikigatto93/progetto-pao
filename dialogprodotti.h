#ifndef DIALOGPRODOTTI_H
#define DIALOGPRODOTTI_H
#include "model.h"
#include "controller.h"
#include "widgetitemgenerico.h"
#include "widgetfinestre.h"
#include "widgetporte.h"
#include "widgetscuri.h"

#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QTabWidget>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QLineEdit>
#include <QComboBox>
#include <QRadioButton>
#include <QSpinBox>



class DialogProdotti : public QDialog
{
public:
    enum Tabs {
        scuri, finestre, porte
    };

    DialogProdotti(const Model* model, Controller*, QWidget* = nullptr);
    void resetCampi();
    void riempiCampiModifica(Tabs, std::pair<Serramento*, unsigned int>);
    void modalitaModifica(bool, int=-1);
    void setTabDaVisualizzare(Tabs);
    void setTitolo(QString);
private:
      WidgetScuri *tab_scuri;
      WidgetFinestre *tab_finestre;
      WidgetPorte  *tab_porte;

    QSpinBox* quant;
    QLabel *l1;
    QTabWidget* tabs;
    const Model* model;
    Controller* controller;
    QPushButton *ok, *cancella;
    bool modalita;
    int indiceArticoloDaModificare;

public slots:
    void accept();

};

#endif // DIALOGPRODOTTI_H
