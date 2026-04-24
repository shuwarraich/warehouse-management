#include <iostream>
using namespace std;
class Supplier
{
private:
    int supplierID;
    string supplierName;
    string contactNumber;
    string email;

public:
    Supplier()
    {
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
    void supplyProduct() { cout << "Product Supplied\n"; }

    void display()
    {
        cout << "\n--- SUPPLIER DETAILS ---\n";
        cout << "ID: " << supplierID << endl;
        cout << "Name: " << supplierName << endl;
        cout << "Contact: " << contactNumber << endl;
        cout << "Email: " << email << endl;
    }
};

int main()
{
    Supplier s;
    s.setSupplierID(10);
    s.setSupplierName("Ali Traders");
    s.setContactNumber("03001234567");
    s.setEmail("ali@gmail.com");
    s.display();
    s.addSupplier();
    return 0;
}