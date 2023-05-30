#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#pragma once

#include <iostream>
#include <string>
using namespace std;

class Department{
public:
    Department(const string& category) : category(category) {};

    string getCategory() const;

private:
    string category;
};

#endif