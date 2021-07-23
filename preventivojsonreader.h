#ifndef PREVENTIVOJSONREADER_H
#define PREVENTIVOJSONREADER_H
#include "preventivo.h"
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>

class PreventivoJsonReader
{
public:
    PreventivoJsonReader(QString);
    Preventivo* read() const;
    QString path;

};

#endif // PREVENTIVOJSONREADER_H
