#include"Resource.h"
Resource::Resource()
{
    resource_id=0;
    resource_name="NULL";
}
int Resource::get_id()
{
    return resource_id;
}
string Resource::get_name()
{
    return resource_name;
}
void Resource::set_Resourse()
{
    cout<<"Enter Resource Name : ";
    getline(cin,resource_name);
    cout<<"Enter Resource Id : ";
    cin>>resource_id;
    cin.ignore();
    cout<<"\x03\x03\x03\x03\x03\x03\n";
}
void Resource::print()
{
    if(resource_name=="NULL")
    {
        cout<<"No Resourse Required!!\n";
        return ;
    }
    cout<<"The Resource Details:- \n";
    cout<<"Resource Name = "<<resource_name<<"\t\t";
    cout<<"Resource Id = "<<resource_id<<endl;

}
