#include "persistentAttribute.h"

PersistentAttribute::PersistentAttribute(QString *name, QVariant::Type type, void *data){
    //this->name = name;
    this->type = type;
    this->data = data;
}

PersistentAttribute::~PersistentAttribute(){
    //cout<< "destructor" << endl;
}
