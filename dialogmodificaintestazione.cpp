#include "dialogmodificaintestazione.h"

DialogModificaIntestazione::DialogModificaIntestazione(const Model* m, Controller* c ,QWidget* parent):
    QDialog(parent, Qt::WindowCloseButtonHint), model(m), controller(c)
{

    QGridLayout *mainLayout = new QGridLayout;
    setLayout(mainLayout);

    l1 = new QLabel("Commessa");
    l2 = new QLabel("Data");
    le1 = new QLineEdit;
    de1 = new QDateEdit;
    ok = new QPushButton("Ok");
    cancel = new QPushButton("Cancella");
    /*ok->setMaximumWidth(80);
    cancel->setMaximumWidth(80);*/

    mainLayout->addWidget(l2, 0, 0);
    mainLayout->addWidget(l1, 1, 0);
    mainLayout->addWidget(le1, 1, 1);
    mainLayout->addWidget(de1, 0, 1);

    mainLayout->addWidget(ok, 2, 0);
    mainLayout->addWidget(cancel, 2, 1);

    connect( ok, SIGNAL(clicked()), this, SLOT(accept()) );
    connect( cancel, SIGNAL(clicked()), this, SLOT(reject()) );
    setWindowTitle("Modifica intestazione");
    setModal(true);

}

void DialogModificaIntestazione::riempiCampi(QDate d, QString com) {

    le1->setText(com);
    de1->setDate(d);

}

void DialogModificaIntestazione::accept() {

    controller->modificaData(de1->date());
    controller->modificaCommessa(le1->text());

    QDialog::accept();

}
