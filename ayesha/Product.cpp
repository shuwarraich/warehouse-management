#include <iostream>
#include <vector>
using namespace std;

class Product
{
private:
    int productID;
    string productName;
    int categoryID;
    float price;
    int quantityInStock;
    string description;

public:
    Product()
    {
        productID = 0;
        productName = "";
        categoryID = 0;
        price = 0.00;
        quantityInStock = 0;
        description = "";
    }

    Product(const Product &p)
    {
        cout << "This is a copy constructor" << endl;
        productID = p.productID;
        productName = p.productName;
        categoryID = p.categoryID;
        price = p.price;
        quantityInStock = p.quantityInStock;
        description = p.description;
    }

    ~Product()
    {
        cout << "Product object " << productID << " is being destroyed." << endl;
    }

    void setProductID(int id)
    {
        productID = id;
    }
    void setProductName(string n)
    {
        productName = n;
    }
    void setCategoryID(int cid)
    {
        categoryID = cid;
    }
    void setPrice(float p)
    {
        price = p;
    }
    void setQuantity(int q)
    {
        quantityInStock = q;
    }
    void setDescription(string desc)
    {
        description = desc;
    }

    int getProductID()
    {
        return productID;
    }
    string getProductName()
    {
        return productName;
    }
    int getCategoryID()
    {
        return categoryID;
    }
    float getPrice()
    {
        return price;
    }
    int getQuantity()
    {
        return quantityInStock;
    }
    string getDescription()
    {
        return description;
    }

    void addProduct()
    {
        cout << "Product " << productName << " added successfully!" << endl;
    }

    void updateProduct()
    {
        cout << "Product " << productName << " updated successfully!" << endl;
    }

    void deleteProduct()
    {
        cout << "Product " << productName << " deleted successfully!" << endl;
    }

    void updateStock(int quantity)
    {
        quantityInStock += quantity;
        cout << " update stock successfully. New quantity: " << quantityInStock << endl;
    }

    void getProductDetails()
    {
        cout << "=== Product Details ===" << endl;
        cout << "ID: " << productID << endl;
        cout << "Name: " << productName << endl;
        cout << "Category ID: " << categoryID << endl;
        cout << "Price: $" << price << endl;
        cout << "Stock: " << quantityInStock << endl;
        cout << "Description: " << description << endl;
    };
};
int main()
{
    Product p1;
    p1.setProductID(101);
    p1.setProductName("clothes");
    p1.setCategoryID(1);
    p1.setPrice(7000.00);
    p1.setQuantity(500);
    p1.setDescription("branded loan clothes");

    Product p3;
    p3.setProductID(103);
    p3.setProductName("shoes");
    p3.setCategoryID(2);
    p3.setPrice(2000.00);
    p3.setQuantity(300);
    p3.setDescription("Fashion shoes");

    Product p4;
    p4.setProductID(104);
    p4.setProductName("Leather Jackets");
    p4.setCategoryID(3);
    p4.setPrice(15000.00);
    p4.setQuantity(200);
    p4.setDescription("Wolf leather jackets");

    p1.addProduct();
    p1.getProductDetails();
    p3.getProductDetails();
    p4.getProductDetails();
    Product p2 = p1;
    p2.updateStock(-10);
    p2.getProductDetails();

    return 0;
}
