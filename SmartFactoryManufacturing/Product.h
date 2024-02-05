#include"Operation.h"
#include"Stack.h"
#ifndef PRODUCT_H
#define PRODUCT_H


class Product
{
private:
    Stack<operation> manufacturingSteps;
    int product_id{};
    string product_name{};
    string product_type{};
public:
    Product();
    void set_product();
    void addStep(operation newstep);

    void print();
    void operator=(Product& otherp);
    friend ostream& operator<<(ostream& out,Product& p)
    {
        out<<"*****The Info of Product*****\n";
        out<<"Product Name: "<<p.product_name<<"\t\t|| ";
        out<<"Product Id = "<<p.product_id<<endl;
        out<<"Product Type : "<<p.product_type<<endl;
        out<<"=>The All Operations of Product :-\n";
        if(!p.manufacturingSteps.isEmpty())
            p.manufacturingSteps.print();
        else
            out<<"There are no operations of Product!!\n";
        out<<"--------------------------------------------\n";

        return out;
    }
    friend istream& operator>>(istream& in,Product& p)
    {
        cout<<"Enter Product Name: ";
        getline(in,p.product_name);
        cout<<"Enter Product Id : ";
        in>>p.product_id;
        in.ignore();
        cout<<"Enter Type of Product : ";
        getline(in,p.product_type);
        int n;
        cout<<"Enter number of Product's Operations : ";
        in>>n;

        in.ignore();
        assert(n>=0);
        int i=1;
        while(n--)
        {
            operation newop;
            cout<<"Add a new Operation Info no "<<i<<":-\n";
            newop.set_operation();
            p.manufacturingSteps.push(newop);
            cout<<endl;
            i++;
        }
        cout<<"The Product Added Successfully \x03\n";
        return in;
    }
};

#endif // PRODUCT_H
