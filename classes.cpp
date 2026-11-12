#include <iostream>
#include <vector>
#include <cstring>
#include "media.h"//delete
#include "videoGames.h"

using namespace std;

int main(){
//янт
  videoGames* g = new videoGames();
  cout << "print a title:" << endl;
  g->getTitle();
  cout << g->returnTitle() << endl;
  cout << endl;
  if(strcmp(g->getID(), "VIDEOGAME") == 0){
    cout << "print a year:" << endl;
    g->getYear();
    cout << g->returnYear() << endl;
    cout << "print a rating";
    g->getRating();
    cout << g->returnRating() << endl;
  }
}
