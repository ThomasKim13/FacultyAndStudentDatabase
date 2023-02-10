/*
 * Thomas Kim
 * 2405924
 * chukim@chapman.edu
 * CPSC-350-01
 * PA5
 * ScapeGoatSt for the Database Project
 * allows the user to create a ScapeGoat Tree*/


#ifndef BST_H
#define BST_H
#include "TreeNode.h"
#include <cmath>
#include<iostream>
#include<fstream>
template <typename T>
class ScapegoatST{
    //public methods
public:
    ScapegoatST();
    virtual ~ScapegoatST();
    int getSize();
    void insert(T d);
    void remove(T d);
    bool contains(T d);
    void printTreeInOrder();

    void printTreePostOrder();
    void printTreePreOrder();
    int scapeGoatEq(int Nodes);
    T findPerson(T data);
    T getMin();
    T getMax();
    T getMedian();
    void logTree(ofstream& outFile);
//private methods and variables
private:
    int m_size;
    int m;

    TreeNode<T>* m_root;
    int leftHeight;
    int rightHeight;
    int depthofTree;
    int insertion;
    T getMinHelper(TreeNode<T>* subTreeRoot);
    T getMaxHelper(TreeNode<T>* subTreeRoot);
    void insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode, int depth);
    bool containsHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* newNode);
    void printTreeInOrderHelper(TreeNode<T>* subTreeRoot);

    void printTreePostOrderHelper(TreeNode<T>* subTreeRoot);
    void printTreePreOrderHelper(TreeNode<T>* subTreeRoot);
    void findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent);
    int storeNodes(TreeNode<T>* Node, TreeNode<T>* arr[], int size);
    TreeNode<T>* buildSubtree(TreeNode<T>* arr[],int size, int index);
    void rebuild(TreeNode<T>*& theRoot);
    int getHeight(TreeNode<T>* Node);
    TreeNode<T>* getSuccessor(TreeNode<T>* rightChild);
    void TreeLogHelper(TreeNode<T>* subTreeRoot, ofstream& outFile);

};
//default constructor
template <typename T>
ScapegoatST<T>::ScapegoatST(){
    m_root = NULL;
    m_size = 0;
    depthofTree = 0;
}
//default deconstructor
template <typename T>
ScapegoatST<T>::~ScapegoatST(){
    if(m_root != NULL){
        delete m_root;
    }
}
//returns the size of the scapegoat
template <typename T>
int ScapegoatST<T>::getSize(){
    return m_size;
}
//allows for the user to insert T value into the Scapegoat
template <typename T>
void ScapegoatST<T>::insert(T d){
    TreeNode<T>* newNode = new TreeNode<T>(d);
    insertHelper(m_root, newNode, 0);
    ++m_size;
    //scapegoat equation that allows for the rebalancing of the tree
    const double log23 = 1.7;
    const double eq = log23 * log2(m_size);
    if((double)depthofTree > eq){
        cout << "REBUILDING TREE" << endl;
        TreeNode<T>* root = newNode->m_parent;
        while(3 * getHeight(root) <= 2 * getHeight(root->m_parent)){

            root = root->m_parent;
        }

        rebuild(root->m_parent);
    }
    ++insertion;

}
template <typename T>
//insertHelper is a recurssive method that runs through the tree to add a specific node at a specific place
void ScapegoatST<T>::insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode, int depth){

    if(subTreeRoot == NULL){
        subTreeRoot = newNode;
        depthofTree = depth;
    } else if(newNode->m_data < subTreeRoot->m_data){
        if(subTreeRoot->m_left == NULL){
            newNode->m_parent = subTreeRoot;
        }
        insertHelper(subTreeRoot->m_left,newNode,depth+1);
    } else{
        if(subTreeRoot->m_right == NULL){
            newNode->m_parent = subTreeRoot;
        }
        insertHelper(subTreeRoot->m_right,newNode,depth+1);
    }
}
//checks the scapegoat to see if there is value that exists in the scapegoat
template <typename T>
bool ScapegoatST<T>::contains(T d){
    TreeNode<T>* newNode = new TreeNode<T>(d);
    return containsHelper(m_root, newNode);
}
template <typename T>
//helper method for the contains method
//goes through the tree recursively to check for the subtreeroot parameter
bool ScapegoatST<T>::containsHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* newNode){

    if(subTreeRoot == NULL){
        return false;
    } else if(*newNode->m_data == *subTreeRoot->m_data){
        return true;
    } else if(*newNode->m_data < *subTreeRoot->m_data){
        return containsHelper(subTreeRoot->m_left,newNode);
    } else{
        return containsHelper(subTreeRoot->m_right,newNode);
    }
}
//prints the tree in ascending order
template <typename T>
void ScapegoatST<T>::printTreeInOrder(){
    printTreeInOrderHelper(m_root);
}
//checks the tree from the left to the right to go from least to greatest
template <typename T>
void ScapegoatST<T>::printTreeInOrderHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot != NULL){
        printTreeInOrderHelper(subTreeRoot->m_left);
        cout << *subTreeRoot->m_data << endl;
        printTreeInOrderHelper(subTreeRoot->m_right);
    }
}
//gets the minimum value of a tree
template <typename T>
T ScapegoatST<T>::getMin(){
    //check if empty
    return getMinHelper(m_root);
}
//goes through the tree recursively to check for the minimum value of the tree
template <typename T>
T ScapegoatST<T>::getMinHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot->m_left==NULL){
        return subTreeRoot->m_data;
    } else{
        return getMinHelper(subTreeRoot->m_left);
    }
}
//returns the max value of the tree
template <typename T>
T ScapegoatST<T>::getMax(){
    //check if empty
    return getMaxHelper(m_root);
}
//goes through the tree recursively to check for the max value of the tree
template <typename T>
T ScapegoatST<T>::getMaxHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot->m_right==NULL){
        return subTreeRoot->m_data;
    } else{
        return getMaxHelper(subTreeRoot->m_right);
    }
}
//returns the median value of the tree
template <typename T>
T ScapegoatST<T>::getMedian(){
    //check if empty
    return m_root->m_data;
}
//this method helps to return a certain value in the tree
template <typename T>
void ScapegoatST<T>::findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent){
    while(target != nullptr && *(target->m_data) != *key){

        parent = target;
        if(*key < *(target->m_data)){

            target = target->m_left;
        } else{

            target = target->m_right;
        }
    }

}
//returns the successor of the child
template <typename T>
TreeNode<T>* ScapegoatST<T>::getSuccessor(TreeNode<T>* rightChild){
    while(rightChild->m_left != NULL){
        rightChild = rightChild->m_left;
    }
    return rightChild;
}
//method that removes a value from the tree
template <typename T>
void ScapegoatST<T>::remove(T d){
    //check if empty
    TreeNode<T>* target = NULL;
    TreeNode<T>* parent = NULL;
    target = m_root;
    findTarget(d,target,parent);

    if(target == NULL){ //value wasn't in tree, othing to do

        return;

    }
    //check if leaf (including the root)
    if(target->m_left == NULL && target->m_right == NULL){ //no children, it's a leaf

        if(target == m_root){ //leaf is the root of tree
            m_root = NULL;

        } else{ //it's not the root
            if(target ==  parent->m_left){
                parent->m_left = NULL;
            } else{
                parent->m_right = NULL;
            }
        }
        //delete target; //free the memory
    } else if(target->m_left != NULL && target->m_right != NULL){ //2 child case
        TreeNode<T>* suc = getSuccessor(target->m_right);
        T value = suc->m_data;
        remove(value); //remove successor treenode
        target->m_data = value;
    } else{ //1 child
        TreeNode<T>* child;
        if(target->m_left != NULL){
            child = target->m_left;
        } else{
            child = target->m_right;
        }
        if(target ==  m_root){
            m_root = child;
        } else{
            if(target == parent->m_left){
                //cout << "I'm here!" << endl;
                parent->m_left = child;
            } else{
                parent->m_right = child;
            }
        }
        //delete target;
    }
    --m_size;

    //based on the research paper this is the equation that must be used to rebuild the tree once a certain amount of trees are deleted
    if(2*m_size < insertion && m_size > 0){
        rebuild(m_root);


        insertion = m_size;
    }

}

template <typename T>
//method that helps to store nodes into an array
int ScapegoatST<T>::storeNodes(TreeNode<T>* Node, TreeNode<T>* arr[], int size) {
    if(Node == NULL){
        return size;
    }
    //used insertHelper template to create this
    //the size parameter helps to keep track of the arr size
    //with recurrsion the left and right nodes are added while the arr is continues to be interated through.
    size = storeNodes(Node->m_left, arr, size);
    arr[size++] = Node;
    return storeNodes(Node->m_right, arr, size);
}
template<typename T>
//helps to build the subtree given an array
TreeNode<T>* ScapegoatST<T>::buildSubtree(TreeNode<T>* arr[],int size, int index) {
    if(size == 0){
        return NULL;
    }
    int median = size / 2;
    arr[index + median]->m_left = buildSubtree(arr,median,index);
    if(arr[index + median]->m_left != NULL){
        arr[index + median]->m_left->m_parent = arr[index + median];
    }
    arr[index + median]->m_right = buildSubtree(arr,size - median - 1,index + median +1);
        if(arr[index + median]->m_right != NULL){
            arr[index + median]->m_right->m_parent = arr[index + median];
        }

    return arr[index + median];

}
//returns the height of the tree
template <typename T>
int ScapegoatST<T>::getHeight(TreeNode<T>* Node) {
    if(Node == NULL){
        return 0;
    }
    return 1 + getHeight(Node->m_left) + getHeight(Node->m_right);
}
template <typename T>
//when there has to be a rebuilding this process this method does so
//given the build subtree method it restructures the tree so that it is balanced
void ScapegoatST<T>::rebuild(TreeNode<T>*& theRoot) {

    int depth = getHeight(theRoot);
    TreeNode<T>** arr = new TreeNode<T>* [depth];
    TreeNode<T>* parentNode = theRoot->m_parent;
    storeNodes(theRoot,arr,0);
    if(parentNode == NULL){

        theRoot = buildSubtree(arr,depth,0);
        theRoot->m_parent = NULL;
    }
    else if(parentNode->m_right == theRoot){
        parentNode->m_right = buildSubtree(arr,depth,0);
        parentNode->m_right->m_parent = parentNode;
    }
    else{
        parentNode->m_left = buildSubtree(arr, depth,0);
        parentNode->m_left->m_parent = parentNode;
    }
}
//Helper method that helps to print the tree before it is ordered.
template <typename T>
void ScapegoatST<T>::printTreePreOrderHelper(TreeNode<T>* subTreeRoot) {
    if (subTreeRoot != NULL)
    {
        cout << subTreeRoot->m_data << " ";
        printTreePreOrder(subTreeRoot -> left);
        printTreePreOrder(subTreeRoot -> right);
    }
}
//method that prints the tree before it is ordered
template <typename T>
void ScapegoatST<T>::printTreePreOrder() {
    printTreeInOrderHelper(m_root);
}

//method that allows me to find a faculty or student in the tree
template <typename T>
T ScapegoatST<T>::findPerson(T data){
    TreeNode<T>* target = NULL;
    TreeNode<T>* parent = NULL;
    target = m_root;
    findTarget(data,target,parent);
    return target->m_data;

}
//method that helps me to output to a file
template <typename T>
void ScapegoatST<T>::logTree(std::ofstream &outFile) {
    TreeLogHelper(m_root,outFile);
}
//helper method that traverses through the tree to output to a file
template <typename T>
void ScapegoatST<T>::TreeLogHelper(TreeNode<T> *subTreeRoot, ofstream &outFile) {
    if(subTreeRoot != NULL){
        TreeLogHelper(subTreeRoot->m_left,outFile);
        outFile << *subTreeRoot->m_data << endl;
        TreeLogHelper(subTreeRoot->m_right,outFile);
    }
}



#endif //PA5_SCAPEGOATST_H


