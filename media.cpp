#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

media::media(){
  strcpy(id, "MEDIA");
}

const char* media::getID(){
  return id;
}

void media::getTitle(){
  cin.get(title, 30);
  cin.get();
}

void media::getYear(){
  cin >> year;
  cin.ignore();
}

void media::printTitle(){
  cout << title;
}

void media::printYear(){
  cout << year;
}


