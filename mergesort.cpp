#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
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
        tail = tail->next;
    }
}
void print_forward(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
}

Node* FindMid (Node* head)
{
    Node* slow, *fast;
    slow = fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeList (Node *&LeftHalf, Node *&rightHalf){
    if (LeftHalf == nullptr) return rightHalf;
    if (rightHalf == nullptr) return LeftHalf;
    if (LeftHalf->value <= rightHalf->value)
    {
        LeftHalf->next = mergeList(LeftHalf->next,rightHalf);
        return LeftHalf;
    }
    else
    {
        rightHalf->next = mergeList(LeftHalf,rightHalf->next);
        return rightHalf;
    }
}

Node *MergeSort (Node* &head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *mid = FindMid(head);
    Node *right = mid;
    mid->next = nullptr;

    Node* LeftHalf = MergeSort(head);
    Node* rightHalf = MergeSort(right);

    Node* merge = mergeList(LeftHalf, rightHalf);
    return merge;
}
int size (Node* head)
    {
        Node* temp = head;
        int count = 0;
        while (temp != nullptr)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }

int main()
{
    LinkedList ls;
    int value;
    while (cin >> value && value != -1)
    {
        pushback(ls.head, ls.tail, value);
    }
    // ls.head = MergeSort (ls.head);
    // print_forward (ls.head);
    int s = size(ls.head);
    cout << s;
}