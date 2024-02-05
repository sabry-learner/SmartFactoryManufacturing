#include "Operation.h"

operation::operation(int n_resourse)
{
    if(n_resourse<1)
    {
        capacity_resources=10;
    }
    capacity_resources=n_resourse;
    resources_required=new Resource[capacity_resources];
    size_resources=0;
}
int operation::get_duration()
{
    return duration;
}
string operation::get_type()
{
    return type;
}
int operation::get_operation_id()
{
    return operation_id;
}
void operation::set_operation()
{
    cout<<"Enter Type of operation : ";
    getline(cin,type);
    cout<<"Enter Operation Id : ";
    cin>>operation_id;
    cin.ignore();
    cout<<"Enter Duration of Operation : ";
    cin>>duration;
    cin.ignore();
    int n_resource;
    cout<<"Enter Number of Resources Required : ";
    cin>>n_resource;
    cin.ignore();
    int i=1;
    while(n_resource--)
    {

        cout<<"Enter Info of Resource no ("<<i<<"):-\n";
        resources_required[size_resources].set_Resourse();
        size_resources++;

        i++;
    }
    cout<<"-----------------\n";
}
void operation::print()
{
    cout<<"==>The Info of Operation :-\n";
    cout<<"Type of operation = "<<type<<"\t\t";
    cout<<"Operation Id = "<<operation_id<<"\n";
    cout<<"Duration of Operation = "<<duration<<"\n";
    cout<<"=>The Info of Required Resources:-\n";
    if(size_resources>0)
    {
        for(int i=0; i<size_resources; i++)
        {
            cout<<"The Info of Resource no ("<<i+1<<") \n";
            cout<<resources_required[i];
            cout<<"--------------------------\n";
        }
    }
    else
        cout<<"No Resources Required in this Operation!!\n";

}
