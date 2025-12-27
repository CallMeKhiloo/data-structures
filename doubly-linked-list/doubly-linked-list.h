#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val = 0)
    {
        this->data = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void push(int val)
    {
        Node *n = new Node(val);
        if (head == NULL)
        {
            head = tail = n;
            return;
        }
        tail->next = n;
        n->prev = tail;
        tail = n;
    }

    void insertAfter(int data, int afterData)
    {
        Node *curr = getNode(afterData);

        if (curr == NULL)
            return;

        if (curr == tail)
        {
            push(data);
            return;
        }
        Node *n = new Node(data);
        n->prev = curr;
        n->next = curr->next;
        curr->next->prev = n;
        curr->next = n;
    }

    void insertBefore(int data, int beforeData)
    {
        Node *curr = getNode(beforeData);

        if (curr == NULL)
            return;

        Node *n = new Node(data);
        if (curr == head)
        {
            head->prev = n;
            n->next = head;
            head = n;
            return;
        }
        n->next = curr;
        n->prev = curr->prev;
        curr->prev->next = n;
        curr->prev = n;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty !!" << '\n';
            return;
        }

        Node *curr = head;

        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

    int getCount()
    {
        if (head == NULL)
            return 0;

        Node *curr = head;
        int cntr = 0;

        while (curr != NULL)
        {
            cntr++;
            curr = curr->next;
        }
        return cntr;
    }

    int getDataByIndex(int index)
    {
        if (head == NULL)
        {
            cout << "List is empty!!";
            return -1;
        }

        Node *curr = head;
        int cntr = 0;

        while (curr != NULL)
        {
            if (index == cntr)
            {
                return curr->data;
            }
            curr = curr->next;
            cntr++;
        }
        cout << "index is out of bounds";
        return -1;
    }

    void removeAllNodes()
    {
        if (head == NULL)
            return;

        Node *curr = head;
        while (head != NULL)
        {
            head = head->next;
            delete curr;
            curr = head;
        }
        tail = NULL;
    }

private:
    Node *getNode(int val)
    {
        if (head == NULL)
        {
            cout << "List is empty!!!" << '\n';
            return NULL;
        }

        int cntr = 0;
        Node *curr = head;

        while (curr != NULL)
        {
            if (curr->data == val)
            {
                cout << "node is found at index = " << cntr << endl;
                return curr;
            }
            curr = curr->next;
            cntr++;
        }
        cout << "Element isn't found!!" << '\n';
        return NULL;
    }
};

#endif