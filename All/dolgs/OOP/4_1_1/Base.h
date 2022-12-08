#ifndef BASE_H
#define BASE_H

#include <string>
#include <vector>

using namespace std;

class Base
{
protected:
    string name;
    Base* head;
    Base* root;
    vector <Base*> arrayPtr;
public:
    Base(Base*, string);
    void set_name(string);
    string get_name();
    void display();
    void set_head(Base*);
    Base* get_headPtr();
};

#endif
