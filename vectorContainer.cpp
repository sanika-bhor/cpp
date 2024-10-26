/*
PROBLEM STATEMENT 6:
Write C++ Program using STL for sorting and searching user defined
records such as item records using vector container.
*/

#include <iostream>
#include <vector>
#include <algorithm> // For sort() and find_if()
using namespace std;

// Item class to store item details
class Item
{
public:
    int id;
    string name;
    float price;

    // Constructor
    Item(int id, string name, float price) : id(id), name(name), price(price) {}

    // Display item information
    void display() const
    {
        cout << "ID: " << id << ", Name: " << name << ", Price: " << price << endl;
    }

    // Overload < operator to sort by item ID
    bool operator<(const Item &other) const
    {
        return id < other.id;
    }
};

// Function to search for an item by ID
void searchItem(const vector<Item> &items, int searchID)
{
    auto it = find_if(items.begin(), items.end(), [searchID](const Item &item)
                      { return item.id == searchID; });

    if (it != items.end())
    {
        cout << "Item found: ";
        it->display();
    }
    else
    {
        cout << "Item not found!" << endl;
    }
}

int main()
{
    vector<Item> items;

    // Add item records
    items.push_back(Item(101, "Laptop", 800.0));
    items.push_back(Item(102, "Phone", 500.0));
    items.push_back(Item(103, "Tablet", 300.0));

    // Display original list
    cout << "Original List:\n";
    for (const auto &item : items)
        item.display();

    // Sort the items by ID
    sort(items.begin(), items.end());

    // Display sorted list
    cout << "\nSorted List:\n";
    for (const auto &item : items)
        item.display();

    // Search for an item by ID
    int searchID;
    cout << "\nEnter ID to search: ";
    cin >> searchID;
    searchItem(items, searchID);

    return 0;
}
