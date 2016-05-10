#ifndef _MAINMENU_H
#define _MAINMENU_H

#include "Report.h"

class MainMenu
{
private:
    Report report;
public:
    //constructor
    MainMenu();

    //destructor
    ~MainMenu();

    //displays the first main menu
    void showMainMenu();
};

#endif // MAINMENU_H
