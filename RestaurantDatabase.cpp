#include "RestaurantDatabase.h"
#include <fstream>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif // _WIN32

RestaurantDatabase::RestaurantDatabase()
{

}

RestaurantDatabase::RestaurantDatabase(BST<string>* uniqueBSTDatabase, BST<string>* secondaryBSTDatabase, HashTable* hashTable)
{
    this->uniqueBSTDatabase = uniqueBSTDatabase;
    this->secondaryBSTDatabase = secondaryBSTDatabase;
    this->hashTable = hashTable;
}

void RestaurantDatabase::setDatabaseFile(string file)
{
    databaseFile = file;
}

string RestaurantDatabase::getDatabaseFile()
{
    return databaseFile;
}

//run this when we need to write to a file
//this will output ALL of the data structures to a file
//this is supposed to be run automatically when the program ends, so we will add it to our destructor
void RestaurantDatabase::writeFile()
{
    //output the restaurants to a file
    //output all of the data for each restaurant
    try
    {
        ofstream fout;
        fout.open(getDatabaseFile().c_str());

        if(fout.fail())
        {
            "Failed to open " + databaseFile + " for writing.\n";
        }
        hashTable->printTableToFile(fout);
        fout.close();
    }
    catch(string e)
    {
        cout << e;
    }
    return;
}

void RestaurantDatabase::readFile()
{
    try
    {
        ifstream fin;
        fin.open(databaseFile.c_str());
        // if unable to open database file, throw error
		if (fin.fail())
		{
			throw "Failed to open " + databaseFile + " for reading.\n";
		}

		//create temp variables to store data
		string name, cuisine, location;
		int openingHour, closingHour;
		double cost, rating, phoneNumber;

		//read the file in a for loop, inputting a complete restaurant object
		//to all 3 databases by calling addRestaurant
		int i = 0;
		while(i < hashTable->getTableSize() && !fin.eof())
        {
            //read in all contents
            getline(fin, name);
            getline(fin, cuisine);
            getline(fin, location);
            fin >> openingHour;
            fin.ignore(1000, '\n');
            fin >> closingHour;
            fin.ignore(1000, '\n');
            fin >> cost;
            fin.ignore(1000, '\n');
            fin >> rating;
            fin.ignore(1000, '\n');
            fin >> phoneNumber;
            fin.ignore(1000, '\n');

            //add the restaurant if it is not a default object
            //must check if name is an empty line here
            //otherwise it will add an invalid restaurant
            if(name != "default name" && name != "")
                addRestaurant(name, cuisine, location, openingHour, closingHour, cost, rating, phoneNumber);

            //increment iterator
            i++;
        }
        //close the input file
        fin.close();
    }
    //if database file is unreadable
    catch (string e)
    {
        cout << e;
    }
}

void RestaurantDatabase::addRestaurant(string name, string cuisine, string location, int openingHour, int closingHour, double cost, double rating, double phoneNumber)
{
    //create a temp restaurant to pass to the databases
    Restaurant rest;
    rest.setCost(cost);
    rest.setRating(rating);
    rest.setName(name);
    rest.setClosingHour(closingHour);
    rest.setOpeningHour(openingHour);
    rest.setLocation(location);
    rest.setCuisine(cuisine);
    rest.setPhoneNumber(phoneNumber);

    //add the new restaurant to all 3 databases
    uniqueBSTDatabase->insertName(rest);
    secondaryBSTDatabase->insertCuisine(rest);
    hashTable->addItem(rest);

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

    //declare temp variables
    string name;
    string cuisine;
    string location;
    int openingHour;
    int closingHour;
    double phoneNumber;
    double rating;
    double cost;
    char alwaysOpen;

    system(CLEAR);

    //get info for the restaurant
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "What is the name of the restaurant? ";
    getline(cin, name);
    while (!done)
    {
        cout << "What is the cost consideration of the restaurant?\nPlease enter a number 0-4: ";
        cin >> cost;
        if (cin.fail() || cost < 0 || cost > 4)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid response.\n\n";
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
			cout << "Invalid response.\n\n";
		}
		else
		{
			done = true;
		}
    }
    done = false;
    while (!done)
    {
        cout << "\nWhat is the phone number of the restaurant?\nPlease enter a 10 digit number ";
        cin >> phoneNumber;
        if (cin.fail() || phoneNumber < 0 || phoneNumber > 9999999999)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid response.\n\n";
		}
		else
		{
			done = true;
		}
    }
    done = false;
    while (!done)
    {
        //if the restaurant is always open, set openingHour and closingHour to 0000 each
        cout << "Is this restaurant always open? (Y/N) ";
        cin >> alwaysOpen;
        if (alwaysOpen == 'y' || alwaysOpen == 'Y')
		{
		    openingHour = 0;
		    closingHour = 0;
			done = true;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else if(alwaysOpen == 'n' || alwaysOpen == 'N')
        {
            while (!done)
            {

                cout << "\nWhat is the opening hour of the restaurant?\nPlease enter a number (0000-2400): ";
                cin >> openingHour;
                cin.clear();
                cin.ignore(1000, '\n');
                if (cin.fail() || openingHour < 0 || openingHour > 2400 || openingHour % 100 >= 60)
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid response.\n\n";
                }
                else
                {
                    done = true;
                }
            }
            done = false;
            while (!done)
            {
                cout << "\nWhat is the closing hour of the restaurant?\nPlease enter a number (0000-2400): ";
                cin >> closingHour;
                cin.clear();
                cin.ignore(1000, '\n');
                if (cin.fail() || closingHour < 0 || closingHour > 2400 || closingHour % 100 >= 60)
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid response.\n\n";
                }
                else
                {
                    done = true;
                }
            }
        }
		else
		{
		    cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid response.\n\n";
		}
    }
    cout << "What is the cuisine of the restaurant? ";
    getline(cin, cuisine);
    cout << "What is the location of the restaurant? ";
    getline(cin, location);

    Restaurant rest;

    //set all the attributes on the local restaurant
    rest.setCost(cost);
    rest.setRating(rating);
    rest.setName(name);
    rest.setClosingHour(closingHour);
    rest.setOpeningHour(openingHour);
    rest.setLocation(location);
    rest.setCuisine(cuisine);
    rest.setPhoneNumber(phoneNumber);

    system(CLEAR);
    cout << rest;
    cout << "\n\nDoes this look right?" << endl << endl;

    //add check for input here later
    cout << "(y/n): ";

    cin.ignore(1000, '\n');

    //we will pass addRestaurant all parameters for a restaurant
    addRestaurant(name, cuisine, location, openingHour, closingHour, rating, cost, phoneNumber);

    system(CLEAR);
    cout << "\n\n\n\t\tRestaurant added successfully!\n\t\tPress any key to continue." << endl;
    cin.ignore(1000, '\n');
    return;
}












