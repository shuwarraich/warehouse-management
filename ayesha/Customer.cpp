#include <iostream>
using namespace std;

class Customer
{
private:
    int customerID;
    string customerName;
    string contactNumber;
    string email;
    string address;


public:
   
    Customer()
    {
        customerID = 0;
        customerName = "";
        contactNumber = "";
        email = "";
        address = "";
    }

    
    Customer(const Customer &c)
    {
        cout << "This is a copy constructor" << endl;
        customerID = c.customerID;
        customerName = c.customerName;
        contactNumber = c.contactNumber;
        email = c.email;
        address = c.address;
    }

   
    ~Customer()
    {
        cout << "Customer object " << customerID << " is being destroyed." << endl;
    }

    // Setters
    void setCustomerID(int id)
    {
        customerID = id;
    }
    
    void setCustomerName(string name)
    {
        customerName = name;
    }
    
    void setContactNumber(string number)
    {
        contactNumber = number;
    }
    
    void setEmail(string e)
    {
        email = e;
    }
    
    void setAddress(string a)
    {
        address = a;
    }

   
    int getCustomerID()
    {
        return customerID;
    }
    
    string getCustomerName()
    {
        return customerName;
    }
    
    string getContactNumber()
    {
        return contactNumber;
    }
    
    string getEmail()
    {
        return email;
    }
    
    string getAddress()
    {
        return address;
    }

   
    void addCustomer()
    {
        cout << "Adding new customer: " << customerName << endl;
        cout << "Customer ID: " << customerID << endl;
        cout << "Contact Number: " << contactNumber << endl;
        cout << "Email: " << email << endl;
        cout << "Address: " << address << endl;
    }

    void updateCustomer()
    {
        cout << "Updating customer information for: " << customerName << endl;
        cout << "Customer ID: " << customerID << endl;
    }

    void placeOrder(int orderID)
    {
        cout << "Placing order #" << orderID << " for customer: " << customerName << endl;
                cout << "Order placed successfully!" << endl;
    }

  };
int main()
{
    Customer c1;

    c1.setCustomerID(123);
    c1.setCustomerName("Nehaal");
    c1.setContactNumber("1234567890");
    c1.setAddress("Karachi");
    c1.setEmail("nehaal@example.com");

    Customer c2;
    c2.setCustomerID(124);
    c2.setCustomerName("Sono");
    c2.setContactNumber("1234076567");
    c2.setAddress("lahore");
    c2.setEmail("sono@example.com");

       c1.addCustomer();
    cout << endl;
    c2.addCustomer();
    
    cout << "--- Placing Orders ---" << endl;
    c1.placeOrder(1001);
    c1.placeOrder(1002);
    c2.placeOrder(1003);
    
      c1.updateCustomer();
    
    
    cout << "--- Copy Constructor ---" << endl;
    Customer c3 = c1;
    cout << "Copied Customer: " << c3.getCustomerName() << endl;
    cout << "Contact Number: " << c3.getContactNumber() << endl;
    cout << "Customer ID: " << c3.getCustomerID() << endl;

    return 0;
}