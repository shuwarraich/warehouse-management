#include <iostream>
#include <limits>
using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

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
    void setCategoryName(string name) { categoryName = name; }
    void setDescription(string d) { description = d; }

    int getCategoryID() { return categoryID; }
    string getCategoryName() { return categoryName; }
    string getDescription() { return description; }

    void addCategory() {
        cout << "Category Added Successfully!" << endl;
    }

    void updateCategory() {
        cout << "Category Updated Successfully!" << endl;
    }

    void assignProduct() {
        cout << "Product Assigned to Category!" << endl;
    }

    void display() {
        cout << "Category ID: " << categoryID << endl;
        cout << "Category Name: " << categoryName << endl;
        cout << "Description: " << description << endl;
    }
};

class Supplier {
private:
    int supplierID;
    string supplierName;
    string contactNumber;
    string email;

public:
    Supplier() {
        supplierID = 0;
        supplierName = "";
        contactNumber = "";
        email = "";
    }

    void setSupplierID(int id) { supplierID = id; }
    void setSupplierName(string n) { supplierName = n; }
    void setContactNumber(string c) { contactNumber = c; }
    void setEmail(string e) { email = e; }

    int getSupplierID() { return supplierID; }
    string getSupplierName() { return supplierName; }
    string getContactNumber() { return contactNumber; }
    string getEmail() { return email; }

    void addSupplier() { cout << "Supplier Added\n"; }
    void updateSupplier() { cout << "Supplier Updated\n"; }
    void supplyProduct() { cout << "Product Supplied\n"; }
    void removeSupplier() { cout << "Supplier Removed\n"; }

    void display() {
        cout << "\n--- SUPPLIER DETAILS ---\n";
        cout << "ID: " << supplierID << endl;
        cout << "Name: " << supplierName << endl;
        cout << "Contact: " << contactNumber << endl;
        cout << "Email: " << email << endl;
    }
};

class Employee {
private:
    int employeeID;
    string employeeName;
    string role;
    float salary;
    string contactNumber;

public:
    Employee() {
        employeeID = 0;
        employeeName = "";
        role = "";
        salary = 0;
        contactNumber = "";
    }

    void setEmployeeID(int id) { employeeID = id; }
    void setEmployeeName(string n) { employeeName = n; }
    void setRole(string r) { role = r; }
    void setSalary(float s) { salary = s; }
    void setContactNumber(string c) { contactNumber = c; }

    int getEmployeeID() { return employeeID; }
    string getEmployeeName() { return employeeName; }
    string getRole() { return role; }
    float getSalary() { return salary; }
    string getContactNumber() { return contactNumber; }

    void inputEmployee() {
        cout << "Enter Employee ID: ";
        cin >> employeeID;
        cout << "Enter Name: ";
        cin >> employeeName;
        cout << "Enter Role: ";
        cin >> role;
        cout << "Enter Salary: ";
        cin >> salary;
        cout << "Enter Contact Number: ";
        cin >> contactNumber;
    }

    void addEmployee() {
        cout << "Employee added successfully!" << endl;
    }

    void updateEmployee() {
        cout << "Employee updated successfully!" << endl;
    }

    void assignTask(string task) {
        cout << "Task Assigned: " << task << endl;
    }

    void promoteEmployee() {
        cout << "Employee Promoted!" << endl;
    }

    void searchEmployee(int id) {
        if (employeeID == id) {
            cout << "Employee Found!" << endl;
            display();
        } else {
            cout << "Employee Not Found!" << endl;
        }
    }

    void display() {
        cout << "\n========== EMPLOYEE DETAILS ==========\n";
        cout << "ID: " << employeeID << endl;
        cout << "Name: " << employeeName << endl;
        cout << "Role: " << role << endl;
        cout << "Salary: " << salary << endl;
        cout << "Contact: " << contactNumber << endl;
        cout << "======================================\n";
    }
};

Category category;
Supplier supplier;
Employee employee;

void categoryMenu() {
    int choice;
    int id;
    string name, desc;

    do {
        cout << "\n========================================\n";
        cout << "       CATEGORY MANAGEMENT MENU\n";
        cout << "========================================\n";
        cout << "1. Add Category\n";
        cout << "2. Update Category\n";
        cout << "3. Assign Product\n";
        cout << "4. Display Category\n";
        cout << "5. Back to Main Menu\n";
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
            cout << "Enter Category Name: ";
            cin >> name;
            cout << "Enter Description: ";
            cin >> desc;
            category.setCategoryID(id);
            category.setCategoryName(name);
            category.setDescription(desc);
            category.addCategory();
            break;
        case 2:
            cout << "\n--- Update Category ---\n";
            cout << "Enter Category ID: ";
            cin >> id;
            cout << "Enter Category Name: ";
            cin >> name;
            cout << "Enter Description: ";
            cin >> desc;
            category.setCategoryID(id);
            category.setCategoryName(name);
            category.setDescription(desc);
            category.updateCategory();
            break;
        case 3:
            category.assignProduct();
            break;
        case 4:
            category.display();
            break;
        case 5:
            cout << "Returning to Main Menu...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);
}

void supplierMenu() {
    int choice;
    int id;
    string name, contact, email;

    do {
        cout << "\n========================================\n";
        cout << "       SUPPLIER MANAGEMENT MENU\n";
        cout << "========================================\n";
        cout << "1. Add Supplier\n";
        cout << "2. Update Supplier\n";
        cout << "3. Supply Product\n";
        cout << "4. Remove Supplier\n";
        cout << "5. Display Supplier\n";
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
            cout << "Enter Supplier Name: ";
            cin >> name;
            cout << "Enter Contact Number: ";
            cin >> contact;
            cout << "Enter Email: ";
            cin >> email;
            supplier.setSupplierID(id);
            supplier.setSupplierName(name);
            supplier.setContactNumber(contact);
            supplier.setEmail(email);
            supplier.addSupplier();
            break;
        case 2:
            cout << "\n--- Update Supplier ---\n";
            cout << "Enter Supplier ID: ";
            cin >> id;
            cout << "Enter Supplier Name: ";
            cin >> name;
            cout << "Enter Contact Number: ";
            cin >> contact;
            cout << "Enter Email: ";
            cin >> email;
            supplier.setSupplierID(id);
            supplier.setSupplierName(name);
            supplier.setContactNumber(contact);
            supplier.setEmail(email);
            supplier.updateSupplier();
            break;
        case 3:
            supplier.supplyProduct();
            break;
        case 4:
            supplier.removeSupplier();
            break;
        case 5:
            supplier.display();
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
    string name, role, task;

    do {
        cout << "\n========================================\n";
        cout << "       EMPLOYEE MANAGEMENT MENU\n";
        cout << "========================================\n";
        cout << "1. Add Employee\n";
        cout << "2. Update Employee\n";
        cout << "3. Assign Task\n";
        cout << "4. Promote Employee\n";
        cout << "5. Search Employee\n";
        cout << "6. Display Employee\n";
        cout << "7. Back to Main Menu\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            clearInputBuffer();
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            cout << "\n--- Add Employee ---\n";
            employee.inputEmployee();
            employee.addEmployee();
            break;
        case 2:
            cout << "\n--- Update Employee ---\n";
            employee.inputEmployee();
            employee.updateEmployee();
            break;
        case 3:
            cout << "Enter task to assign: ";
            cin >> task;
            employee.assignTask(task);
            break;
        case 4:
            employee.promoteEmployee();
            break;
        case 5:
            cout << "Enter Employee ID to search: ";
            cin >> id;
            employee.searchEmployee(id);
            break;
        case 6:
            employee.display();
            break;
        case 7:
            cout << "Returning to Main Menu...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 7);
}

int main() {
    int choice;

    do {
        cout << "\n========================================\n";
        cout << "  WAREHOUSE MANAGEMENT SYSTEM\n";
        cout << "  Contributor: saira\n";
        cout << "========================================\n";
        cout << "1. Manage Category\n";
        cout << "2. Manage Supplier\n";
        cout << "3. Manage Employee\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            clearInputBuffer();
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            categoryMenu();
            break;
        case 2:
            supplierMenu();
            break;
        case 3:
            employeeMenu();
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