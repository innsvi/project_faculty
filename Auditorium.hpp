#ifndef _AUDITORIUM_HPP_
#define _AUDITORIUM_HPP_
#include <string>

using namespace std;
// Class representing an Auditorium
class Auditorium {
public:
    string name;
    bool isForLabs;

    Auditorium(const string& name = "", bool isForLabs = false) : name(name), isForLabs(isForLabs) {}
};
#endif