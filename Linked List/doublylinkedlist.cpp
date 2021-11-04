#include <bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node* next;
    node* prev;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(node* &head, int val)
{
    node* n = new node(val);
    n->next = head;
    if(head != NULL)
    {
        head->prev = n; 
    }
    head = n;
}

void insertAtTail(node* &head, int val)
{
    node* n = new node(val);
    if(head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    node* temp = head;

    while(temp->next != NULL)
    {
        temp= temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void deleteAtHead(node* &head)
{
    node* todelete = head;
    head= head->next;
    head->prev = NULL;
    delete todelete;
}

void deletion(node* &head, int pos)
{
    if(pos == 0)
    {
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    int count = 0;
    while(temp != NULL && count != pos)
    {
        temp= temp->next;
        count++;
    }

    temp->prev->next = temp->next;
    if(temp->next != NULL)
    {
    temp->next->prev = temp->prev;
    }

    delete temp;
}

void display(node* head)
{
    while(head != NULL)
    {
        cout<<head->data<<"<=>";
        head= head->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    insertAtHead(head,5);
    display(head);
    deletion(head, 0);
    display(head);
    deletion(head, 3);
    display(head);

}