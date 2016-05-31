#ifndef _RESTAURANTDATABASE_H_
#define _RESTAURANTDATABASE_H_

#include "Restaurant.h"
#include "Report.h"

class RestaurantDatabase
{
private:
    //pointer to the uniqueBSTDatabase
    BST<string>* uniqueBSTDatabase;

    //contains a pointer to the secondary key BST
    BST<string>* secondaryBSTDatabase;

    //contains a pointer to the hash table
    HashTable* hashTable;

    //used for holding the name of the database file
    string databaseFile;

public:
    RestaurantDatabase();
    RestaurantDatabase(BST<string>* uniqueBSTDatabase, BST<string>* secondaryBSTDatabase, HashTable* hashTable);

    //writes all information to the file
    //user is prompted for file directory and name
    //if no file exists, create a new file
    //this is supposed to be run automatically when the program ends
    //so we will add it to our destructor
    void writeFile();

    //reads a file and creates the data structures from it
    void readFile();

    //sets the database file name to what the user inputs
    void setDatabaseFile(string file);

    //gets the current database file name
    string getDatabaseFile();

    //adds a restaurant to the database
    //need to add all restaurant members here in the function call
    //void addRestaurant(string name, string cuisine, string location, int openingHour, int closingHour, double cost, double rating, double phoneNumber);

    void addRestaurant(Restaurant rest);



    //removes a restaurant from the database
    //searches for a restaurant by name by calling searchByName() from Report.h
    void removeRestaurant(Restaurant r);

    //menu for removing a restaurant
    void removeRestaurantMenu();

    //menu for adding a restaurant
    //provides user with list of items to enter
    void addRestaurantMenu();
};

#endif // RESTAURANTDATABASE_H
