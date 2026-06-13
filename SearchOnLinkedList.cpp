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

class Linked_list
{
public:
    Node *head, *tail;
    Linked_list()
    {
        head = tail = nullptr;
    }
};

void Add_to_Query(Node *&head, Node *&tail, int insertCode, int val)
{
    if (insertCode == 0)
    {
        Node *newnode = new Node(val);
        if (head == nullptr)
        {
            head = newnode;
            tail = head;
            return;
        }
        newnode->next_ob = head;
        head = newnode;
    }

    if (insertCode == 1)
    {
        Node *newnode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newnode;
            return;
        }
        tail->next_ob = newnode;
        tail = newnode;
    }
    if (insertCode == 3)
    {
        // if (head == nullptr) return
        cout << "Enter index :";
        int idx;
        cin >> idx;
        Node *newnode = new Node(val);
        Node *tem = head;
        if (idx == 0)
        {
            newnode->next_ob = head;
            head = newnode;
            return;
        }
        // if (tem == nullptr)
        // {
        //     return;
        // }
        for (int i = 0; i < idx - 1; i++)
        {
            if (tem == nullptr)
            {
                return;
            }
            tem = tem->next_ob;
        }
        if (tem == nullptr)
        {
            return;
        }
        newnode->next_ob = tem->next_ob;
        tem->next_ob = newnode;
        if (tem == tail)
        {
            tail = tail->next_ob;
        }
    }
    if (insertCode == 2)
    {
        Node *temporary = head;
        // here value becomes pos
        if (head == nullptr)
            return;
        if (val == 0)
        {
            head = head->next_ob;
            delete temporary;
            return;
        }
        for (int i = 1; i < val; i++)
        {
            if (temporary == nullptr)
            {
                return;
            }
            temporary = temporary->next_ob;
        }
        if (temporary->next_ob == nullptr)
            return;
        Node *dlt = temporary->next_ob;
        if (dlt == tail)
        {
            tail = temporary;
        }
        temporary->next_ob = dlt->next_ob;
        delete dlt;
        return;
    }
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->value << " ";
        temp = temp->next_ob;
    }
    cout << endl;
}

int main()
{
    Linked_list list;
    int query;
    cin >> query;
    while (query--)
    {
        int x, v;
        cin >> x >> v;
        Add_to_Query(list.head, list.tail, x, v);
        printList(list.head);
    }
}