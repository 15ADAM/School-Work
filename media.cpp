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

const char* media::returnTitle(){
  return title;
}

int media::returnYear(){
  return year;
}


