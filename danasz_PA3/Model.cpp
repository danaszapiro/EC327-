#include "Model.h"

//create all objects
Model::Model()
{
    this->time=0;
    object_ptrs = new GameObject*[10];
    dock_ptrs = new Dock*[3];
    sailor_ptrs = new Sailor*[3];
    port_ptrs = new Port*[5];
    
    dock_ptrs[0] = new Dock::Dock(1, CartPoint(5,1));
    dock_ptrs[1] = new Dock::Dock(2, CartPoint(6,2));
    dock_ptrs[2] = new Dock::Dock(3, CartPoint(1,8));
    sailor_ptrs[0] = new Sailor::Sailor(1, dock_ptrs[0]);
    sailor_ptrs[1] = new Sailor::Sailor(2, dock_ptrs[1]);
    sailor_ptrs[2] = new Sailor::Sailor(3, dock_ptrs[2]);
    port_ptrs[0] = new Port::Port(1, CartPoint(1,20));
    port_ptrs[1] = new Port::Port(2, CartPoint(20,1));
    port_ptrs[2] = new Port::Port(3, CartPoint(20,20));
    port_ptrs[3] = new Port::Port(4, CartPoint(7,2));
    object_ptrs[0]=dock_ptrs[0];
    object_ptrs[1]=dock_ptrs[1];
    object_ptrs[2]=dock_ptrs[2];
    object_ptrs[3]=sailor_ptrs[0];
    object_ptrs[4]=sailor_ptrs[1];
    object_ptrs[5]=sailor_ptrs[2];
    object_ptrs[6]=port_ptrs[0];
    object_ptrs[7]=port_ptrs[1];
    object_ptrs[8]=port_ptrs[2];
    object_ptrs[9]=port_ptrs[3];
    num_objects = 10;
    num_sailors = 3;
    num_ports = 4;
    num_docks = 3;
    cout<<"Model default constructed"<<endl;
}

//destructor

Model::~Model()
{
   for(int i=0; i<10; i++)
       object_ptrs[i]->~GameObject();
       cout<<"Model destruced"<<endl;
}


//get poiner to object functions. itinerates through arrays and look for specific object with corresponding ID.
Sailor* Model::get_Sailor_ptr(int id_num)
{
    for(int i = 0; i<3 ; i++)
    {
        if(sailor_ptrs[i]->get_id()==id_num)
            return sailor_ptrs[i];
    }
    return NULL;
}

Port* Model::get_Port_ptr(int id_num)
{
    for(int i = 0; i<4 ; i++)
    {
        if(port_ptrs[i]->get_id()==id_num)
            return port_ptrs[i];
    }
    return NULL;
}

Dock* Model::get_Dock_ptr(int id_num)
{
    for(int i = 0; i<3 ; i++)
    {
        if(dock_ptrs[i]->get_id()==id_num)
            return dock_ptrs[i];
    }
    return NULL;
}

//update function. calls a pure virtual update function in GameObject to update all objects. Increments time.
bool Model::update()
{
    bool ifChanged=false;
    this->time++;
    for(int i = 0; i<10 ; i++)
    {
      bool check=object_ptrs[i]->update();
        if (check == true)
        {
            ifChanged=true;  
        }
    }
    return ifChanged;
}

void Model::display(View& view)
{
    cout<<"Time: "<<this->time<<endl;
    view =View();
    view.clear();
    for(int i = 0; i<9 ; i++)
    {
      view.plot(object_ptrs[i]); 
    }
    view.draw();
}

void Model::show_status()
{
    for(int i = 0; i<10 ; i++)
    {
      object_ptrs[i]->show_status();  
    }
    
}



