#include <iostream>
#include <limits>

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

class LinkedList
{
public:
    Node *head;
    Node *tail;
    LinkedList()
    {
        head = tail = nullptr;
    }

    void insertInBlank()
    {
        int value;
        while (cin >> value && value != -1)
        {
            Node *tem = new Node(value);
            if (head == nullptr)
            {
                head = tail = tem;
            }
            else
            {
                tail->next_ob = tem;
                tail = tail->next_ob;
            }
        }
    }
};

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

int FindMax (Node *head)
{
    // Node *tem = head;
    int mx = head->value;
    for (Node *tem = head; tem != nullptr; tem = tem->next_ob)
    {
        if (tem->value > mx)
            mx = tem->value;
    }
    return mx;
}

int Findmin (Node *head)
{
    // Node *tem = head;
    int mn = head->value;
    for (Node *tem = head; tem != nullptr; tem = tem->next_ob)
    {
        if (tem->value < mn)
            mn = tem->value;
    }
    return mn;
}


int main()
{
    LinkedList ls1;
    cout << "Enter List : ";
    ls1.insertInBlank();
    int max = FindMax(ls1.head);
    int min = Findmin (ls1.head);
    int difference = max - min;
    cout << difference << endl;
}