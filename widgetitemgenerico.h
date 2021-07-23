#ifndef WIDGETITEMGENERICO_H
#define WIDGETITEMGENERICO_H
#include "baseitem.h"
#include <QWidget>

class WidgetItemGenerico : public QWidget
{
    Q_OBJECT
public:
    WidgetItemGenerico(QWidget *parent = nullptr);
    void showWarning(QString) const;
    virtual bool verificaDati() const = 0;
    virtual void resetCampi() = 0;
};

#endif // WIDGETITEMGENERICO_H
