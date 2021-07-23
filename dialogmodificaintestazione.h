#ifndef DIALOGMODIFICAINTESTAZIONE_H
#define DIALOGMODIFICAINTESTAZIONE_H
#include "model.h"
#include "controller.h"
#include <QWidget>
#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QPushButton>

class DialogModificaIntestazione : public QDialog
{
public:
    DialogModificaIntestazione(const Model*, Controller*, QWidget* = nullptr);
    void riempiCampi(QDate, QString);
private:
    const Model* model;
    Controller* controller;
    QLabel *l1, *l2;
    QLineEdit *le1;
    QDateEdit *de1;
    QPushButton *ok, *cancel;

public slots:
    void accept();
};

#endif // DIALOGMODIFICAINTESTAZIONE_H
