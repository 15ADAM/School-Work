#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

struct student{
  char firstName[15];
  char lastName[15];
  int id;
  float GPA;
};

void addStudent(vector<student*> &v);

int main(){
  bool running = true;
  vector<student*> students;
  char choice[10];
  while (running){
    cout << "Enter your next command: " << endl;
    cin.get(choice, 10);
    cin.get();
    if (strcmp(choice, "ADD") == 0){
      addStudent(students);
    }
    else if (strcmp(choice, "PRINT") == 0){
      for (const auto* s : students) {
      cout << s->firstName << " " << s->lastName << ", " << s->id << ", " << s->GPA << endl;
      }
    }
    else if (strcmp(choice, "QUIT") == 0){
      running = false;
    }
    else{
      cout << "error" << endl;
    }
  }
}

void addStudent(vector<student*> &v){
  char firstName[15];
  char lastName[15];
  int id;
  float GPA;
  student *s = new student();
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
  GPA = round(GPA * 100) / 100;
  strcpy(s -> firstName, firstName);
  strcpy(s -> lastName, lastName);
  s -> id = id;
  s -> GPA = GPA;
  v.push_back(s);
}
