/*
Approach - Reverse Linked List in K groups
    intuition - 
        1 - reverse the first k nodes of the list.
        2 - if there are less than k nodes left in the list, reverse all of them.

    Algorithm - 
        1 - Reverse the first sub-list of size k. While reversing keep track of the next node and previous node. 
            Let the pointer to the next node be next and pointer to the previous node be prev. 
        2 - head->next = reverse(next, k) /* Recursively call for rest of the list and link the two sub-lists 
        3 - return prev /* prev becomes the new head of the list (see the diagrams of iterative method of this post)
*/


#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    ListNode *insert(ListNode *head, int data)
    {
        ListNode *newNode = new ListNode(data);
        if (head == NULL)
        {
            head = newNode;
            return head;
        }
        ListNode *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        return head;
    }

    void print(ListNode *head)
    {
        ListNode *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

class Solution
{
public:

    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL; 
        ListNode *curr = head; 
        ListNode *next = NULL;

        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode *findKthNode(ListNode *head, int k)
    {
        k -= 1;
        ListNode *temp = head;
        while(temp != NULL && k > 0)
        {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;
        ListNode *prevNode = NULL;
        while(temp != NULL)
        {
            ListNode *kthNode = findKthNode(temp, k);
            if(kthNode == NULL)
            {
                if(prevNode != NULL)
                {
                    prevNode->next = temp;
                }
                break;
            }

            // seperate the list of k nodes and remember the next node so that we can connect it later
            ListNode* nextNode = kthNode->next; // remember the next node
            kthNode->next = NULL; // seperate the list of k nodes

            // reverse the list of k nodes
            ListNode *reversedHead = reverse(temp);

            if(head == temp)
            {
                head = reversedHead;
            }
            else
            {
                prevNode->next = reversedHead;
            }

            // remember the previous node so that we can connect it later
            prevNode = temp;

            // connect the list of k nodes with the next node
            temp = nextNode;
        }

        return head;
    }
};

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    // Input: head = [1,2,3,4,5], k = 2
    Solution *sol = new Solution();

    ListNode *head = NULL;
    head = head->insert(head, 1);
    head = head->insert(head, 2);
    head = head->insert(head, 3);
    head = head->insert(head, 4);
    head = head->insert(head, 5);

    int k = 2;

    head = sol->reverseKGroup(head, k);
    head->print(head);

    return 0;
}