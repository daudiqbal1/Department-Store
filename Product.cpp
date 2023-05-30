#include "Product.h"
#include "Department.h"



string Product :: getName() const{
        return name;
    };

double Product :: getPrice() const{
        return price;
    };

string Product :: getCategory() const{
        return department.getCategory();
    };
