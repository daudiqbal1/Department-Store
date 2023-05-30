#include "Garment.h"

void Garment :: getInput(){
        cout << "Enter the garment size: ";
        cin >> size;
    };

string Garment :: getProductDetails() const{
        return "Category: " + getCategory() + "\n" +
               "Name: " + getName() + "\n" +
               "Size: " + size + "\n" +
               "Price: $" + to_string(getPrice());
    };

string Garment :: getSpecificDetail() const{
        return size;
};