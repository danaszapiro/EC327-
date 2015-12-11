#include "sailor.h"

Sailor::Sailor():GameObject('S',0)
{
    this->state='h';
    this->health=25;
    this->size=15;
    this->hold=100;
    this->cargo=0;
    destination CartPoint();
    port=NULL;
    dock=NULL;
    hideout=NULL;
    cout<<"Sailor default constructed"<<endl;
}