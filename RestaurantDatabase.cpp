#include "RestaurantDatabase.h"
#include "BST.h"

RestaurantDatabase::RestaurantDatabase()
{
    uniqueBSTDatabase = new BST<string>;
    secondaryBSTDatabase = new BST<string>;
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
    int data;
    cout << "Add a restaurant to the database" << endl;

    //add placeholder cin to hold the screen
    cin >> data;

    //this is only an example of the usage for our BST
    //insert currently ONLY fucntions for the name parameter
    //until i or someone else updates all the BST functions to work with an operator overload
    Restaurant rest;
    rest.setName("string");
    uniqueBSTDatabase->insert(rest);
    cout << "root: " << uniqueBSTDatabase->getRoot() << endl;

    //example using the secondary BST
    Restaurant rest2;
    rest2.setName("secondary key rest2");
    secondaryBSTDatabase->insert(rest2);
    cout << "root: " << secondaryBSTDatabase->getRoot() << endl;

   // cin.get();
    return;
}

void RestaurantDatabase::removeRestaurant()
{
    int data;
    cout << "Remove a restaurant from the database" << endl;

    //add placeholder cin to hold the screen
    cin >> data;

    //cin.get();
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
        cout << "What is the rating of the restaurant? Please enter a number 0-5: ";
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
    cout << "\n\nDoes this look right?" << endl << endl;
    cout << rest;


}












