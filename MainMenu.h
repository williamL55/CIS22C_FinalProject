#ifndef _MAINMENU_H
#define _MAINMENU_H

#include "Report.h"
#include "RestaurantDatabase.h"
//#include "BST.h"

class MainMenu
{
private:
    Report report;
    RestaurantDatabase* restaurantDatabase;
   // BST<string>* uniqueBSTDatabase;
public:
    //constructor
    MainMenu();

    //destructor
    ~MainMenu();

    //displays the first main menu
    void showMainMenu();
};

#endif // MAINMENU_H
