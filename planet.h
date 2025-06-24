#ifndef PLANET_H
#define PLANET_H

#include<iostream>
#include <vector>
#include "base.h"

using namespace namespace1;
//Planet derived class
class Planet : public ObservedObject {
private:
    double radius; //It refers to the radius of the planet, usually based on the Earth radius.
    bool hasAtmosphere;
    // Indicates whether a planet has an atmosphere, which can help protect the planet's living environment, but may also hinder our observation and research of planets.
    double density_; // density
public:
    Planet(std::string name, double mass, double distanceFromEarth, int type, double radius, bool hasAtmosphere) :
        ObservedObject(name, mass, distanceFromEarth, type), radius(radius), hasAtmosphere(hasAtmosphere) {}
    void displayObjectData();
};

#endif