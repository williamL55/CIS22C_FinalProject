#include "MainMenu.h"
#include <cstdlib>
#include <iostream>

using namespace std;

MainMenu::MainMenu()
{

    //will need to pass in database as an argument to Report() once it is added
    //will also need a new constructor for this to happen
    //this report call to the constructor will create a report object to be used in the main menu
    //report will be used for search, list, and statistics
    report = Report();
}

MainMenu::~MainMenu()
{

}

void MainMenu::showMainMenu()
{
	int choice = 0;
	do
	{
	    #ifdef WINDOWS
            system("CLS");//clear the screen of any old menus
        #else
            system("clear");
        #endif

		//show the mainMenu and get the choice
		cout << "\t\tRestaurants\n\t\tMain Menu\n\n";
		cout << "\t    1. Add new data\n";
		cout << "\t    2. Delete data\n";
		cout << "\t    3. Search\n";
		cout << "\t    4. List\n";
		cout << "\t    5. Statistics\n";
		cout << "\t    6. Write data to file\n";
		cout << "\t    7. Exit\n";
		cout << "\n\t     Enter your choice: ";

		cin >> choice;

		if (choice == 1)
		{
			//run add new data menu
		}
		else if (choice == 2)
		{
			//run delete data menu
		}
		else if (choice == 3)
		{
			//run search menu
			report.searchMainMenu();
		}
		else if (choice == 4)
		{
			//run list menu
			report.listMainMenu();
		}
		else if (choice == 5)
		{
			//run report main menu;

		}
		else if (choice == 6)
		{
			//run writeFile();
		}
		else if (choice == 7)
		{
			#ifdef WINDOWS
                system("CLS");//clear the screen of any old menus
            #else
                system("clear");
            #endif
			cout << "\n\n\t\t   Thank you for using the restaurant database!\n\n";
			cout << "\t\t\t(Press return to continue)";
			cin.ignore();
			cin.get();
			return;
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
	} while (choice != 7);
}





//our main will be in this file
int main()
{
    //we will want to create a MainMenu object here to run the main menu
    MainMenu menu;
    menu.showMainMenu();
}
