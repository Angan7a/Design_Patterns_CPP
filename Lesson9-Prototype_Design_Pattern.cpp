#include <iostream>
using namespace std;


class Animal {
public:
    virtual Animal* makeCopy() = 0;
    virtual void setName(string) = 0;
    virtual string getName() = 0;
};

class Sheep : public Animal {
    string name;
public:
    Sheep() {
        cout << "Sheep is Made" << endl;
    }
    void setName(string newName) {
        name = newName;
    }
    string getName() {
        return name;
    }
    Animal* makeCopy() {
        cout << "Sheep is Being Made" << endl;
        return new Sheep(*this);
    }
};

//class CloneFacotry {
//public:
//    Animal* getClone(Animal *animalSample) {
//         return animalSample->makeCopy();
//    }
//};

int main()
{
    Animal *dolly = new Sheep();
    dolly->setName("Dolly");
    cout <<"Dolly what is your name? - My name is " << dolly->getName() << endl;
    Animal *basy = dolly->makeCopy();
    cout <<"Basy what is your name? - My name is " << basy->getName() << endl;
    delete dolly;
    delete basy;
return 0;
}
