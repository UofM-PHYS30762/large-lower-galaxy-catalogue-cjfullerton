#ifndef FUN_H
#define FUN_H

#include <fstream>
#include<iostream>
#include <vector>
#include "base.h"
#include "planet.h"
#include "star.h"
#include "galaxy.h"

std::ifstream file;

template <typename T>
bool check_number(T number) {
	if (number < 0) {
		std::cout << "It must be a positive value.";
		return 0;
	}
	return 1;
}

void AstronomicalObjectCatalog::displayAllObjectData() {
    for (auto obj : objects) {
        obj->displayObjectData();
    }
}

void AstronomicalObjectCatalog::addObject(int opt) {
    std::string objectType;
    std::cout << "Enter the type of object to add (Galaxy, Star, Planet): ";
    if (opt) file >> objectType;
    else std::cin >> objectType;
    while (objectType != "Galaxy" && objectType != "Star" && objectType != "Planet") {
        std::cout << "your type is not Galaxy Star or Planet, please enter your type again!\n";
        if (opt) file >> objectType;
        else std::cin >> objectType;
    }
    if (objectType == "Galaxy") {
        std::string name, galaxyType;
        double mass, distanceFromEarth;
        int numOfStars;
        std::cout << "Enter name: ";
        if (opt) file >> name;
        else std::cin >> name;
        bool flag = 0;
        while (flag == 0) {
            std::cout << "Enter mass ( x 10^12 solar masses): ";
            if (opt) file >> mass;
            else std::cin >> mass;
            flag = check_number(mass);
        }
        std::cout << "Enter Distance: ";
        if (opt) file >> distanceFromEarth;
        else std::cin >> distanceFromEarth;
        std::cout << "Enter Galaxy type: ";
        if (opt) file >> galaxyType;
        else std::cin >> galaxyType;
        std::cout << "Number of stars: ";
        if (opt) file >> numOfStars;
        else std::cin >> numOfStars;
        Galaxy* now = new Galaxy(name, mass, distanceFromEarth, 1, galaxyType, numOfStars);
        objects.push_back(now);
        // prompt for remaining properties and fill values
        // create a new Galaxy object and add to the objects vector
    }
    else if (objectType == "Star") {
        // prompt and add new Star object
        std::string name, spectralClass;
        double mass, distanceFromEarth, luminosity;
        std::cout << "Enter name: ";
        if (opt) file >> name;
        else std::cin >> name;
        bool flag = 0;
        while (flag == 0) {
            std::cout << "Enter mass ( x 10^12 solar masses): ";
            if (opt) file >> mass;
            else std::cin >> mass;
            flag = check_number(mass);
        }
        std::cout << "Enter Distance: ";
        if (opt) file >> distanceFromEarth;
        else std::cin >> distanceFromEarth;
        std::cout << "Enter spectralClass: ";
        if (opt) file >> spectralClass;
        else std::cin >> spectralClass;
        std::cout << "luminosity: ";
        if (opt) file >> luminosity;
        else std::cin >> luminosity;
        Star* now = new Star(name, mass, distanceFromEarth, 2, spectralClass, luminosity);
        objects.push_back(now);
        std::cout << "The existing galaxies are as follows:\n";
        SeeallGalaxy();
        std::cout << "\nIf there is a galaxy containing that star, please enter the name of the galaxy\n";
        std::cout << "If not, please enter -1\n";
        std:: string ls;
        if (opt) file >> ls;
        else std:: cin >> ls;
        if(ls != "-1")
        for (auto obj : objects) {
            if (obj->Type() == 1 && obj->Name() == ls) {
                obj->AddSon(now);
            }
        }
    }
    else if (objectType == "Planet") {
        // prompt and add new Planet object
        std::string name;
        double mass, distanceFromEarth, radius;
        bool hasAtmosphere;
        std::cout << "Enter name: ";
        if (opt) file >> name;
        else std::cin >> name;
        bool flag = 0;
        while (flag == 0) {
            std::cout << "Enter mass ( x 10^12 solar masses): ";
            if (opt) file >> mass;
            else std::cin >> mass;
            flag = check_number(mass);
        }
        std::cout << "Enter Distance: ";
        if (opt) file >> distanceFromEarth;
        else std::cin >> distanceFromEarth;
        std::cout << "radius: ";
        if (opt) file >> radius;
        else std::cin >> radius;
        bool value = false;
        std::string input;
        while (true) {
            try {
                std::cout << "has Atmosphere or not? (1:yes 0:no): ";
                if (opt) file >> input;
                else std::cin >> input;
                if (input != "0" && input != "1") {
                    throw std::invalid_argument("Invalid input. Please enter 0 or 1.");
                }
                value = (input[0] == '0' ? 0 : 1);
                break;
            }
            catch (const std::invalid_argument& e) {
                std::cerr << "Invalid argument: " << e.what() << std::endl;
            }
            catch (const std::out_of_range& e) {
                std::cerr << "Out of range: " << e.what() << std::endl;
            }
            catch (...) {
                std::cerr << "Unknown error." << std::endl;
            }
        }
        hasAtmosphere = value;
        Planet* now = new Planet(name, mass, distanceFromEarth, 3, radius, hasAtmosphere);
        objects.push_back(now);
        std::cout << "The galaxies contained are as follows:\n";
        SeeallGalaxy();
        std::cout << "\nIf there is a galaxy containing that planet, please enter the name of the galaxy\n";
        std::cout << "If not, please enter -1\n";
        std::string ls;
        if (opt) file >> ls;
        else std::cin >> ls;
        if(ls != "-1")
        for (auto obj : objects) {
            if (obj->Type() == 1 && obj->Name() == ls) {
                obj->AddSon(now);
            }
        }
    }
}

void AstronomicalObjectCatalog::watchgalaxy() {
    for (auto obj : objects) {
        if(obj->Type() == 1)
            obj->displayObjectData();
    }
}

void AstronomicalObjectCatalog::watchstar() {
    for (auto obj : objects) {
        if (obj->Type() == 2)
            obj->displayObjectData();
    }
}

void AstronomicalObjectCatalog::watchplanet() {
    for (auto obj : objects) {
        if (obj->Type() == 3)
            obj->displayObjectData();
    }
}

void AstronomicalObjectCatalog::SeeallGalaxy() {
    for (auto obj : objects) {
        if (obj->Type() == 1)
            std::cout << obj->Name() << " ";
    }
}
//Store and access to the membership information
void ObservedObject::AddSon(ObservedObject* s) {
    Include.push_back(s);
}

void ObservedObject::Includeprint() {
    for (auto obj : Include) {
        obj->displayObjectData();
    }
}

void AstronomicalObjectCatalog::Seegalaxyinclude(std::string lsname) {
    for (auto obj : objects) {
        if (obj->Name() == lsname) {
            obj->Includeprint();
        }
    }
}
// Destructor, destroys all objects in the vector
AstronomicalObjectCatalog::~AstronomicalObjectCatalog() {
    for (auto obj : objects) {
        delete obj;
    }
}

void ObservedObject::displayObjectData() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Mass: " << mass << std::endl;
    std::cout << "DistanceFromEarth: " << distanceFromEarth << std::endl;
}

int ObservedObject::Type() {
    return type;
}

std::string ObservedObject::Name() {
    return name;
}

bool check_number(int number) {
    if (number < 1 || number > 7) {
        std::cout << "your choice must be 1 to 7.\n";
        std::cout << "Enter again!\n";
        return 0;
    }
    return 1;
}

void Work_from_file() {
    AstronomicalObjectCatalog catalog;
    file.open("data.txt");
    int choice;
    
    while (true) {
        std::cout << "\nMenu\n";
        std::cout << "1. Add an object\n";
        std::cout << "2. Display all object data\n";
        std::cout << "3. watch galaxy\n";
        std::cout << "4. watch star\n";
        std::cout << "5. watch planet\n";
        std::cout << "6. View the planets or stars contained in the galaxy\n";
        std::cout << "7. Quit\n";
        file >> choice;
        while (check_number(choice) == 0) {
            file >> choice;
        }
        switch (choice) {
        case 1:
            catalog.addObject(1);
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
            file >> ls;
            catalog.Seegalaxyinclude(ls);
            break;
        }
        case 7:
            return;
        }
    }
}
#endif