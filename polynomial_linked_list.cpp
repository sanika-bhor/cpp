#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node
{
    int coef;
    int expo;
    struct node* next;
} node;

// Function to append a term to the result polynomial
void appendResult(node*& result, int coef, int expo)
{
    node* p = (node*)malloc(sizeof(node));
    p->coef = coef;
    p->expo = expo;
    p->next = NULL;

    if (!result)
    {
        result = p;
    }
    else
    {
        node* q = result;
        while (q->next)
        {
            q = q->next;
        }
        q->next = p;
    }
}

// Function to add two polynomials
node* addition(node* poly1, node* poly2)
{
    node* result = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->expo > poly2->expo)
        {
            appendResult(result, poly1->coef, poly1->expo);
            poly1 = poly1->next;
        }
        else if (poly1->expo < poly2->expo)
        {
            appendResult(result, poly2->coef, poly2->expo);
            poly2 = poly2->next;
        }
        else
        {
            int coef = poly1->coef + poly2->coef;
            appendResult(result, coef, poly1->expo);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1)
    {
        appendResult(result, poly1->coef, poly1->expo);
        poly1 = poly1->next;
    }

    while (poly2)
    {
        appendResult(result, poly2->coef, poly2->expo);
        poly2 = poly2->next;
    }

    return result;
}

// Function to create a polynomial
node* create(int n)
{
    node *head, *p;
    int coef, expo;
    cout << "Enter coefficient and exponent: ";
    cin >> coef >> expo;

    head = (node*)malloc(sizeof(node));
    head->coef = coef;
    head->expo = expo;
    head->next = NULL;

    p = head;
    for (int i = 2; i <= n; i++)
    {
        cout << "Enter coefficient and exponent: ";
        cin >> coef >> expo;

        p->next = (node*)malloc(sizeof(node));
        p = p->next;
        p->coef = coef;
        p->expo = expo;
        p->next = NULL;
    }
    return head;
}

// Function to print a polynomial
void print(node* head)
{
    node* p = head;
    while (p != NULL)
    {
        cout << p->coef << "x^" << p->expo;
        if (p->next)
            cout << " + ";
        p = p->next;
    }
    cout << " -> NULL" << endl;
}

// Main function
int main()
{
    node *head1, *head2, *result;
    head1 = NULL;
    head2 = NULL;
    result = NULL;

    int n1, n2;
    cout << "Enter the number of terms for polynomial 1: ";
    cin >> n1;
    head1 = create(n1);
    cout << "Polynomial 1: ";
    print(head1);

    cout << "Enter the number of terms for polynomial 2: ";
    cin >> n2;
    head2 = create(n2);
    cout << "Polynomial 2: ";
    print(head2);

    result = addition(head1, head2);
    cout << "Resultant Polynomial: ";
    print(result);

    return 0;
}
