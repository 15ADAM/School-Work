#ifndef MOVIES
#define MOVIES
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class movies : public media{
 public:
  movies();
  void getDirector();
  void getDurationH();
  void getDurationM();
  void getRating();
  char* returnDirector();
  int returnDurationH();
  int returnDurationM();
  int returnRating();

 protected:
  char director[30];
  int durationH;
  int durationM;
  int rating;
  int falseRating;
};

#endif
