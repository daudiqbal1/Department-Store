#include "Admin.h"
#include "Garment.h"
#include "FoodProduct.h"
#include <fstream>


using namespace std;


Admin :: ~Admin(){
    DeleteAllProducts();
};

bool Admin::DoesProductExist(const string& productName) const {
    ifstream file("products.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t found = line.find(productName);
            if (found != string::npos) {
                return true;
            }
        }
        file.close();
    }
    return false;
};



void Admin :: AddProduct(){
    try {
        string category, name;
        double price;

        cout << "Enter the product category (Garment/Food): ";
        cin >> category;

        cout << "Enter the product name: ";
        cin.ignore();
        getline(cin, name);

        if (DoesProductExist(name)) {
            cout << "Product already exists. Please try again with a different name." << endl;
            return;
        }

        cout << "Enter the product price: ";
        cin >> price;

        Department department(category);

        Product* product = nullptr;

        if (category == "Garment") {
            string size;
            cout << "Enter the garment size: ";
            cin.ignore();
            getline(cin, size);
            product = new Garment(name, price, size, department);
        } else if (category == "Food") {
            string expiryDate;
            cout << "Enter the food product expiry date(Month/Day/Year): ";
            cin.ignore();
            getline(cin, expiryDate);
            product = new FoodProduct(name, price, expiryDate, department);
        } else {
            throw runtime_error("Invalid category.");
        }

        if (product) {

            ofstream file("products.txt", ios::app);
            if (file.is_open()) {
                file << category << "," << name << "," << price << ",";
                file << product->getSpecificDetail() << endl;
                file.close();
                cout << "Product added successfully." << endl;
            } else {
                throw runtime_error("Failed to open products.txt");
            }

            delete product;
        }
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void Admin::DeleteProduct() {
    try {
        string name;

        cout << "Enter the name of the product you want to delete: ";
        cin.ignore();
        getline(cin, name);

        // Check if the product exists in the file
        if (!DoesProductExist(name)) {
            throw runtime_error("Product not found.");
        }

        // Read products from file
        ifstream inputFile("Products.txt");
        if (!inputFile) {
            throw runtime_error("Failed to open Products.txt for reading.");
        }

        vector<string> lines;
        string line;
        bool productFound = false;
        while (getline(inputFile, line)) {
            // Check if the current line contains the product to delete
            size_t found = line.find(name);
            if (found != string::npos) {
                // Product found, skip adding it to the vector
                productFound = true;
                continue;
            }
            lines.push_back(line);
        }
        inputFile.close();

        // Rewrite the products to the file
        ofstream outputFile("Products.txt");
        if (!outputFile) {
            throw runtime_error("Failed to open Products.txt for writing.");
        }

        for (const auto& line : lines) {
            outputFile << line << endl;
        }

        outputFile.close();

        if (productFound) {
            cout << "Product deleted successfully." << endl;
        } else {
            cout << "Product not found." << endl;
        }
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}


void Admin::SalesReport() {
    ifstream file("SoldItems.txt");
    if (file.is_open()) {
        string line;
        int totalProductsSold = 0;
        double totalRevenue = 0.0;

        cout << "Sales Report:" << endl;

        while (getline(file, line)) {
            if (line.find("Product's Name:") != string::npos) {
                string productName = line.substr(line.find(":") + 2);
                cout << "Product's Name: " << productName << endl;

                getline(file, line); // Read the next line for quantity
                int quantity = stoi(line.substr(line.find(":") + 2));
                totalProductsSold += quantity;
                cout << "Quantity: " << quantity << endl;

                getline(file, line); // Read the next line for total price
                double price = stod(line.substr(line.find("$") + 1));
                totalRevenue += price;
                cout << "Total Price: $" << price << endl;

                cout << "-----------------------" << endl;
            }
        }

        file.close();

        cout << "Total Products Sold: " << totalProductsSold << endl;
        cout << "Total Revenue: $" << totalRevenue << endl;
    } else {
        cout << "Failed to open SoldItems.txt" << endl;
    }
};







void Admin :: SaveProductToFile(const string& productDetails){
    ofstream file("products.txt", ios::app);
    if (file.is_open()) {
        file << productDetails << endl;
        file.close();
    } else {
        throw runtime_error("Failed to open products.txt");
    }
};


void Admin :: DeleteAllProducts(){
    for (const auto& product : products) {
        delete product;
    }
    products.clear();
};

void Admin :: ViewAllProducts() {
    ifstream file("products.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
            cout << "------------------------" << endl;
        }
        file.close();
    } else {
        cout << "Error: Failed to open products.txt" << endl;
    }
};