#include <iostream>
using namespace std;

class EnemyShip {
    string name;
    double amtDemage;
public:
    string getName() { return name; }
    void setName(string newName) { this->name = newName; }

    double getDamage() { return amtDemage; }
    void setDemage(double newDemage) { this->amtDemage = newDemage; }

    void followHeroShip() {
         cout << this->getName() << " is following the Hero" << endl;
    }

    void displayEnemyShip() {
         cout << this->getName() << " is on the screen" << endl;
    }

    void enemyShipShoots() {
         cout << this->getName() << " attacks and does " << this->getDamage() << endl;
    }
};

class UFOEnemyShip : public EnemyShip {
public:
    UFOEnemyShip() {
        setName("UFO Enamy Ship");
        setDemage(20.0);
    }

};

class BigUFOEnemyShip : public UFOEnemyShip {
public:
    BigUFOEnemyShip() {
        setName("Big UFO Enamy Ship");
        setDemage(40.0);
    }

};


class RocketEnemyShip : public EnemyShip {
public:
    RocketEnemyShip() {
        setName("Rocket Enemy Ship");
        setDemage(10.0);
    }

};



class EnemyShipFacotry {
public:
    EnemyShip* makeEnemyShip(string newShipType) {
        EnemyShip newShip;
        if(newShipType == "u") {
            return new UFOEnemyShip();
        } else if(newShipType == "r") {
            return new RocketEnemyShip();
        } else if(newShipType == "b") {
            return new BigUFOEnemyShip();
        } else {
            return NULL;
        }

    }
};


static void doStuffEnemy(EnemyShip *anEnemyShip) {
    anEnemyShip->displayEnemyShip();
    anEnemyShip->followHeroShip();
    anEnemyShip->enemyShipShoots();
}


int main()
{
    EnemyShipFacotry *shipFacotry = new EnemyShipFacotry();
    EnemyShip *theEnemy = NULL;
    string typeOfShip;
    while(typeOfShip != "e") {
        cout << "What type ship? (u / r / b) [press e when you want finish]" << endl;
        cin >> typeOfShip;
        theEnemy = shipFacotry->makeEnemyShip(typeOfShip);
        if(theEnemy != NULL) {
            doStuffEnemy(theEnemy);
        } else if(typeOfShip != "e") {
            cout << "Enter u, r or b next time" << endl;
        }
    }
    delete shipFacotry;
    delete theEnemy;
return 0;
}
