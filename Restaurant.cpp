#include "Restaurant.h"

Restaurant::Restaurant()
{
    name = "default name";
    cuisine = "default cuisine";
    location = "default location";
    openingHour = 0;
    closingHour = 0;
    rating = 0.0;
    cost = 0.0;
}

string Restaurant::getName()
{
    return name;
}

string Restaurant::getCuisine()
{
    return cuisine;
}

string Restaurant::getLocation()
{
    return location;
}

int Restaurant::getOpenHour()
{
    return openingHour;
}

int Restaurant::getClosingHour()
{
    return closingHour;
}

double Restaurant::getRating()
{
    return rating;
}

double Restaurant::getCost()
{
    return cost;
}

void Restaurant::setName(string name)
{
    this->name = name;
}

void Restaurant::setCuisine(string cuisine)
{
    this->cuisine = cuisine;
}

void Restaurant::setLocation(string location)
{
    this->location = location;
}

void Restaurant::setOpenHour(int openingHour)
{
    this->openingHour = openingHour;
}

void Restaurant::setClosingHour(int closingHour)
{
    this->closingHour = closingHour;
}

void Restaurant::setRating(double rating)
{
    this->rating = rating;
}

void Restaurant::setCost(double cost)
{
    this->cost = cost;
}


