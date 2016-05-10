#include "Report.h"
#include <iostream>

using namespace std;


void Report::searchMainMenu()
{
    int choice;

    do
	{
	    #ifdef WINDOWS
            system("CLS");//clear the screen of any old menus
        #else
            system("clear");
        #endif


		//show the mainMenu and get the choice
		cout << "\t\tSearch\n\t\tMain Menu\n\n";
		cout << "\t    1. Search restaurants by name\n";
		cout << "\t    2. Search restaurants by cuisine\n";
		cout << "\t    3. Return to main menu\n";
		cout << "\n\t     Enter your choice: ";

		cin >> choice;

		if (choice == 1)
		{
			//run searchByName();
			searchByName();
		}
		else if (choice == 2)
		{
			//run searchByCuisine();
			searchByCuisine();
		}
		else if (choice == 3)
		{
			//return to main menu
			break;
		}
		else
		{
			#ifdef WINDOWS
            system("CLS");//clear the screen of any old menus
            #else
                system("clear");
            #endif
			cout << "\n\t    Please enter a valid selection.\n";
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\n\t    Press return to continue.";
			cin.get();
			choice = 0;
		}
	} while (choice != 3);
}

void Report::searchByName()
{

}

void Report::searchByCuisine()
{

}

void Report::listMainMenu()
{
    int choice;

    do
	{
	    #ifdef WINDOWS
            system("CLS");//clear the screen of any old menus
        #else
            system("clear");
        #endif


		//show the mainMenu and get the choice
		cout << "\t\tList\n\t\tMain Menu\n\n";
		cout << "\t    1. List unsorted data\n";
		cout << "\t    2. List data sorted by name\n";
		cout << "\t    3. List data sorted by cuisine\n";
		cout << "\t    4. Return to main menu\n";
		cout << "\n\t     Enter your choice: ";

		cin >> choice;

		if (choice == 1)
		{
			//run listUnsorted();
		}
		else if (choice == 2)
		{
			//run listSortedByName();
		}
		else if (choice == 3)
		{
			//run listSortedByCuisine();
		}
		else if (choice == 4)
		{
			//return to main menu
			break;
		}
		else
		{
			#ifdef WINDOWS
            system("CLS");//clear the screen of any old menus
            #else
                system("clear");
            #endif
			cout << "\n\t    Please enter a valid selection.\n";
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\n\t    Press return to continue.";
			cin.get();
			choice = 0;
		}
	} while (choice != 4);
}

void Report::listUnsorted()
{
    return;
}

void Report::listSortedByName()
{
    return;
}

void Report::listSortedByCuisine()
{
    return;
}
