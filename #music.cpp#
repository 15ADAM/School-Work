#include <iostream>
#include <cstring>
#include "music.h"

using namespace std;

music::music(){
  strcpy(id, "MUSIC");
}

void music::getArtist(){
  cin.get(artist, 30);
  cin.get();
}

void music::getDurationM(){
  cin >> durationM;
  cin.ignore();
}

void music::getDurationS(){
  cin >> durationS;
  cin.ignore();
}

void music::getPublisher(){
  cin.get(publisher, 30);
  cin.get();
}

char* music::returnArtist(){
  return artist;
}

int music::returnDurationM(){
  return durationM;
}

int music::returnDurationS(){
  return durationS;
}

char* music::returnPublisher(){
  return publisher;
}
