#include<iostream>
#include<assert.h>

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


template<class T>
struct Node
{
    T data{};
    Node<T>* next{};
    Node<T>(T d):data(d)
    {

    }
};
template<class T>
class Stack
{
private:
    Node<T>* head{};
    Node<T>* tail{};
    int length{};

public:
    Stack<T>()
    {

    }
    ~Stack<T>()
    {
        Node<T>*cur=head;
        while(head)
        {
            cur=head->next;
            delete head;
            head=cur;
        }
    }

    bool isEmpty()
    {
        return !head;
    }
    void push(T val)
    {
        Node<T>* newnode=new Node<T>(val);
        if(isEmpty())
        {
            tail=head=newnode;
        }
        else
        {
            newnode->next=head;
            head=newnode;
        }
        length++;
    }

    T peek()
    {
        assert(!isEmpty());
        return head->data;
    }
    void push_Back(T val)
    {
        Node<T>* newnode=new Node<T>(val);
        if(isEmpty())
        {
            head=tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
        length++;
    }
    void print()
    {
        for(Node<T>* cur=head; cur; cur=cur->next)
        {
            cout<<cur->data<<endl;
        }
    }

    void operator =(Stack<T>& other)
    {
        Node<T>* cur1=head;
        while(head)
        {
            cur1=head->next;
            delete head;
            head=cur1;
        }

        head=nullptr;
        for(Node<T>* cur2=other.head; cur2; cur2=cur2->next)
        {
            push_Back(cur2->data);
        }
    }


};

#endif // STACK_H_INCLUDED
