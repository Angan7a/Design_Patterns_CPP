#include<iostream>
using namespace std;

class Pizza {
protected:
    string name;
    double price;
    string ciasto;
    string sos;
    string dodatki;
public:
    void setName(string newName) { name = newName; }
    void setCiasto(string newCiasto) { ciasto = newCiasto; }
    void setSos(string newSos) { sos = newSos; }
    void setDodatki(string newDodatki) { dodatki = newDodatki; }
    void setPrice(double newPrice) { price = newPrice; }
    double getPrice() { return price; }

    void showPizza() {
        cout << "Pizza: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Dough: " << ciasto << endl;
        cout << "Sauce: " << sos << endl;
        cout << "Topping: " << dodatki << endl << endl;
    }
};


//Abstarct Builder
class PizzaBuilder {
protected:
    Pizza *pizza = new Pizza();
public:
    Pizza* getPizza() { return pizza; }
    virtual void buildName() = 0;
    virtual void buildPrice() = 0;
    virtual void buildCiasto() = 0;
    virtual void buildSos() = 0;
    virtual void buildDodatki() = 0;

};


class PizzaHawaii : public PizzaBuilder {
public:
    void buildName() { pizza->setName("Hawaii"); }
    void buildPrice() { pizza->setPrice(5.60); }
    void buildCiasto() { pizza->setCiasto("cross"); }
    void buildSos() { pizza->setSos("mild"); }
    void buildDodatki() { pizza->setDodatki("ham and pineapple"); }
};

class PizzaPepperoni : public PizzaBuilder {
    void buildName() { pizza->setName("Pepperoni"); }
    void buildPrice() { pizza->setPrice(5.40); }
    void buildCiasto() { pizza->setCiasto("pan baked"); }
    void buildSos() { pizza->setSos("hot"); }
    void buildDodatki() { pizza->setDodatki("pepperoni and salami"); }
};

//Director
class Waiter {
    PizzaBuilder* pizzaBuilder;
public:
    void setPizzaBuilder(PizzaBuilder* b) { pizzaBuilder = b;}
    Pizza* getPizza() { return pizzaBuilder->getPizza(); }

    void constuctPizza() {
        pizzaBuilder->buildName();
        pizzaBuilder->buildPrice();
        pizzaBuilder->buildCiasto();
        pizzaBuilder->buildSos();
        pizzaBuilder->buildDodatki();
    }
};


//factory of pizza
class FactoryPizza {
public:
    virtual PizzaBuilder* makePizza(string namePizza) = 0;
};

class MyFactoryPizza : public FactoryPizza {
public:
    PizzaBuilder* makePizza(string namePizza) {
        if (namePizza == "PizzaHawaii") {
            return new PizzaHawaii();
        } else {
            return new PizzaPepperoni();
        }
    }
};



int main()
{
    Waiter waiter;
    FactoryPizza *factoryPizza = new MyFactoryPizza();
    //make Pizza Hawaii
    PizzaBuilder *pizzaOrdered = factoryPizza->makePizza("PizzaHawaii");
    waiter.setPizzaBuilder(pizzaOrdered);
    waiter.constuctPizza();
    Pizza *pizza = waiter.getPizza();
    pizza->showPizza();
    //make Pizza Pepperoni
    pizzaOrdered = factoryPizza->makePizza("PizzaPepperoni");
    waiter.setPizzaBuilder(pizzaOrdered);
    waiter.constuctPizza();
    pizza = waiter.getPizza();
    pizza->showPizza();


return 0;
}
