#ifndef _COURSE_HPP_
#define _COURSE_HPP_
#include <string>
#include "Teacher.hpp"

using namespace std;
// Class representing a Course
class Course {
public:
    string name;
    bool isLecture;
    Teacher teacher;

    Course(const string& name = "", bool isLecture = false, const Teacher& teacher = Teacher())
        : name(name), isLecture(isLecture), teacher(teacher) {}
};

#endif