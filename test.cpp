#include <iostream>
#include <vector>
using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(1000, '\n');
}

class Customer {
private:
    int customerID;
    string customerName;
    string contactNumber;
    string email;
    string address;

public:
    Customer() {
        customerID = 0;
        customerName = "";
        contactNumber = "";
        email = "";
        address = "";
    }

    void setCustomerID(int id) { customerID = id; }
    void setCustomerName(string name) { customerName = name; }
    void setContactNumber(string number) { contactNumber = number; }
    void setEmail(string e) { email = e; }
    void setAddress(string a) { address = a; }

    int getCustomerID() { return customerID; }
    string getCustomerName() { return customerName; }
    string getContactNumber() { return contactNumber; }
    string getEmail() { return email; }
    string getAddress() { return address; }

    void addCustomer() {
        cout << "Adding new customer: " << customerName << endl;
        cout << "Customer ID: " << customerID << endl;
        cout << "Contact Number: " << contactNumber << endl;
        cout << "Email: " << email << endl;
        cout << "Address: " << address << endl;
    }

    void updateCustomer() {
        cout << "Updating customer information for: " << customerName << endl;
        cout << "Customer ID: " << customerID << endl;
    }

    void placeOrder(int orderID) {
        cout << "Placing order #" << orderID << " for customer: " << customerName << endl;
        cout << "Order placed successfully!" << endl;
    }

    void display() {
        cout << "Customer ID: " << customerID << endl;
        cout << "Name: " << customerName << endl;
        cout << "Contact: " << contactNumber << endl;
        cout << "Email: " << email << endl;
        cout << "Address: " << address << endl;
    }
};

class Product {
private:
    int productID;
    string productName;
    int categoryID;
    float price;
    int quantityInStock;
    string description;

public:
    Product() {
        productID = 0;
        productName = "";
        categoryID = 0;
        price = 0.00;
        quantityInStock = 0;
        description = "";
    }

    void setProductID(int id) { productID = id; }
    void setProductName(string n) { productName = n; }
    void setCategoryID(int cid) { categoryID = cid; }
    void setPrice(float p) { price = p; }
    void setQuantity(int q) { quantityInStock = q; }
    void setDescription(string desc) { description = desc; }

    int getProductID() { return productID; }
    string getProductName() { return productName; }
    int getCategoryID() { return categoryID; }
    float getPrice() { return price; }
    int getQuantity() { return quantityInStock; }
    string getDescription() { return description; }

    void addProduct() {
        cout << "Product " << productName << " added successfully!" << endl;
    }

    void updateProduct() {
        cout << "Product " << productName << " updated successfully!" << endl;
    }

    void deleteProduct() {
        cout << "Product " << productName << " deleted successfully!" << endl;
    }

    void updateStock(int quantity) {
        quantityInStock += quantity;
        cout << "Stock updated. New quantity: " << quantityInStock << endl;
    }

    void getProductDetails() {
        cout << "=== Product Details ===" << endl;
        cout << "ID: " << productID << endl;
        cout << "Name: " << productName << endl;
        cout << "Category ID: " << categoryID << endl;
        cout << "Price: $" << price << endl;
        cout << "Stock: " << quantityInStock << endl;
        cout << "Description: " << description << endl;
    }
};

class Order {
private:
    int orderID;
    string orderDate;
    int customerID;
    int productList[100];
    int productCount;
    float totalAmount;
    string orderStatus;

public:
    Order() {
        orderID = 0;
        orderDate = "";
        customerID = 0;
        totalAmount = 0.0;
        orderStatus = "Pending";
        productCount = 0;
        for (int i = 0; i < 100; i++) {
            productList[i] = 0;
        }
    }

    void setOrderID(int id) { orderID = id; }
    void setOrderDate(string d) { orderDate = d; }
    void setCustomerID(int cid) { customerID = cid; }
    void setOrderStatus(string status) { orderStatus = status; }
    void setTotalAmount(float amount) { totalAmount = amount; }

    int getOrderID() { return orderID; }
    string getOrderDate() { return orderDate; }
    int getCustomerID() { return customerID; }
    float getTotalAmount() { return totalAmount; }
    string getOrderStatus() { return orderStatus; }

    void createOrder(int id, string date, int custID, int products[], int count) {
        orderID = id;
        orderDate = date;
        customerID = custID;
        productCount = count;
        for (int i = 0; i < count; i++) {
            productList[i] = products[i];
        }
        orderStatus = "Created";
        cout << "Order #" << orderID << " created successfully for Customer #" << customerID << endl;
    }

    void calculateTotal(float prices[], int count) {
        totalAmount = 0;
        for (int i = 0; i < productCount && i < count; i++) {
            totalAmount += prices[i];
        }
        cout << "Total amount calculated: $" << totalAmount << endl;
    }

    void updateOrderStatus(string newStatus) {
        cout << "Updating order status from '" << orderStatus << "' to '" << newStatus << "'" << endl;
        orderStatus = newStatus;
    }

    void cancelOrder() {
        if (orderStatus == "Cancelled") {
            cout << "Order is already cancelled!" << endl;
        } else if (orderStatus == "Delivered") {
            cout << "Order has already been delivered!" << endl;
        } else {
            orderStatus = "Cancelled";
            cout << "Order #" << orderID << " has been cancelled successfully!" << endl;
        }
    }

    void displayOrderDetails() {
        cout << "========== ORDER DETAILS ==========" << endl;
        cout << "Order ID: " << orderID << endl;
        cout << "Order Date: " << orderDate << endl;
        cout << "Customer ID: " << customerID << endl;
        cout << "Product List: ";
        for (int i = 0; i < productCount; i++) {
            cout << productList[i] << " ";
        }
        cout << endl;
        cout << "Total Amount: $" << totalAmount << endl;
        cout << "Order Status: " << orderStatus << endl;
        cout << "===================================\n" << endl;
    }
};

Customer customer;
Product product;
Order order;

void customerMenu() {
    int choice;
    int id;
    string name, contact, email, addr;

    do {
        cout << "\n========================================\n";
        cout << "        CUSTOMER MANAGEMENT MENU\n";
        cout << "========================================\n";
        cout << "1. Add Customer\n";
        cout << "2. Update Customer\n";
        cout << "3. Place Order\n";
        cout << "4. Display Customer\n";
        cout << "5. Back to Main Menu\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            clearInputBuffer();
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            cout << "\n--- Add Customer ---\n";
            cout << "Enter Customer ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Contact Number: ";
            cin >> contact;
            cout << "Enter Email: ";
            cin >> email;
            cout << "Enter Address: ";
            cin >> addr;
            customer.setCustomerID(id);
            customer.setCustomerName(name);
            customer.setContactNumber(contact);
            customer.setEmail(email);
            customer.setAddress(addr);
            cout << "\n--- Customer Information Entered ---\n";
            customer.display();
            cout << "-----------------------------------\n";
            customer.addCustomer();
            break;
        case 2:
            cout << "\n--- Update Customer ---\n";
            cout << "Enter Customer ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Contact Number: ";
            cin >> contact;
            cout << "Enter Email: ";
            cin >> email;
            cout << "Enter Address: ";
            cin >> addr;
            customer.setCustomerID(id);
            customer.setCustomerName(name);
            customer.setContactNumber(contact);
            customer.setEmail(email);
            customer.setAddress(addr);
            customer.updateCustomer();
            break;
        case 3:
            cout << "Enter Order ID: ";
            cin >> id;
            customer.placeOrder(id);
            break;
        case 4:
            customer.display();
            break;
        case 5:
            cout << "Returning to Main Menu...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);
}

void productMenu() {
    int choice;
    int id, catId, qty;
    string name, desc;
    float price;

    do {
        cout << "\n========================================\n";
        cout << "        PRODUCT MANAGEMENT MENU\n";
        cout << "========================================\n";
        cout << "1. Add Product\n";
        cout << "2. Update Product\n";
        cout << "3. Delete Product\n";
        cout << "4. Update Stock\n";
        cout << "5. Display Product Details\n";
        cout << "6. Back to Main Menu\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            clearInputBuffer();
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            cout << "\n--- Add Product ---\n";
            cout << "Enter Product ID: ";
            cin >> id;
            cout << "Enter Product Name: ";
            cin >> name;
            cout << "Enter Category ID: ";
            cin >> catId;
            cout << "Enter Price: ";
            cin >> price;
            cout << "Enter Quantity: ";
            cin >> qty;
            cout << "Enter Description: ";
            cin >> desc;
            product.setProductID(id);
            product.setProductName(name);
            product.setCategoryID(catId);
            product.setPrice(price);
            product.setQuantity(qty);
            product.setDescription(desc);
            cout << "\n--- Product Information Entered ---\n";
            product.getProductDetails();
            cout << "------------------------------------\n";
            product.addProduct();
            break;
        case 2:
            cout << "\n--- Update Product ---\n";
            cout << "Enter Product ID: ";
            cin >> id;
            cout << "Enter Product Name: ";
            cin >> name;
            cout << "Enter Category ID: ";
            cin >> catId;
            cout << "Enter Price: ";
            cin >> price;
            cout << "Enter Quantity: ";
            cin >> qty;
            cout << "Enter Description: ";
            cin >> desc;
            product.setProductID(id);
            product.setProductName(name);
            product.setCategoryID(catId);
            product.setPrice(price);
            product.setQuantity(qty);
            product.setDescription(desc);
            product.updateProduct();
            break;
        case 3:
            product.deleteProduct();
            break;
        case 4:
            cout << "Enter quantity change (positive to add, negative to reduce): ";
            cin >> qty;
            product.updateStock(qty);
            break;
        case 5:
            product.getProductDetails();
            break;
        case 6:
            cout << "Returning to Main Menu...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);
}

void orderMenu() {
    int choice;
    int id, custId, count, prods[100];
    string date;
    float prices[100];

    do {
        cout << "\n========================================\n";
        cout << "        ORDER MANAGEMENT MENU\n";
        cout << "========================================\n";
        cout << "1. Create Order\n";
        cout << "2. Calculate Total\n";
        cout << "3. Update Order Status\n";
        cout << "4. Cancel Order\n";
        cout << "5. Display Order Details\n";
        cout << "6. Back to Main Menu\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            clearInputBuffer();
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            cout << "\n--- Create Order ---\n";
            cout << "Enter Order ID: ";
            cin >> id;
            cout << "Enter Order Date: ";
            cin >> date;
            cout << "Enter Customer ID: ";
            cin >> custId;
            cout << "Enter number of products: ";
            cin >> count;
            for (int i = 0; i < count; i++) {
                cout << "Enter Product ID " << i + 1 << ": ";
                cin >> prods[i];
            }
            order.createOrder(id, date, custId, prods, count);
            cout << "\n--- Order Information Entered ---\n";
            cout << "Order ID: " << id << endl;
            cout << "Order Date: " << date << endl;
            cout << "Customer ID: " << custId << endl;
            cout << "Products: ";
            for (int i = 0; i < count; i++) {
                cout << prods[i] << " ";
            }
            cout << endl;
            cout << "---------------------------------\n";
            break;
        case 2:
            cout << "Enter number of products: ";
            cin >> count;
            for (int i = 0; i < count; i++) {
                cout << "Enter Price for Product " << i + 1 << ": ";
                cin >> prices[i];
            }
            order.calculateTotal(prices, count);
            break;
        case 3:
            cout << "Enter new status: ";
            cin >> date;
            order.updateOrderStatus(date);
            break;
        case 4:
            order.cancelOrder();
            break;
        case 5:
            order.displayOrderDetails();
            break;
        case 6:
            cout << "Returning to Main Menu...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);
}

int main() {
    int choice;

    do {
        cout << "\n========================================\n";
        cout << "  WAREHOUSE MANAGEMENT SYSTEM\n";
        cout << "========================================\n";
        cout << "1. Manage Customer\n";
        cout << "2. Manage Product\n";
        cout << "3. Manage Order\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            clearInputBuffer();
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            customerMenu();
            break;
        case 2:
            productMenu();
            break;
        case 3:
            orderMenu();
            break;
        case 4:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}