#ifndef PRODUCT_H
#define PRODUCT_H
#include "Department.h"

#include <iostream>
#include <string>
using namespace std;


#pragma once


class Product{
public:
    Product(const string& name, double price, const Department& department) : name(name), price(price), department(department) {};
    virtual ~Product() = default;

    string getName() const;

    double getPrice() const;

    string getCategory() const;

    virtual void getInput() = 0;
    virtual string getSpecificDetail()  const = 0;
    virtual string getProductDetails() const = 0;

private:
    string name;
    double price;
    Department department;
};

#endif