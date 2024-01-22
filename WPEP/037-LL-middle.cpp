/*
    Approach - Two Pointer
    intuition - 
        1. we will use two pointers fast and slow
        2. fast will move two steps and slow will move one step
        3. when fast will reach the end slow will be at the middle

    Time Complexity - O(n)
    Space Complexity - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data, Node *next = NULL)
    {
        this->data = data;
        this->next = next;
    }

    Node *insert(Node *head, int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            return head;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        return head;
    }

    void print(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    Node *head = NULL;

    head = head->insert(head, 1);
    head = head->insert(head, 2);
    head = head->insert(head, 3);
    head = head->insert(head, 4);
    head = head->insert(head, 5);


    Node* fast = head;
    Node* slow = head;
    
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    cout << slow->data << endl;

    return 0;
}