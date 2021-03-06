#include <iostream>

using namespace std;

class EntertainmentDevice {
public:
     int deviceState;
     int maxSetting;
     int volumeLevel;
     EntertainmentDevice() : volumeLevel(0) {}
     virtual void buttonFivePressed() = 0;
     virtual void buttonSixPressed() = 0;
     virtual void pausedDevice() = 0;

     void deviceFeedback() {
         if (deviceState > maxSetting || deviceState < 0) { deviceState = 0; }
         cout << "On " << deviceState << endl;
     }
     void buttonSevenPressed() {
          volumeLevel++;
          cout << "Voulme at: " << volumeLevel << endl;
     }
     void buttonEightPressed() {
          volumeLevel--;
          cout << "Voulme at: " << volumeLevel << endl;
     }
     void mutedDevice() {
         cout << "Device was Muted" << endl;
     }


};

class TVDevice : public EntertainmentDevice {
public:
     TVDevice(int newDeviceState, int newMaxSetting) {
          deviceState = newDeviceState;
           maxSetting = newMaxSetting;
     }
     void buttonFivePressed() {
         cout << "Chanel Down" << endl;
         deviceState--;
     }
     void buttonSixPressed() {
         cout << "Chanel Up" << endl;
         deviceState++;
     }
     void pausedDevice(){
        cout << "TV was Paused" << endl;
     }

};

class DVDDevice : public EntertainmentDevice {
public:
     DVDDevice(int newDeviceState, int newMaxSetting) {
          deviceState = newDeviceState;
           maxSetting = newMaxSetting;
     }
     void buttonFivePressed() {
         cout << "Previous Move" << endl;
         deviceState--;
     }
     void buttonSixPressed() {
         cout << "Next Move" << endl;
         deviceState++;
     }
     void pausedDevice() {
         cout << "DVD was Paused" << endl;
     }

};

class RemoteButton {
    EntertainmentDevice *theDevice;
public:
    RemoteButton(EntertainmentDevice *newDevice) : theDevice(newDevice) {
    }
    void buttonFivePressed() {
        theDevice->buttonFivePressed();
    }
    void buttonSixPressed() {
        theDevice->buttonSixPressed();
    }
    void deviceFeedback() {
        theDevice->deviceFeedback();
    }
    EntertainmentDevice* getDevice() { return theDevice; }

    virtual void buttonNinePressed() = 0;
};

class TVRemoteMute : public RemoteButton {
public:
    TVRemoteMute(EntertainmentDevice *newDevice) : RemoteButton(newDevice){ }
    void buttonNinePressed() {
        getDevice()->mutedDevice();
    }
};

class TVRemotePause : public RemoteButton {
public:
    TVRemotePause(EntertainmentDevice *newDevice) : RemoteButton(newDevice){ }
    void buttonNinePressed() {
        getDevice()->pausedDevice();
    }
};

int main()
{
      RemoteButton *theTV = new TVRemoteMute(new TVDevice(1, 200));
      RemoteButton *theTV2 = new TVRemotePause(new TVDevice(1, 200));
      RemoteButton *theDVD = new TVRemoteMute(new DVDDevice(2, 4));
      RemoteButton *theDVD2 = new TVRemotePause(new DVDDevice(2, 4));
      cout << "Test TV with Mute" << endl;
      theTV->buttonFivePressed();
      theTV->buttonSixPressed();
      theTV->buttonNinePressed();
      theTV->deviceFeedback();

      cout << "\nTest TV with Pause" << endl;
      theTV2->buttonFivePressed();
      theTV2->buttonSixPressed();
      theTV2->buttonSixPressed();
      theTV2->buttonSixPressed();
      theTV2->buttonSixPressed();
      theTV2->buttonNinePressed();
      theTV2->deviceFeedback();

      cout << "\nTest DVD with Mute" << endl;
      theDVD->buttonFivePressed();
      theDVD->buttonFivePressed();
      theDVD->buttonFivePressed();
      theDVD->buttonNinePressed();
      theDVD->deviceFeedback();

      cout << "\nTest DVD with Pause" << endl;
      theDVD2->buttonFivePressed();
      theDVD2->buttonNinePressed();
      theDVD2->deviceFeedback();

      delete theTV;
      delete theTV2;
      delete theDVD;
      delete theDVD2;
return 0;
}
