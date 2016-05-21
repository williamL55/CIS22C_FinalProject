#ifndef _MAINMENU_H
#define _MAINMENU_H

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

public:
    //constructor
    MainMenu();

    //destructor
    ~MainMenu();

    //displays the first main menu
    void showMainMenu();

    //shows menu asking for input file location
    void fileLoadMenu();
};

#endif // MAINMENU_H
