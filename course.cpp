#include <iostream>
#include <list>
using namespace std;

class Course {

  public:
    string name;
    
    void addGrade(double grade) {
      this->grades.push_back(grade);
      cout << this->grades.size() << endl;
    }

    void total() {
      cout << "grade total" << endl;
      double total = 0;
      for (auto g : this->grades) {
        total += g;
	    }
      double avg = total / this->grades.size();
      cout << this->name << " - " << this->grades.size() << " exams - " << avg << " avg";
    }

  private:  
    std::list<double> grades;
};