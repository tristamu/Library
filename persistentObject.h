#ifndef PERSISTENTOBJECT_H
#define PERSISTENTOBJECT_H

#include <QList>
#include "persistentAttribute.h"
class PersistentObject
{
private:
    QList<PersistentAttribute *> *attributes;
    QString table;
    int id;
public:
    PersistentObject(QString,int);
    ~PersistentObject();
    void addAttribute(PersistentAttribute *);
    int save();
};

#endif // PERSISTENTOBJECT_H
