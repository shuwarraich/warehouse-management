#include <iostream>
#include <string>
using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(1000, '\n');
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

    void display() {
        cout << "ID: " << productID << " | Name: " << productName
             << " | Price: $" << price << " | Stock: " << quantityInStock << endl;
    }

    void displayDetails() {
        cout << "========== PRODUCT DETAILS ==========" << endl;
        cout << "ID: " << productID << endl;
        cout << "Name: " << productName << endl;
        cout << "Category ID: " << categoryID << endl;
        cout << "Price: $" << price << endl;
        cout << "Stock: " << quantityInStock << endl;
        cout << "Description: " << description << endl;
        cout << "======================================" << endl;
    }
};

class Order {
private:
    int orderID;
    string orderDate;
    int customerID;
    Product products[50];
    int productCount;
    float totalAmount;
    string orderStatus;

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
    void setTotalAmount(float amount) { totalAmount = amount; }
    void addProduct(Product p) {
        if (productCount < 50) {
            products[productCount] = p;
            productCount++;
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
    int itemID;
    string itemName;
    int quantity;
    double price;
    string description;

public:
    Inventory() : Warehouse() {
        itemID = 0; itemName = ""; quantity = 0; price = 0.0; description = "";
    }
    void setItemID(int id) { itemID = id; }
    void setItemName(string n) { itemName = n; }
    void setQuantity(int q) { quantity = q; }
    void setPrice(double p) { price = p; }
    void setDescription(string d) { description = d; }
    int getItemID() { return itemID; }
    string getItemName() { return itemName; }
    int getQuantity() { return quantity; }
    double getPrice() { return price; }
    string getDescription() { return description; }

    void display() {
        cout << "========== INVENTORY ITEM ==========" << endl;
        displayEntity();
        cout << "Location: " << location << endl;
        cout << "Item ID: " << itemID << endl;
        cout << "Item Name: " << itemName << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Description: " << description << endl;
        cout << "====================================" << endl;
    }
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

    void display() {
        cout << "========== SHIPMENT DETAILS ==========" << endl;
        cout << "Shipment ID: " << shipmentID << endl;
        displayEntity();
        cout << "Item: " << itemName << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Status: " << status << endl;
        cout << "=====================================" << endl;
    }
};

class CustomerCollection {
private:
    Customer customers[100];
    int count;

public:
    CustomerCollection() {
        count = 0;
    }

    void Add(Customer c) {
        if (count < 100) {
            customers[count] = c;
            count++;
            cout << "Customer added successfully! (Total: " << count << ")" << endl;
        } else {
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
        } else {
            cout << "Customer not found!" << endl;
        }
    }

    void Update(int id) {
        int index = FindByID(id);
        if (index != -1) {
            Customer c;
            int cid;
            string name, contact, email, addr;
            cout << "Enter new Customer ID: ";
            cin >> cid;
            clearInputBuffer();
            name = getStringInput("Enter new Name: ");
            contact = getStringInput("Enter new Contact: ");
            email = getStringInput("Enter new Email: ");
            addr = getStringInput("Enter new Address: ");
            c.setID(cid);
            c.setName(name);
            c.setContact(contact);
            c.setEmail(email);
            c.setAddress(addr);
            customers[index] = c;
            cout << "Customer updated successfully!" << endl;
        } else {
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
};

class ProductCollection {
private:
    Product products[100];
    int count;

public:
    ProductCollection() {
        count = 0;
    }

    void Add(Product p) {
        if (count < 100) {
            products[count] = p;
            count++;
            cout << "Product added successfully! (Total: " << count << ")" << endl;
        } else {
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
        } else {
            cout << "Product not found!" << endl;
        }
    }

    void Update(int id) {
        int index = FindByID(id);
        if (index != -1) {
            Product p;
            int pid, catId, qty;
            string name, desc;
            float price;
            cout << "Enter new Product ID: ";
            cin >> pid;
            clearInputBuffer();
            name = getStringInput("Enter new Name: ");
            cout << "Enter new Category ID: ";
            cin >> catId;
            cout << "Enter new Price: ";
            cin >> price;
            cout << "Enter new Quantity: ";
            cin >> qty;
            clearInputBuffer();
            desc = getStringInput("Enter new Description: ");
            p.setProductID(pid);
            p.setProductName(name);
            p.setCategoryID(catId);
            p.setPrice(price);
            p.setQuantity(qty);
            p.setDescription(desc);
            products[index] = p;
            cout << "Product updated successfully!" << endl;
        } else {
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
};

class OrderCollection {
private:
    Order orders[100];
    int count;

public:
    OrderCollection() {
        count = 0;
    }

    void Add(Order o) {
        if (count < 100) {
            orders[count] = o;
            count++;
            cout << "Order added successfully! (Total: " << count << ")" << endl;
        } else {
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
        } else {
            cout << "Order not found!" << endl;
        }
    }

    void Update(int id) {
        int index = FindByID(id);
        if (index != -1) {
            string status;
            cout << "Enter new status: ";
            cin >> status;
            orders[index].setOrderStatus(status);
            cout << "Order updated successfully!" << endl;
        } else {
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
};

class EmployeeCollection {
private:
    Employee employees[100];
    int count;

public:
    EmployeeCollection() { count = 0; }

    void Add(Employee e) {
        if (count < 100) {
            employees[count] = e;
            count++;
            cout << "Employee added successfully! (Total: " << count << ")" << endl;
        } else {
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
        } else {
            cout << "Employee not found!" << endl;
        }
    }

    void Update(int id) {
        int index = FindByID(id);
        if (index != -1) {
            Employee e;
            int eid;
            string name, contact, email, position, city;
            cout << "Enter new Employee ID: ";
            cin >> eid;
            clearInputBuffer();
            name = getStringInput("Enter new Name: ");
            contact = getStringInput("Enter new Contact: ");
            email = getStringInput("Enter new Email: ");
            position = getStringInput("Enter new Position: ");
            city = getStringInput("Enter new City: ");
            e.setID(eid);
            e.setName(name);
            e.setContact(contact);
            e.setEmail(email);
            e.setPosition(position);
            e.setCity(city);
            employees[index] = e;
            cout << "Employee updated successfully!" << endl;
        } else {
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

    int getCount() { return count; }
};

class SupplierCollection {
private:
    Supplier suppliers[100];
    int count;

public:
    SupplierCollection() { count = 0; }

    void Add(Supplier s) {
        if (count < 100) {
            suppliers[count] = s;
            count++;
            cout << "Supplier added successfully! (Total: " << count << ")" << endl;
        } else {
            cout << "Collection is full!" << endl;
        }
    }

    void Remove(int id) {
        int index = FindByID(id);
        if (index != -1) {
            for (int i = index; i < count - 1; i++) {
                suppliers[i] = suppliers[i + 1];
            }
            count--;
            cout << "Supplier removed successfully!" << endl;
        } else {
            cout << "Supplier not found!" << endl;
        }
    }

    void Update(int id) {
        int index = FindByID(id);
        if (index != -1) {
            Supplier s;
            int sid;
            string name, contact, email, company, city;
            cout << "Enter new Supplier ID: ";
            cin >> sid;
            clearInputBuffer();
            name = getStringInput("Enter new Name: ");
            contact = getStringInput("Enter new Contact: ");
            email = getStringInput("Enter new Email: ");
            company = getStringInput("Enter new Company: ");
            city = getStringInput("Enter new City: ");
            s.setID(sid);
            s.setName(name);
            s.setContact(contact);
            s.setEmail(email);
            s.setCompanyName(company);
            Address* addr = new Address();
            addr->setCity(city);
            s.setAddress(addr);
            suppliers[index] = s;
            cout << "Supplier updated successfully!" << endl;
        } else {
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

    int getCount() { return count; }
};

class CategoryCollection {
private:
    Category categories[100];
    int count;

public:
    CategoryCollection() { count = 0; }

    void Add(Category c) {
        if (count < 100) {
            categories[count] = c;
            count++;
            cout << "Category added successfully! (Total: " << count << ")" << endl;
        } else {
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
        } else {
            cout << "Category not found!" << endl;
        }
    }

    void Update(int id) {
        int index = FindByID(id);
        if (index != -1) {
            Category c;
            int cid;
            string name, desc;
            cout << "Enter new Category ID: ";
            cin >> cid;
            clearInputBuffer();
            name = getStringInput("Enter new Name: ");
            desc = getStringInput("Enter new Description: ");
            c.setCategoryID(cid);
            c.setCategoryName(name);
            c.setDescription(desc);
            categories[index] = c;
            cout << "Category updated successfully!" << endl;
        } else {
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
        cout << "===================================" << endl;
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

    int getCount() { return count; }
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
        } else {
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
        } else {
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
        } else {
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
        } else {
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
        } else {
            cout << "Inventory item not found!" << endl;
        }
    }

    void Update(int itemID) {
        int index = FindByID(itemID);
        if (index != -1) {
            Inventory inv;
            int wid, cap, iid, qty;
            string wname, location, iname, desc;
            double price;
            cout << "Enter new Warehouse ID: ";
            cin >> wid;
            clearInputBuffer();
            wname = getStringInput("Enter new Warehouse Name: ");
            location = getStringInput("Enter new Location: ");
            cout << "Enter new Capacity: ";
            cin >> cap;
            clearInputBuffer();
            cout << "Enter new Item ID: ";
            cin >> iid;
            clearInputBuffer();
            iname = getStringInput("Enter new Item Name: ");
            cout << "Enter new Price: ";
            cin >> price;
            clearInputBuffer();
            cout << "Enter new Quantity: ";
            cin >> qty;
            clearInputBuffer();
            desc = getStringInput("Enter new Description: ");
            inv.setID(wid);
            inv.setName(wname);
            inv.setLocation(location);
            inv.setCapacity(cap);
            inv.setItemID(iid);
            inv.setItemName(iname);
            inv.setPrice(price);
            inv.setQuantity(qty);
            inv.setDescription(desc);
            inventoryItems[index] = inv;
            cout << "Inventory updated successfully!" << endl;
        } else {
            cout << "Inventory item not found!" << endl;
        }
    }

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

    int FindByID(int itemID) {
        for (int i = 0; i < count; i++) {
            if (inventoryItems[i].getItemID() == itemID) {
                return i;
            }
        }
        return -1;
    }

    Inventory* GetInventory(int itemID) {
        int index = FindByID(itemID);
        if (index != -1) {
            return &inventoryItems[index];
        }
        return NULL;
    }

    int getCount() { return count; }
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
        } else {
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
        } else {
            cout << "Shipment not found!" << endl;
        }
    }

    void Update(int shipmentID) {
        int index = FindByID(shipmentID);
        if (index != -1) {
            Shipment ship;
            int sid, wid, cap, iid, qty;
            string wname, location, iname, status;
            double price;
            cout << "Enter new Shipment ID: ";
            cin >> sid;
            clearInputBuffer();
            cout << "Enter new Warehouse ID: ";
            cin >> wid;
            clearInputBuffer();
            wname = getStringInput("Enter new Warehouse Name: ");
            location = getStringInput("Enter new Location: ");
            cout << "Enter new Capacity: ";
            cin >> cap;
            clearInputBuffer();
            cout << "Enter new Item ID: ";
            cin >> iid;
            clearInputBuffer();
            iname = getStringInput("Enter new Item Name: ");
            cout << "Enter new Price: ";
            cin >> price;
            clearInputBuffer();
            cout << "Enter new Quantity: ";
            cin >> qty;
            clearInputBuffer();
            status = getStringInput("Enter new Status: ");
            ship.setShipmentID(sid);
            ship.setID(wid);
            ship.setName(wname);
            ship.setLocation(location);
            ship.setCapacity(cap);
            ship.setItemID(iid);
            ship.setItemName(iname);
            ship.setPrice(price);
            ship.setQuantity(qty);
            ship.setStatus(status);
            shipments[index] = ship;
            cout << "Shipment updated successfully!" << endl;
        } else {
            cout << "Shipment not found!" << endl;
        }
    }

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
            clearInputBuffer();
            name = getStringInput("Enter Name: ");
            contact = getStringInput("Enter Contact: ");
            email = getStringInput("Enter Email: ");
            addr = getStringInput("Enter Address: ");
            c.setID(id);
            c.setName(name);
            c.setContact(contact);
            c.setEmail(email);
            c.setAddress(addr);
            cout << "\n--- Customer Information ---\n";
            c.display();
            customers.Add(c);
            break;
        case 2:
            cout << "\n--- Remove Customer ---\n";
            cout << "Enter Customer ID to remove: ";
            cin >> id;
            customers.Remove(id);
            break;
        case 3:
            cout << "\n--- Update Customer ---\n";
            cout << "Enter Customer ID to update: ";
            cin >> id;
            customers.Update(id);
            break;
        case 4:
            cout << "\n--- Search Customer ---\n";
            cout << "Enter Customer ID to search: ";
            cin >> id;
            {
                Customer* c = customers.GetCustomer(id);
                if (c != NULL) {
                    c->display();
                } else {
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
            clearInputBuffer();
            name = getStringInput("Enter Name: ");
            cout << "Enter Category ID: ";
            cin >> catId;
            cout << "Enter Price: ";
            cin >> price;
            cout << "Enter Quantity: ";
            cin >> qty;
            clearInputBuffer();
            desc = getStringInput("Enter Description: ");
            p.setProductID(id);
            p.setProductName(name);
            p.setCategoryID(catId);
            p.setPrice(price);
            p.setQuantity(qty);
            p.setDescription(desc);
            cout << "\n--- Product Information ---\n";
            p.displayDetails();
            products.Add(p);
            break;
        case 2:
            cout << "\n--- Remove Product ---\n";
            cout << "Enter Product ID to remove: ";
            cin >> id;
            products.Remove(id);
            break;
        case 3:
            cout << "\n--- Update Product ---\n";
            cout << "Enter Product ID to update: ";
            cin >> id;
            products.Update(id);
            break;
        case 4:
            cout << "\n--- Search Product ---\n";
            cout << "Enter Product ID to search: ";
            cin >> id;
            {
                Product* p = products.GetProduct(id);
                if (p != NULL) {
                    p->displayDetails();
                } else {
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
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);
}

void orderMenu() {
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
            cout << "How many products in this order? ";
            cin >> count;
            o.setOrderID(id);
            o.setOrderDate(date);
            o.setCustomerID(custId);
            for (int i = 0; i < count; i++) {
                int pid;
                cout << "Enter Product ID " << i + 1 << ": ";
                cin >> pid;
                Product* p = products.GetProduct(pid);
                if (p != NULL) {
                    o.addProduct(*p);
                } else {
                    cout << "Product not found! Skipping..." << endl;
                }
            }
            orders.Add(o);
            cout << "\n--- Order Created ---\n";
            o.displayDetails();
            break;
        case 2:
            cout << "\n--- Remove Order ---\n";
            cout << "Enter Order ID to remove: ";
            cin >> id;
            orders.Remove(id);
            break;
        case 3:
            cout << "\n--- Update Order Status ---\n";
            cout << "Enter Order ID to update: ";
            cin >> id;
            orders.Update(id);
            break;
        case 4:
            cout << "\n--- Search Order ---\n";
            cout << "Enter Order ID to search: ";
            cin >> id;
            {
                Order* o = orders.GetOrder(id);
                if (o != NULL) {
                    o->displayDetails();
                } else {
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
        default:
            cout << "Invalid choice!\n";
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
                } else {
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
            suppliers.Add(s);
            break;
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
                } else {
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
                } else {
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
                } else {
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
    int choice;
    int itemID, qty, wid, cap;
    string itemName, desc, wname, location;
    double price;
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
            wname = getStringInput("Enter Warehouse Name: ");
            location = getStringInput("Enter Location: ");
            cout << "Enter Capacity: ";
            cin >> cap;
            clearInputBuffer();
            cout << "Enter Item ID: ";
            cin >> itemID;
            clearInputBuffer();
            itemName = getStringInput("Enter Item Name: ");
            cout << "Enter Price: ";
            cin >> price;
            clearInputBuffer();
            cout << "Enter Quantity: ";
            cin >> qty;
            clearInputBuffer();
            desc = getStringInput("Enter Description: ");
            inv.setID(wid);
            inv.setName(wname);
            inv.setLocation(location);
            inv.setCapacity(cap);
            inv.setItemID(itemID);
            inv.setItemName(itemName);
            inv.setPrice(price);
            inv.setQuantity(qty);
            inv.setDescription(desc);
            cout << "\n--- Inventory Information ---\n";
            inv.display();
            inventoryItems.Add(inv);
            break;
        case 2:
            cout << "\n--- Remove Inventory Item ---\n";
            cout << "Enter Item ID to remove: ";
            cin >> itemID;
            inventoryItems.Remove(itemID);
            break;
        case 3:
            cout << "\n--- Update Inventory Item ---\n";
            cout << "Enter Item ID to update: ";
            cin >> itemID;
            inventoryItems.Update(itemID);
            break;
        case 4:
            cout << "\n--- Search Inventory Item ---\n";
            cout << "Enter Item ID to search: ";
            cin >> itemID;
            {
                Inventory* inv = inventoryItems.GetInventory(itemID);
                if (inv != NULL) {
                    inv->display();
                } else {
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
    int choice;
    int shipID, itemID, qty, wid, cap;
    string itemName, status, wname, location;
    double price;
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
            wname = getStringInput("Enter Warehouse Name: ");
            location = getStringInput("Enter Location: ");
            cout << "Enter Capacity: ";
            cin >> cap;
            clearInputBuffer();
            cout << "Enter Item ID: ";
            cin >> itemID;
            clearInputBuffer();
            itemName = getStringInput("Enter Item Name: ");
            cout << "Enter Price: ";
            cin >> price;
            clearInputBuffer();
            cout << "Enter Quantity: ";
            cin >> qty;
            clearInputBuffer();
            status = getStringInput("Enter Status: ");
            ship.setShipmentID(shipID);
            ship.setID(wid);
            ship.setName(wname);
            ship.setLocation(location);
            ship.setCapacity(cap);
            ship.setItemID(itemID);
            ship.setItemName(itemName);
            ship.setPrice(price);
            ship.setQuantity(qty);
            ship.setStatus(status);
            cout << "\n--- Shipment Information ---\n";
            ship.display();
            shipments.Add(ship);
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
                } else {
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

    do {
        cout << "\n========================================\n";
        cout << "  WAREHOUSE MANAGEMENT SYSTEM\n";
        cout << "========================================\n";
        cout << "1. Manage Customer\n";
        cout << "2. Manage Product\n";
        cout << "3. Manage Order\n";
        cout << "4. Manage Employee\n";
        cout << "5. Manage Supplier\n";
        cout << "6. Manage Category\n";
        cout << "7. Manage Warehouse\n";
        cout << "8. Manage Inventory\n";
        cout << "9. Manage Shipment\n";
        cout << "0. Exit\n";
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
            employeeMenu();
            break;
        case 5:
            supplierMenu();
            break;
        case 6:
            categoryMenu();
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
        case 0:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
