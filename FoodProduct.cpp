#include "FoodProduct.h"

void FoodProduct :: getInput(){
        cout << "Enter the food product expiry date: ";
        cin.ignore();
        getline(cin, expiryDate);
    };

string FoodProduct :: getProductDetails() const{
        return "Category: " + getCategory() + "\n" +
               "Name: " + getName() + "\n" +
               "Expiry Date: " + expiryDate + "\n" +
               "Price: $" + to_string(getPrice());
    };

string FoodProduct :: getSpecificDetail() const{
        return expiryDate;
};