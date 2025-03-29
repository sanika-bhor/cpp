#include<iostream>
using namespace std;
typedef struct node
{
    int data;
    node * next;
}node;


node* create(int n)
{
    node *head;
    head = (node *)malloc(sizeof(node));

    node * p;
    int x;
    cout<<"enter data";
    cin>>x;
    head->data=x;
    head->next=NULL;

    p = head;
    for(int i =1 ;i< n;i++)
    {
        cout << "enter data";
        cin >> x;
        p->next = (node *)malloc(sizeof(node));
        p=p->next;
        p->data=x;
        p->next=NULL;
    }
   
    return head;
}


void print(node* head)
{
    node *p;
   p=head;
   while(p!=NULL)
   {
    cout<<p->data<<"->";
    p=p->next;
   }
}
int main()
{
int n;
node *head;
head = (node *)malloc(sizeof(node));

cout<<"enter the size of node";
cin>>n;

head=create(n);
print(head);

return 0;
}