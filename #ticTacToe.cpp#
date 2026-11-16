// Adam Bendersky, 10/02/2026, a tic tac toe game for 2 players(get 3 in a row to win!)
/*
1. No global variables. (Global constants are all right.)

2. No strings. Not ever. (You can use cstrings/character arrays, and the cstring and cctype libraries are okay. In fact, I reccoment using strcmp and strlen in your projects.)

3. You should include <iostream>, not stdio. (This applies more to C programmers.) Also, use "new" and "delete" instead of "malloc" and "free".
*/
#include <iostream>
#include <cstring>

using namespace std;

// setting up the functions
void printMap(char a1, char a2, char a3, char b1, char b2, char b3, char c1, char c2, char c3);
int convertMove(char move[3]);
void turnSwitch(char & turn);
bool checkForEnd(char map[10], bool & spaceLeft);

int main(){
  // setting up variables
  bool stilPlaying = true;
  char turn = 'X';
  char nextMove[3] = " ";
  char map[10] = "---------";
  bool spaceLeft = true;
  int scoreX = 0;
  int scoreO = 0;
  char keepPlaying = 'n';
  // the code that runs as long as we are playing
  while (stilPlaying){
    // prints an empty map and asks for a move
    printMap(map[0], map[1], map[2], map[3], map[4], map[5], map[6], map[7], map[8]);
    cout << "enter your move: " << endl;
    cin.get(nextMove, 3);
    cin.get();
    // checks if the move is legal and if so prints it on the map(else it will ask you again)
    if (convertMove(nextMove) <= 8 && map[convertMove(nextMove)] == '-'){
      map[convertMove(nextMove)] = turn;
      turnSwitch(turn);
    }
    else{
      cout << "Cannot do that move, try another one" << endl;
    }
    // checks if someone had won, and if so prints the new score
    if (checkForEnd(map, spaceLeft)){
      printMap(map[0], map[1], map[2], map[3], map[4], map[5], map[6], map[7], map[8]);
      cout << "Game Over" << endl;
      cout << "The New Score Is:" << endl;
      // checks for a tie & adds score to the winner
      if (spaceLeft == true){
	if (turn == 'X'){
	  scoreO++; }
	else if (turn == 'O'){
	  scoreX++; }
      }
      cout << "X: " << scoreX << endl << "O: " << scoreO << endl;
      // asks if the user want to play again
      cout << "want to play again(y/n)?" << endl;
      cin >> keepPlaying;
      cin.get();
      // if no, stop the game
      if (keepPlaying == 'n'){
	stilPlaying = false; }
      // if yes, reset some of the variables to reset the game
      else if (keepPlaying == 'y'){
	turn = 'X';
	strcpy(map, "---------");
	spaceLeft = true;
      }
    }
  }
}

// function that prints the map
void printMap(char a1, char a2, char a3, char b1, char b2, char b3, char c1, char c2, char c3){
  cout << "  1  2  3" << endl;
  cout << "a " << a1 << "  " << a2 << "  " << a3 << endl << endl;
  cout << "b " << b1 << "  " << b2 << "  " << b3 << endl << endl;
  cout << "c " << c1 << "  " << c2 << "  " << c3 << endl << endl;
}

// function that converts the move entered into a number
int convertMove(char move[3]){
  if (strcmp(move, "1a") == 0 || strcmp(move, "a1") == 0){
    return 0; }
  else if (strcmp(move, "2a") == 0 || strcmp(move, "a2") == 0){
    return 1; }
  else if (strcmp(move, "3a") == 0 || strcmp(move, "a3") == 0){
    return 2; }
  else if (strcmp(move, "1b") == 0 || strcmp(move, "b1") == 0){
    return 3; }
  else if (strcmp(move, "2b") == 0 || strcmp(move, "b2") == 0){
    return 4; }
  else if (strcmp(move, "3b") == 0 || strcmp(move, "b3") == 0){
    return 5; }
  else if (strcmp(move, "1c") == 0 || strcmp(move, "c1") == 0){
    return 6; }
  else if (strcmp(move, "2c") == 0 || strcmp(move, "c2") == 0){
    return 7; }
  else if (strcmp(move, "3c") == 0 || strcmp(move, "c3") == 0){
    return 8; }
  else{
    return 9; }
}

// function that switches the turn from X to O and O to X
void turnSwitch(char & turn){
  if (turn == 'X'){
    turn = 'O'; }
  else if (turn == 'O'){
    turn = 'X'; }
}

// function that checks if someone had won
bool checkForEnd(char map[10], bool & spaceLeft){
  int spaceCount = 0;
  for (int i = 0; i <= 9; i++){
    if (map[i] != '-'){
      // horizontal
      if (i + 2 <= 8 && i % 3 == 0 && map[i] == map[i+1] && map[i] == map[i+2]){
	return true; }
      // vertical
      else if (i + 6 <= 8 && map[i] == map[i+3] && map[i] == map[i+6]){
	return true; }
      // diagonal(left to right)
      else if (i == 0 && map[i] == map[i+4] && map[i] == map[i+8]){
	return true; }
      // diagonal(right to left)
      else if (i == 2 && map[i] == map[i+2] && map[i] == map[i+4]){
	return true; }
      // tie
      else if (i <= 8 && map[i] != '-'){
	spaceCount++;
	if (spaceCount == 9){
	  spaceLeft = false;
	  return true;
	}
      }
    }
  }
  return false;
}


