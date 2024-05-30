#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "Course.hpp"
#include "Teacher.hpp"
#include "Group.hpp"
#include "Auditorium.hpp"
#include "Specialty.hpp"
#include "Timetable.hpp"
#include "Faculty.hpp"


using namespace std;

int main() {
    // Creating teachers
    Teacher teacher1("Dr. Smith");
    Teacher teacher2("Prof. Johnson");

    // Creating the faculty
    Faculty faculty("Engineering");

    // Creating specialties
    Specialty cs("Computer Science");
    Specialty ee("Electrical Engineering");

    // Adding courses to specialties with teachers
    cs.addCourse(Course("Data Structures", true, teacher1));
    cs.addCourse(Course("Operating Systems Lab", false, teacher2));
    ee.addCourse(Course("Circuit Analysis", true, teacher1));
    ee.addCourse(Course("Circuit Lab", false, teacher2));

    // Adding groups to specialties
    cs.addGroup(Group("CS1"));
    cs.addGroup(Group("CS2"));
    ee.addGroup(Group("EE1"));
    ee.addGroup(Group("EE2"));

    // Adding specialties to faculty
    faculty.addSpecialty(cs);
    faculty.addSpecialty(ee);

    // Creating auditoriums
    Auditorium lecHall1("Lecture Hall 1", false);
    Auditorium labRoom1("Lab Room 1", true);

    // Adding auditoriums to faculty
    faculty.addAuditorium(lecHall1);
    faculty.addAuditorium(labRoom1);

    // Adding entries to the timetable
    faculty.timetable.addEntry("Monday", 9, cs.courses[0], lecHall1);
    faculty.timetable.addEntry("Monday", 11, cs.courses[1], labRoom1);
    faculty.timetable.addEntry("Tuesday", 10, ee.courses[0], lecHall1);
    faculty.timetable.addEntry("Tuesday", 12, ee.courses[1], labRoom1);

    // Printing the timetable
    faculty.timetable.print();

    while(true) {
        cout << "Do you want to add another entry? (y/n): ";
        char choice;

        cin >> choice;

        if(choice == 'n') {
            break;
        }

        int day;
        int hour;
        int specialty;
        int course;
        bool isLecture;
        int teacher;
        int auditorium;

        cout << "Enter the day\n";
        cout << "Monday[1], Tuesday[2], Wednesday[3], Thursday[4], Friday[5]:";
        cin >> day;
        if (day < 1 || day > 5) {
            cout << "Invalid day!" << endl;
            continue;
        }

        cout << "Enter the hour: ";
        cin >> hour;
        if (hour < 8 || hour > 18) {
            cout << "Invalid hour!" << endl;
            continue;
        }

        cout << "Enter the specialty\n";
        cout << "Computer Science[1], Electrical Engineering[2]: ";
        cin >> specialty;
        if (specialty != 1 && specialty != 2) {
            cout << "Invalid specialty!" << endl;
            continue;
        }

        cout << "Enter the course from the specialty\n";
        cout << "Data Structures[1], Operating Systems Lab[2], Circuit Analysis[3], Circuit Lab[4]: ";
        cin >> course;

        if (specialty == 1 && (course < 1 || course > 2)) {
            cout << "Invalid course!" << endl;
            continue;
        } else if (specialty == 2 && (course < 3 || course > 4)) {
            cout << "Invalid course!" << endl;
            continue;
        }

        cout << "Is it a lecture? (y/n): ";
        char isLectureChar;
        cin >> isLectureChar;
        if (isLectureChar == 'y') {
            isLecture = true;
        } else if (isLectureChar == 'n') {
            isLecture = false;
        } else {
            cout << "Invalid choice!" << endl;
            continue;
        }

        cout << "Select the teacher\n";
        cout << "Dr. Smith[1], Prof. Johnson[2]: ";
        cin >> teacher;

        if (teacher != 1 && teacher != 2) {
            cout << "Invalid teacher!" << endl;
            continue;
        }

        cout << "Enter the auditorium\n";
        cout << "Lecture Hall 1[1], Lab Room 1[2]: ";
        cin >> auditorium;

        if (auditorium != 1 && auditorium != 2) {
            cout << "Invalid auditorium!" << endl;
            continue;
        }

        if (isLecture && auditorium == 2) {
            cout << "Invalid auditorium for a lecture!" << endl;
            continue;
        }

        Specialty& selectedSpecialty = faculty.specialties[specialty - 1];
        Course& selectedCourse = selectedSpecialty.courses[course - 1];
        Teacher& selectedTeacher = teacher1;
        if (teacher == 2) {
            selectedTeacher = teacher2;
        }
        Auditorium& selectedAuditorium = faculty.auditoriums[auditorium - 1];
        string dayStr;
        switch (day) {
            case 1:
                dayStr = "Monday";
                break;
            case 2:
                dayStr = "Tuesday";
                break;
            case 3:
                dayStr = "Wednesday";
                break;
            case 4:
                dayStr = "Thursday";
                break;
            case 5:
                dayStr = "Friday";
                break;
        }
        faculty.timetable.addEntry(dayStr, hour, selectedCourse, selectedAuditorium);

        cout << "Entry added!" << endl;
    }

    faculty.timetable.print();

    cout << "Goodbye!" << endl;

    return 0;
}
