# Warehouse Management System - Code Explanation

This document explains the `main.cpp` code line by line with examples.

---

## Table of Contents
1. [Header Includes](#1-header-includes)
2. [Helper Function](#2-helper-function)
3. [Class Definitions](#3-class-definitions)
4. [Global Vectors](#4-global-vectors)
5. [Menu Functions](#5-menu-functions)
6. [Main Function](#6-main-function)

---

## 1. Header Includes

### Line 1: `#include <iostream>`
- **What**: Includes input/output library
- **Purpose**: Enables `cout` (print) and `cin` (input)
- **Example**:
  ```cpp
  cout << "Hello!";  // Prints to screen
  cin >> variable;   // Gets user input
  ```

### Line 2: `#include <vector>`
- **What**: Includes vector container library
- **Purpose**: Enables dynamic arrays (vectors) to store multiple objects
- **Example**:
  ```cpp
  vector<int> numbers;    // Creates empty vector
  numbers.push_back(5);  // Adds 5 to vector: [5]
  numbers.push_back(10);  // Adds 10: [5, 10]
  ```

### Line 3: `#include <string>`
- **What**: Includes string library
- **Purpose**: Enables `string` data type for text
- **Example**:
  ```cpp
  string name = "John";  // Text variable
  ```

### Line 4: `using namespace std;`
- **What**: Uses standard namespace
- **Purpose**: Shortens code - `cout` instead of `std::cout`
- **Example**:
  ```cpp
  // Without: std::cout << "Hello";
  // With:    cout << "Hello";
  ```

---

## 2. Helper Function

### Lines 6-9: `clearInputBuffer()`

```cpp
void clearInputBuffer() {
    cin.clear();
    cin.ignore(1000, '\n');
}
```

- **Purpose**: Fixes input errors when user enters wrong data type
- **How it works**:
  - `cin.clear()` - Clears error flags after failed input
  - `cin.ignore(1000, '\n')` - Removes bad input from buffer

**Example**:
```
User enters "abc" when asked for number
cin >> choice   // FAILS - can't read "abc" into number
clearInputBuffer()  // Fixes the error
```

---

## 3. Class Definitions

### Lines 11-55: `Customer` Class

#### Private Members (Lines 12-17)
```cpp
private:
    int customerID;
    string customerName;
    string contactNumber;
    string email;
    string address;
```
- **Data stored**: Each customer has these attributes

#### Constructors (Lines 20-34)
- **Default Constructor** (Lines 20-26): Creates empty Customer
- **Parameterized Constructor** (Lines 28-34): Creates Customer with values

**Example**:
```cpp
Customer c1;                        // Empty customer
Customer c2(1, "John", "555-1234", "john@email.com", "123 Main St");
                                     // Customer with data
```

#### Setters (Lines 36-40)
```cpp
void setCustomerID(int id) { customerID = id; }
void setCustomerName(string name) { customerName = name; }
// ...
```
- **Purpose**: Set values to private members

#### Getters (Lines 42-46)
```cpp
int getCustomerID() { return customerID; }
string getCustomerName() { return customerName; }
// ...
```
- **Purpose**: Get/retrieve values from private members

#### Display Method (Lines 48-54)
```cpp
void display() {
    cout << "Customer ID: " << customerID << endl;
    // ...
}
```
- **Purpose**: Print customer information

**Example Output**:
```
Customer ID: 1
Name: John
Contact: 555-1234
Email: john@email.com
Address: 123 Main St
```

---

### Lines 57-112: `Product` Class

```cpp
class Product {
private:
    int productID;
    string productName;
    int categoryID;
    float price;
    int quantityInStock;
    string description;
public:
    // Constructor, setters, getters, methods
};
```

**Example**:
```cpp
Product p1(101, "Laptop", 1, 999.99, 10, "Gaming laptop");
cout << p1.getProductName();  // Output: Laptop
cout << p1.getPrice();        // Output: 999.99
```

---

### Lines 114-191: `Order` Class

```cpp
class Order {
private:
    int orderID;
    string orderDate;
    int customerID;
    vector<int> productList;    // Dynamic array of product IDs
    float totalAmount;
    string orderStatus;
public:
    // Constructor, setters, getters, methods
};
```

**Key Feature**: Uses `vector<int>` for product list (can hold any number of products)

**Example**:
```cpp
vector<int> prods = {101, 102, 103};  // 3 products
Order o1(1, "2024-01-15", 5, prods, 299.99);
  // Order #1, date 2024-01-15, customer #5, products [101,102,103], total $299.99
```

---

### Lines 193-204: `Category` Class

Simple class for product categories:

```cpp
class Category {
private:
    int id;
    string name;
public:
    Category() { id = 0; name = ""; }
    Category(int i, string n) { id = i; name = n; }
    void set(int i, string n) { id = i; name = n; }
    int getID() { return id; }
    string getName() { return name; }
    void display() { cout << "ID: " << id << " Name: " << name << endl; }
};
```

**Example**:
```cpp
Category cat1(1, "Electronics");
cat1.display();
// Output: ID: 1 Name: Electronics
```

---

### Lines 206-221: `Supplier` Class

```cpp
class Supplier {
private:
    int id;
    string name;
    string contact;
    string email;
};
```

**Example**:
```cpp
Supplier s1(1, "Acme Corp", "555-1234", "sales@acme.com");
```

---

### Lines 223-238: `Employee` Class

```cpp
class Employee {
private:
    int id;
    string name;
    string position;
    float salary;
};
```

**Example**:
```cpp
Employee e1(101, "Jane Doe", "Manager", 5000.00);
e1.display();
// Output: ID: 101 Name: Jane Doe Position: Manager Salary: 5000
```

---

### Lines 240-286: `Warehouse` Class

```cpp
class Warehouse {
private:
    int warehouseID;
    string location;
    int totalCapacity;
    int availableSpace;
public:
    void allocateSpace(int space) { availableSpace -= space; }
    void removeProduct(int space) { availableSpace += space; }
};
```

**Example**:
```cpp
Warehouse w1(1, "New York", 1000, 500);
w1.allocateSpace(200);   // availableSpace = 300
w1.removeProduct(100);   // availableSpace = 400
```

---

### Lines 288-330: `Inventory` Class

```cpp
class Inventory {
private:
    int inventoryID;
    string productList;
    int totalItems;
    string lastUpdatedDate;
public:
    void updateQuantity(int q) { totalItems += q; }
};
```

**Example**:
```cpp
Inventory inv1(1, "Laptops", 50, "2024-01-15");
inv1.updateQuantity(10);  // totalItems = 60
inv1.updateQuantity(-5);  // totalItems = 55
```

---

### Lines 332-380: `Shipment` Class

```cpp
class Shipment {
private:
    int shipmentID;
    int orderID;
    string shipmentDate;
    string deliveryDate;
    string deliveryStatus;
public:
    void confirmDelivery() { deliveryStatus = "Delivered"; }
};
```

**Example**:
```cpp
Shipment ship1(1, 100, "2024-01-15", "2024-01-20", "Pending");
ship1.confirmDelivery();
// deliveryStatus is now "Delivered"
```

---

## 4. Global Vectors

### Lines 382-390

```cpp
vector<Customer> customers;
vector<Product> products;
vector<Order> orders;
vector<Category> categories;
vector<Supplier> suppliers;
vector<Employee> employees;
vector<Warehouse> warehouses;
vector<Inventory> inventories;
vector<Shipment> shipments;
```

- **Purpose**: Store all data in memory during program execution
- **Example**:
  ```cpp
  customers.push_back(Customer(1, "John", "555-1234", "john@email.com", "123 Main St"));
  // customers vector now has 1 customer
  ```

---

## 5. Menu Functions

### Lines 392-513: `customerMenu()`

Manages customer operations:

```
1. Add Customer    -> Creates new customer and stores in vector
2. Update Customer -> Finds and modifies existing customer
3. Display All Customers -> Shows all customers in vector
4. Find Customer by ID -> Searches for specific customer
5. Delete Customer -> Removes customer from vector
6. Back to Main Menu
```

**Example Run - Adding Customer**:
```cpp
case 1:
    cout << "Enter Customer ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;
    // ... get other fields
    customers.push_back(Customer(id, name, contact, email, addr));
    // Adds Customer object to customers vector
```

**Example Run - Finding Customer**:
```cpp
case 4:
    cout << "Enter Customer ID to find: ";
    cin >> id;
    for (int i = 0; i < customers.size(); i++) {
        if (customers[i].getCustomerID() == id) {
            customers[i].display();  // Found! Show details
            break;
        }
    }
```

**Example Run - Deleting Customer**:
```cpp
case 5:
    for (int i = 0; i < customers.size(); i++) {
        if (customers[i].getCustomerID() == id) {
            customers.erase(customers.begin() + i);  // Remove from vector
            break;
        }
    }
```

---

### Lines 515-645: `productMenu()`

Similar to customerMenu but for products:

```
1. Add Product
2. Update Product
3. Delete Product
4. Display All Products
5. Update Stock (add/remove quantity)
6. Back
```

**Example - Update Stock**:
```cpp
case 5:
    cout << "Enter Product ID to update stock: ";
    cin >> id;
    cout << "Enter quantity change (positive to add, negative to reduce): ";
    cin >> qty;
    for (int i = 0; i < products.size(); i++) {
        if (products[i].getProductID() == id) {
            products[i].updateStock(qty);  // Modifies quantity
            break;
        }
    }
```

---

### Lines 647-765: `orderMenu()`

```
1. Create Order
2. Display All Orders
3. Update Order Status
4. Cancel Order
5. Calculate Order Total
6. Back
```

**Example - Create Order**:
```cpp
case 1:
    cout << "Enter number of products: ";
    cin >> count;
    prods.clear();  // Clear previous products
    for (int i = 0; i < count; i++) {
        cin >> prodId;
        prods.push_back(prodId);  // Add each product ID
    }
    orders.push_back(Order(id, date, custId, prods, 0));
    // Creates order with list of products
```

---

### Lines 767-832: `categoryMenu()`

Simple menu:
```
1. Add Category
2. Update Category
3. Delete Category
4. Display All
5. Back
```

---

### Lines 834-907: `supplierMenu()`

Same pattern as categoryMenu for suppliers

---

### Lines 909-983: `employeeMenu()`

Same pattern for employees

---

### Lines 985-1124: `warehouseMenu()`

```
1. Add Warehouse
2. Update Warehouse
3. Display All Warehouses
4. Check Capacity
5. Allocate Space
6. Remove Product
7. Back
```

---

### Lines 1126-1244: `inventoryMenu()`

```
1. Add Inventory
2. Update Inventory
3. Display All
4. Update Quantity
5. Check Stock
6. Back
```

---

### Lines 1246-1357: `shipmentMenu()`

```
1. Create Shipment
2. Update Status
3. Display All Shipments
4. Track Shipment
5. Confirm Delivery
6. Back
```

---

## 6. Main Function

### Lines 1360-1421: `main()`

```cpp
int main() {
    int choice;

    do {
        // Show main menu
        cout << "1. Manage Customer\n";
        // ... other options 2-9
        cout << "10. Exit\n";
        
        cin >> choice;
        
        switch (choice) {
        case 1: customerMenu(); break;
        case 2: productMenu(); break;
        case 3: orderMenu(); break;
        case 4: categoryMenu(); break;
        case 5: supplierMenu(); break;
        case 6: employeeMenu(); break;
        case 7: warehouseMenu(); break;
        case 8: inventoryMenu(); break;
        case 9: shipmentMenu(); break;
        case 10: exit; break;
        }
    } while (choice != 10);

    return 0;
}
```

**Program Flow**:
1. Display main menu
2. Get user choice
3. Call appropriate menu function
4. When menu returns, show main menu again
5. Exit when user enters 10

**Example Session**:
```
========================================
  WAREHOUSE MANAGEMENT SYSTEM
========================================
1. Manage Customer
2. Manage Product
...
Enter your choice: 1

        CUSTOMER MANAGEMENT MENU
========================================
1. Add Customer
2. Update Customer
...
Enter your choice: 1

--- Add Customer ---
Enter Customer ID: 1
Enter Name: John Doe
Enter Contact Number: 555-1234
Enter Email: john@email.com
Enter Address: 123 Main St
Customer added successfully!
```

---

## Summary

This program demonstrates:

| Concept | Example |
|---------|---------|
| **Classes** | `Customer`, `Product`, `Order`, etc. - group related data |
| **Vectors** | Store multiple objects: `vector<Customer> customers` |
| **CRUD Operations** | Create, Read, Update, Delete for each entity |
| **Encapsulation** | Private members + public getters/setters |
| **Menu System** | do-while loop with switch statement |
| **Input Validation** | `if (!(cin >> choice))` + `clearInputBuffer()` |

### Data Flow

```
User Input --> Menu Function --> Class Constructor --> push_back() --> Vector
                                                              |
Vector --> display() <-- Customer Data <-- Getter Methods <---------+
```