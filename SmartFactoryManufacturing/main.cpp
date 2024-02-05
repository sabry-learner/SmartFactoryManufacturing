#include <iostream>
#include"SmartFactory.h"



using namespace std;


int main()
{

    SmartFactory sf;

    while(true){
        cout<<"\t\t\t____________________\n";
        cout<<"\t\t\t|Smart Factory APP |\n";
        cout<<"\t\t\t|__________________|\n\n";
        cout<<"\t1 - Add Product In Smart Factory\n";
        cout<<"\t2 - Remove Product From Factory\n";
        cout<<"\t3 - Display All Product In Smart Factory\n";
        cout<<"\t0 - Exit\n";
        cout<<"=>Enter Choice Here : ";
        int ch;
        cin>>ch;
        cin.ignore();
        switch(ch){
        case 1:
            sf.add_product();
            break;
        case 2:
            sf.remove_product();
            break;
        case 3:
            sf.display();
            break;
        case 0:
        {
                system("cls");
                cout<<"\t\tThanks For Using My Program :)\n";
                exit(0);
        }
        default:
            cout<<"Invalid Input , Try Again!!\n";
            break;
        }

    }
    return 0;
}
