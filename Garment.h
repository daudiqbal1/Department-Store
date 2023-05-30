#ifndef GARMENT_H
#define GARMENT_H
#include "Product.h"

#pragma once

using namespace std;

class Garment : public Product{
public:
    Garment(const string& name, double price, const string& size, const Department& department) : Product(name, price, department), size(size) {}

    void getInput() ;

    string getProductDetails() const ;

    string getSpecificDetail() const ;

private:
    string size;
};


#endif