#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct student{
  char firstName[15];
  char lastName[15];
  int id;
  float GPA;
};

void addStudent(vector<student*> &students);

int main(){
  addStudent(vector<sudent*> &students = {"adam", "bendersky", 523149, 5.2});  
}

void addStudent(vector<student*> &v){
  student *s = new Student()
}
