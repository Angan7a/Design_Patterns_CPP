#include <iostream>

using namespace std;

class RobotPlan {
public:
    virtual void setRobotHead(string head) = 0;
    virtual void setRobotTorso(string torso) = 0;
    virtual void setRobotArms(string arms) = 0;
    virtual void setRobotLegs(string legs) = 0;

};

class Robot : public RobotPlan {
    string robotHead;
    string robotTorso;
    string robotArms;
    string robotLegs;
public:
    string getRobotHead() { return robotHead; }
    void setRobotHead(string head) {
        robotHead = head;
    }
    string getRobotTorso() { return robotTorso; }
    void setRobotTorso(string torso) {
        robotTorso = torso;
    }
    string getRobotArms() { return robotArms; }
    void setRobotArms(string arms) {
        robotArms = arms;
    }
    string getRobotLegs() { return robotLegs; }
    void setRobotLegs(string legs) {
        robotLegs = legs;
    }


};

class RobotBuilder {
public:
    virtual void buildRobotHead() = 0;
    virtual void buildRobotTorso() = 0;
    virtual void buildRobotArms() = 0;
    virtual void buildRobotLegs() = 0;
    virtual Robot* getRobot() = 0;

};

class OldRobotBuilder : public RobotBuilder {
     Robot *robot;
public:
    OldRobotBuilder() {
        this->robot = new Robot();
    }
    void buildRobotHead() {
        robot->setRobotHead("Tin Head");
    }
    void buildRobotTorso() {
        robot->setRobotTorso("Tin Torso");
    }
    void buildRobotArms() {
        robot->setRobotArms("Blowtorch Arms");
    }
    void buildRobotLegs() {
        robot->setRobotLegs("Roller Skates");
    }
    Robot* getRobot() {
        return this->robot;
    }
};


class RobotEngineer {
    RobotBuilder *robotBuilder;
public:
    RobotEngineer(RobotBuilder *robotBuilder) {
        this->robotBuilder = robotBuilder;
    }
    Robot* getRobot() {
         return this->robotBuilder->getRobot();
    }
    void makeRobot() {
        this->robotBuilder->buildRobotHead();
        this->robotBuilder->buildRobotTorso();
        this->robotBuilder->buildRobotArms();
        this->robotBuilder->buildRobotLegs();
    }
};


int main()
{
    RobotBuilder *oldStyleRobot = new OldRobotBuilder();
    RobotEngineer *robotEngineer = new RobotEngineer(oldStyleRobot);
    robotEngineer->makeRobot();
    Robot *firstRobot = robotEngineer->getRobot();

    cout << "Robot Build" << endl;

    cout << "Robot Head Type: " << firstRobot->getRobotHead() << endl;
    cout << "Robot Torso Type: " << firstRobot->getRobotTorso() << endl;
    cout << "Robot Arm Type: " << firstRobot->getRobotArms() << endl;
    cout << "Robot Leg Type: " << firstRobot->getRobotLegs() << endl;

    delete oldStyleRobot;
    delete robotEngineer;
    delete firstRobot;
return 0;
}
