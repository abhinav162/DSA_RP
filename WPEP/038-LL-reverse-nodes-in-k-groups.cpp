#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}

    // insert at the end
    void insert(int x)
    {
        Node *temp = this;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new Node(x);
    }

    void print()
    {
        Node *temp = this;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    Node *head = new Node(1);
    head->insert(2);
    head->insert(3);
    head->insert(4);

    head->print();

    return 0;
}