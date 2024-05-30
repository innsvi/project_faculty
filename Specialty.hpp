#ifndef _SPECIALTY_HPP_
#define _SPECIALTY_HPP_

#include <string>
#include <vector>
#include "Course.hpp"
#include "Group.hpp"

using namespace std;
// Class representing a Specialty
class Specialty {
public:
    string name;
    vector<Course> courses;
    vector<Group> groups;

    Specialty(const string& name = "") : name(name) {}

    void addCourse(const Course& course) {
        courses.push_back(course);
    }

    void addGroup(const Group& group) {
        groups.push_back(group);
    }
};

#endif