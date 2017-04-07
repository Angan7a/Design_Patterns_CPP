#include <iostream>

class Creature {
    std::string name;
    int weight;
    std::string sound;
public:
    virtual void setName(std::string newName) = 0;
    virtual std::string getName() = 0;

    virtual void setWeight(int newWeight) = 0;
    virtual int getWeight() = 0;
};

//Class Giraffe
class Giraffe: public Creature {
    std::string name;
public:
    void setName(std::string newName) {
        name = newName;
    }
    std::string getName() {
        return name;
    }

    void setWeight(int newWeight) {
    }
    int getWeight() {
    }
};

//Class Animal
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

// Class Dog
class Dog: public Animal {
    void bePrivate() {
         std::cout << "In private method" << std::endl;
    }
public:
    Dog() {
        setSound("Bark");
    }

    void digHole() {
    std::cout << "Hole Dug" << std::endl;
    }

    void accesPrivate() {
        bePrivate();
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

//speak Animal
static void speakAnimal(Animal *ranAnimal) {
     std::cout << "Animal says: " <<  ranAnimal->getSound() << std::endl;
}



int main()
{
    Animal *doggy = new Dog();
    Animal *kitty = new Cat();
    Dog *azor = new Dog();

    std::cout << "Dogy says: " << doggy->getSound() << std::endl;
    std::cout << "Kitty says: " << kitty->getSound() << std::endl;

    Animal ** animals = new Animal*[4];
    animals[0] = doggy;
    animals[1] = kitty;

    std::cout << "Dogy says: " << animals[0]->getSound() << std::endl;
    std::cout << "Kitty says: " << animals[1]->getSound() << std::endl;

    speakAnimal(doggy);
    ((Dog*)doggy)->digHole();

    azor->digHole();

    azor->accesPrivate();

    Giraffe *giraffe = new Giraffe();
    giraffe->setName("Frank");
    std::cout << giraffe->getName() << std::endl;

    delete doggy;
    delete kitty;
    delete azor;
    delete animals;
    delete giraffe;
    return 0;
}
