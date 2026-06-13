#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
    int value;
    Node *next_ob;
    Node(int value)
    {
        this->value = value;
        this->next_ob = nullptr;
    }
};

void addtoposition(int value, int idx, Node *&head, LinkedList &list)
{
    Node *newnode = new Node(value);
    if (head == nullptr && idx > 0)
    {
        cout << "Empty list" << endl;
        return;
    }
    if (idx == 0)
    {
        newnode->next_ob = head;
        head = newnode;
        list.printList();
        return;
    }
    Node *tem = head;
    for (int i = 0; i < idx - 1; i++)
    {
        tem = tem->next_ob;
        // if current index is nullptr means i am at the last
        if (tem == nullptr)
        {
            cout << "Invalid Position" << endl;
            return;
        }
    }
    newnode->next_ob = tem->next_ob;
    tem->next_ob = newnode;
    list.printList();
}



int main()
{
    Node *head = new Node(2);
    Node *a = new Node(3);
    Node *b = new Node(9);
    Node *c = new Node(7);

    head->next_ob = a;
    a->next_ob = b;
    b->next_ob = c;
    c->next_ob = nullptr;
    // asks for value
    cout << "Enter value: ";
    int value;
    cin >> value;
    Node *newnode = new Node(value);
    // asks for position
    cout << "Enter pos: ";
    int pos;
    cin >> pos;
    if (pos == 0)
    {
        newnode->next_ob = head;
        head = newnode;
    }
    else
    {
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next_ob;
        }
        newnode->next_ob = temp->next_ob;
        temp->next_ob = newnode;
    }

    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->value << " ";
        temp = temp->next_ob;
    }
    cout << endl;
}