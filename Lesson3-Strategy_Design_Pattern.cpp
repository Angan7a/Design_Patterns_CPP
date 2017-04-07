
#include <iostream>

class Flys {
public:
   virtual std::string fly() = 0;
};

class ItFlys : public Flys {
public:
    std::string fly() {
         return "Flying High";
    }
};

class CantFlys : public Flys {
public:
    std::string fly() {
         return "I can't fly";
    }
};

//Class Animal
class Animal {
    std::string name;
    double height;
    int weight;
    std::string favFood;
    double speed;
    std::string sound;
public:
    Flys *flyingType;
    void setName(std::string newName) {
        name = newName;
    }
    std::string getName() {
        return name;
    }

    void setHeight(double newHeight) {
        height = newHeight;
    }
    double getHeight() {
        return height;
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

    void setFavFood(std::string newFavFood) {
        favFood = newFavFood;
    }
    std::string getFavFood() {
        return favFood;
    }

    void setSpeed(int newSpeed) {
        speed = newSpeed;
    }
    int getSpeed() {
        return speed;
    }

    void setSound(std::string newSound) {
        sound = newSound;
    }
    std::string getSound() {
        return sound;
    }

    std::string tryToFly() {
        return flyingType->fly();
    }

    void setFlyingAbility(Flys *newFlyType) {
        flyingType = newFlyType;
    }
};

//Class Bird
class Bird: public Animal {
public:
     Bird() {
         setSound("Tweet");
         flyingType = new ItFlys();
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
        flyingType = new CantFlys();
    }

    void digHole() {
    std::cout << "Hole Dug" << std::endl;
    }

    void accesPrivate() {
        bePrivate();
    }

};


int main()
{
    Animal *sparky = new Dog();
    Animal *tweety = new Bird();

    std::cout << "Dog: " << sparky->tryToFly() << std::endl;
    std::cout << "Bird: " << tweety->tryToFly() << std::endl;

    sparky->setFlyingAbility(new ItFlys());
    std::cout << "Dog: " << sparky->tryToFly() << std::endl;

    delete sparky;
    delete tweety;
    return 0;
}
