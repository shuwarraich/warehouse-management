#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getValidatedInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            clearInputBuffer();
            return value;
        }
        else {
            cout << "Invalid input. Please enter an integer.\n";
            clearInputBuffer();
        }
    }
}

float getValidatedFloat(const string& prompt) {
    float value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            clearInputBuffer();
            return value;
        }
        else {
            cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
        }
    }
}

int getValidatedMenuChoice(int low, int high) {
    int choice;
    while (true) {
        cout << "Enter your choice: ";
        if (cin >> choice && choice >= low && choice <= high) {
            clearInputBuffer();
            return choice;
        }
        else {
            cout << "Invalid choice. Please enter a number between " << low << " and " << high << ".\n";
            clearInputBuffer();
        }
    }
}

string getStringInput(string prompt) {
    cout << prompt;
    string input;
    getline(cin, input);
    return input;
}

class Person {
protected:
    int id;
    string name;
    string contact;
    string email;

public:
    Person() {
        id = 0;
        name = "";
        contact = "";
        email = "";
    }

    void setID(int i) { id = i; }
    void setName(string n) { name = n; }
    void setContact(string c) { contact = c; }
    void setEmail(string e) { email = e; }

    int getID() { return id; }
    string getName() { return name; }
    string getContact() { return contact; }
    string getEmail() { return email; }

    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Contact: " << contact << endl;
        cout << "Email: " << email << endl;
    }
};

class Customer : public Person {
private:
    string address;

public:
    Customer() {
        address = "";
    }

    void setAddress(string a) { address = a; }
    string getAddress() { return address; }

    void display() {
        cout << "========== CUSTOMER DETAILS ==========" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Contact: " << contact << endl;
        cout << "Email: " << email << endl;
        cout << "Address: " << address << endl;
        cout << "=======================================" << endl;
    }
};

class Product {
private:
    int productID;
    string productName;
    int categoryID;
    float price;
    string description;

public:
    Product() {
        productID = 0;
        productName = "";
        categoryID = 0;
        price = 0.00;
        description = "";
    }

    void setProductID(int id) { productID = id; }
    void setProductName(string n) { productName = n; }
    void setCategoryID(int cid) { categoryID = cid; }
    void setPrice(float p) { price = p; }
    void setDescription(string desc) { description = desc; }

    int getProductID() { return productID; }
    string getProductName() { return productName; }
    int getCategoryID() { return categoryID; }
    float getPrice() { return price; }
    string getDescription() { return description; }

    void display() {
        cout << "ID: " << productID << " | Name: " << productName
            << " | Price: $" << price << endl;
    }

    void displayDetails() {
        cout << "========== PRODUCT DETAILS ==========" << endl;
        cout << "ID: " << productID << endl;
        cout << "Name: " << productName << endl;
        cout << "Category ID: " << categoryID << endl;
        cout << "Price: $" << price << endl;
        cout << "Description: " << description << endl;
        cout << "======================================" << endl;
    }
};

class Order {
    friend class OrderCollection;
private:
    int orderID;
    string orderDate;
    int customerID;
    Product products[50];
    int productCount;
    float totalAmount;
    string orderStatus;
    void setTotalAmount(float amount) { totalAmount = amount; }

public:
    Order() {
        orderID = 0;
        orderDate = "";
        customerID = 0;
        productCount = 0;
        totalAmount = 0.0;
        orderStatus = "Pending";
    }

    void setOrderID(int id) { orderID = id; }
    void setOrderDate(string d) { orderDate = d; }
    void setCustomerID(int cid) { customerID = cid; }
    void setOrderStatus(string status) { orderStatus = status; }
    void addProduct(Product p) {
        if (productCount < 50) {
            products[productCount] = p;
            productCount++;
            totalAmount += p.getPrice();
        }
    }

    int getOrderID() { return orderID; }
    string getOrderDate() { return orderDate; }
    int getCustomerID() { return customerID; }
    float getTotalAmount() { return totalAmount; }
    string getOrderStatus() { return orderStatus; }
    int getProductCount() { return productCount; }

    void display() {
        cout << "ID: " << orderID << " | Date: " << orderDate
            << " | Customer: " << customerID << " | Status: " << orderStatus << endl;
    }

    void displayDetails() {
        cout << "========== ORDER DETAILS ==========" << endl;
        cout << "Order ID: " << orderID << endl;
        cout << "Order Date: " << orderDate << endl;
        cout << "Customer ID: " << customerID << endl;
        cout << "Products (" << productCount << "): ";
        for (int i = 0; i < productCount; i++) {
            cout << products[i].getProductID() << " ";
        }
        cout << endl;
        cout << "Total Amount: $" << totalAmount << endl;
        cout << "Status: " << orderStatus << endl;
        cout << "====================================" << endl;
    }
};

class Address {
private:
    string city;

public:
    Address() {
        city = "";
    }
    void setCity(string c) { city = c; }
    string getCity() { return city; }
    void display() {
        cout << "City: " << city << endl;
    }
};

class Employee : public Person {
private:
    Address address; // Composition (strong relationship)
    string position;

public:
    Employee() : Person() {
        position = "";
    }
    void setPosition(string p) { position = p; }
    void setCity(string c) { address.setCity(c); }
    string getPosition() { return position; }
    string getCity() { return address.getCity(); }

    void display() {
        cout << "========== EMPLOYEE DETAILS ==========" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Contact: " << contact << endl;
        cout << "Email: " << email << endl;
        cout << "Position: " << position << endl;
        address.display();
        cout << "=======================================" << endl;
    }
};

class Supplier : public Person {
private:
    Address* address; // Aggregation (weak relationship)
    string companyName;

public:
    Supplier() : Person() {
        address = NULL;
        companyName = "";
    }
    void setCompanyName(string c) { companyName = c; }
    void setAddress(Address* addr) { address = addr; }
    string getCompanyName() { return companyName; }

    void display() {
        cout << "========== SUPPLIER DETAILS ==========" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Contact: " << contact << endl;
        cout << "Email: " << email << endl;
        cout << "Company: " << companyName << endl;
        if (address != NULL)
            address->display();
        cout << "=======================================" << endl;
    }
};

class Category {
private:
    int categoryID;
    string categoryName;
    string description;

public:
    Category() {
        categoryID = 0;
        categoryName = "";
        description = "";
    }
    void setCategoryID(int id) { categoryID = id; }
    void setCategoryName(string n) { categoryName = n; }
    void setDescription(string d) { description = d; }
    int getCategoryID() { return categoryID; }
    string getCategoryName() { return categoryName; }
    string getDescription() { return description; }

    void display() {
        cout << "ID: " << categoryID << " | Name: " << categoryName
            << " | Description: " << description << endl;
    }

    void displayDetails() {
        cout << "========== CATEGORY DETAILS ==========" << endl;
        cout << "Category ID: " << categoryID << endl;
        cout << "Name: " << categoryName << endl;
        cout << "Description: " << description << endl;
        cout << "======================================" << endl;
    }
};

class Entity {
protected:
    int id;
    string name;

public:
    Entity() { id = 0; name = ""; }
    void setID(int i) { id = i; }
    void setName(string n) { name = n; }
    int getID() { return id; }
    string getName() { return name; }
    void displayEntity() {
        cout << "ID: " << id << " | Name: " << name << endl;
    }
};

class Warehouse : public Entity {
protected:
    string location;
    int capacity;

public:
    Warehouse() : Entity() { location = ""; capacity = 0; }
    void setLocation(string l) { location = l; }
    void setCapacity(int c) { capacity = c; }
    string getLocation() { return location; }
    int getCapacity() { return capacity; }

    void display() {
        cout << "========== WAREHOUSE DETAILS ==========" << endl;
        displayEntity();
        cout << "Location: " << location << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "=======================================" << endl;
    }
};

class Inventory : public Warehouse {
protected:
    int productID;
    int quantity;

public:
    Inventory() : Warehouse() {
        productID = 0; quantity = 0;
    }
    void setProductID(int id) { productID = id; }
    void setQuantity(int q) { quantity = q; }
    int getProductID() { return productID; }
    int getQuantity() { return quantity; }

    void display();
};

class Shipment : public Inventory {
private:
    int shipmentID;
    string status;

public:
    Shipment() : Inventory() { shipmentID = 0; status = "Pending"; }
    void setShipmentID(int id) { shipmentID = id; }
    void setStatus(string s) { status = s; }
    int getShipmentID() { return shipmentID; }
    string getStatus() { return status; }

    void display();
};

class CustomerCollection {
private:
    Customer customers[100];
    int count;
    int nextID;

public:
    CustomerCollection() {
        count = 0;
        nextID = 1;
    }

    int getNextID() { return nextID++; }

    void Add(Customer c) {
        if (FindByID(c.getID()) != -1) {
            cout << "Error: Customer with ID " << c.getID() << " already exists!" << endl;
            return;
        }
        if (count < 100) {
            customers[count] = c;
            count++;
            cout << "Customer added successfully! (Total: " << count << ")" << endl;
        }
        else {
            cout << "Collection is full!" << endl;
        }
    }

    void Remove(int id) {
        int index = FindByID(id);
        if (index != -1) {
            for (int i = index; i < count - 1; i++) {
                customers[i] = customers[i + 1];
            }
            count--;
            cout << "Customer removed successfully!" << endl;
        }
        else {
            cout << "Customer not found!" << endl;
        }
    }

    void Update(int id) {
        int index = FindByID(id);
        if (index != -1) {
            Customer c;
            string name, contact, email, addr;
            name = getStringInput("Enter new Name: ");
            contact = getStringInput("Enter new Contact: ");
            email = getStringInput("Enter new Email: ");
            addr = getStringInput("Enter new Address: ");
            c.setID(customers[index].getID());
            c.setName(name);
            c.setContact(contact);
            c.setEmail(email);
            c.setAddress(addr);
            customers[index] = c;
            cout << "Customer updated successfully!" << endl;
        }
        else {
            cout << "Customer not found!" << endl;
        }
    }

    void DisplayAll() {
        if (count == 0) {
            cout << "No customers in collection!" << endl;
            return;
        }
        cout << "\n========== ALL CUSTOMERS ==========" << endl;
        for (int i = 0; i < count; i++) {
            customers[i].display();
            cout << endl;
        }
    }

    int FindByID(int id) {
        for (int i = 0; i < count; i++) {
            if (customers[i].getID() == id) {
                return i;
            }
        }
        return -1;
    }

    Customer* GetCustomer(int id) {
        int index = FindByID(id);
        if (index != -1) {
            return &customers[index];
        }
        return NULL;
    }

    int getCount() { return count; }

    void loadFromCSV(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Warning: Could not open " << filename << ". Starting with empty collection.\n";
            return;
        }
        string line;
        bool headerSkipped = false;
        while (getline(file, line)) {
            if (line.empty()) continue;
            if (!headerSkipped) {
                if (line.find("ID") != string::npos || line.find("id") != string::npos) {
                    headerSkipped = true;
                    continue;
                }
                headerSkipped = true;
            }
            stringstream ss(line);
            string idStr, name, contact, email, address;
            if (getline(ss, idStr, ',') &&
                getline(ss, name, ',') &&
                getline(ss, contact, ',') &&
                getline(ss, email, ',') &&
                getline(ss, address, ',')) {
                Customer c;
                int loadedID = stoi(idStr);
                c.setID(loadedID);
                c.setName(name);
                c.setContact(contact);
                c.setEmail(email);
                c.setAddress(address);
                customers[count] = c;
                count++;
                if (loadedID >= nextID) {
                    nextID = loadedID + 1;
                }
            }
        }
        file.close();
        cout << "Loaded " << count << " customers from " << filename << ".\n";
    }

    void saveToCSV(const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Error: Could not write to " << filename << endl;
            return;
        }
        file << "ID,Name,Contact,Email,Address\n";
        for (int i = 0; i < count; i++) {
            file << customers[i].getID() << ","
                << customers[i].getName() << ","
                << customers[i].getContact() << ","
                << customers[i].getEmail() << ","
                << customers[i].getAddress() << "\n";
        }
        file.close();
        cout << "Saved " << count << " customers to " << filename << ".\n";
    }
};

class ProductCollection {
private:
    Product products[100];
    int count;
    int nextID;

public:
    ProductCollection() {
        count = 0;
        nextID = 1;
    }

    int getNextID() { return nextID++; }

    void Add(Product p) {
        if (FindByID(p.getProductID()) != -1) {
            cout << "Error: Product with ID " << p.getProductID() << " already exists!" << endl;
            return;
        }
        if (count < 100) {
            products[count] = p;
            count++;
            cout << "Product added successfully! (Total: " << count << ")" << endl;
        }
        else {
            cout << "Collection is full!" << endl;
        }
    }

    void Remove(int id) {
        int index = FindByID(id);
        if (index != -1) {
            for (int i = index; i < count - 1; i++) {
                products[i] = products[i + 1];
            }
            count--;
            cout << "Product removed successfully!" << endl;
        }
        else {
            cout << "Product not found!" << endl;
        }
    }

    void Update(int id) {
        int index = FindByID(id);
        if (index != -1) {
            Product p;
            int catId;
            string name, desc;
            float price;
            name = getStringInput("Enter new Name: ");
            catId = getValidatedInt("Enter new Category ID: ");
            price = getValidatedFloat("Enter new Price: ");
            desc = getStringInput("Enter new Description: ");
            p.setProductID(products[index].getProductID());
            p.setProductName(name);
            p.setCategoryID(catId);
            p.setPrice(price);
            p.setDescription(desc);
            products[index] = p;
            cout << "Product updated successfully!" << endl;
        }
        else {
            cout << "Product not found!" << endl;
        }
    }

    void DisplayAll() {
        if (count == 0) {
            cout << "No products in collection!" << endl;
            return;
        }
        cout << "\n========== ALL PRODUCTS ==========" << endl;
        for (int i = 0; i < count; i++) {
            products[i].display();
        }
        cout << "=================================" << endl;
    }

    int FindByID(int id) {
        for (int i = 0; i < count; i++) {
            if (products[i].getProductID() == id) {
                return i;
            }
        }
        return -1;
    }

    Product* GetProduct(int id) {
        int index = FindByID(id);
        if (index != -1) {
            return &products[index];
        }
        return NULL;
    }

    int getCount() { return count; }

    void loadFromCSV(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Warning: Could not open " << filename << ". Starting with empty collection.\n";
            return;
        }
        string line;
        bool headerSkipped = false;
        while (getline(file, line)) {
            if (line.empty()) continue;
            if (!headerSkipped) {
                if (line.find("ProductID") != string::npos || line.find("ID") != string::npos) {
                    headerSkipped = true;
                    continue;
                }
                headerSkipped = true;
            }
            stringstream ss(line);
            string pidStr, name, catIdStr, priceStr, desc;
            if (getline(ss, pidStr, ',') &&
                getline(ss, name, ',') &&
                getline(ss, catIdStr, ',') &&
                getline(ss, priceStr, ',') &&
                getline(ss, desc, ',')) {
                Product p;
                int loadedPID = stoi(pidStr);
                p.setProductID(loadedPID);
                p.setProductName(name);
                p.setCategoryID(stoi(catIdStr));
                p.setPrice(stof(priceStr));
                p.setDescription(desc);
                products[count] = p;
                count++;
                if (loadedPID >= nextID) {
                    nextID = loadedPID + 1;
                }
            }
        }
        file.close();
        cout << "Loaded " << count << " products from " << filename << ".\n";
    }

    void saveToCSV(const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Error: Could not write to " << filename << endl;
            return;
        }
        file << "ProductID,ProductName,CategoryID,Price,Description\n";
        for (int i = 0; i < count; i++) {
            file << products[i].getProductID() << ","
                << products[i].getProductName() << ","
                << products[i].getCategoryID() << ","
                << products[i].getPrice() << ","
                << products[i].getDescription() << "\n";
        }
        file.close();
        cout << "Saved " << count << " products to " << filename << ".\n";
    }
};

class OrderCollection {
private:
    Order orders[100];
    int count;
    int nextID;

public:
    OrderCollection() {
        count = 0;
        nextID = 1;
    }

    int getNextID() { return nextID++; }

    void Add(Order o) {
        if (FindByID(o.getOrderID()) != -1) {
            cout << "Error: Order with ID " << o.getOrderID() << " already exists!" << endl;
            return;
        }
        if (count < 100) {
            orders[count] = o;
            count++;
            cout << "Order added successfully! (Total: " << count << ")" << endl;
        }
        else {
            cout << "Collection is full!" << endl;
        }
    }

    void Remove(int id) {
        int index = FindByID(id);
        if (index != -1) {
            for (int i = index; i < count - 1; i++) {
                orders[i] = orders[i + 1];
            }
            count--;
            cout << "Order removed successfully!" << endl;
        }
        else {
            cout << "Order not found!" << endl;
        }
    }

    void Update(int id) {
        int index = FindByID(id);
        if (index != -1) {
            string status = getStringInput("Enter new status: ");
            orders[index].setOrderStatus(status);
            cout << "Order updated successfully!" << endl;
        }
        else {
            cout << "Order not found!" << endl;
        }
    }

    void DisplayAll() {
        if (count == 0) {
            cout << "No orders in collection!" << endl;
            return;
        }
        cout << "\n========== ALL ORDERS ==========" << endl;
        for (int i = 0; i < count; i++) {
            orders[i].display();
        }
        cout << "===============================" << endl;
    }

    int FindByID(int id) {
        for (int i = 0; i < count; i++) {
            if (orders[i].getOrderID() == id) {
                return i;
            }
        }
        return -1;
    }

    Order* GetOrder(int id) {
        int index = FindByID(id);
        if (index != -1) {
            return &orders[index];
        }
        return NULL;
    }

    int getCount() { return count; }

    void loadFromCSV(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Warning: Could not open " << filename << ". Starting with empty collection.\n";
            return;
        }
        string line;
        bool headerSkipped = false;
        while (getline(file, line)) {
            if (line.empty()) continue;
            if (!headerSkipped) {
                if (line.find("OrderID") != string::npos || line.find("ID") != string::npos) {
                    headerSkipped = true;
                    continue;
                }
                headerSkipped = true;
            }
            stringstream ss(line);
            string oidStr, date, custIdStr, totalStr, status;
            if (getline(ss, oidStr, ',') &&
                getline(ss, date, ',') &&
                getline(ss, custIdStr, ',') &&
                getline(ss, totalStr, ',') &&
                getline(ss, status, ',')) {
                Order o;
                int loadedOID = stoi(oidStr);
                o.setOrderID(loadedOID);
                o.setOrderDate(date);
                o.setCustomerID(stoi(custIdStr));
                o.totalAmount = stof(totalStr);
                o.setOrderStatus(status);
                orders[count] = o;
                count++;
                if (loadedOID >= nextID) {
                    nextID = loadedOID + 1;
                }
            }
        }
        file.close();
        cout << "Loaded " << count << " orders from " << filename << ".\n";
    }

    void saveToCSV(const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Error: Could not write to " << filename << endl;
            return;
        }
        file << "OrderID,OrderDate,CustomerID,TotalAmount,OrderStatus\n";
        for (int i = 0; i < count; i++) {
            file << orders[i].getOrderID() << ","
                << orders[i].getOrderDate() << ","
                << orders[i].getCustomerID() << ","
                << orders[i].getTotalAmount() << ","
                << orders[i].getOrderStatus() << "\n";
        }
        file.close();
        cout << "Saved " << count << " orders to " << filename << ".\n";
    }
};

class CategoryCollection {
private:
    Category categories[100];
    int count;
    int nextID;

public:
    CategoryCollection() {
        count = 0;
        nextID = 1;
    }

    int getNextID() {
        return nextID++;
    }

    void Add(Category c) {

        if (FindByID(c.getCategoryID()) != -1) {
            cout << "Error: Category with ID already exists!" << endl;
            return;
        }

        if (count < 100) {
            categories[count] = c;
            count++;

            cout << "Category added successfully! (Total: "
                << count << ")" << endl;

        }
        else {
            cout << "Collection is full!" << endl;
        }
    }

    void Remove(int id) {

        int index = FindByID(id);

        if (index != -1) {

            for (int i = index; i < count - 1; i++) {
                categories[i] = categories[i + 1];
            }

            count--;

            cout << "Category removed successfully!" << endl;

        }
        else {
            cout << "Category not found!" << endl;
        }
    }

    void Update(int id) {

        int index = FindByID(id);

        if (index != -1) {

            Category c;

            string name, desc;

            name = getStringInput("Enter new Category Name: ");
            desc = getStringInput("Enter new Description: ");

            c.setCategoryID(categories[index].getCategoryID());
            c.setCategoryName(name);
            c.setDescription(desc);

            categories[index] = c;

            cout << "Category updated successfully!" << endl;

        }
        else {
            cout << "Category not found!" << endl;
        }
    }

    void DisplayAll() {

        if (count == 0) {
            cout << "No categories in collection!" << endl;
            return;
        }

        cout << "\n========== ALL CATEGORIES ==========" << endl;

        for (int i = 0; i < count; i++) {
            categories[i].display();
        }

        cout << "====================================" << endl;
    }

    int FindByID(int id) {

        for (int i = 0; i < count; i++) {

            if (categories[i].getCategoryID() == id) {
                return i;
            }
        }

        return -1;
    }

    Category* GetCategory(int id) {

        int index = FindByID(id);

        if (index != -1) {
            return &categories[index];
        }

        return NULL;
    }

    int getCount() {
        return count;
    }

    void loadFromCSV(const string& filename) {

        ifstream file(filename);

        if (!file.is_open()) {
            cerr << "Warning: Could not open "
                << filename
                << ". Starting with empty collection.\n";
            return;
        }

        string line;

        bool headerSkipped = false;

        while (getline(file, line)) {

            if (line.empty()) continue;

            if (!headerSkipped) {

                if (line.find("ID") != string::npos ||
                    line.find("id") != string::npos) {

                    headerSkipped = true;
                    continue;
                }

                headerSkipped = true;
            }

            stringstream ss(line);

            string idStr, name, desc;

            if (getline(ss, idStr, ',') &&
                getline(ss, name, ',') &&
                getline(ss, desc, ',')) {

                Category c;

                int loadedID = stoi(idStr);

                c.setCategoryID(loadedID);
                c.setCategoryName(name);
                c.setDescription(desc);

                categories[count] = c;

                count++;

                if (loadedID >= nextID) {
                    nextID = loadedID + 1;
                }
            }
        }

        file.close();

        cout << "Loaded "
            << count
            << " categories from "
            << filename
            << ".\n";
    }

    void saveToCSV(const string& filename) {

        ofstream file(filename);

        if (!file.is_open()) {
            cerr << "Error: Could not write to "
                << filename << endl;
            return;
        }

        file << "ID,Name,Description\n";

        for (int i = 0; i < count; i++) {

            file << categories[i].getCategoryID() << ","
                << categories[i].getCategoryName() << ","
                << categories[i].getDescription() << "\n";
        }

        file.close();

        cout << "Saved "
            << count
            << " categories to "
            << filename
            << ".\n";
    }
};

class EmployeeCollection {
private:
    Employee employees[100];
    int count;
    int nextID;

public:
    EmployeeCollection() {

        count = 0;
        nextID = 1;
    }

    int getNextID() {
        return nextID++;
    }

    void Add(Employee e) {

        if (FindByID(e.getID()) != -1) {

            cout << "Error: Employee with ID "
                << e.getID()
                << " already exists!" << endl;

            return;
        }

        if (count < 100) {

            employees[count] = e;

            count++;

            cout << "Employee added successfully! (Total: "
                << count << ")" << endl;

        }
        else {

            cout << "Collection is full!" << endl;
        }
    }

    void Remove(int id) {

        int index = FindByID(id);

        if (index != -1) {

            for (int i = index; i < count - 1; i++) {
                employees[i] = employees[i + 1];
            }

            count--;

            cout << "Employee removed successfully!" << endl;

        }
        else {

            cout << "Employee not found!" << endl;
        }
    }

    void Update(int id) {

        int index = FindByID(id);

        if (index != -1) {

            Employee e;

            string name, contact, email, city, position;

            name = getStringInput("Enter new Name: ");
            contact = getStringInput("Enter new Contact: ");
            email = getStringInput("Enter new Email: ");
            city = getStringInput("Enter new City: ");
            position = getStringInput("Enter new Position: ");

            e.setID(employees[index].getID());
            e.setName(name);
            e.setContact(contact);
            e.setEmail(email);
            e.setCity(city);
            e.setPosition(position);

            employees[index] = e;

            cout << "Employee updated successfully!" << endl;

        }
        else {

            cout << "Employee not found!" << endl;
        }
    }

    void DisplayAll() {

        if (count == 0) {

            cout << "No employees in collection!" << endl;
            return;
        }

        cout << "\n========== ALL EMPLOYEES ==========" << endl;

        for (int i = 0; i < count; i++) {

            employees[i].display();
            cout << endl;
        }
    }

    int FindByID(int id) {

        for (int i = 0; i < count; i++) {

            if (employees[i].getID() == id) {
                return i;
            }
        }

        return -1;
    }

    Employee* GetEmployee(int id) {

        int index = FindByID(id);

        if (index != -1) {
            return &employees[index];
        }

        return NULL;
    }

    int getCount() {
        return count;
    }

    void loadFromCSV(const string& filename) {

        ifstream file(filename);

        if (!file.is_open()) {

            cerr << "Warning: Could not open "
                << filename
                << ". Starting with empty collection.\n";

            return;
        }

        string line;

        bool headerSkipped = false;

        while (getline(file, line)) {

            if (line.empty()) continue;

            if (!headerSkipped) {

                if (line.find("ID") != string::npos ||
                    line.find("id") != string::npos) {

                    headerSkipped = true;
                    continue;
                }

                headerSkipped = true;
            }

            stringstream ss(line);

            string idStr, name, contact,
                email, city, position;

            if (getline(ss, idStr, ',') &&
                getline(ss, name, ',') &&
                getline(ss, contact, ',') &&
                getline(ss, email, ',') &&
                getline(ss, city, ',') &&
                getline(ss, position, ',')) {

                Employee e;

                int loadedID = stoi(idStr);

                e.setID(loadedID);
                e.setName(name);
                e.setContact(contact);
                e.setEmail(email);
                e.setCity(city);
                e.setPosition(position);

                employees[count] = e;

                count++;

                if (loadedID >= nextID) {
                    nextID = loadedID + 1;
                }
            }
        }

        file.close();

        cout << "Loaded "
            << count
            << " employees from "
            << filename
            << ".\n";
    }

    void saveToCSV(const string& filename) {

        ofstream file(filename);

        if (!file.is_open()) {

            cerr << "Error: Could not write to "
                << filename << endl;

            return;
        }

        file << "ID,Name,Contact,Email,City,Position\n";

        for (int i = 0; i < count; i++) {

            file << employees[i].getID() << ","
                << employees[i].getName() << ","
                << employees[i].getContact() << ","
                << employees[i].getEmail() << ","
                << employees[i].getCity() << ","
                << employees[i].getPosition() << "\n";
        }

        file.close();

        cout << "Saved "
            << count
            << " employees to "
            << filename
            << ".\n";
    }
};

class SupplierCollection {
private:

    Supplier suppliers[100];
    Address addresses[100];

    int count;
    int nextID;

public:

    SupplierCollection() {

        count = 0;
        nextID = 1;
    }

    int getNextID() {
        return nextID++;
    }

    void Add(Supplier s, Address a) {

        if (FindByID(s.getID()) != -1) {

            cout << "Error: Supplier with ID "
                << s.getID()
                << " already exists!" << endl;

            return;
        }

        if (count < 100) {

            addresses[count] = a;

            s.setAddress(&addresses[count]);

            suppliers[count] = s;

            count++;

            cout << "Supplier added successfully! (Total: "
                << count << ")" << endl;

        }
        else {

            cout << "Collection is full!" << endl;
        }
    }

    void Remove(int id) {

        int index = FindByID(id);

        if (index != -1) {

            for (int i = index; i < count - 1; i++) {

                suppliers[i] = suppliers[i + 1];
                addresses[i] = addresses[i + 1];
            }

            count--;

            cout << "Supplier removed successfully!" << endl;

        }
        else {

            cout << "Supplier not found!" << endl;
        }
    }

    void Update(int id) {

        int index = FindByID(id);

        if (index != -1) {

            Supplier s;
            Address a;

            string name, contact, email,
                company, city;

            name = getStringInput("Enter new Name: ");
            contact = getStringInput("Enter new Contact: ");
            email = getStringInput("Enter new Email: ");
            company = getStringInput("Enter new Company Name: ");
            city = getStringInput("Enter new City: ");

            a.setCity(city);

            s.setID(suppliers[index].getID());
            s.setName(name);
            s.setContact(contact);
            s.setEmail(email);
            s.setCompanyName(company);

            addresses[index] = a;

            s.setAddress(&addresses[index]);

            suppliers[index] = s;

            cout << "Supplier updated successfully!" << endl;

        }
        else {

            cout << "Supplier not found!" << endl;
        }
    }

    void DisplayAll() {

        if (count == 0) {

            cout << "No suppliers in collection!" << endl;
            return;
        }

        cout << "\n========== ALL SUPPLIERS ==========" << endl;

        for (int i = 0; i < count; i++) {

            suppliers[i].display();
            cout << endl;
        }
    }

    int FindByID(int id) {

        for (int i = 0; i < count; i++) {

            if (suppliers[i].getID() == id) {
                return i;
            }
        }

        return -1;
    }

    Supplier* GetSupplier(int id) {

        int index = FindByID(id);

        if (index != -1) {
            return &suppliers[index];
        }

        return NULL;
    }

    int getCount() {
        return count;
    }

    void loadFromCSV(const string& filename) {

        ifstream file(filename);

        if (!file.is_open()) {

            cerr << "Warning: Could not open "
                << filename
                << ". Starting with empty collection.\n";

            return;
        }

        string line;

        bool headerSkipped = false;

        while (getline(file, line)) {

            if (line.empty()) continue;

            if (!headerSkipped) {

                if (line.find("ID") != string::npos ||
                    line.find("id") != string::npos) {

                    headerSkipped = true;
                    continue;
                }

                headerSkipped = true;
            }

            stringstream ss(line);

            string idStr, name, contact,
                email, company, city;

            if (getline(ss, idStr, ',') &&
                getline(ss, name, ',') &&
                getline(ss, contact, ',') &&
                getline(ss, email, ',') &&
                getline(ss, company, ',') &&
                getline(ss, city, ',')) {

                Supplier s;
                Address a;

                int loadedID = stoi(idStr);

                a.setCity(city);

                addresses[count] = a;

                s.setID(loadedID);
                s.setName(name);
                s.setContact(contact);
                s.setEmail(email);
                s.setCompanyName(company);
                s.setAddress(&addresses[count]);

                suppliers[count] = s;

                count++;

                if (loadedID >= nextID) {
                    nextID = loadedID + 1;
                }
            }
        }

        file.close();

        cout << "Loaded "
            << count
            << " suppliers from "
            << filename
            << ".\n";
    }

    void saveToCSV(const string& filename) {

        ofstream file(filename);

        if (!file.is_open()) {

            cerr << "Error: Could not write to "
                << filename << endl;

            return;
        }

        file << "ID,Name,Contact,Email,Company,City\n";

        for (int i = 0; i < count; i++) {

            file << suppliers[i].getID() << ","
                << suppliers[i].getName() << ","
                << suppliers[i].getContact() << ","
                << suppliers[i].getEmail() << ","
                << suppliers[i].getCompanyName() << ","
                << addresses[i].getCity() << "\n";
        }

        file.close();

        cout << "Saved "
            << count
            << " suppliers to "
            << filename
            << ".\n";
    }
};

class WarehouseCollection {
private:
    Warehouse warehouses[100];
    int count;

public:
    WarehouseCollection() { count = 0; }

    void Add(Warehouse w) {
        if (count < 100) {
            warehouses[count] = w;
            count++;
            cout << "Warehouse added successfully! (Total: " << count << ")" << endl;
        }
        else {
            cout << "Collection is full!" << endl;
        }
    }

    void Remove(int id) {
        int index = FindByID(id);
        if (index != -1) {
            for (int i = index; i < count - 1; i++) {
                warehouses[i] = warehouses[i + 1];
            }
            count--;
            cout << "Warehouse removed successfully!" << endl;
        }
        else {
            cout << "Warehouse not found!" << endl;
        }
    }

    void Update(int id) {
        int index = FindByID(id);
        if (index != -1) {
            Warehouse w;
            int wid, cap;
            string name, location;
            cout << "Enter new Warehouse ID: ";
            cin >> wid;
            clearInputBuffer();
            name = getStringInput("Enter new Name: ");
            location = getStringInput("Enter new Location: ");
            cout << "Enter new Capacity: ";
            cin >> cap;
            clearInputBuffer();
            w.setID(wid);
            w.setName(name);
            w.setLocation(location);
            w.setCapacity(cap);
            warehouses[index] = w;
            cout << "Warehouse updated successfully!" << endl;
        }
        else {
            cout << "Warehouse not found!" << endl;
        }
    }

    void DisplayAll() {
        if (count == 0) {
            cout << "No warehouses in collection!" << endl;
            return;
        }
        cout << "\n========== ALL WAREHOUSES ==========" << endl;
        for (int i = 0; i < count; i++) {
            warehouses[i].display();
            cout << endl;
        }
    }

    int FindByID(int id) {
        for (int i = 0; i < count; i++) {
            if (warehouses[i].getID() == id) {
                return i;
            }
        }
        return -1;
    }

    Warehouse* GetWarehouse(int id) {
        int index = FindByID(id);
        if (index != -1) {
            return &warehouses[index];
        }
        return NULL;
    }

    int getCount() { return count; }
    void loadFromCSV(const string& filename) {
        ifstream file(filename);

        if (!file.is_open()) {
            cout << "Could not open file: " << filename << endl;
            return;
        }

        string line;
        getline(file, line);

        while (getline(file, line)) {
            stringstream ss(line);
            string temp;

            Warehouse w;

            getline(ss, temp, ',');
            w.setID(stoi(temp));

            getline(ss, temp, ',');
            w.setName(temp);

            getline(ss, temp, ',');
            w.setLocation(temp);

            getline(ss, temp, ',');
            w.setCapacity(stoi(temp));

            Add(w);
        }

        file.close();
    }

    void saveToCSV(const string& filename) {
        ofstream file(filename);

        if (!file.is_open()) {
            cout << "Could not create file: " << filename << endl;
            return;
        }

        file << "ID,Name,Location,Capacity\n";

        for (int i = 0; i < count; i++) {
            file << warehouses[i].getID() << ","
                << warehouses[i].getName() << ","
                << warehouses[i].getLocation() << ","
                << warehouses[i].getCapacity() << "\n";
        }

        file.close();

        cout << "Warehouse data saved successfully!" << endl;
    }
};

class InventoryCollection {
private:
    Inventory inventoryItems[100];
    int count;

public:
    InventoryCollection() { count = 0; }

    void Add(Inventory inv) {
        if (count < 100) {
            inventoryItems[count] = inv;
            count++;
            cout << "Inventory item added successfully! (Total: " << count << ")" << endl;
        }
        else {
            cout << "Collection is full!" << endl;
        }
    }

    void Remove(int itemID) {
        int index = FindByID(itemID);
        if (index != -1) {
            for (int i = index; i < count - 1; i++) {
                inventoryItems[i] = inventoryItems[i + 1];
            }
            count--;
            cout << "Inventory item removed successfully!" << endl;
        }
        else {
            cout << "Inventory item not found!" << endl;
        }
    }

    void Update(int productID);

    void DisplayAll() {
        if (count == 0) {
            cout << "No inventory items in collection!" << endl;
            return;
        }
        cout << "\n========== ALL INVENTORY ITEMS ==========" << endl;
        for (int i = 0; i < count; i++) {
            inventoryItems[i].display();
            cout << endl;
        }
    }

    int FindByID(int productID) {
        for (int i = 0; i < count; i++) {
            if (inventoryItems[i].getProductID() == productID) {
                return i;
            }
        }
        return -1;
    }

    Inventory* GetInventory(int productID) {
        int index = FindByID(productID);
        if (index != -1) {
            return &inventoryItems[index];
        }
        return NULL;
    }

    int getCount() { return count; }
    void loadFromCSV(const string& filename) {
        ifstream file(filename);

        if (!file.is_open()) {
            cout << "Could not open file: " << filename << endl;
            return;
        }

        string line;
        getline(file, line);

        while (getline(file, line)) {
            stringstream ss(line);
            string temp;

            Inventory inv;

            getline(ss, temp, ',');
            inv.setID(stoi(temp));

            getline(ss, temp, ',');
            inv.setName(temp);

            getline(ss, temp, ',');
            inv.setLocation(temp);

            getline(ss, temp, ',');
            inv.setCapacity(stoi(temp));

            getline(ss, temp, ',');
            inv.setProductID(stoi(temp));

            getline(ss, temp, ',');
            inv.setQuantity(stoi(temp));

            Add(inv);
        }

        file.close();
    }

    void saveToCSV(const string& filename) {
        ofstream file(filename);

        if (!file.is_open()) {
            cout << "Could not create file: " << filename << endl;
            return;
        }

        file << "WarehouseID,WarehouseName,Location,Capacity,ProductID,Quantity\n";

        for (int i = 0; i < count; i++) {
            file << inventoryItems[i].getID() << ","
                << inventoryItems[i].getName() << ","
                << inventoryItems[i].getLocation() << ","
                << inventoryItems[i].getCapacity() << ","
                << inventoryItems[i].getProductID() << ","
                << inventoryItems[i].getQuantity() << "\n";
        }

        file.close();

        cout << "Inventory data saved successfully!" << endl;
    }
};

class ShipmentCollection {
private:
    Shipment shipments[100];
    int count;

public:
    ShipmentCollection() { count = 0; }

    void Add(Shipment ship) {
        if (count < 100) {
            shipments[count] = ship;
            count++;
            cout << "Shipment added successfully! (Total: " << count << ")" << endl;
        }
        else {
            cout << "Collection is full!" << endl;
        }
    }

    void Remove(int shipmentID) {
        int index = FindByID(shipmentID);
        if (index != -1) {
            for (int i = index; i < count - 1; i++) {
                shipments[i] = shipments[i + 1];
            }
            count--;
            cout << "Shipment removed successfully!" << endl;
        }
        else {
            cout << "Shipment not found!" << endl;
        }
    }

    void Update(int shipmentID);

    void DisplayAll() {
        if (count == 0) {
            cout << "No shipments in collection!" << endl;
            return;
        }
        cout << "\n========== ALL SHIPMENTS ==========" << endl;
        for (int i = 0; i < count; i++) {
            shipments[i].display();
            cout << endl;
        }
    }

    int FindByID(int shipmentID) {
        for (int i = 0; i < count; i++) {
            if (shipments[i].getShipmentID() == shipmentID) {
                return i;
            }
        }
        return -1;
    }

    Shipment* GetShipment(int shipmentID) {
        int index = FindByID(shipmentID);
        if (index != -1) {
            return &shipments[index];
        }
        return NULL;
    }

    int getCount() { return count; }
    void loadFromCSV(const string& filename) {
        ifstream file(filename);

        if (!file.is_open()) {
            cout << "Could not open file: " << filename << endl;
            return;
        }

        string line;
        getline(file, line);

        while (getline(file, line)) {
            stringstream ss(line);
            string temp;

            Shipment ship;

            getline(ss, temp, ',');
            ship.setShipmentID(stoi(temp));

            getline(ss, temp, ',');
            ship.setID(stoi(temp));

            getline(ss, temp, ',');
            ship.setName(temp);

            getline(ss, temp, ',');
            ship.setLocation(temp);

            getline(ss, temp, ',');
            ship.setCapacity(stoi(temp));

            getline(ss, temp, ',');
            ship.setProductID(stoi(temp));

            getline(ss, temp, ',');
            ship.setQuantity(stoi(temp));

            getline(ss, temp, ',');
            ship.setStatus(temp);

            Add(ship);
        }

        file.close();
    }

    void saveToCSV(const string& filename) {
        ofstream file(filename);

        if (!file.is_open()) {
            cout << "Could not create file: " << filename << endl;
            return;
        }

        file << "ShipmentID,WarehouseID,WarehouseName,Location,Capacity,ProductID,Quantity,Status\n";

        for (int i = 0; i < count; i++) {
            file << shipments[i].getShipmentID() << ","
                << shipments[i].getID() << ","
                << shipments[i].getName() << ","
                << shipments[i].getLocation() << ","
                << shipments[i].getCapacity() << ","
                << shipments[i].getProductID() << ","
                << shipments[i].getQuantity() << ","
                << shipments[i].getStatus() << "\n";
        }

        file.close();

        cout << "Shipment data saved successfully!" << endl;
    }

};

CustomerCollection customers;
ProductCollection products;
OrderCollection orders;
EmployeeCollection employees;
SupplierCollection suppliers;
CategoryCollection categories;
WarehouseCollection warehouses;
InventoryCollection inventoryItems;
ShipmentCollection shipments;

void Inventory::display() {
    cout << "========== INVENTORY ITEM ==========" << endl;
    displayEntity();
    cout << "Location: " << location << endl;
    cout << "Product ID: " << productID << endl;
    Product* p = products.GetProduct(productID);
    cout << "Product: " << (p ? p->getProductName() : "Unknown") << endl;
    cout << "Price: $" << (p ? p->getPrice() : 0.0f) << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "====================================" << endl;
}

void Shipment::display() {
    cout << "========== SHIPMENT DETAILS ==========" << endl;
    cout << "Shipment ID: " << shipmentID << endl;
    displayEntity();
    Product* p = products.GetProduct(productID);
    cout << "Product: " << (p ? p->getProductName() : "Unknown") << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Status: " << status << endl;
    cout << "=====================================" << endl;
}

void InventoryCollection::Update(int productID) {
    int index = FindByID(productID);
    if (index != -1) {
        Inventory inv;
        int wid, pid, qty;
        cout << "Enter new Warehouse ID: ";
        cin >> wid;
        clearInputBuffer();
        Warehouse* w = warehouses.GetWarehouse(wid);
        if (w == NULL) {
            cout << "Warehouse not found! Update cancelled.\n";
            return;
        }
        cout << "Enter new Product ID: ";
        cin >> pid;
        clearInputBuffer();
        cout << "Enter new Quantity: ";
        cin >> qty;
        clearInputBuffer();
        inv.setID(wid);
        inv.setName(w->getName());
        inv.setLocation(w->getLocation());
        inv.setCapacity(w->getCapacity());
        inv.setProductID(pid);
        inv.setQuantity(qty);
        inventoryItems[index] = inv;
        cout << "Inventory updated successfully!" << endl;
    }
    else {
        cout << "Inventory item not found!" << endl;
    }
}

void ShipmentCollection::Update(int shipmentID) {
    int index = FindByID(shipmentID);
    if (index != -1) {
        Shipment ship;
        int sid, wid, pid, qty;
        string status;
        cout << "Enter new Shipment ID: ";
        cin >> sid;
        clearInputBuffer();
        cout << "Enter new Warehouse ID: ";
        cin >> wid;
        clearInputBuffer();
        Warehouse* w = warehouses.GetWarehouse(wid);
        if (w == NULL) {
            cout << "Warehouse not found! Update cancelled.\n";
            return;
        }
        cout << "Enter new Product ID: ";
        cin >> pid;
        clearInputBuffer();
        cout << "Enter new Quantity: ";
        cin >> qty;
        clearInputBuffer();
        status = getStringInput("Enter new Status: ");
        ship.setShipmentID(sid);
        ship.setID(wid);
        ship.setName(w->getName());
        ship.setLocation(w->getLocation());
        ship.setCapacity(w->getCapacity());
        ship.setProductID(pid);
        ship.setQuantity(qty);
        ship.setStatus(status);
        shipments[index] = ship;
        cout << "Shipment updated successfully!" << endl;
    }
    else {
        cout << "Shipment not found!" << endl;
    }
}

void customerMenu() {
    int choice;
    int id;
    string name, contact, email, addr;
    Customer c;

    do {
        cout << "\n========================================\n";
        cout << "        CUSTOMER MANAGEMENT MENU\n";
        cout << "========================================\n";
        cout << "1. Add Customer\n";
        cout << "2. Remove Customer\n";
        cout << "3. Update Customer\n";
        cout << "4. Search Customer\n";
        cout << "5. Display All Customers\n";
        cout << "6. Back to Main Menu\n";
        choice = getValidatedMenuChoice(1, 6);

        switch (choice) {
        case 1:
            cout << "\n--- Add Customer ---\n";
            c.setID(customers.getNextID());
            name = getStringInput("Enter Name: ");
            contact = getStringInput("Enter Contact: ");
            email = getStringInput("Enter Email: ");
            addr = getStringInput("Enter Address: ");
            c.setName(name);
            c.setContact(contact);
            c.setEmail(email);
            c.setAddress(addr);
            cout << "Assigned Customer ID: " << c.getID() << endl;
            cout << "\n--- Customer Information ---\n";
            c.display();
            customers.Add(c);
            break;
        case 2:
            cout << "\n--- Remove Customer ---\n";
            id = getValidatedInt("Enter Customer ID to remove: ");
            if (customers.FindByID(id) == -1) {
                cout << "Customer not found!\n";
            }
            else {
                customers.Remove(id);
            }
            break;
        case 3:
            cout << "\n--- Update Customer ---\n";
            id = getValidatedInt("Enter Customer ID to update: ");
            if (customers.FindByID(id) == -1) {
                cout << "Customer not found!\n";
            }
            else {
                customers.Update(id);
            }
            break;
        case 4:
            cout << "\n--- Search Customer ---\n";
            id = getValidatedInt("Enter Customer ID to search: ");
            {
                Customer* c = customers.GetCustomer(id);
                if (c != NULL) {
                    c->display();
                }
                else {
                    cout << "Customer not found!" << endl;
                }
            }
            break;
        case 5:
            customers.DisplayAll();
            break;
        case 6:
            cout << "Returning to Main Menu...\n";
            break;
        }
    } while (choice != 6);
}

void productMenu() {
    if (categories.getCount() == 0) {
        cout << "\nCannot manage products: No categories available. Add a category first (Menu > Manage Category).\n";
        return;
    }
    int choice;
    int id, catId;
    string name, desc;
    float price;
    Product p;

    do {
        cout << "\n========================================\n";
        cout << "        PRODUCT MANAGEMENT MENU\n";
        cout << "========================================\n";
        cout << "1. Add Product\n";
        cout << "2. Remove Product\n";
        cout << "3. Update Product\n";
        cout << "4. Search Product\n";
        cout << "5. Display All Products\n";
        cout << "6. Back to Main Menu\n";
        choice = getValidatedMenuChoice(1, 6);

        switch (choice) {
        case 1:
            cout << "\n--- Add Product ---\n";
            name = getStringInput("Enter Name: ");
            catId = getValidatedInt("Enter Category ID: ");
            if (categories.FindByID(catId) == -1) {
                cout << "Category not found! Cannot add product.\n";
                break;
            }
            price = getValidatedFloat("Enter Price: ");
            desc = getStringInput("Enter Description: ");
            p.setProductID(products.getNextID());
            p.setProductName(name);
            p.setCategoryID(catId);
            p.setPrice(price);
            p.setDescription(desc);
            cout << "Assigned Product ID: " << p.getProductID() << endl;
            cout << "\n--- Product Information ---\n";
            p.displayDetails();
            products.Add(p);
            break;
        case 2:
            cout << "\n--- Remove Product ---\n";
            id = getValidatedInt("Enter Product ID to remove: ");
            if (products.FindByID(id) == -1) {
                cout << "Product not found!\n";
            }
            else {
                products.Remove(id);
            }
            break;
        case 3:
            cout << "\n--- Update Product ---\n";
            id = getValidatedInt("Enter Product ID to update: ");
            if (products.FindByID(id) == -1) {
                cout << "Product not found!\n";
            }
            else {
                int newCatId = getValidatedInt("Enter new Category ID: ");
                if (categories.FindByID(newCatId) == -1) {
                    cout << "Category not found! Update cancelled.\n";
                }
                else {
                    Product* p = products.GetProduct(id);
                    p->setCategoryID(newCatId);
                    p->setProductName(getStringInput("Enter new Name: "));
                    p->setPrice(getValidatedFloat("Enter new Price: "));
                    p->setDescription(getStringInput("Enter new Description: "));
                    cout << "Product updated successfully!" << endl;
                }
            }
            break;
        case 4:
            cout << "\n--- Search Product ---\n";
            id = getValidatedInt("Enter Product ID to search: ");
            {
                Product* p = products.GetProduct(id);
                if (p != NULL) {
                    p->displayDetails();
                }
                else {
                    cout << "Product not found!" << endl;
                }
            }
            break;
        case 5:
            products.DisplayAll();
            break;
        case 6:
            cout << "Returning to Main Menu...\n";
            break;
        }
    } while (choice != 6);
}

void orderMenu() {
    if (customers.getCount() == 0 || products.getCount() == 0) {
        cout << "\nCannot manage orders: Need at least one customer and one product.\n";
        return;
    }
    int choice;
    int id, custId, count;
    string date;
    Order o;

    do {
        cout << "\n========================================\n";
        cout << "        ORDER MANAGEMENT MENU\n";
        cout << "========================================\n";
        cout << "1. Create Order\n";
        cout << "2. Remove Order\n";
        cout << "3. Update Order Status\n";
        cout << "4. Search Order\n";
        cout << "5. Display All Orders\n";
        cout << "6. Back to Main Menu\n";
        choice = getValidatedMenuChoice(1, 6);

        switch (choice) {
        case 1:
            cout << "\n--- Create Order ---\n";
            {
                Order o;
                date = getStringInput("Enter Order Date: ");
                custId = getValidatedInt("Enter Customer ID: ");
                if (customers.FindByID(custId) == -1) {
                    cout << "Customer not found!\n";
                    break;
                }
                count = getValidatedInt("How many products in this order? ");
                o.setOrderID(orders.getNextID());
                o.setOrderDate(date);
                o.setCustomerID(custId);
                for (int i = 0; i < count; i++) {
                    int pid = getValidatedInt("Enter Product ID: ");
                    Product* p = products.GetProduct(pid);
                    if (p != NULL) {
                        o.addProduct(*p);
                    }
                    else {
                        cout << "Product not found! Skipping...\n";
                    }
                }
                orders.Add(o);
                cout << "Assigned Order ID: " << o.getOrderID() << endl;
                cout << "\n--- Order Created ---\n";
                o.displayDetails();
            }
            break;
        case 2:
            cout << "\n--- Remove Order ---\n";
            id = getValidatedInt("Enter Order ID to remove: ");
            if (orders.FindByID(id) == -1) {
                cout << "Order not found!\n";
            }
            else {
                orders.Remove(id);
            }
            break;
        case 3:
            cout << "\n--- Update Order Status ---\n";
            id = getValidatedInt("Enter Order ID to update: ");
            if (orders.FindByID(id) == -1) {
                cout << "Order not found!\n";
            }
            else {
                orders.Update(id);
            }
            break;
        case 4:
            cout << "\n--- Search Order ---\n";
            id = getValidatedInt("Enter Order ID to search: ");
            {
                Order* o = orders.GetOrder(id);
                if (o != NULL) {
                    o->displayDetails();
                }
                else {
                    cout << "Order not found!" << endl;
                }
            }
            break;
        case 5:
            orders.DisplayAll();
            break;
        case 6:
            cout << "Returning to Main Menu...\n";
            break;
        }
    } while (choice != 6);
}

void employeeMenu() {
    int choice;
    int id;
    string name, contact, email, position, city;
    Employee e;

    do {
        cout << "\n========================================\n";
        cout << "        EMPLOYEE MANAGEMENT MENU\n";
        cout << "========================================\n";
        cout << "1. Add Employee\n";
        cout << "2. Remove Employee\n";
        cout << "3. Update Employee\n";
        cout << "4. Search Employee\n";
        cout << "5. Display All Employees\n";
        cout << "6. Back to Main Menu\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            clearInputBuffer();
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            cout << "\n--- Add Employee ---\n";
            cout << "Enter Employee ID: ";
            cin >> id;
            clearInputBuffer();
            name = getStringInput("Enter Name: ");
            contact = getStringInput("Enter Contact: ");
            email = getStringInput("Enter Email: ");
            position = getStringInput("Enter Position: ");
            city = getStringInput("Enter City: ");
            e.setID(id);
            e.setName(name);
            e.setContact(contact);
            e.setEmail(email);
            e.setPosition(position);
            e.setCity(city);
            cout << "\n--- Employee Information ---\n";
            e.display();
            employees.Add(e);
            break;
        case 2:
            cout << "\n--- Remove Employee ---\n";
            cout << "Enter Employee ID to remove: ";
            cin >> id;
            employees.Remove(id);
            break;
        case 3:
            cout << "\n--- Update Employee ---\n";
            cout << "Enter Employee ID to update: ";
            cin >> id;
            employees.Update(id);
            break;
        case 4:
            cout << "\n--- Search Employee ---\n";
            cout << "Enter Employee ID to search: ";
            cin >> id;
            {
                Employee* e = employees.GetEmployee(id);
                if (e != NULL) {
                    e->display();
                }
                else {
                    cout << "Employee not found!" << endl;
                }
            }
            break;
        case 5:
            employees.DisplayAll();
            break;
        case 6:
            cout << "Returning to Main Menu...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);
}

void supplierMenu() {
    int choice;
    int id;
    string name, contact, email, company, city;
    Supplier s;

    do {
        cout << "\n========================================\n";
        cout << "        SUPPLIER MANAGEMENT MENU\n";
        cout << "========================================\n";
        cout << "1. Add Supplier\n";
        cout << "2. Remove Supplier\n";
        cout << "3. Update Supplier\n";
        cout << "4. Search Supplier\n";
        cout << "5. Display All Suppliers\n";
        cout << "6. Back to Main Menu\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            clearInputBuffer();
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
        {
            cout << "\n--- Add Supplier ---\n";
            cout << "Enter Supplier ID: ";
            cin >> id;
            clearInputBuffer();
            name = getStringInput("Enter Name: ");
            contact = getStringInput("Enter Contact: ");
            email = getStringInput("Enter Email: ");
            company = getStringInput("Enter Company: ");
            city = getStringInput("Enter City: ");
            s.setID(id);
            s.setName(name);
            s.setContact(contact);
            s.setEmail(email);
            s.setCompanyName(company);
            {
                Address* addr = new Address();
                addr->setCity(city);
                s.setAddress(addr);
            }
            cout << "\n--- Supplier Information ---\n";
            s.display();
            Address a;
            suppliers.Add(s, a);
            break;
        }
        case 2:
            cout << "\n--- Remove Supplier ---\n";
            cout << "Enter Supplier ID to remove: ";
            cin >> id;
            suppliers.Remove(id);
            break;
        case 3:
            cout << "\n--- Update Supplier ---\n";
            cout << "Enter Supplier ID to update: ";
            cin >> id;
            suppliers.Update(id);
            break;
        case 4:
            cout << "\n--- Search Supplier ---\n";
            cout << "Enter Supplier ID to search: ";
            cin >> id;
            {
                Supplier* s = suppliers.GetSupplier(id);
                if (s != NULL) {
                    s->display();
                }
                else {
                    cout << "Supplier not found!" << endl;
                }
            }
            break;
        case 5:
            suppliers.DisplayAll();
            break;
        case 6:
            cout << "Returning to Main Menu...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);
}

void categoryMenu() {
    int choice;
    int id;
    string name, desc;
    Category c;

    do {
        cout << "\n========================================\n";
        cout << "        CATEGORY MANAGEMENT MENU\n";
        cout << "========================================\n";
        cout << "1. Add Category\n";
        cout << "2. Remove Category\n";
        cout << "3. Update Category\n";
        cout << "4. Search Category\n";
        cout << "5. Display All Categories\n";
        cout << "6. Back to Main Menu\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            clearInputBuffer();
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            cout << "\n--- Add Category ---\n";
            cout << "Enter Category ID: ";
            cin >> id;
            clearInputBuffer();
            name = getStringInput("Enter Name: ");
            desc = getStringInput("Enter Description: ");
            c.setCategoryID(id);
            c.setCategoryName(name);
            c.setDescription(desc);
            cout << "\n--- Category Information ---\n";
            c.displayDetails();
            categories.Add(c);
            break;
        case 2:
            cout << "\n--- Remove Category ---\n";
            cout << "Enter Category ID to remove: ";
            cin >> id;
            categories.Remove(id);
            break;
        case 3:
            cout << "\n--- Update Category ---\n";
            cout << "Enter Category ID to update: ";
            cin >> id;
            categories.Update(id);
            break;
        case 4:
            cout << "\n--- Search Category ---\n";
            cout << "Enter Category ID to search: ";
            cin >> id;
            {
                Category* c = categories.GetCategory(id);
                if (c != NULL) {
                    c->displayDetails();
                }
                else {
                    cout << "Category not found!" << endl;
                }
            }
            break;
        case 5:
            categories.DisplayAll();
            break;
        case 6:
            cout << "Returning to Main Menu...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);
}

void warehouseMenu() {
    int choice;
    int id, capacity;
    string name, location;
    Warehouse w;

    do {
        cout << "\n========================================\n";
        cout << "        WAREHOUSE MANAGEMENT MENU\n";
        cout << "========================================\n";
        cout << "1. Add Warehouse\n";
        cout << "2. Remove Warehouse\n";
        cout << "3. Update Warehouse\n";
        cout << "4. Search Warehouse\n";
        cout << "5. Display All Warehouses\n";
        cout << "6. Back to Main Menu\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            clearInputBuffer();
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            cout << "\n--- Add Warehouse ---\n";
            cout << "Enter Warehouse ID: ";
            cin >> id;
            clearInputBuffer();
            name = getStringInput("Enter Name: ");
            location = getStringInput("Enter Location: ");
            cout << "Enter Capacity: ";
            cin >> capacity;
            clearInputBuffer();
            w.setID(id);
            w.setName(name);
            w.setLocation(location);
            w.setCapacity(capacity);
            cout << "\n--- Warehouse Information ---\n";
            w.display();
            warehouses.Add(w);
            break;
        case 2:
            cout << "\n--- Remove Warehouse ---\n";
            cout << "Enter Warehouse ID to remove: ";
            cin >> id;
            warehouses.Remove(id);
            break;
        case 3:
            cout << "\n--- Update Warehouse ---\n";
            cout << "Enter Warehouse ID to update: ";
            cin >> id;
            warehouses.Update(id);
            break;
        case 4:
            cout << "\n--- Search Warehouse ---\n";
            cout << "Enter Warehouse ID to search: ";
            cin >> id;
            {
                Warehouse* w = warehouses.GetWarehouse(id);
                if (w != NULL) {
                    w->display();
                }
                else {
                    cout << "Warehouse not found!" << endl;
                }
            }
            break;
        case 5:
            warehouses.DisplayAll();
            break;
        case 6:
            cout << "Returning to Main Menu...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);
}

void inventoryMenu() {
    if (warehouses.getCount() == 0 || products.getCount() == 0) {
        cout << "\nCannot manage inventory: Need at least one warehouse and one product.\n";
        return;
    }
    int choice;
    int productID, qty, wid;
    Inventory inv;

    do {
        cout << "\n========================================\n";
        cout << "        INVENTORY MANAGEMENT MENU\n";
        cout << "========================================\n";
        cout << "1. Add Inventory Item\n";
        cout << "2. Remove Inventory Item\n";
        cout << "3. Update Inventory Item\n";
        cout << "4. Search Inventory Item\n";
        cout << "5. Display All Inventory Items\n";
        cout << "6. Back to Main Menu\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            clearInputBuffer();
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            cout << "\n--- Add Inventory Item ---\n";
            cout << "Enter Warehouse ID: ";
            cin >> wid;
            clearInputBuffer();
            {
                Warehouse* w = warehouses.GetWarehouse(wid);
                if (w == NULL) {
                    cout << "Warehouse not found! Cannot add inventory item.\n";
                    break;
                }
                cout << "Enter Product ID: ";
                cin >> productID;
                clearInputBuffer();
                if (products.GetProduct(productID) == NULL) {
                    cout << "Product not found! Cannot add inventory item.\n";
                    break;
                }
                cout << "Enter Quantity: ";
                cin >> qty;
                clearInputBuffer();
                inv.setID(wid);
                inv.setName(w->getName());
                inv.setLocation(w->getLocation());
                inv.setCapacity(w->getCapacity());
                inv.setProductID(productID);
                inv.setQuantity(qty);
                cout << "\n--- Inventory Information ---\n";
                inv.display();
                inventoryItems.Add(inv);
            }
            break;
        case 2:
            cout << "\n--- Remove Inventory Item ---\n";
            cout << "Enter Product ID to remove: ";
            cin >> productID;
            inventoryItems.Remove(productID);
            break;
        case 3:
            cout << "\n--- Update Inventory Item ---\n";
            cout << "Enter Product ID to update: ";
            cin >> productID;
            inventoryItems.Update(productID);
            break;
        case 4:
            cout << "\n--- Search Inventory Item ---\n";
            cout << "Enter Product ID to search: ";
            cin >> productID;
            {
                Inventory* inv = inventoryItems.GetInventory(productID);
                if (inv != NULL) {
                    inv->display();
                }
                else {
                    cout << "Inventory item not found!" << endl;
                }
            }
            break;
        case 5:
            inventoryItems.DisplayAll();
            break;
        case 6:
            cout << "Returning to Main Menu...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);
}

void shipmentMenu() {
    if (warehouses.getCount() == 0 || products.getCount() == 0) {
        cout << "\nCannot manage shipments: Need at least one order, one warehouse, and one product.\n";
        return;
    }
    int choice;
    int shipID, productID, qty, wid;
    string status;
    Shipment ship;

    do {
        cout << "\n========================================\n";
        cout << "        SHIPMENT MANAGEMENT MENU\n";
        cout << "========================================\n";
        cout << "1. Add Shipment\n";
        cout << "2. Remove Shipment\n";
        cout << "3. Update Shipment\n";
        cout << "4. Search Shipment\n";
        cout << "5. Display All Shipments\n";
        cout << "6. Back to Main Menu\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            clearInputBuffer();
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            cout << "\n--- Add Shipment ---\n";
            cout << "Enter Shipment ID: ";
            cin >> shipID;
            clearInputBuffer();
            cout << "Enter Warehouse ID: ";
            cin >> wid;
            clearInputBuffer();
            {
                Warehouse* w = warehouses.GetWarehouse(wid);
                if (w == NULL) {
                    cout << "Warehouse not found! Cannot add shipment.\n";
                    break;
                }
                cout << "Enter Product ID: ";
                cin >> productID;
                clearInputBuffer();
                if (products.GetProduct(productID) == NULL) {
                    cout << "Product not found! Cannot add shipment.\n";
                    break;
                }
                cout << "Enter Quantity: ";
                cin >> qty;
                clearInputBuffer();
                status = getStringInput("Enter Status: ");
                ship.setShipmentID(shipID);
                ship.setID(wid);
                ship.setName(w->getName());
                ship.setLocation(w->getLocation());
                ship.setCapacity(w->getCapacity());
                ship.setProductID(productID);
                ship.setQuantity(qty);
                ship.setStatus(status);
                cout << "\n--- Shipment Information ---\n";
                ship.display();
                shipments.Add(ship);
            }
            break;
        case 2:
            cout << "\n--- Remove Shipment ---\n";
            cout << "Enter Shipment ID to remove: ";
            cin >> shipID;
            shipments.Remove(shipID);
            break;
        case 3:
            cout << "\n--- Update Shipment ---\n";
            cout << "Enter Shipment ID to update: ";
            cin >> shipID;
            shipments.Update(shipID);
            break;
        case 4:
            cout << "\n--- Search Shipment ---\n";
            cout << "Enter Shipment ID to search: ";
            cin >> shipID;
            {
                Shipment* ship = shipments.GetShipment(shipID);
                if (ship != NULL) {
                    ship->display();
                }
                else {
                    cout << "Shipment not found!" << endl;
                }
            }
            break;
        case 5:
            shipments.DisplayAll();
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

    cout << "Loading data from CSV files...\n";
    customers.loadFromCSV("customers.csv");
    products.loadFromCSV("products.csv");
    orders.loadFromCSV("orders.csv");
    employees.loadFromCSV("employees.csv");
    suppliers.loadFromCSV("suppliers.csv");
    categories.loadFromCSV("categories.csv");
    warehouses.loadFromCSV("warehouse.csv");
    inventoryItems.loadFromCSV("inventory.csv");
    shipments.loadFromCSV("shipment.csv");
    cout << "Data loaded successfully.\n";

    do {
        cout << "\n========================================\n";
        cout << "  WAREHOUSE MANAGEMENT SYSTEM\n";
        cout << "========================================\n";

        struct MenuItem { const char* label; void (*action)(); bool enabled; };
        MenuItem items[] = {
            {"Manage Customer",  customerMenu,  true},
            {"Manage Product",   productMenu,   categories.getCount() > 0},
            {"Manage Order",     orderMenu,     customers.getCount() > 0 && products.getCount() > 0},
            {"Manage Employee",  employeeMenu,  true},
            {"Manage Supplier",  supplierMenu,  true},
            {"Manage Category",  categoryMenu,  true},
            {"Manage Warehouse", warehouseMenu, true},
            {"Manage Inventory", inventoryMenu, warehouses.getCount() > 0 && products.getCount() > 0},
            {"Manage Shipment",  shipmentMenu,  orders.getCount() > 0 && warehouses.getCount() > 0 && products.getCount() > 0},
        };
        const int itemCount = 9;
        int exitNum = itemCount + 1;

        for (int i = 0; i < itemCount; i++) {
            cout << i + 1 << ". " << items[i].label;
            if (!items[i].enabled)
                cout << "   [ADD DEPENDENCIES FIRST]";
            cout << "\n";
        }
        cout << exitNum << ". Exit\n";
        choice = getValidatedMenuChoice(1, exitNum);

        if (choice == exitNum) {
            cout << "\nSaving data to CSV files...\n";
            customers.saveToCSV("customers.csv");
            products.saveToCSV("products.csv");
            orders.saveToCSV("orders.csv");
            employees.saveToCSV("employees.csv");
            suppliers.saveToCSV("suppliers.csv");
            categories.saveToCSV("categories.csv");
            warehouses.saveToCSV("warehouse.csv");
            inventoryItems.saveToCSV("inventory.csv");
            shipments.saveToCSV("shipment.csv");
            cout << "Data saved successfully. Exiting program...\n";
            break;
        }
        if (choice >= 1 && choice <= itemCount && items[choice - 1].enabled)
            items[choice - 1].action();
        else if (choice >= 1 && choice <= itemCount)
            cout << "Option unavailable: add the required dependencies first.\n";
    } while (true);

    return 0;
}

