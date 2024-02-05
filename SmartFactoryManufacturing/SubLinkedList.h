#include<iostream>
#include<assert.h>
#ifndef SUBLINKEDLIST_H_INCLUDED
#define SUBLINKEDLIST_H_INCLUDED


template<typename T>
struct NodeList
{
    T* data{};
    int rear{};
    int Front{};
    int Size{};
    int added_elements{};
    NodeList<T>* next{};
    NodeList<T>(int s=8):Size(s)
    {
        data=new T[Size];
        rear=Front=0;
        added_elements=0;
    }
    T delete_front()
    {
        assert(!isEmpty());
        T value=data[Front];
        Front=(Front+1)%Size;
        added_elements--;
        return value;
    }
    void Set(T val)
    {
        assert(!isFull());
        data[rear]=val;
        rear=(rear+1)%Size;
        added_elements++;
    }

    void print()
    {
        if(added_elements<1)
        {
            cout<<added_elements<<" is empty\n";
            return ;
        }
        for(int i=Front,steps=0; steps<added_elements; i=(i+1)%Size,steps++)
        {
            cout<<data[i];
        }
        cout<<"\n";
    }
    bool isEmpty()
    {
        return added_elements==0;
    }
    bool isFull()
    {
        return added_elements==Size;
    }

    ~NodeList<T>()
    {
        delete [] data;
        data=nullptr;
    }


};
template<class T>
class SubLinkedList
{
private:
    NodeList<T>* head{};
    NodeList<T>* tail{};
    int length{};
    int n_nodes{};
    int capacity_arr{};
public:
    SubLinkedList<T>(int cap=2)
    {
        n_nodes=0;
        length=0;
        head=tail=nullptr;
        capacity_arr=cap;
    }
    ~SubLinkedList<T>()
    {
        NodeList<T>* temp=head;
        while(head)
        {
            temp=head->next;
            delete head;
            head=temp;
        }
    }
    bool isEmpty()
    {
        return !head;
    }
    void enqueue(T val)
    {

        if(isEmpty())
        {
            NodeList<T>* newnode=new NodeList<T>(capacity_arr);
            newnode->Set(val);


            head=tail=newnode;

            n_nodes++;
        }
        else if(tail->isFull())
        {
            NodeList<T>* newnode=new NodeList<T>(capacity_arr);
            newnode->Set(val);
            tail->next=newnode;
            tail=newnode;
            tail->next=nullptr;
            n_nodes++;
        }
        else
        {
            tail->Set(val);

        }
        length++;
    }
    T dequeue()
    {
        assert(!isEmpty());
        T val=head->delete_front();

        if(head->isEmpty())
        {
            if(head==tail)
            {
                delete head;
                head=tail=nullptr;
            }
            else
            {
                NodeList<T>* del_head=head;
                head=head->next;
                delete del_head;
                del_head=nullptr;

            }
            n_nodes--;
        }

        length--;

        return val;
    }
    void display()
    {

        NodeList<T>* cur=head;
        if(!cur)
        {
            cout<<"The Sub Linked List is Empty!!\n";
            return ;
        }
        int i=1;
        int n=n_nodes;
        while(n--)
        {
            cout<<"Factory no ("<<i<<")"<<endl;
            cur->print();

            cur=cur->next;
            i++;

        }
    }




};

#endif // SUBLINKEDLIST_H_INCLUDED
