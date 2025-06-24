#ifndef GALAXY_H
#define GALAXY_H

#include<iostream>
#include <vector>
#include "base.h"

using namespace namespace1;
//Galaxy derived class 
class Galaxy : public ObservedObject {
private:
    std::string galaxyType; // Represents the type of galaxy. For example, spiral galaxies, elliptical galaxies, or irregular galaxy.
    int numOfStars; // Represents the number of stars in a galaxy
    
public:
    Galaxy(std::string name, double mass, double distanceFromEarth, int type, std::string galaxyType, int numOfStars) :
        ObservedObject(name, mass, distanceFromEarth, type), galaxyType(galaxyType), numOfStars(numOfStars) {}
    void displayObjectData();
    
    void watchSon();
};

#endif