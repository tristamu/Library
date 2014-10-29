#ifndef PERSISTENTATTRIBUTE_H
#define PERSISTENTATTRIBUTE_H

#include <QVariant>
class PersistentAttribute
{
public:
QString name;
QVariant::Type type;
void *data;
PersistentAttribute(QString *, QVariant::Type, void *);
~PersistentAttribute();
};

#endif // PERSISTENTATTRIBUTE_H
