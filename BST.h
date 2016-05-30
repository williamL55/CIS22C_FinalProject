#ifndef _BST_H_
#define _BST_H_

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
            Restaurant rest;

            Node(): left(NULL), right(NULL), rest(){}
            Node(Restaurant newRest): left(NULL), right(NULL), rest(newRest){}
    };

    typedef struct Node* Nodeptr;

    Nodeptr root;


                /**Private helper functions*/

    void insert_name_value(Nodeptr root, Restaurant rest);
    void insert_cuisine_value(Nodeptr root, Restaurant rest);
    void inOrderPrint(Nodeptr root);
    void containsValue(Nodeptr root, bstdata value);
    Nodeptr remove(Nodeptr root, bstdata value);
    void deleteTree(Nodeptr root);
    int getHeight(Nodeptr root);
    bstdata findMin(Nodeptr root);

public:
    BST();
    ~BST();
    bool is_empty();
    void insertName(Restaurant rest);
    void insertCuisine(Restaurant rest);
    void inOrderPrint();
    bool search(bstdata value);
    void remove(bstdata value);
    bool isEmpty();
    int getHeight();
};

template <class bstdata>
BST<bstdata>::BST()
{
    root = NULL;
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
void BST<bstdata>::insertName(Restaurant rest)
{
    if (root == NULL)
    {
        root = new Node(rest); //if the tree is empty insert the value at the root

    }
    else
        insert_name_value(root, rest); //otherwise call the helper function, passing it the root

}


template <class bstdata>
void BST<bstdata>::insert_name_value(Nodeptr root, Restaurant rest)
{
    if(rest.getName() == root->rest.getName() && rest.getPhoneNumber() == root->rest.getPhoneNumber())
    {
            return;
        if(rest.getPhoneNumber() < root->rest.getPhoneNumber())
        {
        	if(root->left == NULL)
        		root->left = new Node(rest);
        	else
        		insert_name_value(root->left, rest);
        }
        else
        {
        	if(root->right == NULL)
        		root->right = new Node(rest);
        	else
        		insert_name_value(root->right, rest);
        }
    }
    else if(rest.getName() < root->rest.getName())
    {
        if(root->left == NULL)
            root->left = new Node(rest);
        else
            insert_name_value(root->left, rest);
    }
    else
    {
        if(root->right == NULL)
            root->right = new Node(rest);
        else
            insert_name_value(root->right, rest);
    }
}

template <class bstdata>
void BST<bstdata>::insertCuisine(Restaurant rest)
{
    if (root == NULL)
    {
        root = new Node(rest); //if the tree is empty insert the value at the root

    }
    else
        insert_cuisine_value(root, rest); //otherwise call the helper function, passing it the root

}


template <class bstdata>
void BST<bstdata>::insert_cuisine_value(Nodeptr root, Restaurant rest)
{
    if(rest.getCuisine() == root->rest.getCuisine())
    {
        if(rest.getPhoneNumber() == root->rest.getPhoneNumber())
            return;
        else if(rest.getPhoneNumber() < root->rest.getPhoneNumber())
        {
        	if(root->left == NULL)
        		root->left = new Node(rest);
        	else
        		insert_cuisine_value(root->left, rest);
        }
        else
        {
        	if(root->right == NULL)
        		root->right = new Node(rest);
        	else
        		insert_cuisine_value(root->right, rest);
        }

    }
    else if(rest.getCuisine() < root->rest.getCuisine())
    {
        if(root->left == NULL)
            root->left = new Node(rest);
        else
            insert_cuisine_value(root->left, rest);
    }
    else
    {
        if(root->right == NULL)
            root->right = new Node(rest);
        else
            insert_cuisine_value(root->right, rest);
    }
}

template <class bstdata>
void BST<bstdata>::inOrderPrint(Nodeptr root)
{
    if(root)
    {

        inOrderPrint(root->left);
        cout << "\n------------------------------------" << endl << endl;
        cout << root->rest;
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
void BST<bstdata>::containsValue(Nodeptr root, bstdata value)
{
    string temp = root->rest.getCuisine();
    for (unsigned int i =0; i < root->rest.getCuisine().length(); i++)
        temp[i] = tolower(temp[i]);
    if(temp.find(value) != std::string::npos)
    {
        cout << "\n------------------------------------" << endl << endl;
        cout << root->rest;
    }
    if(root->left)
        containsValue(root->left, value);
    if(root->right)
        containsValue(root->right, value);
}

template <class bstdata>
bool BST<bstdata>::search(bstdata value)
{
    if(root->rest.getCuisine() == value)
        cout << root->rest;
    if(root)
    {
        containsValue(root, value);
        return true;
    }
    else return false;
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

template <class bstdata>
bstdata BST<bstdata>::findMin(Nodeptr root)
{
    while(root->left)
        root = root->left;
    return root->data;
}


#endif
