#include<iostream>

using namespace std;
#ifndef RESOURCE_H_INCLUDED
#define RESOURCE_H_INCLUDED


class Resource
{
private:
    int resource_id{};
    string resource_name{};
public:
    Resource();
    int get_id();
    string get_name();
    void set_Resourse();
    void print();
    friend ostream& operator<<(ostream& out,Resource& r)
    {
        if(r.resource_name=="NULL")
        {
            out<<"No Resourse Required!!\n";
            return out ;
        }
        out<<"The Resource Details:- \n";
        out<<"Resource Name = "<<r.resource_name<<"\t\t";
        out<<"Resource Id = "<<r.resource_id<<endl;

        return out;
    }
    friend istream& operator>>(istream& in,Resource& r)
    {
        r.set_Resourse();
        return in;
    }

};

#endif // RESOURCE_H_INCLUDED
