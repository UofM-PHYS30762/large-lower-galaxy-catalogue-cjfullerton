// w77182qw, 2022-2023

#include "base.h"
#include "fun.h"
#include "galaxy.h"
#include "planet.h"
#include "star.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

// the main function
int main() {
  std::cout << "Select read in method 1. Keyboard 2. File\n";
  int opt;
  std::cin >> opt;
  if (opt == 2) {
    Work_from_file();
    return 0;
  }
  using namespace namespace1;
  AstronomicalObjectCatalog catalog;
  while (true) {
    std::cout << "\nMenu\n";
    std::cout << "1. Add an object\n";
    std::cout << "2. Display all object data\n";
    std::cout << "3. watch galaxy\n";
    std::cout << "4. watch star\n";
    std::cout << "5. watch planet\n";
    std::cout << "6. View the planets or stars contained in the galaxy\n";
    std::cout << "7. Quit\n";
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    while (check_number(choice) == 0) {
      std::cin >> choice;
    }
    switch (choice) {
    case 1:
      catalog.addObject(0);
      break;
    case 2:
      catalog.displayAllObjectData();
      break;
    case 3:
      catalog.watchgalaxy();
      break;
    case 4:
      catalog.watchstar();
      break;
    case 5:
      catalog.watchplanet();
      break;
    case 6: {
      std::cout << "Enter the name of the galaxy you want to view:\n";
      std::string ls;
      std::cin >> ls;
      catalog.Seegalaxyinclude(ls);
      break;
    }
    case 7:
      return 0;
    }
  }
  return 0;
}
