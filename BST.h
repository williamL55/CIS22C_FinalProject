#ifndef _BST_H
#define _BST_H

#include <cstddef>
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Restaurant.h"

using namespace std;

template <class bstdata>
class BST
{
    private:
        struct Node
        {
                Node* left;
                Node* right;
                bstdata nameOrCuisine;
                int phoneNumber;

                Node(): left(NULL), right(NULL), nameOrCuisine(""), phoneNumber(0){}
                Node(bstdata nameOrCuisine,int phoneNumber): left(NULL), right(NULL), nameOrCuisine(nameOrCuisine), phoneNumber(phoneNumber){}
        };

        typedef struct Node* Nodeptr;

        Nodeptr root;


                    /**Private helper functions*/

        void insert_value(Nodeptr root, bstdata nameOrCuisine, int phoneNumber);

        //private helper function for insert

        //recursively inserts a value into the BST

        void inOrderPrint(Nodeptr root);

        //private helper function for inOrderPrint

        //recursively prints tree values in order from smallest to largest

        void preOrderPrint(Nodeptr root, ofstream &fout);

        //private helper function for preOrderPrint

        //recursively prints tree values in preorder


        void postOrderPrint(Nodeptr root, ofstream &fout);

        //private helper function for postOrderPrint

        //recursively prints tree values according in postorder

        bool containsValue(Nodeptr root, bstdata value);

        bstdata findMin(Nodeptr root);

        Nodeptr remove(Nodeptr root, bstdata value);

        void copyHelper(const Nodeptr origRoot, Nodeptr &root);

        void deleteTree(Nodeptr root);

        bstdata findMax(Nodeptr root);

        int getSize(Nodeptr root);

        int getHeight(Nodeptr root);

    public:
        BST();

        //Instantiates a new BST

        //post: a new BST object

        BST(const BST &BST);

        ~BST();

        bool is_empty();

        //determines whether the BST is empty

        void insert(bstdata nameOrCuisine, int phoneNumber);

        //inserts a new value into the BST

        //post: a new value inserted into the BST

        //MUST use exception when calling
        //otherwise will crash when calling if tree is empty
        bstdata getRoot();

        //returns the value stored at the root of the BST

        //pre: the BST is not empty

        void inOrderPrint();

        //calls the inOrderPrint function to print out the values

        //stored in the BST


        void preOrderPrint(ofstream &fout);

        //calls the reOrderPrint function to print out the values

        //stored in the BST


        void postOrderPrint(ofstream &fout);

        //calls the postOrderPrint function to print out the values

        //stored in the BST

        //more functions to be added here!

        bool search(bstdata value);

        bstdata minimum();

        void remove(bstdata value);

        bstdata maximum();

        bool isEmpty();

        int getSize();

        int getHeight();



};

template <class bstdata>
BST<bstdata>::BST()
{
    root = NULL;
}

template <class bstdata>
BST<bstdata>::BST(const BST &BST)
{
    if(!BST.root)
        root = NULL;
    else copyHelper(BST.root, root);

}

template <class bstdata>
BST<bstdata>::~BST()
{
    deleteTree(root);
}

template <class bstdata>
void BST<bstdata>::deleteTree(Nodeptr root)
{
    if(root)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

template <class bstdata>
void BST<bstdata>::copyHelper(const Nodeptr origRoot, Nodeptr &root)
{
    if(origRoot)
    {
        root = new Node(origRoot->data);
        copyHelper(origRoot->left, root->left);
        copyHelper(origRoot->right, root->right);
    }
}

template <class bstdata>
void BST<bstdata>::insert(bstdata nameOrCuisine, int phoneNumber)
{
    if (root == NULL)
    {
        root = new Node(nameOrCuisine, phoneNumber); //if the tree is empty insert the value at the root

    }
    else
        insert_value(root, nameOrCuisine, phoneNumber); //otherwise call the helper function, passing it the root

}

template <class bstdata>
void BST<bstdata>::insert_value(Nodeptr root, bstdata nameOrCuisine, int phoneNumber)
{

    //change the root->rest.getName() later to
    // operator== overload
    if(nameOrCuisine == root->nameOrCuisine)
        return;
    else if(nameOrCuisine < root->nameOrCuisine)
    {
        if(root->left == NULL)
            root->left = new Node(nameOrCuisine, phoneNumber);
        else
            insert_value(root->left, nameOrCuisine, phoneNumber);
    }
    else
    {
        if(root->right == NULL)
            root->right = new Node(nameOrCuisine, phoneNumber);
        else
            insert_value(root->right, nameOrCuisine, phoneNumber);
    }
}

template <class bstdata>
bstdata BST<bstdata>::getRoot()
{
    if(root)
       return root->nameOrCuisine;
    else
    {
        throw "The tree is empty";
    }
}


template <class bstdata>
void BST<bstdata>::inOrderPrint(Nodeptr root)
{
    if(root)
    {
        inOrderPrint(root->left);
        //fout << root->data << " ";
        cout << root->nameOrCuisine;
        inOrderPrint(root->right);
    }
}

template <class bstdata>
void BST<bstdata>::inOrderPrint()
{
    inOrderPrint(root);
    cout << endl;
}

template <class bstdata>
void BST<bstdata>::preOrderPrint(Nodeptr root, ofstream &fout)
{
    if(root)
    {
        fout << root->data << " ";
        preOrderPrint(root->left, fout);
        preOrderPrint(root->right, fout);
    }
}

template <class bstdata>
void BST<bstdata>::preOrderPrint(ofstream &fout)
{
    preOrderPrint(root, fout);
    fout << endl;
}

template <class bstdata>
void BST<bstdata>::postOrderPrint(Nodeptr root, ofstream &fout)
{
    if(root)
    {
        postOrderPrint(root->left, fout);
        postOrderPrint(root->right, fout);
        fout << root->data << " ";
    }
}

template <class bstdata>
void BST<bstdata>::postOrderPrint(ofstream &fout)
{
    postOrderPrint(root, fout);
    fout << endl;
}

template <class bstdata>
bool BST<bstdata>::containsValue(Nodeptr root, bstdata value)
{
    if(root->data == value)
        return true;
    else if(value < root->data)
    {
        if(!root->left)
            return false;
        else
            return containsValue(root->left, value);
    }
    else if(value > root->data)
    {
        if(!root->right)
            return false;
        else
            return containsValue(root->right, value);
    }
    return false;
}

template <class bstdata>
bool BST<bstdata>::search(bstdata value)
{
    if(root->data == value)
        return true;
    else if(root)
        return containsValue(root, value);
    else return false;
}

template <class bstdata>
bstdata BST<bstdata>::minimum()
{
    if (root == NULL)
    {
        cout << "Minimum: Tree is empty" << endl;
        //will need to include cstdlib for exit below
            exit(-1);
    }
    else return findMin(root);
}

template <class bstdata>
bstdata BST<bstdata>::findMin(Nodeptr root)
{
    while(root->left)
        root = root->left;
    return root->data;
}

template <class bstdata>
bstdata BST<bstdata>::maximum()
{
    if (root == NULL)
    {
        cout << "Maximum: Tree is empty" << endl;
        //will need to include cstdlib for exit below
            exit(-1);
    }
    else return findMax(root);
}

template <class bstdata>
bstdata BST<bstdata>::findMax(Nodeptr root)
{
    while(root->right)
        root = root->right;
    return root->data;
}

template <class bstdata>
void BST<bstdata>::remove(bstdata value)
{
    //add test(s) for pre-condition(s)
    if(root)
        root = remove(root, value);
    //size--;
}

template <class bstdata>
typename BST<bstdata>::Nodeptr BST<bstdata>::remove(Nodeptr root, bstdata value)
{
    if(!root)
        return root;
    else if (value < root->data)
        root->left = remove(root->left, value);
    else if (value > root->data)
        root->right = remove(root->right, value);
    else
    {
        if (!root->left && !root->right)
        {
            Nodeptr temp = root;
            root = root->left;
            delete temp;
        }
        else if(root->left && !root->right)
        {
            Nodeptr temp = root;
            root = root->left;
            delete temp;
        }
        else if(!root->left && root->right)
        {
            Nodeptr temp = root;
            root = root->right;
            delete temp;
        }
        else
        {
            root->data = findMin(root->right);
            root->right = remove(root->right, findMin(root->right));
        }
    }
    return root;
}

template <class bstdata>
bool BST<bstdata>::isEmpty()
{
    return root == NULL;
}

template <class bstdata>
int BST<bstdata>::getSize()
{
    return getSize(root);
}

template <class bstdata>
int BST<bstdata>::getSize(Nodeptr root)
{
    int sum = 0;
    if(root)
    {
        sum += getSize(root->left);
        sum += getSize(root->right);
        sum++;
    }
   return sum;
}

template <class bstdata>
int BST<bstdata>::getHeight(Nodeptr root)
{

    int height = 0;
    if(root)
    {
        if(root->left || root->right)
        {
            int leftHeight = 0;
            int rightHeight = 0;
            if(root->left)
            {
                leftHeight = getHeight(root->left);
            }
            if(root->right)
            {
                rightHeight = getHeight(root->right);
            }
            if(rightHeight < leftHeight)
                height = leftHeight + 1;
            else
                height = rightHeight + 1;
        }
    }
    return height;

}

template <class bstdata>
int BST<bstdata>::getHeight()
{
    int height;
    if(root)
        height = getHeight(root);
    return height;
}


#endif




