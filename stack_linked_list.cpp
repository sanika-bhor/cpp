#include <iostream>
using namespace std;

// Define node structure
struct Node
{
    int data;
    Node *next;
};

// Initialize stack
void init(Node *&top)
{
    top = nullptr;
}

// Push operation
void push(Node *&top)
{
    int x;
    cout << "Enter data to be inserted: ";
    cin >> x;

    Node *newNode = new Node; // Allocate memory for new node
    newNode->data = x;
    newNode->next = top;
    top = newNode;

    cout << "Data inserted.\n";
}

// Pop operation
void pop(Node *&top)
{
    if (top == nullptr)
    {
        cout << "Stack underflow. No element to delete.\n";
        return;
    }

    Node *temp = top;
    top = top->next;
    cout << "Data deleted: " << temp->data << endl;
    delete temp; // Free the memory
}

// Print stack
void print(Node *top)
{
    if (top == nullptr)
    {
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Stack elements:\n";
    Node *current = top;
    while (current != nullptr)
    {
        cout << current->data << "\n";
        current = current->next;
    }
}

int main()
{
    Node *top; // Stack top
    init(top);

    int ch;
    do
    {
        cout << "\n\n1. Insert\n2. Delete\n3. Print\n4. Exit\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            push(top);
            break;
        case 2:
            pop(top);
            break;
        case 3:
            print(top);
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (ch != 4);

    // Free remaining memory (if any)
    while (top != nullptr)
    {
        pop(top);
    }

    return 0;
}
