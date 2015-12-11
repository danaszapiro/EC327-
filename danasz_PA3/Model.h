#ifndef MODEL_H
#define MODEL_H

#include <iostream>


#include "Port.h"
#include "CartPoint.h"
#include "CartVector.h"
#include "GameObject.h"
#include "math.h"
#include "Dock.h"
#include "Sailor.h"
#include "View.h"
using namespace std;

class View;

class Model
{
public:
    Model();
    ~Model();
    Sailor* get_Sailor_ptr(int id_num);
    Port* get_Port_ptr(int id_num);
    Dock* get_Dock_ptr(int id_num);
    bool update();
    void display(View& view);
    void show_status();
private:
    int time;
    GameObject** object_ptrs;
    int num_objects;
    Sailor** sailor_ptrs;
    int num_sailors;
    Dock** dock_ptrs;
    int num_docks;
    Port** port_ptrs;
    int num_ports;
};


#endif