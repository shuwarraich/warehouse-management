#include <iostream>
using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(1000, '\n');
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
            cout << "Enter new Name: ";
            cin >> name;
            cout << "Enter new Contact: ";
            cin >> contact;
            cout << "Enter new Email: ";
            cin >> email;
            cout << "Enter new Address: ";
            cin >> addr;
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
            cout << "Enter new Name: ";
            cin >> name;
            cout << "Enter new Category ID: ";
            cin >> catId;
            cout << "Enter new Price: ";
            cin >> price;
            cout << "Enter new Quantity: ";
            cin >> qty;
            cout << "Enter new Description: ";
            cin >> desc;
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

CustomerCollection customers;
ProductCollection products;
OrderCollection orders;

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
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Contact: ";
            cin >> contact;
            cout << "Enter Email: ";
            cin >> email;
            cout << "Enter Address: ";
            cin >> addr;
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
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Category ID: ";
            cin >> catId;
            cout << "Enter Price: ";
            cin >> price;
            cout << "Enter Quantity: ";
            cin >> qty;
            cout << "Enter Description: ";
            cin >> desc;
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