#include <iostream>
#include <vector>
#include <cstring>
#include "media.h"

using namespace std;

int main(){
//янт
  media* g = new media();
  cout << "print a title:" << endl;
  g->getTitle();
  g->printTitle();
  cout << endl;
  if(strcmp(g->getID(), "MEDIA") == 0){
    cout << "print a year:" << endl;
    g->getYear();
    g->printYear();
  }
}
