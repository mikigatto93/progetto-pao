#include "widgetvetri.h"

WidgetVetri::WidgetVetri() : QWidget(nullptr)
{
    QGridLayout *mainLayout = new QGridLayout;
    setLayout(mainLayout);

    l1 = new QLabel("Crea un nuovo vetro:");
    l2 = new QLabel("Coeff. termico");
    l3 = new QLabel("Prezzo base");
    l4 = new QLabel("Modello vetro");
    l5 = new QLabel("Canalina");
    l6 = new QLabel("Categoria");
    l7 = new QLabel("Gas interno");
    antisfondamento = new QCheckBox("Antisfondamento");
    le1 = new QLineEdit();
    le2 = new QLineEdit();
    le3 = new QLineEdit();
    cb1 = new QComboBox();
    cb2 = new QComboBox();
    cb3 = new QComboBox();

    //popolamento combobox
    cb1->addItem("Alluminio");
    cb1->addItem("Acciaio");
    cb1->addItem("Warm Edge");

    cb2->addItem("Temperato");
    cb2->addItem("Stratificato");
    cb2->addItem("Satinato");

    cb3->addItem("Aria");
    cb3->addItem("Argon");
    cb3->addItem("Xeno");
    mainLayout->addWidget(l1, 0, 0, 1, 2);
    mainLayout->addWidget(l2, 1, 0);
    mainLayout->addWidget(l3, 2, 0);
    mainLayout->addWidget(l4, 3, 0);
    mainLayout->addWidget(l5, 1, 2);
    mainLayout->addWidget(l6, 2, 2);
    mainLayout->addWidget(l7, 3, 2);
    mainLayout->addWidget(antisfondamento, 4, 0, 1, 2);
    mainLayout->addWidget(le1, 1, 1);
    mainLayout->addWidget(le2, 2, 1);
    mainLayout->addWidget(le3, 3, 1);
    mainLayout->addWidget(cb1, 1, 3);
    mainLayout->addWidget(cb2, 2, 3);
    mainLayout->addWidget(cb3, 3, 3);

}
