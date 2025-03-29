#include <iostream>
#include <string>
using namespace std;

namespace ProductData
{
    class Product
    {
    public:
        static int count;
        int id;
        string ProductName;
        string description;
        int quantity;
        double price;

        Product()
        {
            cout << " Constructor is called" << endl;
            id = 11;
            ProductName = "Mogara";
            description="beautiful flower";
            quantity=2500;
            price = 5;
            count++;
        }

        Product(int ProductId, string ProductName, string ProductDescription, int ProductQuantity, double ProductPrice)
        {
            cout << " Parameterized Constructor is called" << endl;
            id = ProductId;
            ProductName = ProductName;
            description = ProductDescription;
            quantity = ProductQuantity;
            price = ProductPrice;
            count++;
        }

        ~Product()
        {
            cout << " destructor is called" << endl;
            count--;
        }
    };
}

using namespace ProductData;
int Product::count = 0;

int main()
{

    Product flower1(1, "gerberra","merrage flower",25, 782);
    Product flower2;
    cout << "Number of product objects  " << Product::count << endl;

    Product flower3(2, "Rose", "valentine flower", 20, 1230);
    Product flower4(3, "marigold", "festival flower", 12, 25300);
    Product flower5;

    cout << "Number of product objects  " << Product::count << endl;
}