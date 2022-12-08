#include "Base.h"
#include <iostream>
#include <algorithm>

using namespace std;

Base::Base(Base* head, string name)
{
    this->head = head;
    this->name = name;
    if (this->head != nullptr) {
        this->head->arrayPtr.emplace(this->head->arrayPtr.end(), this);
    }
}

void Base::set_name(string name) {
    this->name = name;
}

string Base::get_name() {
    return this->name;
}

void Base::set_head(Base* newHead) {
    if (this->head != nullptr) {
        this->head->arrayPtr.erase(find(this->head->arrayPtr.begin(), this->head->arrayPtr.end(), this));
    }
    if (newHead != nullptr) {
        newHead->arrayPtr.push_back(this);
        this->head = newHead;
    }
}

Base* Base::get_headPtr() {
    return this->head;
}

void Base::display() {
    int i;
    Base* now = root;
    cout << now->get_name();
    if (now->arrayPtr.size() != 0) cout << endl;
    while (now->arrayPtr.size() != 0) {
        cout << now->name;
        for (i = 0; i < now->arrayPtr.size(); i++) {
            cout << "  " << now->arrayPtr[i]->get_name();
        }
        now = now->arrayPtr[now->arrayPtr.size() - 1];
        if (now->arrayPtr.size() != 0) {
            cout << endl;
        }
    }
}