#ifndef LISTNODE_H
#define LISTNODE_H

template <class T>
class ListNode
{
public:
    T data;
    ListNode<T> *next;

    ListNode(T value, ListNode<T> *next) : data(value), next(next) {}

};

#endif // LISTNODE_H
