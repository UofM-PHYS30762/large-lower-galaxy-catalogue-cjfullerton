#ifndef STAR_H
#define STAR_H

#include<iostream>
#include <vector>
#include "base.h"

using namespace namespace1;
//Star derived class
class Star : public ObservedObject {
private:
    std::string spectralClass; //Represents the spectral type of a star, usually represented by a combination of letters and numbers. For example, G2V is the spectral type of the sun.
    double luminosity; //Represents the absolute brightness of a star, which is how many times brighter it is than the sun within the same distance.
public:
    Star(std::string name, double mass, double distanceFromEarth, int type, std::string spectralClass, double luminosity) :
        ObservedObject(name, mass, distanceFromEarth, type), spectralClass(spectralClass), luminosity(luminosity) {}
    void displayObjectData();
};
#endif