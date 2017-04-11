#include<iostream>
using namespace std;

class EnemyAttacker {
public:
    virtual void fireWeapon() = 0;
    virtual void driveForward() = 0;
    virtual void assignDriver(string driverName) = 0;
};


class EnemyTank : public EnemyAttacker {
public:
    void fireWeapon(){
        int attackDamage = 5;
        cout << "Enemy Tank Does " << attackDamage << " Damage" << endl;
    }
    void driveForward() {
        int movment = 3;
        cout << "Enemy Tank moves " << movment << " spaces" << endl;
    }
    void assignDriver(string driverName) {
        cout << driverName << " is driving tank" << endl;
    }
};

class EnemyRobot {
public:
    void smashWithHands() {
        int attackDamage = 4;
        cout << "Enemy Robot Causes " << attackDamage << " Damage With Its Hands" << endl; 
    }
    void walkForward() {
        int movment = 2;
        cout << "Enemy Robot Walks Forward " << movment << " Spaces" << endl;
    }
    void reactToHuman(string driverName) {
        cout << "Enemy Robot Tramps on " << driverName << endl;
    }
};

class EnemyRobotAdapter : public EnemyAttacker {
EnemyRobot *theRobot;
public:
    EnemyRobotAdapter(EnemyRobot *newRobot) {
        theRobot = newRobot;
    }
    void fireWeapon() {
        theRobot->smashWithHands();
    }
    void driveForward() {
        theRobot->walkForward();
    }
    void assignDriver(string driverName) {
        theRobot->reactToHuman(driverName);
    }

};

int main()
{
     EnemyTank* rx7Tank = new EnemyTank();
     EnemyRobot* fredTheRobot = new EnemyRobot();
     EnemyAttacker *robotAdapter = new EnemyRobotAdapter(fredTheRobot);

     cout << "The Robot" << endl;
     fredTheRobot->reactToHuman("Paul");
     fredTheRobot->walkForward();
     fredTheRobot->smashWithHands();
     cout << endl;

     cout << "The Enemy Tank" << endl;
     rx7Tank->assignDriver("Frank");
     rx7Tank->driveForward();
     rx7Tank->fireWeapon();
     cout << endl;

     cout << "The Robot with Adapter" << endl;
     robotAdapter->assignDriver("Mark");
     robotAdapter->driveForward();
     robotAdapter->fireWeapon();


     delete rx7Tank;
     delete fredTheRobot;
     delete robotAdapter;

return 0;
}
