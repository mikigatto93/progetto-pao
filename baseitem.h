#ifndef BASEITEM_H
#define BASEITEM_H
#include <QJsonObject>

class BaseItem
{
public:
    BaseItem();
    virtual ~BaseItem() = default;
    virtual BaseItem* clone() const = 0;
    virtual void Serialize(QJsonObject&) const = 0;
};

#endif // BASEITEM_H
