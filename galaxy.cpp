#include "galaxy.h"
#include <iostream>
// implementation of the derived class Galaxy
void Galaxy::displayObjectData() {
  std::cout << "Name: " << name << std::endl;
  std::cout << "Mass: " << mass << " x 10^12 solar masses" << std::endl;
  std::cout << "Distance: " << distanceFromEarth << " light years" << std::endl;
  std::cout << "Galaxy type: " << galaxyType << std::endl;
  std::cout << "Number of stars: " << numOfStars << std::endl;
  std::cout << "\n";
}

void Galaxy::watchSon() {
  for (auto obj : Include) {
    obj->displayObjectData();
  }
}