#include <iostream>
#include <vector>
#include <string>
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

    Customer(int id, string name, string contact, string e, string a) {
        customerID = id;
        customerName = name;
        contactNumber = contact;
        email = e;
        address = a;
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

    Product(int id, string name, int catId, float p, int qty, string desc) {
        productID = id;
        productName = name;
        categoryID = catId;
        price = p;
        quantityInStock = qty;
        description = desc;
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

    void updateStock(int quantity) {
        quantityInStock += quantity;
    }

    void display() {
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
    vector<int> productList;
    float totalAmount;
    string orderStatus;

public:
    Order() {
        orderID = 0;
        orderDate = "";
        customerID = 0;
        totalAmount = 0.0;
        orderStatus = "Pending";
    }

    Order(int id, string date, int custID, vector<int> products, float total) {
        orderID = id;
        orderDate = date;
        customerID = custID;
        productList = products;
        totalAmount = total;
        orderStatus = "Created";
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
    vector<int> getProductList() { return productList; }

    void addProduct(int productID) {
        productList.push_back(productID);
    }

    void calculateTotal(float price) {
        totalAmount += price;
    }

    void updateOrderStatus(string newStatus) {
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

    void display() {
        cout << "========== ORDER DETAILS ==========" << endl;
        cout << "Order ID: " << orderID << endl;
        cout << "Order Date: " << orderDate << endl;
        cout << "Customer ID: " << customerID << endl;
        cout << "Product List: ";
        for (int i = 0; i < productList.size(); i++) {
            cout << productList[i] << " ";
        }
        cout << endl;
        cout << "Total Amount: $" << totalAmount << endl;
        cout << "Order Status: " << orderStatus << endl;
        cout << "===================================\n" << endl;
    }
};

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

class Supplier {
private:
    int id;
    string name;
    string contact;
    string email;
public:
    Supplier() { id = 0; name = ""; contact = ""; email = ""; }
    Supplier(int i, string n, string c, string e) { id = i; name = n; contact = c; email = e; }
    void set(int i, string n, string c, string e) { id = i; name = n; contact = c; email = e; }
    int getID() { return id; }
    string getName() { return name; }
    string getContact() { return contact; }
    string getEmail() { return email; }
    void display() { cout << "ID: " << id << " Name: " << name << " Contact: " << contact << " Email: " << email << endl; }
};

class Employee {
private:
    int id;
    string name;
    string position;
    float salary;
public:
    Employee() { id = 0; name = ""; position = ""; salary = 0; }
    Employee(int i, string n, string p, float s) { id = i; name = n; position = p; salary = s; }
    void set(int i, string n, string p, float s) { id = i; name = n; position = p; salary = s; }
    int getID() { return id; }
    string getName() { return name; }
    string getPosition() { return position; }
    float getSalary() { return salary; }
    void display() { cout << "ID: " << id << " Name: " << name << " Position: " << position << " Salary: " << salary << endl; }
};

class Warehouse {
private:
    int warehouseID;
    string location;
    int totalCapacity;
    int availableSpace;

public:
    Warehouse() {
        warehouseID = 0;
        location = "";
        totalCapacity = 0;
        availableSpace = 0;
    }

    Warehouse(int id, string loc, int cap, int space) {
        warehouseID = id;
        location = loc;
        totalCapacity = cap;
        availableSpace = space;
    }

    void setWarehouseID(int id) { warehouseID = id; }
    void setLocation(string loc) { location = loc; }
    void setTotalCapacity(int cap) { totalCapacity = cap; }
    void setAvailableSpace(int space) { availableSpace = space; }

    int getWarehouseID() { return warehouseID; }
    string getLocation() { return location; }
    int getTotalCapacity() { return totalCapacity; }
    int getAvailableSpace() { return availableSpace; }

    void allocateSpace(int space) {
        availableSpace -= space;
    }

    void removeProduct(int space) {
        availableSpace += space;
    }

    void display() {
        cout << "Warehouse ID: " << warehouseID << endl;
        cout << "Location: " << location << endl;
        cout << "Total Capacity: " << totalCapacity << endl;
        cout << "Available Space: " << availableSpace << endl;
    }
};

class Inventory {
private:
    int inventoryID;
    string productList;
    int totalItems;
    string lastUpdatedDate;

public:
    Inventory() {
        inventoryID = 0;
        productList = "";
        totalItems = 0;
        lastUpdatedDate = "";
    }

    Inventory(int id, string list, int items, string date) {
        inventoryID = id;
        productList = list;
        totalItems = items;
        lastUpdatedDate = date;
    }

    void setInventoryID(int id) { inventoryID = id; }
    void setProductList(string list) { productList = list; }
    void setTotalItems(int items) { totalItems = items; }
    void setDate(string date) { lastUpdatedDate = date; }

    int getInventoryID() { return inventoryID; }
    string getProductList() { return productList; }
    int getTotalItems() { return totalItems; }
    string getDate() { return lastUpdatedDate; }

    void updateQuantity(int q) {
        totalItems += q;
    }

    void display() {
        cout << "Inventory ID: " << inventoryID << endl;
        cout << "Products: " << productList << endl;
        cout << "Total Items: " << totalItems << endl;
        cout << "Last Updated: " << lastUpdatedDate << endl;
    }
};

class Shipment {
private:
    int shipmentID;
    int orderID;
    string shipmentDate;
    string deliveryDate;
    string deliveryStatus;

public:
    Shipment() {
        shipmentID = 0;
        orderID = 0;
        shipmentDate = "";
        deliveryDate = "";
        deliveryStatus = "Pending";
    }

    Shipment(int id, int oid, string sDate, string dDate, string status) {
        shipmentID = id;
        orderID = oid;
        shipmentDate = sDate;
        deliveryDate = dDate;
        deliveryStatus = status;
    }

    void setShipmentID(int id) { shipmentID = id; }
    void setOrderID(int oid) { orderID = oid; }
    void setShipmentDate(string d) { shipmentDate = d; }
    void setDeliveryDate(string d) { deliveryDate = d; }
    void setStatus(string s) { deliveryStatus = s; }

    int getShipmentID() { return shipmentID; }
    int getOrderID() { return orderID; }
    string getShipmentDate() { return shipmentDate; }
    string getDeliveryDate() { return deliveryDate; }
    string getStatus() { return deliveryStatus; }

    void confirmDelivery() {
        deliveryStatus = "Delivered";
    }

    void display() {
        cout << "Shipment ID: " << shipmentID << endl;
        cout << "Order ID: " << orderID << endl;
        cout << "Shipment Date: " << shipmentDate << endl;
        cout << "Delivery Date: " << deliveryDate << endl;
        cout << "Status: " << deliveryStatus << endl;
    }
};

vector<Customer> customers;
vector<Product> products;
vector<Order> orders;
vector<Category> categories;
vector<Supplier> suppliers;
vector<Employee> employees;
vector<Warehouse> warehouses;
vector<Inventory> inventories;
vector<Shipment> shipments;

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
        cout << "3. Display All Customers\n";
        cout << "4. Find Customer by ID\n";
        cout << "5. Delete Customer\n";
        cout << "6. Back to Main Menu\n";
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
            customers.push_back(Customer(id, name, contact, email, addr));
            cout << "Customer added successfully!" << endl;
            break;
        case 2:
            cout << "\n--- Update Customer ---\n";
            cout << "Enter Customer ID to update: ";
            cin >> id;
            {
                bool found = false;
                for (int i = 0; i < customers.size(); i++) {
                    if (customers[i].getCustomerID() == id) {
                        cout << "Enter new Name: ";
                        cin >> name;
                        cout << "Enter new Contact Number: ";
                        cin >> contact;
                        cout << "Enter new Email: ";
                        cin >> email;
                        cout << "Enter new Address: ";
                        cin >> addr;
                        customers[i].setCustomerName(name);
                        customers[i].setContactNumber(contact);
                        customers[i].setEmail(email);
                        customers[i].setAddress(addr);
                        cout << "Customer updated successfully!" << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Customer not found!" << endl;
                }
            }
            break;
        case 3:
            cout << "\n--- All Customers ---\n";
            if (customers.empty()) {
                cout << "No customers found." << endl;
            } else {
                for (int i = 0; i < customers.size(); i++) {
                    customers[i].display();
                    cout << "-----------------------------------\n";
                }
            }
            break;
        case 4:
            cout << "Enter Customer ID to find: ";
            cin >> id;
            {
                bool found = false;
                for (int i = 0; i < customers.size(); i++) {
                    if (customers[i].getCustomerID() == id) {
                        customers[i].display();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Customer not found!" << endl;
                }
            }
            break;
        case 5:
            cout << "Enter Customer ID to delete: ";
            cin >> id;
            {
                bool found = false;
                for (int i = 0; i < customers.size(); i++) {
                    if (customers[i].getCustomerID() == id) {
                        customers.erase(customers.begin() + i);
                        cout << "Customer deleted successfully!" << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Customer not found!" << endl;
                }
            }
            break;
        case 6:
            cout << "Returning to Main Menu...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);
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
        cout << "4. Display All Products\n";
        cout << "5. Update Stock\n";
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
            products.push_back(Product(id, name, catId, price, qty, desc));
            cout << "Product added successfully!" << endl;
            break;
        case 2:
            cout << "\n--- Update Product ---\n";
            cout << "Enter Product ID to update: ";
            cin >> id;
            {
                bool found = false;
                for (int i = 0; i < products.size(); i++) {
                    if (products[i].getProductID() == id) {
                        cout << "Enter new Product Name: ";
                        cin >> name;
                        cout << "Enter new Category ID: ";
                        cin >> catId;
                        cout << "Enter new Price: ";
                        cin >> price;
                        cout << "Enter new Quantity: ";
                        cin >> qty;
                        cout << "Enter new Description: ";
                        cin >> desc;
                        products[i].setProductName(name);
                        products[i].setCategoryID(catId);
                        products[i].setPrice(price);
                        products[i].setQuantity(qty);
                        products[i].setDescription(desc);
                        cout << "Product updated successfully!" << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Product not found!" << endl;
                }
            }
            break;
        case 3:
            cout << "Enter Product ID to delete: ";
            cin >> id;
            {
                bool found = false;
                for (int i = 0; i < products.size(); i++) {
                    if (products[i].getProductID() == id) {
                        products.erase(products.begin() + i);
                        cout << "Product deleted successfully!" << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Product not found!" << endl;
                }
            }
            break;
        case 4:
            cout << "\n--- All Products ---\n";
            if (products.empty()) {
                cout << "No products found." << endl;
            } else {
                for (int i = 0; i < products.size(); i++) {
                    products[i].display();
                    cout << "-----------------------------------\n";
                }
            }
            break;
        case 5:
            cout << "Enter Product ID to update stock: ";
            cin >> id;
            cout << "Enter quantity change (positive to add, negative to reduce): ";
            cin >> qty;
            {
                bool found = false;
                for (int i = 0; i < products.size(); i++) {
                    if (products[i].getProductID() == id) {
                        products[i].updateStock(qty);
                        cout << "Stock updated. New quantity: " << products[i].getQuantity() << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Product not found!" << endl;
                }
            }
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
    int id, custId, count, prodId;
    string date;
    float price, total = 0;
    vector<int> prods;

    do {
        cout << "\n========================================\n";
        cout << "        ORDER MANAGEMENT MENU\n";
        cout << "========================================\n";
        cout << "1. Create Order\n";
        cout << "2. Display All Orders\n";
        cout << "3. Update Order Status\n";
        cout << "4. Cancel Order\n";
        cout << "5. Calculate Order Total\n";
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
            prods.clear();
            for (int i = 0; i < count; i++) {
                cout << "Enter Product ID " << i + 1 << ": ";
                cin >> prodId;
                prods.push_back(prodId);
            }
            orders.push_back(Order(id, date, custId, prods, 0));
            cout << "Order created successfully!" << endl;
            break;
        case 2:
            cout << "\n--- All Orders ---\n";
            if (orders.empty()) {
                cout << "No orders found." << endl;
            } else {
                for (int i = 0; i < orders.size(); i++) {
                    orders[i].display();
                }
            }
            break;
        case 3:
            cout << "Enter Order ID: ";
            cin >> id;
            cout << "Enter new status: ";
            cin >> date;
            {
                bool found = false;
                for (int i = 0; i < orders.size(); i++) {
                    if (orders[i].getOrderID() == id) {
                        orders[i].updateOrderStatus(date);
                        cout << "Order status updated!" << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Order not found!" << endl;
                }
            }
            break;
        case 4:
            cout << "Enter Order ID to cancel: ";
            cin >> id;
            {
                bool found = false;
                for (int i = 0; i < orders.size(); i++) {
                    if (orders[i].getOrderID() == id) {
                        orders[i].cancelOrder();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Order not found!" << endl;
                }
            }
            break;
        case 5:
            cout << "Enter Order ID: ";
            cin >> id;
            cout << "Enter total amount: ";
            cin >> total;
            {
                bool found = false;
                for (int i = 0; i < orders.size(); i++) {
                    if (orders[i].getOrderID() == id) {
                        orders[i].setTotalAmount(total);
                        cout << "Total calculated: $" << total << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Order not found!" << endl;
                }
            }
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
    int ch, id;
    string name;
    do {
        cout << "\n===== CATEGORY MENU =====\n";
        cout << "1.Add 2.Update 3.Delete 4.Display 5.Back\n";
        cout << "Enter your choice: ";
        if (!(cin >> ch)) {
            clearInputBuffer();
            cout << "Invalid input!\n";
            continue;
        }
        switch (ch) {
        case 1:
            cout << "Enter Category ID: ";
            cin >> id;
            cout << "Enter Category Name: ";
            cin >> name;
            categories.push_back(Category(id, name));
            cout << "Category Added\n";
            break;
        case 2:
            cout << "Enter Category ID to update: ";
            cin >> id;
            {
                bool found = false;
                for (int i = 0; i < categories.size(); i++) {
                    if (categories[i].getID() == id) {
                        cout << "Enter new Category Name: ";
                        cin >> name;
                        categories[i].set(id, name);
                        cout << "Category Updated\n";
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Category not found!\n";
            }
            break;
        case 3:
            cout << "Enter Category ID to delete: ";
            cin >> id;
            {
                bool found = false;
                for (int i = 0; i < categories.size(); i++) {
                    if (categories[i].getID() == id) {
                        categories.erase(categories.begin() + i);
                        cout << "Category Deleted\n";
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Category not found!\n";
            }
            break;
        case 4:
            for (int i = 0; i < categories.size(); i++) categories[i].display();
            break;
        case 5:
            cout << "Returning to Main Menu...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (ch != 5);
}

void supplierMenu() {
    int ch, id;
    string name, contact, email;
    do {
        cout << "\n===== SUPPLIER MENU =====\n";
        cout << "1.Add 2.Update 3.Delete 4.Display 5.Back\n";
        cout << "Enter your choice: ";
        if (!(cin >> ch)) {
            clearInputBuffer();
            cout << "Invalid input!\n";
            continue;
        }
        switch (ch) {
        case 1:
            cout << "Enter Supplier ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Contact: ";
            cin >> contact;
            cout << "Enter Email: ";
            cin >> email;
            suppliers.push_back(Supplier(id, name, contact, email));
            cout << "Supplier Added\n";
            break;
        case 2:
            cout << "Enter Supplier ID to update: ";
            cin >> id;
            {
                bool found = false;
                for (int i = 0; i < suppliers.size(); i++) {
                    if (suppliers[i].getID() == id) {
                        cout << "Enter new Name: ";
                        cin >> name;
                        cout << "Enter new Contact: ";
                        cin >> contact;
                        cout << "Enter new Email: ";
                        cin >> email;
                        suppliers[i].set(id, name, contact, email);
                        cout << "Supplier Updated\n";
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Supplier not found!\n";
            }
            break;
        case 3:
            cout << "Enter Supplier ID to delete: ";
            cin >> id;
            {
                bool found = false;
                for (int i = 0; i < suppliers.size(); i++) {
                    if (suppliers[i].getID() == id) {
                        suppliers.erase(suppliers.begin() + i);
                        cout << "Supplier Deleted\n";
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Supplier not found!\n";
            }
            break;
        case 4:
            for (int i = 0; i < suppliers.size(); i++) suppliers[i].display();
            break;
        case 5:
            cout << "Returning to Main Menu...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (ch != 5);
}

void employeeMenu() {
    int ch, id;
    string name, pos;
    float salary;
    do {
        cout << "\n===== EMPLOYEE MENU =====\n";
        cout << "1.Add 2.Update 3.Delete 4.Display 5.Back\n";
        cout << "Enter your choice: ";
        if (!(cin >> ch)) {
            clearInputBuffer();
            cout << "Invalid input!\n";
            continue;
        }
        switch (ch) {
        case 1:
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Position: ";
            cin >> pos;
            cout << "Enter Salary: ";
            cin >> salary;
            employees.push_back(Employee(id, name, pos, salary));
            cout << "Employee Added\n";
            break;
        case 2:
            cout << "Enter Employee ID to update: ";
            cin >> id;
            {
                bool found = false;
                for (int i = 0; i < employees.size(); i++) {
                    if (employees[i].getID() == id) {
                        cout << "Enter new Name: ";
                        cin >> name;
                        cout << "Enter new Position: ";
                        cin >> pos;
                        cout << "Enter new Salary: ";
                        cin >> salary;
                        employees[i].set(id, name, pos, salary);
                        cout << "Employee Updated\n";
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Employee not found!\n";
            }
            break;
        case 3:
            cout << "Enter Employee ID to delete: ";
            cin >> id;
            {
                bool found = false;
                for (int i = 0; i < employees.size(); i++) {
                    if (employees[i].getID() == id) {
                        employees.erase(employees.begin() + i);
                        cout << "Employee Deleted\n";
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Employee not found!\n";
            }
            break;
        case 4:
            for (int i = 0; i < employees.size(); i++) employees[i].display();
            break;
        case 5:
            cout << "Returning to Main Menu...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (ch != 5);
}

void warehouseMenu() {
    int choice;
    int id, cap, space;
    string loc;

    do {
        cout << "\n========================================\n";
        cout << "       WAREHOUSE MANAGEMENT MENU\n";
        cout << "========================================\n";
        cout << "1. Add Warehouse\n";
        cout << "2. Update Warehouse\n";
        cout << "3. Display All Warehouses\n";
        cout << "4. Check Capacity\n";
        cout << "5. Allocate Space\n";
        cout << "6. Remove Product\n";
        cout << "7. Back to Main Menu\n";
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
            cout << "Enter Location: ";
            cin >> loc;
            cout << "Enter Total Capacity: ";
            cin >> cap;
            cout << "Enter Available Space: ";
            cin >> space;
            warehouses.push_back(Warehouse(id, loc, cap, space));
            cout << "Warehouse added successfully!" << endl;
            break;
        case 2:
            cout << "\n--- Update Warehouse ---\n";
            cout << "Enter Warehouse ID to update: ";
            cin >> id;
            {
                bool found = false;
                for (int i = 0; i < warehouses.size(); i++) {
                    if (warehouses[i].getWarehouseID() == id) {
                        cout << "Enter new Location: ";
                        cin >> loc;
                        cout << "Enter new Total Capacity: ";
                        cin >> cap;
                        cout << "Enter new Available Space: ";
                        cin >> space;
                        warehouses[i].setLocation(loc);
                        warehouses[i].setTotalCapacity(cap);
                        warehouses[i].setAvailableSpace(space);
                        cout << "Warehouse updated successfully!" << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Warehouse not found!" << endl;
                }
            }
            break;
        case 3:
            cout << "\n--- All Warehouses ---\n";
            if (warehouses.empty()) {
                cout << "No warehouses found." << endl;
            } else {
                for (int i = 0; i < warehouses.size(); i++) {
                    warehouses[i].display();
                    cout << "-----------------------------------\n";
                }
            }
            break;
        case 4:
            cout << "Enter Warehouse ID: ";
            cin >> id;
            {
                bool found = false;
                for (int i = 0; i < warehouses.size(); i++) {
                    if (warehouses[i].getWarehouseID() == id) {
                        cout << "Available Space: " << warehouses[i].getAvailableSpace() << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Warehouse not found!" << endl;
                }
            }
            break;
        case 5:
            cout << "Enter Warehouse ID: ";
            cin >> id;
            cout << "Enter space to allocate: ";
            cin >> space;
            {
                bool found = false;
                for (int i = 0; i < warehouses.size(); i++) {
                    if (warehouses[i].getWarehouseID() == id) {
                        warehouses[i].allocateSpace(space);
                        cout << "Space allocated. Remaining: " << warehouses[i].getAvailableSpace() << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Warehouse not found!" << endl;
                }
            }
            break;
        case 6:
            cout << "Enter Warehouse ID: ";
            cin >> id;
            cout << "Enter space to release: ";
            cin >> space;
            {
                bool found = false;
                for (int i = 0; i < warehouses.size(); i++) {
                    if (warehouses[i].getWarehouseID() == id) {
                        warehouses[i].removeProduct(space);
                        cout << "Space released. Available: " << warehouses[i].getAvailableSpace() << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Warehouse not found!" << endl;
                }
            }
            break;
        case 7:
            cout << "Returning to Main Menu...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 7);
}

void inventoryMenu() {
    int choice;
    int id, items;
    string list, date;

    do {
        cout << "\n========================================\n";
        cout << "        INVENTORY MANAGEMENT MENU\n";
        cout << "========================================\n";
        cout << "1. Add Inventory\n";
        cout << "2. Update Inventory\n";
        cout << "3. Display All Inventories\n";
        cout << "4. Update Quantity\n";
        cout << "5. Check Stock\n";
        cout << "6. Back to Main Menu\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            clearInputBuffer();
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            cout << "\n--- Add Inventory ---\n";
            cout << "Enter Inventory ID: ";
            cin >> id;
            cout << "Enter Product List: ";
            cin >> list;
            cout << "Enter Total Items: ";
            cin >> items;
            cout << "Enter Last Updated Date: ";
            cin >> date;
            inventories.push_back(Inventory(id, list, items, date));
            cout << "Item added successfully!" << endl;
            break;
        case 2:
            cout << "\n--- Update Inventory ---\n";
            cout << "Enter Inventory ID to update: ";
            cin >> id;
            {
                bool found = false;
                for (int i = 0; i < inventories.size(); i++) {
                    if (inventories[i].getInventoryID() == id) {
                        cout << "Enter new Product List: ";
                        cin >> list;
                        cout << "Enter new Total Items: ";
                        cin >> items;
                        cout << "Enter new Last Updated Date: ";
                        cin >> date;
                        inventories[i].setProductList(list);
                        inventories[i].setTotalItems(items);
                        inventories[i].setDate(date);
                        cout << "Inventory updated successfully!" << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Inventory not found!" << endl;
                }
            }
            break;
        case 3:
            cout << "\n--- All Inventories ---\n";
            if (inventories.empty()) {
                cout << "No inventories found." << endl;
            } else {
                for (int i = 0; i < inventories.size(); i++) {
                    inventories[i].display();
                    cout << "-----------------------------------\n";
                }
            }
            break;
        case 4:
            cout << "Enter Inventory ID: ";
            cin >> id;
            cout << "Enter quantity change (positive to add, negative to reduce): ";
            cin >> items;
            {
                bool found = false;
                for (int i = 0; i < inventories.size(); i++) {
                    if (inventories[i].getInventoryID() == id) {
                        inventories[i].updateQuantity(items);
                        cout << "Quantity updated: " << inventories[i].getTotalItems() << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Inventory not found!" << endl;
                }
            }
            break;
        case 5:
            cout << "Enter Inventory ID: ";
            cin >> id;
            {
                bool found = false;
                for (int i = 0; i < inventories.size(); i++) {
                    if (inventories[i].getInventoryID() == id) {
                        cout << "Stock Level: " << inventories[i].getTotalItems() << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Inventory not found!" << endl;
                }
            }
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
    int choice;
    int sid, oid;
    string sDate, dDate, status;

    do {
        cout << "\n========================================\n";
        cout << "        SHIPMENT MANAGEMENT MENU\n";
        cout << "========================================\n";
        cout << "1. Create Shipment\n";
        cout << "2. Update Status\n";
        cout << "3. Display All Shipments\n";
        cout << "4. Track Shipment\n";
        cout << "5. Confirm Delivery\n";
        cout << "6. Back to Main Menu\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            clearInputBuffer();
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            cout << "\n--- Create Shipment ---\n";
            cout << "Enter Shipment ID: ";
            cin >> sid;
            cout << "Enter Order ID: ";
            cin >> oid;
            cout << "Enter Shipment Date: ";
            cin >> sDate;
            cout << "Enter Delivery Date: ";
            cin >> dDate;
            cout << "Enter Status: ";
            cin >> status;
            shipments.push_back(Shipment(sid, oid, sDate, dDate, status));
            cout << "Shipment created successfully!" << endl;
            break;
        case 2:
            cout << "Enter Shipment ID: ";
            cin >> sid;
            cout << "Enter new status: ";
            cin >> status;
            {
                bool found = false;
                for (int i = 0; i < shipments.size(); i++) {
                    if (shipments[i].getShipmentID() == sid) {
                        shipments[i].setStatus(status);
                        cout << "Status updated to: " << status << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Shipment not found!" << endl;
                }
            }
            break;
        case 3:
            cout << "\n--- All Shipments ---\n";
            if (shipments.empty()) {
                cout << "No shipments found." << endl;
            } else {
                for (int i = 0; i < shipments.size(); i++) {
                    shipments[i].display();
                    cout << "-----------------------------------\n";
                }
            }
            break;
        case 4:
            cout << "Enter Shipment ID: ";
            cin >> sid;
            {
                bool found = false;
                for (int i = 0; i < shipments.size(); i++) {
                    if (shipments[i].getShipmentID() == sid) {
                        cout << "Shipment Status: " << shipments[i].getStatus() << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Shipment not found!" << endl;
                }
            }
            break;
        case 5:
            cout << "Enter Shipment ID: ";
            cin >> sid;
            {
                bool found = false;
                for (int i = 0; i < shipments.size(); i++) {
                    if (shipments[i].getShipmentID() == sid) {
                        shipments[i].confirmDelivery();
                        cout << "Delivery confirmed!" << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Shipment not found!" << endl;
                }
            }
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
        cout << "4. Manage Category\n";
        cout << "5. Manage Supplier\n";
        cout << "6. Manage Employee\n";
        cout << "7. Manage Warehouse\n";
        cout << "8. Manage Inventory\n";
        cout << "9. Manage Shipment\n";
        cout << "10. Exit\n";
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
            categoryMenu();
            break;
        case 5:
            supplierMenu();
            break;
        case 6:
            employeeMenu();
            break;
        case 7:
            warehouseMenu();
            break;
        case 8:
            inventoryMenu();
            break;
        case 9:
            shipmentMenu();
            break;
        case 10:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 10);

    return 0;
}
