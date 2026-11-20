/*A program that allows you to create a vector of classes that are different media types(video games/music/movies), you can add items, search for them by the year they were published or their title, and delete them*/

/*
1. No global variables. (Global constants are all right.)

2. No strings. Not ever. (You can use cstrings/character arrays, and the cstring and cctype libraries are okay. In fact, I reccoment 
using strcmp and strlen in your projects.)

3. You should include <iostream>, not stdio. (This applies more to C programmers.) Also, use "new" and "delete" instead of "malloc" a
nd "free".
*/

//all the libraries
#include <iostream>
#include <vector>
#include <cstring>
#include "media.h"
#include "videoGames.h"
#include "music.h"
#include "movies.h"

using namespace std;

//all the functions
void addMedia(vector<media*> &v);
void searchAndDel(vector<media*> &v);

//main code
void addMedia(vector<media*> &v);
void searchAndDel(vector<media*> &v);

int main(){
//янт
  //all the variables
  vector<media*> allMedia;
  bool running = true;
  char choice[15];

  //infinite while loop so you can enter commands as much as you want
  while (running){
    //asking the user for a command
    cout << "Enter a command(ADD, SEARCH&DEL, QUIT): " << endl; 
    cin.get(choice, 15);
    cin.get();
    cout << endl;
    //if "ADD", then run the addMedia function
    if (strcmp(choice, "ADD") == 0){
      addMedia(allMedia);
    }
    //if "SEARCH&DEL", then run the searchAndDel function
    else if (strcmp(choice, "SEARCH&DEL") == 0){
      searchAndDel(allMedia);
    }
    //if "QUIT", then stop the while loop
    else if (strcmp(choice, "QUIT") == 0){
      running = false;
    }
  }
}

//the function to add items for the main vector of classes
void addMedia(vector<media*> &v){
  //variables
  char choice[15];
  media* c;
  //ask the user what type of media they want to add 
  cout << "What type of media do you want to add?(video game, music, movie)" << endl;
  cin.get(choice, 15);
  cin.get();
  cout << endl;
  //if something is wrong, then ask the user again
  while (strcmp(choice, "video game") != 0 && strcmp(choice, "music") != 0 && strcmp(choice, "movie") != 0){
    cout << "There is no such type of media. Try again(video game, music, movie)" << endl;
    cin.get(choice, 15);
    cin.get();
    cout << endl;
  }
  //for each type, ask the user for the information of the class
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
  //for everyone ask for title and year
  cout << "Enter it's title: " << endl;
  c->getTitle();
  cout << endl;
  cout << "Enter the year of which it was published: " << endl;
  c->getYear();
  cout << endl;

  //add the class created to the main vector
  v.push_back(c);
  cout << "Your digital media was succesfully added!" << endl;
  cout << endl;
}

//function for searching and deleting objects from the main vector
void searchAndDel(vector<media*> &v){
  //variables
  char choice[10];
  int year;
  char title[30];
  char delOption[10];
  vector<media*> toDelete;
  //ask the user if he wants to search by the title of year
  cout << "Do you want to search by title or year?" << endl;
  cin.get(choice, 10);
  cin.get();
  cout << endl;
  //if something wrong, ask the user again
  while (strcmp(choice, "year") != 0 && strcmp(choice, "title") != 0){
    cout << "Invalid command. try again(title, year):" << endl;
    cin.get(choice, 10);
    cin.get();
  }
  //depending on what the user entered, ask it from them
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
  //for loop that goes through the main vector
  for (media* m : v){
    //if the item has the same year or title depends on what the user entered earlier, add it to a vector
    if (m->returnYear() == year || strcmp(m->returnTitle(), title) == 0){
      toDelete.push_back(m);
      //print the item with all the info if has the same year or title as the user entered
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
  //if nothing was found, say that
  if (toDelete.size() == 0) {
    cout << "No items were found, try again" << endl;
    cout << endl;
  }
  //if something was found, ask the user if he wants to delete that
  else {
    cout << "Do you want to delete those files?(yes, no):" << endl;
    cin.get(delOption, 10);
    cin.get();
    cout << endl;
    //if something wrong, ask again
    while (strcmp(delOption, "yes") != 0 && strcmp(delOption, "no") != 0){
      cout << "Invalid command, try again(yes, no):" << endl;
      cin.get();
      cout << endl;
    }
    //if yes, search for similarities in the created vector and the main vector, if something has been found, delete it
    if (strcmp(delOption, "yes") == 0){
      for (media* d : toDelete) {
	for (auto it = v.begin(); it != v.end();) {
	  if (d->returnYear() == (*it)->returnYear() && d->returnTitle() == (*it)->returnTitle()) {
	    cout << "Nice!" << endl;
	    delete *it;
	    it = v.erase(it);
	  }
	  else{
	    it++;
	  }
	}
      }
    }
    //say the user that everything went good
    cout << "Deleted all the files successfully!" << endl;
    cout << endl;
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
  cout << "Do you want to search by title or year?" << endl;
  cin.get(choice, 10);
  cin.get();
  cout << endl;
  while (strcmp(choice, "year") != 0 && strcmp(choice, "title") != 0){
    cout << "Invalid command. try again(title, year):" << endl;
    cin.get(choice, 10);
    cin.get();
  }
  for (media* m : v){
    if (strcmp(m->getID(), "VIDEOGAME") == 0){
      videoGames* c = static_cast<videoGames*>(m);
      cout << "Title: " << c->returnTitle() << " Year published: " << c->returnYear() << " Publisher: " << c->returnPublisher() << " Rating: " << c->returnRating() << "/10" << endl; 
    }
    else if (strcmp(m->getID(), "MUSIC") == 0){
      music* c = static_cast<music*>(m);
      cout << "Title: " << c->returnTitle() << " Year published: " << c->returnYear() << " Artist: " << c->returnArtist() << " Duration: " << c->returnDurationM() << " minutes, and " << c->returnDurationS() << " seconds " << "Publisher: " << c->returnPublisher() << endl;
    }
    else if (strcmp(m->getID(), "MOVIES") == 0){
      movies* c = static_cast<movies*>(m);
      cout << "Title: " << c->returnTitle() << " Year published: " << c->returnYear() << " Director: " << c->returnDirector() << " Duration: " << c->returnDurationH() << " hours, and " << c->returnDurationM() << " minutes " << "Rating: " << c->returnRating() << "/10" << endl;
    }
  }    
}
