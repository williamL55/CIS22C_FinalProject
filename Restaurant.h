#ifndef _RESTAURANT_H
#define _RESTAURANT_H

//#include "Restaurant.h"
#include <string>

using namespace std;

 class Restaurant
 {
 private:
     //list attributes for each restaurant here
     //ex. name, cuisine, location, etc
     string name;
     string cuisine;
     string location;
     int openingHour;
     int closingHour;
     double rating;
     double cost;
 public:
     //default constructor
     Restaurant();

     /* getters */
     string getName();
     string getCuisine();
     string getLocation();
     int getOpenHour();
     int getClosingHour();
     double getRating();
     double getCost();

     /* setters */

     void setName(string name);
     void setCuisine(string cuisine);
     void setLocation(string location);
     void setOpenHour(int openingHour);
     void setClosingHour(int closingHour);
     void setRating(double rating);
     void setVost(double cost);
};

 #endif // _RESTAURANT_H
