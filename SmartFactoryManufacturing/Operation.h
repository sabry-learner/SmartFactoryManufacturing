#include"Resource.h"
#ifndef OPERATION_H
#define OPERATION_H



class operation
{
private:
    Resource* resources_required ;
    int size_resources{};
    int capacity_resources{};
    int duration{};
    string type{};
    int operation_id{};
public:
    operation(int n_resource=10);
    int get_duration();
    string get_type();
    int get_operation_id();
    void set_operation();
    void print();
    friend ostream& operator<<(ostream& out,operation& op)
    {
        op.print();
        return out;
    }
    friend istream& operator>> (istream& in,operation& op)
    {
        op.set_operation();
        return in;
    }
};
#endif // OPERATION_H
