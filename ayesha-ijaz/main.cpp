#include <iostream>
using namespace std;

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

    Warehouse(const Warehouse& w) {
        cout << "This is a copy constructor" << endl;
        warehouseID = w.warehouseID;
        location = w.location;
        totalCapacity = w.totalCapacity;
        availableSpace = w.availableSpace;
    }

    ~Warehouse() {
        cout << "Warehouse object " << warehouseID << " is being destroyed." << endl;
    }

    void setWarehouseID(int id) { warehouseID = id; }
    void setLocation(string loc) { location = loc; }
    void setTotalCapacity(int cap) { totalCapacity = cap; }
    void setAvailableSpace(int space) { availableSpace = space; }

    int getWarehouseID() { return warehouseID; }
    string getLocation() { return location; }
    int getTotalCapacity() { return totalCapacity; }
    int getAvailableSpace() { return availableSpace; }

    void addWarehouse() {
        cout << "Warehouse added successfully!" << endl;
    }

    void updateWarehouse() {
        cout << "Warehouse updated successfully!" << endl;
    }

    void checkCapacity() {
        cout << "Available Space: " << availableSpace << endl;
    }

    void allocateSpace(int space) {
        availableSpace -= space;
        cout << "Space allocated. Remaining: " << availableSpace << endl;
    }

    void removeProduct(int space) {
        availableSpace += space;
        cout << "Product removed. Space now: " << availableSpace << endl;
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

    Inventory(const Inventory& i) {
        cout << "This is a copy constructor" << endl;
        inventoryID = i.inventoryID;
        productList = i.productList;
        totalItems = i.totalItems;
        lastUpdatedDate = i.lastUpdatedDate;
    }

    ~Inventory() {
        cout << "Inventory object " << inventoryID << " is being destroyed." << endl;
    }

    void setInventoryID(int id) { inventoryID = id; }
    void setProductList(string list) { productList = list; }
    void setTotalItems(int items) { totalItems = items; }
    void setDate(string date) { lastUpdatedDate = date; }

    int getInventoryID() { return inventoryID; }
    string getProductList() { return productList; }
    int getTotalItems() { return totalItems; }
    string getDate() { return lastUpdatedDate; }

    void addItem() {
        cout << "Item added successfully!" << endl;
    }

    void removeItem() {
        cout << "Item removed successfully!" << endl;
    }

    void updateQuantity(int q) {
        totalItems += q;
        cout << "Quantity updated: " << totalItems << endl;
    }

    void checkStock() {
        cout << "Stock Level: " << totalItems << endl;
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

    Shipment(const Shipment& s) {
        cout << "This is a copy constructor" << endl;
        shipmentID = s.shipmentID;
        orderID = s.orderID;
        shipmentDate = s.shipmentDate;
        deliveryDate = s.deliveryDate;
        deliveryStatus = s.deliveryStatus;
    }

    ~Shipment() {
        cout << "Shipment object " << shipmentID << " is being destroyed." << endl;
    }

    void setShipmentID(int id) { shipmentID = id; }
    void setOrderID(int oid) { orderID = oid; }
    void setShipmentDate(string d) { shipmentDate = d; }
    void setDeliveryDate(string d) { deliveryDate = d; }
    void setStatus(string s) { deliveryStatus = s; }

    int getShipmentID() { return shipmentID; }
    int getOrderID() { return orderID; }

    void createShipment() {
        cout << "Shipment created successfully!" << endl;
    }

    void updateStatus(string s) {
        deliveryStatus = s;
        cout << "Status updated to: " << deliveryStatus << endl;
    }

    void trackShipment() {
        cout << "Shipment Status: " << deliveryStatus << endl;
    }

    void confirmDelivery() {
        deliveryStatus = "Delivered";
        cout << "Delivery confirmed!" << endl;
    }

    void display() {
        cout << "Shipment ID: " << shipmentID << endl;
        cout << "Order ID: " << orderID << endl;
        cout << "Shipment Date: " << shipmentDate << endl;
        cout << "Delivery Date: " << deliveryDate << endl;
        cout << "Status: " << deliveryStatus << endl;
    }
};

int main() {
    int choice;

    do {
        cout << "\n========================================\n";
        cout << "WAREHOUSE MANAGEMENT SYSTEM\n";
        cout << "========================================\n";
        cout << "1. Manage Warehouse\n";
        cout << "2. Manage Inventory\n";
        cout << "3. Manage Shipment\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            Warehouse w;
            int id, cap, space;
            string loc;

            cout << "\n--- Add Warehouse ---\n";
            cout << "Enter Warehouse ID: ";
            cin >> id;
            cout << "Enter Location: ";
            cin >> loc;
            cout << "Enter Total Capacity: ";
            cin >> cap;
            cout << "Enter Available Space: ";
            cin >> space;

            w.setWarehouseID(id);
            w.setLocation(loc);
            w.setTotalCapacity(cap);
            w.setAvailableSpace(space);

            w.addWarehouse();
            w.display();

            break;
        }

        case 2: {
            Inventory i;
            int id, items;
            string list, date;

            cout << "\n--- Add Inventory ---\n";
            cout << "Enter Inventory ID: ";
            cin >> id;
            cout << "Enter Product List: ";
            cin >> list;
            cout << "Enter Total Items: ";
            cin >> items;
            cout << "Enter Last Updated Date: ";
            cin >> date;

            i.setInventoryID(id);
            i.setProductList(list);
            i.setTotalItems(items);
            i.setDate(date);

            i.addItem();
            i.display();

            break;
        }

        case 3: {
            Shipment s;
            int sid, oid;
            string sDate, dDate, status;

            cout << "\n--- Add Shipment ---\n";
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

            s.setShipmentID(sid);
            s.setOrderID(oid);
            s.setShipmentDate(sDate);
            s.setDeliveryDate(dDate);
            s.setStatus(status);

            s.createShipment();
            s.display();

            break;
        }

        case 4:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}