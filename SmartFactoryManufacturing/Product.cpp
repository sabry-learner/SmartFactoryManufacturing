#include "Product.h"
Product::Product()
{

    product_name="NULL";
    product_type="NULL";
    product_id=0;

}
void Product::set_product()
{
    cout<<"Enter Product Name: ";
    getline(cin,product_name);
    cout<<"Enter Product Id : ";
    cin>>product_id;
    cin.ignore();
    cout<<"Enter Type of Product : ";
    getline(cin,product_type);
    int n;
    cout<<"Enter number of Product's Operations : ";
    cin>>n;
    cin.ignore();
    assert(n>=0);
    int i=1;
    while(n--)
    {
        operation newop;
        cout<<"Add a new Operation Info no "<<i<<":-\n";
        newop.set_operation();
        manufacturingSteps.push(newop);
        cout<<endl;
        i++;
    }
    cout<<"The Product Added Successfully \x03\n";
}
void Product::addStep(operation newstep)
{
    manufacturingSteps.push(newstep);
}


void Product::print()
{
    cout<<"*****The Info of Product*****\n";
    cout<<"Product Name: "<<product_name<<"\t\t|| ";
    cout<<"Product Id = "<<product_id<<endl;
    cout<<"Product Type : "<<product_type<<endl;
    cout<<"=>The All Operations of Product :-\n";
    if(!manufacturingSteps.isEmpty())
        manufacturingSteps.print();
    else
        cout<<"There are no operations of Product!!\n";
    cout<<"--------------------------------------------\n";

}
void Product::operator=(Product& otherp)
{

    manufacturingSteps=otherp.manufacturingSteps;

    product_id=otherp.product_id;
    product_name=otherp.product_name;
    product_type=otherp.product_type;

}
