#include <iostream>

//singly linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//doubly linked list
struct DListNode
{
    int val;
    DListNode *prev;
    DListNode *next;
    DListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};

//circular linked list
struct CListNode
{
    int val;
    CListNode *next;
    CListNode(int x) : val(x), next(nullptr) {}
};

// remove duplicate nodes from a sorted singly linked list
ListNode *removeDuplicates(ListNode *head)
{
    ListNode *current = head;
    while (current && current->next)
    {
        if (current->val == current->next->val)
        {
            ListNode *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else
        {
            current = current->next;
        }
    }
    return head;
}

//rotate a singly linked list to the right by k places
ListNode *rotateRight(ListNode *head, int k)
{
    if (!head || !head->next || k == 0)
        return head;

    int len = 1;
    ListNode *tail = head;
    while (tail->next)
    {
        tail = tail->next;
        len++;
    }
    k %= len;
    if (k == 0)
        return head;

    tail->next = head;
    for (int i = 0; i < len - k; i++)
    {
        tail = tail->next;
    }
    head = tail->next;
    tail->next = nullptr;
    return head;
}

// insert a new node at a given position in a doubly linked list
DListNode *insertAtPosition(DListNode *head, int val, int pos)
{
    DListNode *newNode = new DListNode(val);
    if (pos == 1)
    {
        newNode->next = head;
        if (head)
            head->prev = newNode;
        return newNode;
    }
    DListNode *current = head;
    for (int i = 1; current && i < pos - 1; i++)
    {
        current = current->next;
    }
    if (!current)
        return head;
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next)
        current->next->prev = newNode;
    current->next = newNode;
    return head;
}

//split a circular linked list into two equal halves
void splitCircularList(CListNode *head, CListNode *&head1, CListNode *&head2)
{
    if (!head || !head->next)
        return;
    CListNode *slow = head;
    CListNode *fast = head;
    while (fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    head1 = head;
    head2 = slow->next;
    slow->next = head1;
    CListNode *temp = head2;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = head2;
}
