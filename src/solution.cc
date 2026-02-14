#include "solution.hpp"
#include <string>

Student ReadStudentRecFromStream(std::istream& is) {
  // your implementation here...
  std::string first_name, last_name;
  is >> first_name;
  if (is.fail()) {
    return Student{};
  }
  is >> last_name;
  if (is.fail()) {
    return Student{};
  }
  if (last_name.empty() || last_name.back() != ',') {
    return Student{};
  }
  last_name.pop_back();
  }
  unsigned int uin = 0;
  is >> uin;
  if (is.fail()) {
    return Student{};
  }
  double gpa = 0.0;
  is >> gpa;
  if (is.fail()) {
    return Student{};
  }
  char comma = '\0';
  is >> comma;
  if (is.fail() || comma != ',') {
    return Student{};
  }
  Student s;
  s.full_name = first_name + " " + last_name;
  s.uin = uin;
  s.gpa = gpa;
  return s;
}