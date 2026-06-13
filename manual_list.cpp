#include <iostream>
#include <vector>
#include <algorithm>
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

class Linked_list
{
public:
    Node *head, *tail;
    Linked_list()
    {
        head = tail = nullptr;
    }
    void insertInBlank()
    {
        int val;
        while (cin >> val && val != -1)
        {
            Node *tem = new Node(val);
            if (head == nullptr)
            {
                head = tail = tem;
            }
            else
            {
                tail->next = tem;
                tail = tail->next;
            }
        }
    }
    int get_size ()
    {
        Node* temp = head;
        int sz = 0;
        while (temp)
        {
            sz++;
            temp = temp->next;
        }
        return sz;
    }
};


void print(Node *head, Node *tail)
{
    cout << "L -> ";
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "R -> ";
    temp = tail;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}


void Add_to_position(Node *&head, Node *&tail, int idx, int val)
{
    Node *newnode = new Node(val);
    Node *tem = head;
    if (idx == 0)
    {
        if (head == nullptr)
        {
            head = tail = newnode;
            print(head, tail);
            return;
        }
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        print(head, tail);
        return;
    }
    if (head == nullptr)
    {
        cout << "Invalid" << endl;
        return;
    }
    // for any position
    for (int i = 0; i < idx - 1; i++)
    {
        if (tem == nullptr || tem->next == nullptr)
        {
            cout << "Invalid" << endl;
            return;
        }
        tem = tem->next;
    }
    if (tem == nullptr && tem->next == nullptr)
    {
        cout << "Invalid" << endl;
        return;
    }
    if (tem == tail)
    {
        tem->next = newnode;
        newnode->prev = tem;
        tail = tail->next;
        print(head, tail);
        return;
    }
    newnode->next = tem->next;
    newnode->prev = tem;
    tem->next = newnode;
    newnode->next->prev = newnode;
    print(head, tail);
}

void Add_to_Query(Node *&head, Node *&tail, int insertCode, int val)
{
    //add head
    if (insertCode == 0)
    {
        Node *newnode = new Node(val);
        if (head == nullptr)
        {
            head = newnode;
            tail = head;
            return;
        }
        newnode->next = head;
        head = newnode;
    }
    //add tail
    if (insertCode == 1)
    {
        Node *newnode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newnode;
            return;
        }
        tail->next = newnode;
        tail = newnode;
    }
    // add any pos
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
            newnode->next = head;
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
            tem = tem->next;
        }
        if (tem == nullptr)
        {
            return;
        }
        newnode->next = tem->next;
        tem->next = newnode;
        if (tem == tail)
        {
            tail = tail->next;
        }
    }
    // delete
    if (insertCode == 2)
    {
        Node *temporary = head;
        // here val becomes pos
        if (head == nullptr)
            return;
        if (val == 0)
        {
            head = head->next;
            delete temporary;
            return;
        }
        // delete index wise
        for (int i = 1; i < val; i++)
        {
            if (temporary == nullptr)
            {
                return;
            }
            temporary = temporary->next;
        }
        if (temporary->next == nullptr)
            return;
        Node *dlt = temporary->next;
        if (dlt == tail)
        {
            tail = temporary;
        }
        temporary->next = dlt->next;
        delete dlt;
        return;
    }
}



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    Node* removeNthFromEnd(Node* &head, int n) {
        Node* fast = new Node (0); 
        Node *slow = new Node (0);
        fast->next = head;
        slow->next = head;
        // if (head->next == nullptr)
        // {
        //     Node* dlt = head;
        //     head = head->next;
        //     delete dlt;
        //     return head;
        // }
        for (int i = 0; i < n; i++)
        {
            if (fast->next == nullptr) break;
            fast = fast->next;
        }
        while (fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        Node* dlt = slow->next;
        if (dlt == head) head = head->next;
        else slow->next = dlt->next;
        delete dlt;
        return head;
    }
};

int main()
{
    Linked_list list;
    list.insertInBlank();
    int n; cin >> n;
    Solution one;
    Node* New = one.removeNthFromEnd(list.head, n);
    cout << "After Removing " << endl;
    while (New!= nullptr)
    {
        cout << New->val << endl;
        New = New->next;
    }
}