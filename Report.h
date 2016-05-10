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

    //we need a main menu to get user input for searching
    void searchMainMenu();

    //searches restaurants by name
    //this is the primary key
    void searchName();

    //searches restaurants by cuisine type
    //this is the secondary key
    void searchCuisine();

    /* List functions */

    //we also need a main menu for the listings
    void listMainMenu();

    //lists entire restaurant database unsorted
    void listUnsorted();

    //lists restaurant databaase sorted by name
    //this is the primary key
    void listSortedByName();

    //lists restaurant database sorted by cuisine
    //this is the secondary key
    void listSortedByCuisine();

};

#endif // _REPORT_H
