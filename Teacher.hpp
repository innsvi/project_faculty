#ifndef _TEACHER_HPP_
#define _TEACHER_HPP_
#include <string>

using namespace std;
// Class representing a Teacher
class Teacher {
public:
    string name;

    Teacher(const string& name = "") : name(name) {}
};

#endif