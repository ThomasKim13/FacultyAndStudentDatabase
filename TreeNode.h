/*
 * Thomas Kim
 * 2405924
 * chukim@chapman.edu
 * CPSC-350-01
 * PA5
 * TreeNode for the Database Project
 * creates a TreeNode that can be used in ScapeGoat class*/
#ifndef TREE_NODE_H
#define TREE_NODE_H
#include <cstdlib>
#include <iostream>
using namespace std;
template <typename T>
class TreeNode{
public:
    TreeNode(T d);
    virtual ~TreeNode();
    T getData();
    template <typename S>
    friend class ScapegoatST;
private:
    T m_data;
    int key;
    TreeNode<T>* m_left;
    TreeNode<T>* m_right;
    TreeNode<T>* m_parent;
};
#endif
//default constructor
template <typename T>
TreeNode<T>::TreeNode(T d){
    key = 0;
    m_data = d;
    m_left = NULL;
    m_right = NULL;
}
//default deconstructor
template <typename T>
TreeNode<T>::~TreeNode(){
    if(m_left != NULL){
        delete m_left;
    }
    if(m_right != NULL){
        delete m_right;
    }
}
//method that allows you to get the data
template <typename T>
T TreeNode<T>::getData(){
    return m_data;
}

