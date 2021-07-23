#include "widgetitemgenerico.h"
#include "qmessagebox.h"

WidgetItemGenerico::WidgetItemGenerico(QWidget *parent) : QWidget(parent)
{

}


void WidgetItemGenerico::showWarning(QString s) const {

    QMessageBox *mb = new QMessageBox();
    mb->setAttribute(Qt::WA_DeleteOnClose);
    mb->setIcon(QMessageBox::Warning);
    mb->setWindowTitle("Attenzione!");
    mb->setText(s);
    mb->show();

}
