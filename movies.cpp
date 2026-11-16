#include <iostream>
#include <cstring>
#include "movies.h"

movies::movies(){
  strcpy(id, "MOVIES");
}

void movies::getDirector(){
  cin.get(director, 30);
  cin.get();
}

void movies::getDurationH(){
  cin >> durationH;
  cin.ignore();
}

void movies::getDurationM(){
  cin >> durationM;
  cin.ignore();
}

void movies::getRating(){
  cin >> falseRating;
  cin.ignore();
  while(falseRating > 10 || falseRating < 0){
    cout << "invalid rating. Enter a number between 0 and 10: " << endl;
    cin >> falseRating;
    cin.ignore();
  }
  rating = falseRating;
}

char* movies::returnDirector(){
  return director;
}

int movies::returnDurationH(){
  return durationH;
}

int movies::returnDurationM(){
  return durationM;
}

int movies::returnRating(){
  return rating;
}
