#include "GameCommand.h"

void do_sail_command(Model* model)
{
    int ID;
    cin>>ID;
    Sailor* sailor=model->get_Sailor_ptr(ID);
    if(sailor!=(Sailor*)NULL)
    {
        double x, y;
        cin>>x>>y;
        CartPoint dest= CartPoint(x,y);
        sailor->start_sailing(dest);
    }
}

void do_go_command(Model* model)
{
    cout<<"Advancing time one tick"<<endl;
    model->update();
}

void do_run_command(Model* model)
{   
    cout<<"Advancing to next event or 5 ticks"<<endl;
    int i=1;
    bool updatecheck = false;
    while(updatecheck!= true && i<=5)
    {
        updatecheck=model->update();
        i++;
    }
}

void do_port_command(Model* model)
{
    int ID1, ID2;
    cin>>ID1>>ID2;
    Sailor* sailor=model->get_Sailor_ptr(ID1);
    Port* port=model->get_Port_ptr(ID2);
    if(sailor!=(Sailor*)NULL && port!=(Port*)NULL)
    {
        sailor->start_supplying(port);
    }
}
void do_hide_command(Model* model)
{
    int ID;
    cin>>ID;
    Sailor* sailor=model->get_Sailor_ptr(ID);
    if(sailor!=(Sailor*)NULL)
    {
        sailor->start_hiding();
    }
}

void do_anchor_command(Model* model)
{
    int ID;
    cin>>ID;
    Sailor* sailor=model->get_Sailor_ptr(ID);
    if(sailor!=(Sailor*)NULL)
    {
        sailor->anchor();
    }
}
void do_list_command(Model* model)
{
    model->show_status();
}
    
void do_dock_command(Model* model)
    {
    int ID1, ID2;
    cin>>ID1>>ID2;
    Sailor* sailor=model->get_Sailor_ptr(ID1);
    Dock* dock=model->get_Dock_ptr(ID2);
    if(sailor!=(Sailor*)NULL && dock!=(Dock*)NULL)
    {
        sailor->start_docking(dock);
    }
}

