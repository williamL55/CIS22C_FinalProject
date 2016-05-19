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

void Restaurant::setName(string name)
{
    this->name = name;
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
