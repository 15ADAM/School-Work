#ifndef MUSIC
#define MUSIC
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class music : public media{
 public:
  music();
  void getArtist();
  void getDurationM();
  void getDurationS();
  void getPublisher();
  char* returnArtist();
  int returnDurationM();
  int returnDurationS();
  char* returnPublisher();

 protected:
  char artist[30];
  int durationM;
  int durationS;
  char publisher[30];
};  

#endif
