#include "App.h"
#include "Object.h"
#include <iostream>
#include <string>

using namespace std;

App::App(Base* head) : Base(head, "root") {
    this->head = head;
    root = this;
}

void App::build_tree() {
    string name, nameP, nameC;
    cin >> name;
    this->set_name(name);
    Base* parent = this;
    Base* child = this;
    cin >> nameP >> nameC;
    while (nameP != nameC) {
        if (nameP != parent->get_name()) {
            parent = child;
        }
        child = new Object(parent, nameC);
        cin >> nameP >> nameC;
    }
}

int App::start_app() {
    this->display();
    return 0;
}