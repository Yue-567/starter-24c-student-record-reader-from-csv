#include "solution.hpp"

Student ReadStudentRecFromStream(std::istream& is) {
  // your implementation here...
  std::string first_name, last_name;
  unsigned int uin = 0;
  double gpa = 0.0;
  char comma1 = '\0', comma2 = '\0';
  if (!(is >> first_name >> last_name)) {
    return Student{};
  }
  if (last_name.empty() || last_name.back() != ',') {
    return Student{};
  }
  last_name.pop_back();
  if (!(is >> uin)) {
    return Student{};
  }
  if (!(is >> comma1) || comma1 != ',') {
    return Student{};
  }
  if (!(is >> gpa)) {
    return Student{};
  }
  Student s;
  s.full_name = first_name + " " + last_name;
  s.uin = uin;
  s.gpa = gpa;
  return s;
}