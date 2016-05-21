
#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_
#include "Restaurant.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

class HashTable {

public:
    HashTable();

    ~HashTable();
    //Destructor

    //returns the hash value for the given key
    //the hash value is the sum of
    //the ASCII values of each character % the table size
    int hash(string key);

    //inserts a new item into the table
    //calls the hash function on the key title to determine the correct bucket
    void addItem(Restaurant rest);

    //removes the item with the given key
    void removeItem(string key);

    //Helper function to printTable
    //Counts the number of items in each bucket
    int numItemsAtIndex(int index);

    //prints the first item of each bucket
    //includes the number of items stored at that bucket
    void printTable();

    void printTableToFile(ofstream &fout);

    //Prints all items stored at a single bucket
    void printBucket(int index);

    //Searches for an author in the table using the key
    //returns the index under which the author is stored
    //returns -1 if the author is not found
    int findAuthor(string title);

    //need a way to get table size for looping
    int getTableSize();

private:

    struct Node
    {
        Restaurant rest;
        Node* next;
        Node(): rest(), next(NULL){}
        Node(Restaurant newRest): rest(newRest), next(NULL) {}
    };

    typedef struct Node* Nodeptr;

    static const int TABLE_SIZE = 60;
    Nodeptr Table[TABLE_SIZE];

};

#endif /* HASHTABLE_H_ */
