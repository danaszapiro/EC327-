#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <iostream>
#include "CartPoint.h"
using namespace std;


class GameObject
{
public:
    GameObject(char, int);
    GameObject(char, int, CartPoint);
    CartPoint get_location();
    int get_id();
    virtual void show_status();
    virtual ~GameObject();
    virtual bool update()=0;
    void drawself(char* grid);
protected:
    CartPoint location;
    char display_code;
    char state;
private:
    int id_num;

}; 

#endif