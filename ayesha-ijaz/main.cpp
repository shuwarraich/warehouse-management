#include <iostream>
#include <limits>
using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

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

void warehouseMenu() {
    int choice;
    Warehouse w;
    int id, cap, space;
    string loc;

    do {
        cout << "\n========================================\n";
        cout << "       WAREHOUSE MANAGEMENT MENU\n";
        cout << "========================================\n";
        cout << "1. Add Warehouse\n";
        cout << "2. Update Warehouse\n";
        cout << "3. Check Capacity\n";
        cout << "4. Allocate Space\n";
        cout << "5. Remove Product\n";
        cout << "6. Display Warehouse\n";
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
            w.setWarehouseID(id);
            w.setLocation(loc);
            w.setTotalCapacity(cap);
            w.setAvailableSpace(space);
            w.addWarehouse();
            break;
        case 2:
            cout << "\n--- Update Warehouse ---\n";
            cout << "Enter new Warehouse ID: ";
            cin >> id;
            cout << "Enter new Location: ";
            cin >> loc;
            cout << "Enter new Total Capacity: ";
            cin >> cap;
            cout << "Enter new Available Space: ";
            cin >> space;
            w.setWarehouseID(id);
            w.setLocation(loc);
            w.setTotalCapacity(cap);
            w.setAvailableSpace(space);
            w.updateWarehouse();
            break;
        case 3:
            w.checkCapacity();
            break;
        case 4:
            cout << "Enter space to allocate: ";
            cin >> space;
            w.allocateSpace(space);
            break;
        case 5:
            cout << "Enter space to release: ";
            cin >> space;
            w.removeProduct(space);
            break;
        case 6:
            w.display();
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
    Inventory i;
    int id, items;
    string list, date;

    do {
        cout << "\n========================================\n";
        cout << "        INVENTORY MANAGEMENT MENU\n";
        cout << "========================================\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. Update Quantity\n";
        cout << "4. Check Stock\n";
        cout << "5. Display Inventory\n";
        cout << "6. Back to Main Menu\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            clearInputBuffer();
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            cout << "\n--- Add Item ---\n";
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
            break;
        case 2:
            i.removeItem();
            break;
        case 3:
            cout << "Enter quantity change (positive to add, negative to reduce): ";
            cin >> items;
            i.updateQuantity(items);
            break;
        case 4:
            i.checkStock();
            break;
        case 5:
            i.display();
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
    Shipment s;
    int sid, oid;
    string sDate, dDate, status;

    do {
        cout << "\n========================================\n";
        cout << "        SHIPMENT MANAGEMENT MENU\n";
        cout << "========================================\n";
        cout << "1. Create Shipment\n";
        cout << "2. Update Status\n";
        cout << "3. Track Shipment\n";
        cout << "4. Confirm Delivery\n";
        cout << "5. Display Shipment\n";
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
            s.setShipmentID(sid);
            s.setOrderID(oid);
            s.setShipmentDate(sDate);
            s.setDeliveryDate(dDate);
            s.setStatus(status);
            s.createShipment();
            break;
        case 2:
            cout << "Enter new status: ";
            cin >> status;
            s.updateStatus(status);
            break;
        case 3:
            s.trackShipment();
            break;
        case 4:
            s.confirmDelivery();
            break;
        case 5:
            s.display();
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
        cout << "  Contributor: ayesha-ijaz\n";
        cout << "========================================\n";
        cout << "1. Manage Warehouse\n";
        cout << "2. Manage Inventory\n";
        cout << "3. Manage Shipment\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            clearInputBuffer();
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            warehouseMenu();
            break;
        case 2:
            inventoryMenu();
            break;
        case 3:
            shipmentMenu();
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