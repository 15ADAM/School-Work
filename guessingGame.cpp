/*
  (09/02/2026), Adam Bendersky, This is a guessing game where a rundom number is selected by the program,
  and the user need to guess it with as little guesses as possible
*/
/*
  1. No global Variables.
  2. No strings. Not ever.
  3. You should include <iostream>, not stdio. Also, use "new" and "delete" instead of "malloc" and "free".
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//The function that represents the game
int Game()
{
  //setting up variables including the random number
  srand(time(NULL));
  int num = (rand() % 101);
  int enterNum = 101;
  int guesses = 0;
  //the game starts and asks you to take a guess of the random number until you guess it correctly
  cout << "Enter a number: ";
  while (enterNum != num){
    cin >> enterNum;
    //every time you take a guess adding 1 to the count of guesses taken
    guesses++;
    //if the number is too low/high, says that
    if (enterNum > num){
      cout << "wrong, try a lower number: ";
    }
    else if (enterNum < num){
      cout << "wrong, try a higher number: ";
    }
  }
  //ends the game when guessing correctly and prints the number of guesses
  cout << "You Guessed The Number!" << endl;
  cout << "You had " << guesses << " guesses!" << endl;
  return 0;
}

//the main function that runs the game
int main()
{
  //setting u pvariables
  bool stillPlaying = true;
  char wannaPlay = 'n';
  //starting the gave
  Game();
  //asking if the player want to play again, if so, play the game again, if not, end the program
  while (stillPlaying || wannaPlay != 'n' && wannaPlay != 'y'){
    cout << "want to keep playing?(y/n)" << endl;
    cin >> wannaPlay;
    if (wannaPlay == 'y'){
      Game();
    }
    else if (wannaPlay == 'n'){
      stillPlaying = false;
    }
  }
}
