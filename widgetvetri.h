#ifndef WIDGETVETRI_H
#define WIDGETVETRI_H
#include <QWidget>
#include <QGridLayout>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>

class WidgetVetri : public QWidget
{
    Q_OBJECT
public:
    WidgetVetri();

private:
    QLabel *l1, *l2, *l3, *l4, *l5, *l6, *l7;
    QLineEdit *le1, *le2, *le3;
    QComboBox *cb1, *cb2, *cb3;
    QCheckBox *antisfondamento;


};

#endif // WIDGETVETRI_H
