#include "planet.h"
#include <iostream>
// implementation of the derived class Planet
void Planet::displayObjectData() {
  std::cout << "Name: " << name << std::endl;
  std::cout << "Mass: " << mass << " x 10^12 solar masses" << std::endl;
  std::cout << "Distance: " << distanceFromEarth << " light years" << std::endl;
  std::cout << "radius: " << radius << std::endl;
  auto density = [](double r, double m) -> double {
    return (3 * m / (4 * 3.1415 * r * r * r));
  };
  density_ = density(radius, mass);
  std::cout << "density: " << density_ << std::endl;
  std::cout << "hasAtmosphere: " << hasAtmosphere << std::endl;
  std::cout << "\n";
}
