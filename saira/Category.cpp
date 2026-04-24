#include <iostream>
using namespace std;
class Category
{
private:
    int categoryID;
    string categoryName;
    string description;

public:
    Category()
    {
        categoryID = 0;
        categoryName = "";
        description = "";
    }
    void setCategoryID(int id)
    {
        categoryID = id;
    }
    void setCategoryName(string name)
    {
        categoryName = name;
    }
    void setDescription(string d)
    {
        description = d;
    }

    int getCategoryID()
    {
        return categoryID;
    }
    string getCategoryName()
    {
        return categoryName;
    }
    string getDescription()
    {
        return description;
    }
    void addCategory()
    {
        cout << "Category Added Successfully!" << endl;
    }
    void updateCategory()
    {
        cout << "Category Updated Successfully!" << endl;
    }
    void assignProduct()
    {
        cout << "Product Assigned to Category!" << endl;
    }
};

int main()
{
    Category c1;
    c1.setCategoryID(101);
    c1.setCategoryName("Electronics");
    c1.setDescription("All electronic items");
    cout << "ID: " << c1.getCategoryID() << endl;
    cout << "Name: " << c1.getCategoryName() << endl;
    cout << "Description: " << c1.getDescription() << endl;
    c1.addCategory();
    c1.assignProduct();
    return 0;
}
