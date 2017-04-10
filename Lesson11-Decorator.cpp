#include<iostream>
using namespace std;

class Pizza {
public:
    virtual string getDescription() = 0;
    virtual double getCost() = 0;
};

class PlainPizza : public Pizza{
public:
    string getDescription() {
         return "Thin Dough";
    }
    double getCost(){
         return 4.00;
    }
};

class ToopingDecorator : public PlainPizza {
protected:
    Pizza *tempPizza;
public:
    ToopingDecorator(Pizza *newPizza) {
        tempPizza = newPizza;
    }
    string getDescription() {
        return tempPizza->getDescription();
    }
    double getCost() {
        return tempPizza->getCost();
    }
};


class Mozzarella : public ToopingDecorator {
public:
    Mozzarella(Pizza *newPizza) : ToopingDecorator(newPizza) {
        cout << "Adding Dough" << endl;
        cout << "Adding Moz" << endl;
    }
    string getDescription() {
        return tempPizza->getDescription() + ", Mozzarella";
    }
    double getCost() {
        return (tempPizza->getCost() + 0.50);
    }

};

class TomatoSauce : public ToopingDecorator {
public:
    TomatoSauce(Pizza *newPizza) : ToopingDecorator(newPizza) {
        cout << "Adding Sauce" << endl;
    }
    string getDescription() {
        return tempPizza->getDescription() + ", Tomato Souce";
    }
    double getCost() {
        return (tempPizza->getCost() + 0.35);
    }

};

class ExtraChees : public ToopingDecorator {
public:
    ExtraChees(Pizza *newPizza) : ToopingDecorator(newPizza) {
        cout << "Adding Extra Chees" << endl;
    }
    string getDescription() {
        return tempPizza->getDescription() + ", Extra Chees";
    }
    double getCost() {
        return (tempPizza->getCost() + 0.45);
    }

};
int main()
{
     Pizza *basicPizza = new TomatoSauce(new ExtraChees(new Mozzarella( new PlainPizza())));
    cout << "Ingrediens: " << basicPizza->getDescription() << endl;
    cout << "Price: " << basicPizza->getCost() << endl;
return 0;
}
