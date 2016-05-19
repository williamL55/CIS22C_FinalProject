#include "RestaurantDatabase.h"
#include "BST.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif // _WIN32

RestaurantDatabase::RestaurantDatabase()
{
    //uniqueBSTDatabase = new BST<string>;
    //secondaryBSTDatabase = new BST<string>;
}

RestaurantDatabase::RestaurantDatabase(BST<string>* uniqueBSTDatabase, BST<string>* secondaryBSTDatabase)
{
    this->uniqueBSTDatabase = uniqueBSTDatabase;
    this->secondaryBSTDatabase = secondaryBSTDatabase;
}

//run this when we need to write to a file
//this will output ALL of the data structures to a file
void RestaurantDatabase::writeFile()
{
    return;
}

void RestaurantDatabase::readFile()
{
    return;
}

void RestaurantDatabase::addRestaurant()
{
    //this is only an example of the usage for our BST
    //insert currently ONLY fucntions for the name parameter
    //until i or someone else updates all the BST functions to work with an operator overload
    Restaurant rest;
    rest.setName("string");
    uniqueBSTDatabase->insert(rest);
    //cout << "root: " << uniqueBSTDatabase->getRoot() << endl;

    //example using the secondary BST
    Restaurant rest2;
    rest2.setName("secondary key rest2");
    secondaryBSTDatabase->insert(rest2);
    //cout << "root: " << secondaryBSTDatabase->getRoot() << endl;

    system(CLEAR);
    cout << "\n\n\n\t\tAdd successful!\n\t\tPress any key to continue." << endl;
    cin.ignore(1000, '\n');
    cin.get();
    return;
}

void RestaurantDatabase::removeRestaurant()
{
    system(CLEAR);
    cout << "\n\t\tPress any key to continue." << endl;
    cin.ignore(1000, '\n');
    cin.get();
    return;
}

void RestaurantDatabase::addRestaurantMenu()
{
    bool done = false;

    string name;
    string cuisine;
    string location;
    int openingHour;
    int closingHour;
    double rating;
    double cost;

    system(CLEAR);

    while (!done)
    {
        cout << "What is the cost consideration of the restaurant?\nPlease enter a number 0-5: ";
        cin >> cost;
        if (cin.fail() || cost < 0 || cost > 5)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid response.\n";
		}
		else
		{
			done = true;
		}
    }
    done = false;
    while (!done)
    {
        cout << "\nWhat is the rating of the restaurant?\nPlease enter a number 0-5: ";
        cin >> rating;
        if (cin.fail() || rating < 0 || rating > 5)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid response.\n";
		}
		else
		{
			done = true;
		}
    }

    Restaurant rest;
    rest.setCost(cost);
    rest.setRating(rating);
    system(CLEAR);
    cout << rest;
    cout << "\n\nDoes this look right?" << endl << endl;

    //add check for input here later
    cout << "(y/n): ";

    cin.ignore(1000, '\n');
    cin.get();


    //we will pass addRestaurant all parameters for a restaurant
    addRestaurant();

}












