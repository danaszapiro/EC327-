#ifndef VIEW_H
#define VIEW_H

#include <iostream>


#include "Port.h"
#include "CartPoint.h"
#include "CartVector.h"
#include "GameObject.h"
#include "math.h"
#include "Dock.h"
#include "Sailor.h"
#include "model.h"
#include "GameCommand.h"

using namespace std;

const int view_maxsize=20;

class View
{
public:
    View();
    void clear();
    void plot(GameObject* otr);
    void draw();
    ~View();
    
private:
    int size;
    double scale;
    CartPoint origin;
    char grid[view_maxsize][view_maxsize][2];
    bool get_subscripts(int &ix, int &iy, CartPoint location);
};

#endif