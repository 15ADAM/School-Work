#include <iostream>
#include <vector>
#include <cstring>
#include "media.h"
#include "videoGames.h"
#include "music.h"
#include "movies.h"

using namespace std;

void addMedia(vector<media*> &v);
void searchAndDel(vector<media*> &v);

int main(){
//янт
  vector<media*> allMedia;
  bool running = true;
  char choice[15];

  while (running){
    cout << "Enter a command(ADD, SEARCH&DEL, QUIT): " << endl; 
    cin.get(choice, 15);
    cin.get();
    cout << endl;
    if (strcmp(choice, "ADD") == 0){
      addMedia(allMedia);
    }
    else if (strcmp(choice, "SEARCH&DEL") == 0){
      searchAndDel(allMedia);
    }
    else if (strcmp(choice, "QUIT") == 0){
      running = false;
    }
  }
}

void addMedia(vector<media*> &v){
  char choice[15];
  media* c;
  cout << "What type of media do you want to add?(video game, music, movie)" << endl;
  cin.get(choice, 15);
  cin.get();
  cout << endl;
  while (strcmp(choice, "video game") != 0 && strcmp(choice, "music") != 0 && strcmp(choice, "movie") != 0){
    cout << "There is no such type of media. Try again(video game, music, movie)" << endl;
    cin.get(choice, 15);
    cin.get();
    cout << endl;
  }
  if (strcmp(choice, "video game") == 0){
    videoGames* m = new videoGames();
    cout << "Enter the publisher of the game:" << endl;
    m->getPublisher();
    cout << endl;
    cout << "Enter the rating of the game(out of 10): " << endl;
    m->getRating();
    cout << endl;
    c = m;
  }
  else if (strcmp(choice, "music") == 0){
    music* m = new music();
    cout << "Enter the artist of the song:" << endl;
    m->getArtist();
    cout << endl;
    cout << "Enter the duration of the song(minutes):" << endl;
    m->getDurationM();
    cout << endl;
    cout << "Enter the duration of the song(seconds):" << endl;
    m->getDurationS();
    cout << endl;
    cout << "Enter the publisher of the song:" << endl;
    m->getPublisher();
    cout << endl;
    c = m;
  }
  else if (strcmp(choice, "movie") == 0){
    movies* m = new movies();
    cout << "Enter the director of the movie:" << endl;
    m->getDirector();
    cout << endl;
    cout << "Enter the duration of the movie(hours):" << endl;
    m->getDurationH();
    cout << endl;
    cout << "Enter the duration of the movie(minutes):" << endl;
    m->getDurationM();
    cout << endl;
    cout << "Enter the rating of the movie(out of 10):" << endl;
    m->getRating();
    cout << endl;
    c = m;
  }
  cout << "Enter it's title: " << endl;
  c->getTitle();
  cout << endl;
  cout << "Enter the year of which it was published: " << endl;
  c->getYear();
  cout << endl;
  v.push_back(c);
  cout << "Your digital media was succesfully added!" << endl;
  cout << endl;
}

void searchAndDel(vector<media*> &v){
  char choice[10];
  int year;
  char title[30];
  char delOption[10];
  vector<media*> toDelete;
  cout << "Do you want to search by title or year?" << endl;
  cin.get(choice, 10);
  cin.get();
  cout << endl;
  while (strcmp(choice, "year") != 0 && strcmp(choice, "title") != 0){
    cout << "Invalid command. try again(title, year):" << endl;
    cin.get(choice, 10);
    cin.get();
  }
  if(strcmp(choice, "year") == 0){
    cout << "Enter a year:" << endl;
    cin >> year;
    cin.ignore();
    cout << endl;
  }
  else if (strcmp(choice, "title") == 0){
    cout << "Enter a title:" << endl;
    cin.get(title, 30);
    cin.get();
    cout << endl;
  }
  for (media* m : v){
    if (m->returnYear() == year || strcmp(m->returnTitle(), title) == 0){
      toDelete.push_back(m);
      if (strcmp(m->getID(), "VIDEOGAME") == 0){
	videoGames* c = static_cast<videoGames*>(m);
	cout << "Title: " << c->returnTitle() << " Year published: "
	     << c->returnYear() << " Publisher: " << c->returnPublisher()
	     << " Rating: " << c->returnRating() << "/10" << endl;
      }
      else if (strcmp(m->getID(), "MUSIC") == 0){
	music* c = static_cast<music*>(m);
	cout << "Title: " << c->returnTitle() << " Year published: " << c->returnYear()
	     << " Artist: " << c->returnArtist() << " Duration: " << c->returnDurationM()
	     << " minutes, and " << c->returnDurationS() << " seconds " << "Publisher: " << c->returnPublisher() << endl;
      }
      else if (strcmp(m->getID(), "MOVIES") == 0){
	movies* c = static_cast<movies*>(m);
	cout << "Title: " << c->returnTitle() << " Year published: " << c->returnYear()
	     << " Director: " << c->returnDirector() << " Duration: " << c->returnDurationH()
	     << " hours, and " << c->returnDurationM() << " minutes " << "Rating: " << c->returnRating() << "/10" << endl;
      }
    }
  }
  cout << endl;
  cout << "Do you want to delete those files?(yes, no):" << endl;
  cin.get(delOption, 10);
  cin.get();
  cout << endl;
  while (strcmp(delOption, "yes") != 0 && strcmp(delOption, "no") != 0){
    cout << "Invalid command, try again(yes, no):" << endl;
    cin.get();
    cout << endl;
  }
  if (strcmp(delOption, "yes") == 0){
    for (media* d : toDelete) {
      for (auto it = v.begin(); it != v.end(); it++) {
	if (d->returnYear() == (*it)->returnYear() && d->returnTitle() == (*it)->returnTitle()) {
	  cout << "Nice!" << endl;
	  delete *it;
	  it = v.erase(it);
	}
      }
    }
  }
}
