#ifndef MEDIA
#define MEDIA
#include <iostream>
#include <cstring>

using namespace std;

class media {
public:
  media();
  char* getID();
  void getTitle();
  void getYear();
  char* returnTitle();
  int returnYear();
  
protected:
  char title[30];
  int year;
  char id[10];
};

#endif
