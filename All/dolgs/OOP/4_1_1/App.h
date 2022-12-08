#ifndef APP_H
#define APP_H
#include "Base.h"

class App : public Base
{
public:
    App(Base*);
    void build_tree();
    int start_app();
};

#endif