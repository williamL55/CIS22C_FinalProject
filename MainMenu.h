#ifndef _MAINMENU_H_
#define _MAINMENU_H_

#include "Report.h"
#include "RestaurantDatabase.h"

class MainMenu
{
private:
    Report report;
    RestaurantDatabase* restaurantDatabase;

    //contains a pointer to the unique key BST
    BST<string>* uniqueBSTDatabase;

    //contains a pointer to the secondary key BST
    BST<string>* secondaryBSTDatabase;

    //contains a pointer to the hash
    HashTable* hashTable;

public:
    //constructor
    MainMenu();

    //destructor
    ~MainMenu();

    //displays the first main menu
    void showMainMenu();

    //shows menu asking for input file location
    void fileLoadMenu();

    //shows menu asking for output file location
    void fileSaveMenu();
};

#endif // MAINMENU_H
