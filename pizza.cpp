#include<iostream>
using namespace std;

class Pizza {
protected:
    double price;
public:
    virtual void setPrice(double) = 0;
    virtual double getPrice() = 0;
};

class PizzaHawaii : public Pizza {
public:
    void setPrice(double newPrice) {
        price = newPrice;
    }
    double getPrice() {
        return price;
    }

};

//factory of pizza
class FactoryPizza {
public:
    virtual Pizza* makePizza(string namePizza) = 0;
};

class MyFactoryPizza : public FactoryPizza {
public:
    Pizza* makePizza(string namePizza) {
        if (namePizza == "PizzaHawaii") {
            return new PizzaHawaii();
        }
    }
};

int main()
{
    MyFactoryPizza myFactoryPizza;
    Pizza *pizzaHawaii = myFactoryPizza.makePizza("PizzaHawaii");
    pizzaHawaii->setPrice(34.50);
    cout << "Price pizza: " << pizzaHawaii->getPrice() << endl;
    delete pizzaHawaii;
return 0;
}
