// Adam Bendersky, 10/15/2026, a program that lets you make a list of students, adding, deleting, and printing them
/*
1. No global variables. (Global constants are all right.)

2. No strings. Not ever. (You can use cstrings/character arrays, and the cstring and cctype libraries are okay. In fact, I reccoment using strcmp and strlen in your projects.)

3. You should include <iostream>, not stdio. (This applies more to C programmers.) Also, use "new" and "delete" instead of "malloc" and "free".
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

//adding struct
struct student{
  char firstName[15];
  char lastName[15];
  int id;
  float GPA;
};

//setting up the functions
void addStudent(vector<student*> &v);
void deleteStudent(vector<student*> &v);

//main function
int main(){
  //setting up variables
  bool running = true;
  vector<student*> students;
  char choice[10];
  //the while loop that runs until the code finishes
  while (running){
    //asking for command (ADD, PRINT, ect.)
    cout << "Enter your next command: " << endl;
    cin.get(choice, 10);
    cin.get();
    //if "ADD", add student
    if (strcmp(choice, "ADD") == 0){
      addStudent(students);
    }
    //if "PRINT", print all the students with all their info
    else if (strcmp(choice, "PRINT") == 0){
      for (student* s : students) {
      cout << s->firstName << " " << s->lastName << ", " << s->id << ", " << s->GPA << endl;
      }
    }
    //if "QUIT", stop the code
    else if (strcmp(choice, "QUIT") == 0){
      running = false;
    }
    //if "DELETE" delete a student
    else if (strcmp(choice, "DELETE") == 0){
      deleteStudent(students);
    }
    //if something else, print that it is a not valid command
    else{
      cout << "The command is not valid" << endl;
    }
  }
}

//the function for adding students
void addStudent(vector<student*> &v){
  //setting up variables
  char firstName[15];
  char lastName[15];
  int id;
  float GPA;
  student *s = new student();
  //asking for the info of the student
  cout << "Enter first name: ";
  cin.get(firstName, 15);
  cin.get();
  cout << "Enter last name: ";
  cin.get(lastName, 15);
  cin.get();
  cout << "Enter ID: ";
  cin >> id;
  cout << "Enter GPA: ";
  cin >> GPA;
  cin.ignore();
  //rounding the GPA
  GPA = round(GPA * 100) / 100;
  //copying the variables into a struct
  strcpy(s -> firstName, firstName);
  strcpy(s -> lastName, lastName);
  s -> id = id;
  s -> GPA = GPA;
  //entering the struct to the vector
  v.push_back(s);
  cout << "The student was succesfully added" << endl;
}

//function for deleting student
void deleteStudent(vector<student*> &v) {
  //setting up variables
  int deleteID;
  //asking the user for the ID of the student they want to delete
  cout << "Enter the ID of the student you want to delete:" << endl;
  cin >> deleteID;
  cin.ignore();
  //serching for the student with that ID and deleting them from the main vector
  for (auto it = v.begin(); it != v.end(); it++){
    if ((*it)->id == deleteID){
      delete(*it);
      v.erase(it);
      cout << "student has been deleted" << endl;
      return;
    }
  }
  cout << "No student with that ID was found" << endl;
}
