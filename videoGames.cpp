#include <iostream>
#include <cstring>
#include "videoGames.h"

using namespace std;

videoGames::videoGames(){
  strcpy(id, "VIDEOGAME");
}

void videoGames::getPublisher(){
  cin.get(publisher, 30);
  cin.get();
}

void videoGames::getRating(){
  cin >> falseRating;
  cin.ignore();
  while(falseRating > 10 || falseRating < 0){
    cout << "invalid rating. Enter a number between 0 and 10: " << endl;
    cin >> falseRating;
    cin.ignore();
  }
  rating = falseRating;
}

char* videoGames::returnPublisher(){
  return publisher;
}

int videoGames::returnRating(){
  return rating;
}
