#ifndef _FACULTY_HPP_
#define _FACULTY_HPP_

#include <string>
#include <vector>
#include "Specialty.hpp"
#include "Auditorium.hpp"
#include "Timetable.hpp"

using namespace std;

// Class representing a Faculty
class Faculty {
public:
    string name;
    vector<Specialty> specialties;
    vector<Auditorium> auditoriums;
    Timetable timetable;

    Faculty(const string& name = "") : name(name) {}

    void addSpecialty(const Specialty& specialty) {
        specialties.push_back(specialty);
    }

    void addAuditorium(const Auditorium& auditorium) {
        auditoriums.push_back(auditorium);
    }
};

#endif