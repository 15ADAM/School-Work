/*
the .h file for the media parent class, it has a title, year, and id which all the child classes will have 

the child classes will have similar structure, just with different variables
*/
#ifndef MEDIA
#define MEDIA
#include <iostream>
#include <cstring>

using namespace std;

class media {
public:
  media();
  virtual ~media();
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
