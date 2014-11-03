#include"persistentObject.h"
#include<iostream>

PersistentObject::PersistentObject(QString className,int isbn){
    attributes = new QList<PersistentAttribute *>();
    id = isbn;
    table = className;
}

PersistentObject::~PersistentObject(){
    delete(attributes);
    std::cout << "destructor of persistantObject" << std::endl;
}
void PersistentObject::addAttribute(PersistentAttribute * attri){
    attributes->append(attri);
    std::cout << "persistentObject length is "<<attributes->length() << std::endl;
}

int PersistentObject::save(){
    return id;
}
