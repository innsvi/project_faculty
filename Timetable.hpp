#ifndef _TIMETABLE_HPP_
#define _TIMETABLE_HPP_

#include <string>
#include <map>
#include <iostream>
#include "Course.hpp"
#include "Auditorium.hpp"

using namespace std;

// Class representing a Timetable
class Timetable {
public:
    map<string, map<int, pair<Course, Auditorium> > > schedule; // Day -> (Hour -> (Course, Auditorium))

    void addEntry(const string& day, int hour, const Course& course, const Auditorium& auditorium) {
        schedule[day][hour] = make_pair(course, auditorium);
    }

    void print() {
        for (const auto& day : schedule) {
            cout << "Day: " << day.first << endl;
            for (const auto& entry : day.second) {
                cout << "  Hour: " << entry.first 
                          << " - Course: " << entry.second.first.name 
                          << " (Lecture: " << (entry.second.first.isLecture ? "Yes" : "No") 
                          << "), Teacher: " << entry.second.first.teacher.name
                          << ", Auditorium: " << entry.second.second.name << endl;
            }
        }
    }
};

#endif