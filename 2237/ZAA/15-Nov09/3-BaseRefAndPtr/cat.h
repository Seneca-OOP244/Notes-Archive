#pragma once
#include "Animal.h"
namespace sdds {
   class Cat : public Animal {
      int m_numOfLives;
   public:
      Cat( );
      Cat(const char* name=  "Garfield",
        int numOfLives = 9);
      void act();
      void move();
      void sound();
      void play();
      ~Cat();
   };
}

