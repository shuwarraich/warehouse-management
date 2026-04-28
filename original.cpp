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
};// ================= CATEGORY =================
class Category {
private:
 int id;
 string name;
public:
 void set(int i, string n) { id = i; name = n; }
 void add() { cout << "Category Added\n"; }
 void update() { cout << "Category Updated\n"; }
 void del() { cout << "Category Deleted\n"; }
 void display() {
 cout << "ID: " << id << " Name: " << name << endl;
 }
};
// ================= SUPPLIER =================
class Supplier {
private:
 int id;
 string name;
 string contact;
 string email;
public:
 void set(int i, string n, string c, string e) {
 id = i; name = n; contact = c; email = e;
 }
 void add() { cout << "Supplier Added\n"; }
 void update() { cout << "Supplier Updated\n"; }
 void del() { cout << "Supplier Deleted\n"; }
 void display() {
 cout << "ID: " << id << " Name: " << name
 << " Contact: " << contact
 << " Email: " << email << endl;
 }
};
// ================= EMPLOYEE =================
class Employee {
private:
 int id;
 string name;
 string position;
 float salary;
public:
 void set(int i, string n, string p, float s) {
 id = i; name = n; position = p; salary = s;
 }
 void add() { cout << "Employee Added\n"; }
 void update() { cout << "Employee Updated\n"; }
 void del() { cout << "Employee Deleted\n"; }
 void display() {
 cout << "ID: " << id << " Name: " << name
 << " Position: " << position
 << " Salary: " << salary <<endl;
  }
};
// ================= WAREHOUSE CLASS =================
class Warehouse {
public:
    int id;
    string location;
    string manager;

    void input() {
        cout << "Enter Warehouse ID: ";
        cin >> id;
        cout << "Enter Location: ";
        cin >> location;
        cout << "Enter Manager Name: ";
        cin >> manager;
    }

    void display() {
        cout << "ID: " << id
             << " | Location: " << location
             << " | Manager: " << manager << endl;
         }
     };
     // ================= INVENTORY CLASS =================
class Inventory {
public:
    int id;
    string productName;
    int quantity;
    double price;

    void input() {
        cout << "Enter Inventory ID: ";
        cin >> id;
        cout << "Enter Product Name: ";
        cin >> productName;
        cout << "Enter Quantity: ";
        cin >> quantity;
        cout << "Enter Price: ";
        cin >> price;
    }

    void display() {
        cout << "ID: " << id
             << " | Product: " << productName
             << " | Quantity: " << quantity
              << " | Price: " << price << endl;
    }
};
// ================= SHIPMENT CLASS =================
class Shipment {
public:
    int id;
    string supplierName;
    string destination;
    string status;

    void input() {
        cout << "Enter Shipment ID: ";
        cin >> id;
        cout << "Enter Supplier Name: ";
        cin >> supplierName;
        cout << "Enter Destination: ";
        cin >> destination;
        cout << "Enter Status: ";
        cin >> status;
    }

    void display() {
        cout << "ID: " << id
        << " | Supplier: " << supplierName
             << " | Destination: " << destination
             << " | Status: " << status << endl;
    }
};

Customer customer;
Product product;
Order order;
Category category;
Supplier supplier;
Employee employee;

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
         // ================= CATEGORY MENU =================
            void categoryMenu(){
			 int ch, id;
 string name;
 do {
 cout << "\n===== CATEGORY MENU =====\n";
 cout << "1.Add 2.Update 3.Delete 4.Display 5.Back\n";
 cin >> ch;
 switch (ch) {
 case 1:
 cin >> id >> name;
 category.set(id, name);
 category.add();
 break;
 case 2:
 cin >> id >> name;
 category.set(id, name);
 category.update();
 break;
 case 3:
 category.del();
 break;
 case 4:
 category.display();
 break;
 }
 } while (ch != 5);
}
// ================= SUPPLIER MENU =================
void supplierMenu() {
 int ch, id;
 string name, contact, email;
 do {
 cout << "\n===== SUPPLIER MENU =====\n";
 cout << "1.Add 2.Update 3.Delete 4.Display 5.Back\n";
 cin >> ch;
 switch (ch) {
 case 1:
 cin >> id >> name >> contact >> email;
 supplier.set(id, name, contact, email);
 supplier.add();
 break;
 case 2:
 cin >> id >> name >> contact >> email;
 supplier.set(id, name, contact, email);
 supplier.update();
 break;
 case 3:
 supplier.del();
 break;
 case 4:
 supplier.display();
 break;
 }
 } while (ch != 5);
}
// ================= EMPLOYEE MENU =================
void employeeMenu() {
 int ch, id;
 string name, pos;
 float salary;
 do {
 cout << "\n===== EMPLOYEE MENU =====\n";
 cout << "1.Add 2.Update 3.Delete 4.Display 5.Back\n";
 cin >> ch;
 switch (ch) {
 case 1:
 cin >> id >> name >> pos >> salary;
 employee.set(id, name, pos, salary);
 employee.add();
 break;
 case 2:
 cin >> id >> name >> pos >> salary;
 employee.set(id, name, pos, salary);
 employee.update();
 break;
 case 3:
 employee.del();
 break;
 case 4:
 employee.display();
 break;
 }
 } while (ch != 5);
}
cout << "\n========================================\n";
        cout << "        WAREHOUSE MANAGEMENT MENU\n";
        cout << "========================================\n";
        cout << "1. Add Warehouse\n";
        cout << "2. Update Warehouse\n";
        cout << "3. Display Warehouse\n";
        cout << "4. Back to Main Menu\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            clearInputBuffer();
            cout << "Invalid input!\n";
            continue;
        }

        switch (choice) {

        case 1:
            cout << "\n--- Add Warehouse ---\n";
            cout << "Enter ID: "; cin >> id;
            cout << "Enter Location: "; cin >> location;
             cout << "Enter Manager: "; cin >> manager;

            warehouse.setId(id);
            warehouse.setLocation(location);
            warehouse.setManager(manager);

            warehouse.addWarehouse();
            cout << "Warehouse Added!\n";
            break;

        case 2:
            cout << "\n--- Update Warehouse ---\n";
            cout << "Enter ID: "; cin >> id;
            cout << "Enter Location: "; cin >> location;
            cout << "Enter Manager: "; cin >> manager;

            warehouse.setId(id);
            warehouse.setLocation(location);
            warehouse.setManager(manager);
            warehouse.updateWarehouse();
            cout << "Warehouse Updated!\n";
            break;

        case 3:
            warehouse.display();
            break;

        case 4:
            cout << "Back to Main Menu...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);
}
void inventoryMenu() {
    int choice;
    int id, qty;
    string product;
    double price;

    do {
        cout << "\n========================================\n";
        cout << "        INVENTORY MANAGEMENT MENU\n";
        cout << "========================================\n";
        cout << "1. Add Inventory\n";
        cout << "2. Update Inventory\n";
        cout << "3. Display Inventory\n";
        cout << "4. Back to Main Menu\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            clearInputBuffer();
            cout << "Invalid input!\n";
            continue;
        }

        switch (choice) {

        case 1:
            cout << "\n--- Add Inventory ---\n";
            cout << "Enter ID: "; cin >> id;
            cout << "Enter Product: "; cin >> product;
            cout << "Enter Quantity: "; cin >> qty;
            cout << "Enter Price: "; cin >> price;

            inventory.setId(id);
            inventory.setProductName(product);
            inventory.setQuantity(qty);
            inventory.setPrice(price);

            inventory.addInventory();
            cout << "Inventory Added!\n";
            break;

        case 2:
            cout << "\n--- Update Inventory ---\n";
            cout << "Enter ID: "; cin >> id;
            cout << "Enter Product: "; cin >> product;
            cout << "Enter Quantity: "; cin >> qty;
            cout << "Enter Price: "; cin >> price;

            inventory.setId(id);
            inventory.setProductName(product);
            inventory.setQuantity(qty);
            inventory.setPrice(price);

            inventory.updateInventory();
            cout << "Inventory Updated!\n";
            break;

        case 3:
            inventory.display();
            break;

        case 4:
            cout << "Back to Main Menu...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);
}
void shipmentMenu() {
    int choice;
    int id;
    string supplier, destination, status;

    do {
        cout << "\n========================================\n";
        cout << "        SHIPMENT MANAGEMENT MENU\n";
        cout << "========================================\n";
        cout << "1. Add Shipment\n";
        cout << "2. Update Shipment\n";
        cout << "3. Display Shipment\n";
        cout << "4. Back to Main Menu\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            clearInputBuffer();
            cout << "Invalid input!\n";
            continue;
        }

        switch (choice) {

        case 1:
            cout << "\n--- Add Shipment ---\n";
            cout << "Enter ID: "; cin >> id;
            cout << "Enter Supplier: "; cin >> supplier;
            cout << "Enter Destination: "; cin >> destination;
            cout << "Enter Status: "; cin >> status;

            shipment.setId(id);
            shipment.setSupplierName(supplier);
            shipment.setDestination(destination);
            shipment.setStatus(status);

            shipment.addShipment();
            cout << "Shipment Added!\n";
            break;

        case 2:
            cout << "\n--- Update Shipment ---\n";
            cout << "Enter ID: "; cin >> id;
            cout << "Enter Supplier: "; cin >> supplier;
            cout << "Enter Destination: "; cin >> destination;
            cout << "Enter Status: "; cin >> status;

            shipment.setId(id);
            shipment.setSupplierName(supplier);
            shipment.setDestination(destination);
            shipment.setStatus(status);

            shipment.updateShipment();
            cout << "Shipment Updated!\n";
            break;

        case 3:
            shipment.display();
            break;

        case 4:
            cout << "Back to Main Menu...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);
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
        cout << "9. Manage Shippment\n";
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
            shippmentMenu();
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


 