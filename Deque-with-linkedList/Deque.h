#ifndef __DEQUE__
#define __DEQUE__

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val = 0);
};

class Deque
{
private:
    Node *front;
    Node *rear;

public:
    Deque();

    void push_front(int val);
    void push_back(int val);
    int size();
    void pop_back();
    void pop_front();
    void removeAllNodes();
    void display();
    ~Deque();
};

#endif
