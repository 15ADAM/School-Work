/*
the .cpp file for the media parent class. It has all the functions that allows the user add variables for the class by entering them, functions that just returns the variables, and a function that sets the id of the class.

This implies for all the child classes. they just have different variables(some child classes will have rating which in the get function will not allow you add a number above 10)
*/
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

media::media(){
  strcpy(id, "MEDIA");
}

media::~media(){}

char* media::getID(){
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

char* media::returnTitle(){
  return title;
}

int media::returnYear(){
  return year;
}


