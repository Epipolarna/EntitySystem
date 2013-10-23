#include <iostream>
#include "EntitySystem.hpp"
#include "Component.hpp"
#include "System.hpp"

#define AllComponents Name,Position     //OBS required as for now... :(

class Name : public Component<> {
public:
    std::string nameString;
};

class Position : public Component<Name> {
public:
    float x;
};

class SystemTest : public System<Name, AllComponents>
{
public:
    SystemTest(EntitySystem<AllComponents> & es):System<Name, AllComponents>::System(es) {}
    void processStep(Name & name) {
        std::cerr << "name: " + name.nameString + "\n";
    }
};

int main()
{
    EntitySystem<AllComponents> entitySystem;

    Entity<AllComponents> & e = entitySystem.createEntity();
    Entity<AllComponents> & e2 = entitySystem.createEntity();
    e.add<Position>();
    e.add<Name>();
    e.add<Position>();
    //std::cerr << "hasName: "+std::to_string(e.has<Name>());
    //std::cerr << "hasPosition: "+std::to_string(e.has<Position>());
    std::cerr << "\n";
/*
    e.get<Name>().nameString = "John Doe";
    e.remove<Name>();
    e2.add<Name>();
    //e2.get<Name>().nameString = "Bar Foo";
*/
    std::cerr << "\n";
    SystemTest test(entitySystem);
    test.batch();

    return 0;
}

