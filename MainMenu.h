#ifndef _MAINMENU_H
#define _MAINMENU_H

#include "Report.h"
#include "RestaurantDatabase.h"

class MainMenu
{
private:
    Report report;
    RestaurantDatabase* restaurantDatabase;
public:
    //constructor
    MainMenu();

    //destructor
    ~MainMenu();

    //displays the first main menu
    void showMainMenu();
};

#endif // MAINMENU_H
