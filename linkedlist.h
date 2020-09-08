#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstddef>
#include <iostream>

#include "listnode.h"

using namespace std;

class EmptyException { };

template <class T>
class LinkedList
{
public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    virtual ~LinkedList()
    {
        ListNode<T> *tmp = head;
        while(head != NULL)
        {
            head = head->next;
            delete tmp;
            tmp = head;
        }
        head = NULL;
        tail = NULL;
    }

    void push_front(T value)
    {
        head = new ListNode<T>(value, head);
        if(tail == NULL)
        {
            tail = head;
        }
    }

    void push_back(T value)
    {
        if(head == NULL)
        {
            push_front(value);
        }
        else
        {
            ListNode<T> *newNode = new ListNode<T>(value, NULL);
            tail->next = newNode;
            tail = newNode;
        }
    }

    T pop_front()
    {
        if(head == NULL)
        {
            throw EmptyException();
        }
        T data = head->data;
        ListNode<T> *tmpNode = head;
        head = head->next;
        if(head == NULL)
        {
            tail = head;
        }
        delete tmpNode;
        return data;
    }

    // This is the public reverse function, called from the outside
    void reverse()
    {
        if(head == NULL)
        {
            throw EmptyException();
        }
        else
        {
            tail = reverse(head);
            tail->next = NULL;
        }
    }

    friend ostream& operator <<(ostream& outs, const LinkedList<T> &lis)
    {
        ListNode<T> *tmpNode = lis.head;
        while(tmpNode != NULL)
        {
            outs << tmpNode->data << " ";
            tmpNode = tmpNode->next;
        }
        return outs;
    }

private:

    ListNode<T> *reverse(ListNode<T> *nextNode)
    {
        if(nextNode->next == NULL)      //BASE CASE
        {
            head = nextNode;
            return nextNode;
        }
        else                            //RECURSION
        {
            ListNode<T> *temp = reverse(nextNode->next);
            temp->next = nextNode;
            return nextNode;
        }
    }

    ListNode<T> *head;
    ListNode<T> *tail;

};


#endif // LINKEDLIST_H
