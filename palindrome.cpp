// Adam Bendersky, 09/17/2026. A program that asks for a text and checks whether it is a palindrome or not
/*
1. No global variables. (Global constants are all right.)

2. No strings. Not ever. (You can use cstrings/character arrays, and the cstring and cctype libraries are okay. In fact, I recommend using strcmp and strlen in your projects.)

3. You should include <iostream>, not stdio. (This applies more to C programmers.) Also, use "new" and "delete" instead of "malloc" and "free".
*/
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main(){
  // setting up variables
  char allowedText[37] = "qwertyuiopasdfghjklzxcvbnm1234567890";
  char word[81] = "";
  char allowedWord[81] = "";
  char revWord[81] = "";
  int firstCount = 0;
  int finalCount = -1;
  // getting the word/sentence from the user
  cout << "print out a word: ";
  cin.get(word, 81);
  cin.get();
  // a program so the word will have only lowercase letters and numbers
  for (int i = 0; i <= 81; i++){
    word[i] = tolower(word[i]);
    for (int t = 0; t <= 37; t++){
      if (word[i] == allowedText[t] && word[i] != '\0'){
	allowedWord[firstCount] = word[i];
	firstCount++;
      }
    }
  }
  // reversing the word, and placing it into a new c string, while keeping the old one
  for (int i = 81; i >= 0; i--){
    if (allowedWord[i] != '\0'){
      revWord[finalCount] = allowedWord[i];
      finalCount++;
    }
  }
  // comparing the reversed and unreversed words, whether its a palindrome or not, prints it 
  if (strcmp(allowedWord, revWord) == 0){
    cout << "a palindrome" << endl;
  }
  else{
    cout << "not a palindrome" << endl;
  }
}
