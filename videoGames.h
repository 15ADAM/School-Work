#ifndef VIDEOGAMES
#define VIDEOGAMES
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class videoGames : public media{
 public:
  videoGames();
  void getPublisher();
  void getRating();
  char* returnPublisher();
  int returnRating();

 protected:
  char publisher[30];
  int rating;
  int falseRating;
};

#endif
