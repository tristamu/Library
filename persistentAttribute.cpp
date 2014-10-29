#include "persistentAttribute.h"

PersistentAttribute::PersistentAttribute(QString *nom, QVariant::Type typ, void *donnee){
    name = nom;
    type = typ;
    data = donnee;
}

PersistentAttribute::~PersistentAttribute(){
    //cout<< "destructor" << endl;
}
