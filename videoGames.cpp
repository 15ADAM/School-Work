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
  cin >> rating;
  cin.ignore();
}

const char* videoGames::returnPublisher(){
  return publisher;
}

int videoGames::returnRating(){
  return rating;
}
