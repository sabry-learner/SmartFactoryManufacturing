#include"Product.h"
#include"SubLinkedList.h"
#ifndef SMARTFACTORY_H
#define SMARTFACTORY_H

class SmartFactory
{
private:

    SubLinkedList<Product> products_list;
    int n_product{};

public:
    SmartFactory();
    void add_product();
    void remove_product();
    void display();

};

#endif // SMARTFACTORY_H
