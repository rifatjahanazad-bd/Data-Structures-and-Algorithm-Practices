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
    void addtolist();
};

void LinkedList::addtolist()
{
    int val;
    while (cin >> val && val != -1)
    {
        Node *temp = new Node(val);
        if (head == nullptr)
        {
            head = tail = temp;
        }
        else
        {
            tail->next_ob = temp;
            tail = tail->next_ob;
        }
    }
}


void printList(Node* head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->value << " ";
        temp = temp->next_ob;
    }
    cout << endl;
}
// head nullptr
// value

void FindValue (Node* &head, int x, int val)
{
    if (head == nullptr) return;
    Node* tem = head;
    Node* newnode = new Node (val);
    while (tem!= nullptr)
    {
        if (tem->value == x)
        {
            newnode->next_ob = tem->next_ob;
            tem->next_ob = newnode;
            return;
        }
        tem = tem->next_ob;
    }
}

int main()
{
    LinkedList list_1;
    list_1.addtolist();
    
    //
    int x, val;
    cin >> x >> val;
    // Node* insert_after = 
    FindValue (list_1.head, x, val);
    printList(list_1.head);
}