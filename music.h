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
  void returnArtist();
  void returnDurationM();
  void returnDurationS();
  void returnPublisher();

 protected:
  char artist[30];
  int durationM;
  int durationS;
  char publisher;
};  
