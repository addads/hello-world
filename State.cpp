// State.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

class MusicPlayer;
class StoppedState;
class PausedState;
class PlayingState;

class MusicPlayerState
{
public:
   MusicPlayerState(std::string name);

   virtual ~MusicPlayerState();

   virtual void play(MusicPlayer *player);

   virtual void pause(MusicPlayer *player);

   virtual void stop(MusicPlayer *player);

   std::string getName();

private:
   std::string mName;
};

class MusicPlayer
{
public:
   enum State
   {
      STOPPED,
      PLAYING,
      PAUSED
   };

   MusicPlayer();

   virtual ~MusicPlayer();

   void play();

   void pause();

   void stop();

   void setState(State state);

private:
   MusicPlayerState *mState;
};

class PlayingState : public MusicPlayerState
{
public:
   PlayingState();

   virtual ~PlayingState();

   virtual void pause(MusicPlayer *player);

   virtual void stop(MusicPlayer *player);
};

class PausedState : public MusicPlayerState
{
public:
   PausedState();

   virtual ~PausedState();

   virtual void play(MusicPlayer *player);

   virtual void stop(MusicPlayer *player);
};

class StoppedState : public MusicPlayerState
{
public:
   StoppedState();

   virtual ~StoppedState();

   virtual void play(MusicPlayer *player);
};







MusicPlayerState::MusicPlayerState(std::string name) : mName(name) {}

MusicPlayerState::~MusicPlayerState() {}

void  MusicPlayerState::play(MusicPlayer *player)
{
   std::cout << "NoPeE: " << getName() << " tO pLaYiNg" << std::endl;
}

void  MusicPlayerState::pause(MusicPlayer *player)
{
   std::cout << "nOpEe: " << getName() << " To PaUsEd" << std::endl;
}

void  MusicPlayerState::stop(MusicPlayer *player)
{
   std::cout << "NoPeE: " << getName() << " tO sToPpEd" << std::endl;
}

std::string  MusicPlayerState::getName()
{
   return mName;
}


MusicPlayer::MusicPlayer() : mState(new StoppedState()) {}

MusicPlayer::~MusicPlayer()
{
   delete mState;
}

void MusicPlayer::play()
{
   mState->play(this);
}

void MusicPlayer::pause()
{
   mState->pause(this);
}

void MusicPlayer::stop()
{
   mState->stop(this);
}

void MusicPlayer::setState(State state)
{
   std::cout << "FrOm " << mState->getName() << " To ";
   delete mState;

   if (state == STOPPED)
   {
      mState = new StoppedState();
      std::cout << mState->getName() << std::endl;
      return;
   }

   if (state == PLAYING)
   {
      mState = new PlayingState();
      std::cout << mState->getName() << std::endl;
      return;
   }

   if (state == PAUSED)
   {
      mState = new PausedState();
      std::cout << mState->getName() << std::endl;
      return;
   }
}




PlayingState::PlayingState() : MusicPlayerState(std::string("pLaYiNg")) {}

PlayingState::~PlayingState() {}

void  PlayingState::pause(MusicPlayer *player)
{
   player->setState(MusicPlayer::PAUSED);
}

void  PlayingState::stop(MusicPlayer *player)
{
   player->setState(MusicPlayer::STOPPED);
}



PausedState::PausedState() : MusicPlayerState(std::string("PaUsEd")) {}

PausedState::~PausedState() {}

void PausedState::play(MusicPlayer *player)
{
   player->setState(MusicPlayer::PLAYING);
}

void PausedState::stop(MusicPlayer *player)
{
   player->setState(MusicPlayer::STOPPED);
}



StoppedState::StoppedState() : MusicPlayerState(std::string("sToPpEd")) {}

StoppedState::~StoppedState() {}

void StoppedState::play(MusicPlayer *player)
{
   player->setState(MusicPlayer::PLAYING);
}



int main()
{
    std::cout << "Hello World!\n"; 

    MusicPlayer player;
    player.play();
    player.pause();
    player.stop();
    player.play();
    player.pause();
    player.play();
    player.stop();
    player.pause();

    return 0;
}