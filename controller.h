#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include "preventivo.h"
#include "vetro.h"
#include "legno.h"
class Model;
class MainWindow;

class Controller : public QObject
{
    Q_OBJECT
public:
    Controller(QObject *parent = nullptr);
    void setModel(Model*);
    void setView(MainWindow*);

    void setPreventivo(Preventivo*);
    void applicaSconto(double);
    void modificaData(QDate);
    void modificaCommessa(QString);

    void aggiungiArticolo(Serramento*, unsigned int);
    void rimuoviArticolo(unsigned int);
    void modificaArticolo(unsigned int, Serramento*, unsigned int);



    void salvaPreventivo(QString) const;
    void apriPreventivo(QString);

private:
     Model *model;
     MainWindow *view;
};

#endif // CONTROLLER_H
