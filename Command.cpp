// Command.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

class Command
{
public:
   virtual void execute() = 0;
};

class Light
{
public:
   void on()
   {
      std::cout << "LiGhTs On" << std::endl;
   }

   void off()
   {
      std::cout << "lIgHtS oFf" << std::endl;
   }
};

class Fan
{
public:
   void on()
   {
      std::cout << "FaN oN" << std::endl;
   }

   void off()
   {
      std::cout << "fAn OfF" << std::endl;
   }
};

class Door
{
public:
   void on()
   {
      std::cout << "DoOr On" << std::endl;
   }

   void off()
   {
      std::cout << "dOoR oFf" << std::endl;
   }
};

class Oven
{
public:
   void on()
   {
      std::cout << "OvEn On" << std::endl;
   }

   void off()
   {
      std::cout << "oVeN oFf" << std::endl;
   }
};

class NullCommand : public Command
{
public:
   void execute()
   {
      std::cout << "NuLl CoMmAnD" << std::endl;
   }
};

class LightOnCommand : public Command
{
public:
   LightOnCommand(Light *light) : mLight(light) {}

   void execute()
   {
      mLight->on();
   }

private:
   Light *mLight;
};

class LightOffCommand : public Command
{
public:
   LightOffCommand(Light *light) : mLight(light) {}

   void execute()
   {
      mLight->off();
   }

private:
   Light *mLight;
};

class FanOnCommand : public Command
{
public:
   FanOnCommand(Fan *fan) :mFan(fan) {}

   void execute()
   {
      mFan->on();
   }

private:
   Fan *mFan;
};

class FanOffCommand : public Command
{
public:
   FanOffCommand(Fan *fan) : mFan(fan) {}

   void execute()
   {
      mFan->off();
   }

private:
   Fan *mFan;
};

class DoorOnCommand : public Command
{
public:
   DoorOnCommand(Door *door) :mDoor(door) {}

   void execute()
   {
      mDoor->on();
   }

private:
   Door *mDoor;
};

class DoorOffCommand : public Command
{
public:
   DoorOffCommand(Door *door) : mDoor(door) {}

   void execute()
   {
      mDoor->off();
   }

private:
   Door *mDoor;
};

class OvenOnCommand : public Command
{
public:
   OvenOnCommand(Oven *oven) :mOven(oven) {}

   void execute()
   {
      mOven->on();
   }

private:
   Oven *mOven;
};

class OvenOffCommand : public Command
{
public:
   OvenOffCommand(Oven *oven) : mOven(oven) {}

   void execute()
   {
      mOven->off();
   }

private:
   Oven *mOven;
};


class RemoteControl
{
public:
   RemoteControl() : mOnCommand(5), mOffCommand(5)
   {
      Command *nullCmd = new NullCommand;
      for (int i = 0; i < 5; i++)
      {
         mOffCommand[i] = nullCmd;
         mOnCommand[i] = nullCmd;
      }
   }

   void setCommand(int id, Command *onCmd, Command *offCmd) 
   {
      mOnCommand[id] = onCmd;
      mOffCommand[id] = offCmd;
   }

   void onButtonPressed(int id)
   {
      mOnCommand[id]->execute();
   }

   void offButtonPressed(int id)
   {
      mOffCommand[id]->execute();
   }

private:
   std::vector<Command*> mOnCommand;
   std::vector<Command*> mOffCommand;
};

int main()
{
    std::cout << "Hello World!\n"; 

    Light *light = new Light;
    Fan *fan = new Fan;
    Door *door = new Door;
    Oven *oven = new Oven;

    LightOnCommand *lightOn = new LightOnCommand(light);
    LightOffCommand *lightOff = new LightOffCommand(light);
    FanOnCommand *fanOn = new FanOnCommand(fan);
    FanOffCommand *fanOff = new FanOffCommand(fan);
    DoorOnCommand *doorOn = new DoorOnCommand(door);
    DoorOffCommand *doorOff = new DoorOffCommand(door);
    OvenOnCommand *ovenOn = new OvenOnCommand(oven);
    OvenOffCommand *ovenOff = new OvenOffCommand(oven);
    NullCommand *nullOn = new NullCommand();
    NullCommand *nullOff = new NullCommand();

    RemoteControl *control = new RemoteControl;

    control->setCommand(1, lightOn, lightOff);
    control->onButtonPressed(1);
    control->offButtonPressed(1);

    control->setCommand(2, fanOn, fanOff);
    control->onButtonPressed(2);
    control->offButtonPressed(2);

    control->setCommand(3, doorOn, doorOff);
    control->onButtonPressed(3);
    control->offButtonPressed(3);

    control->setCommand(0, nullOn, nullOff);
    control->onButtonPressed(0);

    control->setCommand(4, ovenOn, ovenOff);
    control->onButtonPressed(4);
    control->offButtonPressed(4);

    delete light, lightOn, lightOff;
    delete fan, fanOn, fanOff;
    delete door, doorOn, doorOff;
    delete oven, ovenOn, ovenOff;
    delete control;

    return 0;
}


