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
    void containsCuisineValue(Nodeptr root, bstdata value);
    void containsNameValue(Nodeptr root, bstdata value);
    void printCuisine(Nodeptr root, string cuisine);
    Nodeptr removeName(Nodeptr root, Restaurant r);
    Nodeptr removeCuisine(Nodeptr root, Restaurant r);
    void deleteTree(Nodeptr root);
    int getHeight(Nodeptr root);
    Restaurant findMin(Nodeptr root);

public:
    BST();
    ~BST();
    bool is_empty();
    void insertName(Restaurant rest);
    void insertCuisine(Restaurant rest);
    void inOrderPrint();
    bool searchCuisine(bstdata value);
    bool searchName(bstdata value);
    //void searchCuisine(string cuisine);
    void removeName(Restaurant r);
    void removeCuisine(Restaurant r);
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
void BST<bstdata>::containsCuisineValue(Nodeptr root, bstdata value)
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
        containsCuisineValue(root->left, value);
    if(root->right)
        containsCuisineValue(root->right, value);
}

template <class bstdata>
void BST<bstdata>::containsNameValue(Nodeptr root, bstdata value)
{
    if(root->rest.getName() == value)
    {
        cout << "\n------------------------------------" << endl << endl;
        cout << root->rest;
    }
    if(root->left)
        containsNameValue(root->left, value);
    if(root->right)
        containsNameValue(root->right, value);
}

template <class bstdata>
bool BST<bstdata>::searchCuisine(bstdata value)
{
    if(root->rest.getCuisine() == value)
        cout << root->rest;
    if(root)
    {
        containsCuisineValue(root, value);
        return true;
    }
    else return false;
}

template <class bstdata>
bool BST<bstdata>::searchName(bstdata value)
{
    if(root->rest.getName() == value)
        cout << root->rest;
    if(root)
    {
        containsNameValue(root, value);
        return true;
    }
    else return false;
}

template <class bstdata>
void BST<bstdata>::removeName(Restaurant r)
{
    if(root)
        root = removeName(root, r);
}

template <class bstdata>
typename BST<bstdata>::Nodeptr BST<bstdata>::removeName(Nodeptr root, Restaurant r)
{
    if(!root)
        return root;
    else if (r.getName() < root->rest.getName())
        root->left = removeName(root->left, r);
    else if (r.getName() > root->rest.getName())
        root->right = removeName(root->right, r);
	else if(r.getPhoneNumber() < root->rest.getPhoneNumber())
		root->left = removeName(root->left, r);
	else if(r.getPhoneNumber() > root->rest.getPhoneNumber())
		root->right = removeName(root->right, r);
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
            root->rest = findMin(root->right);
            root->right = removeName(root->right, findMin(root->right));
        }
    }
    return root;
}

template <class bstdata>
void BST<bstdata>::removeCuisine(Restaurant r)
{
	if(root)
		root = removeCuisine(root, r);
}

template <class bstdata>
typename BST<bstdata>::Nodeptr BST<bstdata>::removeCuisine(Nodeptr root, Restaurant r)
{
	if(!root)
		return root;
    else if (r.getCuisine() < root->rest.getCuisine())
        root->left = removeCuisine(root->left, r);
    else if (r.getCuisine() > root->rest.getCuisine())
        root->right = removeCuisine(root->right, r);
	else if(r.getPhoneNumber() < root->rest.getPhoneNumber())
		root->left = removeCuisine(root->left, r);
	else if(r.getPhoneNumber() > root->rest.getPhoneNumber())
		root->right = removeName(root->right, r);
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
            root->rest = findMin(root->right);
            root->right = removeName(root->right, findMin(root->right));
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
Restaurant BST<bstdata>::findMin(Nodeptr root)
{
    while(root->left)
        root = root->left;
    return root->rest;
}


#endif
