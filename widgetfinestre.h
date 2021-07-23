#ifndef WIDGETFINESTRE_H
#define WIDGETFINESTRE_H
#include "widgetitemgenerico.h"
#include "finestra.h"
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

class WidgetFinestre: public WidgetItemGenerico
{
    Q_OBJECT
public:
    WidgetFinestre(const Model*);
    void generaProdotto(Finestra*&) const;
    bool verificaDati() const override;
    void resetCampi() override;
    void riempiCampi(const Finestra*);
private:
    const Model* model;
    QLabel *l0, *l1, *l2, *l3, *l4, *l5, *l6,
           *l7, *l8, *l9, *l10, *l11, *l12, *l13, *l14,
           *l15, *l16, *l17, *l18, *l19, *l20, *l21;
    QLineEdit *le0, *le1, *le2, *le4, *le5, *le7, *le8;
    QComboBox *cb0, *cb1, *cb2, *cb3, *cb5, *cb6, *cb8,
              *cb10, *cb11, *cb12;
    QDoubleSpinBox *dsp1, *dsp2;
    QCheckBox *ribal,  *spazzlegno, *antisfondamento;


};

#endif // WIDGETFINESTRE_H
