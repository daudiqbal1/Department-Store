#ifndef ADMIN_H
#define ADMIN_H
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "Department.h"
#include "Product.h"
#include "Garment.h"
#include "FoodProduct.h"


using namespace std;


class Admin{
public:
    ~Admin();
    void AddProduct();
    void DeleteProduct();
    void SalesReport();
    bool DoesProductExist(const string& productName) const;
    void ViewAllProducts();
    

private:
    std::vector<Product*> products;

    void DeleteAllProducts();
    void SaveProductToFile(const string& productDetails);
    


};

#endif