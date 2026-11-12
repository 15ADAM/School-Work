#include <iostream>
#include <cstring>

using namespace std;

class media {
public:
  media();
  const char* getID();
  void getTitle();
  void getYear();
  const char* returnTitle();
  int returnYear();
  
protected:
  char title[30];
  int year;
  char id[10];
};
