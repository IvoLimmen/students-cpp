#include <iostream>
#include <sstream>
#include <vector>
#include "student.cpp"

void help() {
  cout << "Grading system" << endl;
  cout <<  "add-student [name] - Add student" << endl;
  cout <<  "select-student [name] - Select a student" << endl;
  cout <<  "add-grade [course] [grade] - Add a grade for a course for the current selected student" << endl;
  cout <<  "end - Stop the program" << endl;
}

std::vector<std::string> split(std::string &text, char sep) {
  std::vector<std::string> tokens;
  std::size_t start = 0, end = 0;
  while ((end = text.find(sep, start)) != std::string::npos) {
    tokens.push_back(text.substr(start, end - start));    
    start = end + 1;
  }
  tokens.push_back(text.substr(start));
  return tokens;
}

int main() {

  std::list<Student> students;
  Student *student;
  string command;

  while (command != "end") {
    getline(cin, command);

    if (command == "help") {
      help();
    }

    if (command.find("add-student") != std::string::npos) {     
      std::vector<std::string> args = split(command, ' ');
      Student newStudent;
      newStudent.name = args[1];
      students.push_back(newStudent);
      student = &newStudent;
    }
    if (command.find("select-student") != std::string::npos) {     
      std::vector<std::string> args = split(command, ' ');
      for (auto s : students) {
        if (s.name == args[1]) {
          student = &s;
        }
      }
      cout << student->name << " selected" << endl;
    }
    if (command.find("add-grade") != std::string::npos) {      
      std::vector<std::string> args = split(command, ' ');
      Course c = student->getCourse(args[1]);
      cout << c.name << " selected" << endl;
      c.addGrade(stod(args[2]));
    }
  }

  for (auto s : students) {
    s.totals();
  }      

  return 0;
} 