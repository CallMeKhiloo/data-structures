#include "Deque.h"

Node::Node(int val)
{
    this->data = val;
    next = NULL;
    prev = NULL;
}

Deque::Deque() : front(NULL), rear(NULL) {};

void Deque::push_back(int val)
{
    Node *node = new Node(val);
    if (front == NULL && rear == NULL)
    {
        front = rear = node;
        return;
    }
    rear->next = node;
    node->prev = rear;
    rear = node;
}

void Deque::push_front(int val)
{
    Node *node = new Node(val);
    if (front == NULL && rear == NULL)
    {
        front = rear = node;
        return;
    }
    front->prev = node;
    node->next = front;
    front = node;
}

int Deque::size()
{
    Node *curr = front;
    int val = 0;
    while (curr != NULL)
    {
        val++;
        curr = curr->next;
    }
    return val;
}

void Deque::pop_back()
{
    if (front == NULL && rear == NULL)
    {
        cout << "Deque is empty !!" << "\n";
        return;
    }
    Node *ptr = rear;
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        rear = rear->prev;
        rear->next = NULL;
    }
    delete ptr;
}

void Deque::pop_front()
{
    if (front == NULL && rear == NULL)
    {
        cout << "Deque is empty !!" << "\n";
        return;
    }
    Node *ptr = front;
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        front->prev = NULL;
    }
    delete ptr;
}

void Deque::display()
{
    Node *curr = front;
    while (curr != NULL)
    {
        cout << curr->data << "\n";
        curr = curr->next;
    }
}

void Deque::removeAllNodes()
{
    while (front != NULL)
    {
        Node *curr = front;
        front = front->next;
        delete curr;
    }
    rear = front;
}

Deque::~Deque()
{
    this->removeAllNodes();
}