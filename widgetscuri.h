#ifndef WIDGETSCURI_H
#define WIDGETSCURI_H
#include "widgetitemgenerico.h"
#include "scuro.h"
#include "model.h"
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QGroupBox>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QSpinBox>
#include <QDoubleSpinBox>

class WidgetScuri: public WidgetItemGenerico
{
    Q_OBJECT
public:
    WidgetScuri(const Model*);
    bool verificaDati() const override;
    void generaProdotto(Scuro*& ) const;
    void resetCampi() override;
    void riempiCampi(const Scuro*);
private:
    const Model* model;
    QLabel *l0, *l1, *l2, *l3, *l4, *l5, *l6, *l7,
           *l8, *l9, *l10, *l11, *l12, *l13;
    QLineEdit *le0, *le1, *le2, *le4, *le5;
    QComboBox *cb1, *cb2, *cb3, *cb4, *cb5, *cb6,
              *cb8;
    QDoubleSpinBox *dsp1;
    QCheckBox *spazzlegno;

};

#endif // WIDGETSCURI_H
