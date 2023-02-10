/*
 * Thomas Kim
 * 2405924
 * chukim@chapman.edu
 * CPSC-350-01
 * PA5
 * ListNode class for the Database Project
 * creates a Node that can be used in DblList*/
#ifndef LIST_NODE_H
#define LIST_NODE_H
#include <cstdlib>
template<typename T>
class ListNode{
    //public method
public:
    ListNode(T data);
    virtual ~ListNode();
    T m_data;
    ListNode<T>* m_next; //recursive data structure b/c it points to instances of
    ListNode<T>* m_prev;
};
//default constructor
template<typename T>
ListNode<T>::ListNode(T data){
    m_data = data;
    m_next = NULL;
    m_prev = NULL;
}
//default deconstructor
template<typename T>
ListNode<T>::~ListNode(){
    m_next = NULL;
    m_prev = NULL;
}
#endif