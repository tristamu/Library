#include "persistentAttribute.h"
#include<iostream>

PersistentAttribute::PersistentAttribute(QString *nom, QVariant::Type typ, void *donnee){
    name = *nom;
    type = typ;
    data = donnee;
}

PersistentAttribute::~PersistentAttribute(){
    std::cout<< "destructor" << std::endl;
}
