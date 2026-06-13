#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;
    LinkedList()
    {
        head = tail = nullptr;
    }
    void print_forward()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }
    bool IsPalindrome();
};

void pushback(Node *&head, Node *&tail, int value)
{
    Node *newnode = new Node(value);
    if (head == nullptr)
    {
        head = tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = tail->next;
    }
}

bool LinkedList::IsPalindrome()
{
    for (Node *i = head, *j = tail; i != j && i->next != j->prev; i = i->next, j = j->prev)
    {
        cout << i->val << " : " << j->val << endl;
        if (i->val != j->val)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int val;
    LinkedList l1;
    while (cin >> val && val != -1)
    {
        pushback(l1.head, l1.tail, val);
    }
    // l1.print_forward();
    bool flag = l1.IsPalindrome();
    flag == true ? cout << "YES" : cout << "NO";
}