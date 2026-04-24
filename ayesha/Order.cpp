#include <iostream>
using namespace std;

class Order
{
private:
    int orderID;
    string orderDate;
    int customerID;
    int productList[100];
    int productCount;
    float totalAmount;
    string orderStatus;

public:
    Order()
    {
        orderID = 0;
        orderDate = "";
        customerID = 0;
        totalAmount = 0.0;
        orderStatus = "Pending";
        productCount = 0;
        for (int i = 0; i < 100; i++)
        {
            productList[i] = 0;
        }
    }

    Order(const Order &o)
    {
        cout << "This is a copy constructor" << endl;
        orderID = o.orderID;
        orderDate = o.orderDate;
        customerID = o.customerID;
        productCount = o.productCount;
        for (int i = 0; i < productCount; i++)
        {
            productList[i] = o.productList[i];
        }
        totalAmount = o.totalAmount;
        orderStatus = o.orderStatus;
    }

    ~Order()
    {
        cout << "Order object " << orderID << " is being destroyed." << endl;
    }

    void setOrderID(int id)
    {
        orderID = id;
    }

    void setOrderDate(string d)
    {
        orderDate = d;
    }

    void setCustomerID(int cid)
    {
        customerID = cid;
    }

    void setOrderStatus(string status)
    {
        orderStatus = status;
    }

    void setTotalAmount(float amount)
    {
        totalAmount = amount;
    }

    int getOrderID()
    {
        return orderID;
    }

    string getOrderDate()
    {
        return orderDate;
    }

    int getCustomerID()
    {
        return customerID;
    }

    float getTotalAmount()
    {
        return totalAmount;
    }

    string getOrderStatus()
    {
        return orderStatus;
    }

    void displayProductList()
    {
        cout << "Product IDs: ";
        for (int i = 0; i < productCount; i++)
        {
            cout << productList[i] << " ";
        }
        cout << endl;
    }

    void createOrder(int id, string date, int custID, int products[], int count)
    {
        orderID = id;
        orderDate = date;
        customerID = custID;
        productCount = count;
        for (int i = 0; i < count; i++)
        {
            productList[i] = products[i];
        }
        orderStatus = "Created";
        cout << "Order #" << orderID << " created successfully for Customer #" << customerID << endl;
    }

    void calculateTotal(float prices[], int count)
    {
        totalAmount = 0;
        for (int i = 0; i < productCount && i < count; i++)
        {
            totalAmount += prices[i];
        }
        cout << "Total amount calculated: $" << totalAmount << endl;
    }

    void updateOrderStatus(string newStatus)
    {
        cout << "Updating order status from '" << orderStatus << "' to '" << newStatus << "'" << endl;
        orderStatus = newStatus;
        cout << "Order status updated successfully!" << endl;
    }

    void cancelOrder()
    {
        if (orderStatus == "Cancelled")
        {
            cout << "Order is already cancelled!" << endl;
        }
        else if (orderStatus == "Delivered")
        {
            cout << " Order has already been delivered!" << endl;
        }
        else
        {
            orderStatus = "Cancelled";
            cout << "Order #" << orderID << " has been cancelled successfully!" << endl;
        }
    }

    void displayOrderDetails()
    {
        cout << "========== ORDER DETAILS ==========" << endl;
        cout << "Order ID: " << orderID << endl;
        cout << "Order Date: " << orderDate << endl;
        cout << "Customer ID: " << customerID << endl;
        cout << "Product List: ";
        for (int i = 0; i < productCount; i++)
        {
            cout << productList[i] << " ";
        }
        cout << endl;
        cout << "Total Amount: $" << totalAmount << endl;
        cout << "Order Status: " << orderStatus << endl;
        cout << "===================================\n"
             << endl;
    }
};

int main()
{
    int products1[] = {101, 102, 103};
    int count1 = 3;
    float prices1[] = {25.50, 15.75, 30.00};

    Order o1;
    o1.createOrder(1001, "2026-03-30", 123, products1, count1);
    o1.calculateTotal(prices1, count1);
    o1.displayOrderDetails();

    o1.updateOrderStatus("Processing");
    o1.displayOrderDetails();

    int products2[] = {201, 202};
    int count2 = 2;
    float prices2[] = {50.00, 35.50};

    Order o2;
    o2.createOrder(1002, "2026-03-30", 124, products2, count2);
    o2.calculateTotal(prices2, count2);
    o2.displayOrderDetails();

    o2.cancelOrder();
    o2.displayOrderDetails();

    o2.cancelOrder();
    
    cout << "========== COPY CONSTRUCTOR ==========" << endl;
    Order o3 = o1;
    o3.displayOrderDetails();

    return 0;
}