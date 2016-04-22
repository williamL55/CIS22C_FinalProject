#ifndef _REPORT_H
#define _REPORT_H

/*
    This class will be for our reporting
    This includes the Search, List, and Statistics portions mentioned in the Menu Requirements
*/


class Report
{
public:
    //we need to have at least 3 different types of Statistics to report

    /* Searching functions */

    //searches restaurants by name
    //this is the primary key
    void searchName();

    //searches restaurants by cuisine type
    //this is the secondary key
    void searchCuisine();

    //we need a main menu to get user input for searching
    void searchMainMenu();

    //we also need a main menu for the listings
    void listMainMenu();

};

#endif // _REPORT_H
