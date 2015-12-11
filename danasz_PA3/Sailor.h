#ifndef SAILOR_H
#define SAILOR_H
#include <iostream>


#include "Port.h"
#include "CartPoint.h"
#include "CartVector.h"
#include "GameObject.h"
#include "math.h"
#include "Dock.h"
using namespace std;

class Dock;

class Sailor : public GameObject
{
public:
    Sailor();
    Sailor(int, Dock*);
    bool update();
    double originalsize;
    double get_size();
    double get_cargo();
    void start_sailing(CartPoint);
    void start_supplying(Port* destPort);
    void start_hiding();
    bool is_hidden();
    void start_docking(Dock*);
    void anchor();
    void show_status();
    double get_speed();
    ~Sailor();
private:
    double health, size, hold, cargo;
    CartPoint destination;
    CartVector delta;
    Port* port;
    Dock* dock;
    Dock* hideout;
    bool update_location();
    void setup_destination(CartPoint);    
};
#endif