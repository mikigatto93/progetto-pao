#ifndef WIDGETPORTE_H
#define WIDGETPORTE_H
#include "widgetitemgenerico.h"
#include "porta.h"
#include "model.h"
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QGroupBox>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QSpinBox>
#include <QSpacerItem>
#include <QDoubleSpinBox>
#include <QRegExp>

class WidgetPorte: public WidgetItemGenerico
{
    Q_OBJECT
public:
    WidgetPorte(const Model*);
    void generaProdotto(Porta*&) const;
    bool verificaDati() const override;
    void resetCampi() override;
    void riempiCampi(const Porta* p);
private:

    const Model* model;
    QLabel *l0, *l1, *l2, *l3, *l4, *l5, *l6, *l7,
           *l8, *l9, *l10, *l11, *l12, *l13, *l14;
    QLineEdit *le0, *le1, *le2, *le4, *le5;
    QComboBox *cb1, *cb2, *cb3, *cb4, *cb5, *cb6,
              *cb8;
    QSpinBox *sp1;
    QDoubleSpinBox *dsp1;
    QCheckBox *spazzlegno;


};

#endif // WIDGETPORTE_H
