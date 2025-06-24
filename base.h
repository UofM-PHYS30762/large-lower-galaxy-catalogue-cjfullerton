#ifndef BASE_H
#define BASE_H

#include<iostream>
#include <vector>

namespace namespace1 {
    //Create a pure virtual abstract base class ObservedObject that contains properties common to each astronomical objects:
    class ObservedObject {
    protected:
        std::string name; // name
        double mass; // mass
        double distanceFromEarth; // in light years
        int type;
        std::vector<ObservedObject*> Include;
    public:
        ObservedObject(std::string name, double mass, double distanceFromEarth, int type) :
            name(name), mass(mass), distanceFromEarth(distanceFromEarth), type(type) {}
        virtual void displayObjectData() = 0;
        int Type();
        std::string Name();
        void AddSon(ObservedObject* s);
        void Includeprint();
    };
    class AstronomicalObjectCatalog {
    private:
        std::vector<ObservedObject*> objects;
    public:
        AstronomicalObjectCatalog() {};
        ~AstronomicalObjectCatalog();
        void addObject(int opt);
        void displayAllObjectData();
        void watchgalaxy();
        void watchstar();
        void watchplanet();
        void SeeallGalaxy();
        void Seegalaxyinclude(std::string lsname);
    };
}
#endif