#include <iostream>
#include "star.h"
//implementation of the derived class Star
void Star::displayObjectData() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Mass: " << mass << " x 10^12 solar masses" << std::endl;
    std::cout << "Distance: " << distanceFromEarth << " light years" << std::endl;
    std::cout << "spectralClass: " << spectralClass << std::endl;
    std::cout << "luminosity: " << luminosity << std::endl;
    std::cout << "\n";
}
