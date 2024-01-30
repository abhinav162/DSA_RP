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

    Node* reverse(Node *head)
    {
        // Node *prev = NULL;
        // Node *curr = head;
        // Node *next = NULL;

        // while (curr != NULL)
        // {
        //     next = curr->next;
        //     curr->next = prev;

        //     prev = curr;
        //     curr = next;
        // }

        // head = prev;

        // return head;

        Node* prev = NULL;
        Node* curr = head;
        Node *next = NULL;

        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
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

    head->print(head);

    head = head->reverse(head);

    head->print(head);

    return 0;
}