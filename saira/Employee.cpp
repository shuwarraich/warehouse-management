#include <iostream>
using namespace std;
class Employee
{
private:
    int employeeID;
    string employeeName;
    string role;
    float salary;
    string contactNumber;

public:
    Employee()
    {
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

    void inputEmployee()
    {
        cout << "\nEnter Employee ID: ";
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

    void addEmployee()
    {
        cout << "\n Employee added successfully!" << endl;
    }
    void updateEmployee()
    {
        cout << "\n Employee updated successfully!" << endl;
    }
    void assignTask(string task)
    {
        cout << "\n Task Assigned: " << task << endl;
    }
    void promoteEmployee()
    {
        cout << "\n Employee Promoted!" << endl;
    }

    void searchEmployee(int id)
    {
        if (employeeID == id)
        {
            cout << "\n Employee Found!" << endl;
            display();
        }
        else
        {
            cout << "\n Employee Not Found!" << endl;
        }
    }

    void display()
    {
        cout << "\n========== EMPLOYEE DETAILS ==========\n";
        cout << "ID : " << employeeID << endl;
        cout << "Name : " << employeeName << endl;
        cout << "Role : " << role << endl;
        cout << "Salary : " << salary << endl;
        cout << "Contact : " << contactNumber << endl;
        cout << "======================================\n";
    }
};

int main()
{
    Employee e1;

    e1.inputEmployee();
    e1.addEmployee();
    e1.assignTask("Manage Orders");
    e1.promoteEmployee();

    e1.display();

    e1.searchEmployee(10);
    return 0;
}