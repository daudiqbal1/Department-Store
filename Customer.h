#ifndef CUSTOMER_H
#define CUSTOMER_H

#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>
#include "Product.h"
#include "FoodProduct.h"
#include "Garment.h"

using namespace std;

class Customer {
public:
    void purchaseProducts();
    void displayMenu();
    void displayProducts(const vector<Product*>& products);
    void addToCart(Product* product, int quantity);
    void checkout();

private:
    vector<Product*> cart;
};




#endif