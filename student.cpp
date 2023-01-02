#include <iostream>
#include "course.cpp"

class Student {
  public:
    string name;

    void addCourse(string name) {
      Course newCourse;
      newCourse.name = name;
      this->courses.push_back(newCourse);
    }

    Course getCourse(string name) {
     for (auto c : this->courses) {
        if (c.name == name) {
          return c;
        }
      }
      this->addCourse(name);      
      return this->getCourse(name);
    }

    void totals() {
      cout << "Grades for " << this->name << endl;
      for (auto c : this->courses) {
        c.total();
      }    
      list<Course>::iterator itSet;  
      for (itSet = this->courses.begin(); itSet != this->courses.end(); itSet++) {
        itSet->total();
      }      
      cout << "Done" << endl;
    }

  private:  
    std::list<Course> courses;
};