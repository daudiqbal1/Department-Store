#include "Customer.h"
#include "Product.h"
#include "FoodProduct.h"
#include "Garment.h"

using namespace std;


void Customer::purchaseProducts() {
    while (true) {
        displayMenu();

        int choice;
        cin >> choice;

        if (choice == 1) {
            vector<Product*> garments;
            vector<Product*> foodProducts;

            // Read products from file
            ifstream file("products.txt");
            if (file.is_open()) {
                string line;
                while (getline(file, line)) {
                    stringstream ss(line);
                    string data;

                    // Read the comma-separated values
                    vector<string> values;
                    while (getline(ss, data, ',')) {
                        values.push_back(data);
                    }

                    if (values.size() >= 4) {
                        string category = values[0];
                        string name = values[1];
                        double price = stod(values[2]);
                        string attribute = values[3];

                        Department department(category);

                        if (category == "Garment") {
                            string size = attribute;
                            Product* garment = new Garment(name, price, size, department);
                            garments.push_back(garment);
                        } else if (category == "Food") {
                            string expiryDate = attribute;
                            Product* foodProduct = new FoodProduct(name, price, expiryDate, department);
                            foodProducts.push_back(foodProduct);
                        }
                    }
                }

                file.close();
            } else {
                throw runtime_error("Failed to open products.txt");
            }

            cout << "Choose a department:" << endl;
            cout << "1. Garments" << endl;
            cout << "2. Food" << endl;
            cout << "3. Go back" << endl;

            int departmentChoice;
            cin >> departmentChoice;

            vector<Product*> selectedProducts;
            if (departmentChoice == 1) {
                selectedProducts = garments;
            } else if (departmentChoice == 2) {
                selectedProducts = foodProducts;
            } else if (departmentChoice == 3) {
                continue; // Go back to the main menu
            } else {
                throw runtime_error("Invalid department choice.");
            }

            displayProducts(selectedProducts);

            cout << "Choose a product by entering its number (or enter 0 to cancel): ";
            int productChoice;
            cin >> productChoice;

            if (productChoice == 0) {
                continue; // Go back to the department selection
            } else if (productChoice < 1 || productChoice > selectedProducts.size()) {
                throw runtime_error("Invalid product choice.");
            }

            Product* selectedProduct = selectedProducts[productChoice - 1];

            int quantity;
            cout << "Enter the quantity: ";
            cin >> quantity;

            if (quantity <= 0) {
                throw runtime_error("Invalid quantity.");
            }

            addToCart(selectedProduct, quantity);

            cout << "Product added to cart." << endl;
            cout << "-----------------------" << endl;
        } else if (choice == 2) {
            checkout();
            break; // End the purchase process
        } else {
            throw runtime_error("Invalid choice.");
        }
    }
};



void Customer :: displayMenu(){
    cout << "Menu:" << endl;
    cout << "1. Choose Department" << endl;
    cout << "2. Go to Checkout" << endl;
    cout << "Enter your choice: ";
};

void Customer :: displayProducts(const vector<Product*>& products){
    cout << "Products available:" << endl;
    for (size_t i = 0; i < products.size(); ++i) {
        cout << i + 1 << ". " << products[i]->getProductDetails() << endl;
    }
    cout << "-----------------------" << endl;
};

void Customer :: addToCart(Product* product, int quantity){
    for (int i = 0; i < quantity; ++i) {
        cart.push_back(product);
    }
};

void Customer :: checkout(){
    if (cart.empty()) {
        cout << "Your cart is empty." << endl;
        return;
    }

    double totalPrice = 0.0;

    ofstream file("SoldItems.txt", ios::app);
    if (file.is_open()) {
        for (const auto& product : cart) {
            file << "Product's Name: " << product->getName() << endl;
            file << "Quantity: 1" << endl; // Assuming quantity is always 1 for each product
            file << "Total Price: $" << product->getPrice() << endl;
            file << "-----------------------" << endl;

            totalPrice += product->getPrice();
        }

        file.close();
    } else {
        throw runtime_error("Failed to open SoldItems.txt");
    }

    cout << "Checkout completed." << endl;
    cout << "Total Price: $" << totalPrice << endl;

    // Clear the cart
    for (auto& product : cart) {
        delete product;
    }
    cart.clear();
};