#include <iostream>

class Animal {
    std::string name;
    int weight;
    std::string sound;
public:
    void setName(std::string newName) {
        name = newName;
    }
    std::string getName() {
        return name;
    }

    void setWeight(int newWeight) {
        if (newWeight > 0) {
           weight = newWeight;
        } else {
           std::cout << "Weight should be more than 0!" << std::endl;
        }
    }
    int getWeight() {
        return weight;
    }

    void setSound(std::string newSound) {
        sound = newSound;
    }
    std::string getSound() {
        return sound;
    }
};

//Class Bird
class Bird: public Animal {
    void move(int);
};

// Class Dog
class Dog: public Animal {
public:
    Dog() {
        setSound("Bark");
    }

    void digHole() {
    std::cout << "Hole Dug" << std::endl;
    }
};

//Class Cat
class Cat: public Animal {
public:
    Cat() {
        setSound("Mial");
    }
};

//changing Object Name
static void changeObjectName(Dog &fidoo) {
    fidoo.setName("Markus");
}

int main()
{
    Dog *fido = new Dog();
    fido->setName("Fido");
    Dog azor;
    std::cout << fido->getName() << std::endl;
    fido->digHole();
    fido->setWeight(-1);
    changeObjectName(azor);
    std::cout << azor.getName() << std::endl;
    delete fido;
    return 0;
}
