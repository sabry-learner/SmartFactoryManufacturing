#include "SmartFactory.h"

SmartFactory::SmartFactory()
{

    n_product=0;
}
void SmartFactory::add_product()
{
    Product newprod;
    newprod.set_product();
    products_list.enqueue(newprod);
    n_product++;
}
void SmartFactory::remove_product()
{
    if (n_product > 0) {
        products_list.dequeue();
        n_product--;
        cout << "The Product is Removed Successfully \x02\n";
    } else {
        cout << "No products to remove.\n";
    }
}
void SmartFactory::display()
{
    cout<<"###############################################################\n";
    cout<<"^^^^^^^^^Displaying All Products Info In Smart Factory^^^^^^^^^\n\n";
    cout<<"The All Products In Smary Factory = "<<n_product<<endl;
    products_list.display();

}
