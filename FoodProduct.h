#ifndef FOODPRODUCTS_H
#define FOODPRODUCTS_H
#include "Product.h"

#pragma once

class FoodProduct : public Product {
public:
    FoodProduct(const string& name, double price, const string& expiryDate, const Department& department) : Product(name, price, department), expiryDate(expiryDate) {}

    void getInput() ;

    string getProductDetails() const ;

    string getSpecificDetail() const ;

private:
    string expiryDate;
};

#endif