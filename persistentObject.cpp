#include"persistentObject.h"

PersistentObject::PersistentObject(QString className){
    attributes = NULL;
    id = 0;
    *table = className;
}

void PersistentObject::addAttribute(PersistentAttribute * attri){
    attributes->append(attri);
}

int PersistentObject::save(){
    return id;
}
