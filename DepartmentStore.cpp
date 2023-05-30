

#include"FreeFunctions.h"
#include"Admin.h"
#include"Customer.h"
#include"Product.h"
#include"Garment.h"
#include"FoodProduct.h"
#include<unistd.h>              //for sleep function
#include <string.h>

using namespace std;


int main(){

     Admin admin;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. View All Products" << endl;
        cout << "2. View Sales Report" << endl;
        cout << "3. Add Product" << endl;
        cout << "4. Delete Product" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                admin.ViewAllProducts();
                break;
            case 2:
                admin.SalesReport();
                break;
            case 3:
                admin.AddProduct();
                break;
            case 4:
                admin.DeleteProduct();
                return 0;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    };

    try {
        Customer customer;
        customer.purchaseProducts();
    } catch (const exception& e) {
        cout << "An error occurred: " << e.what() << endl;
    }

    return 0;
}