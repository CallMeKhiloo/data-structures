#ifndef __BST__
#define __BST__

#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int data = 0);
};

class BST
{
private:
    Node *root;
    Node *insert(Node *curr, int value); // can't make this public as i will need to send the root which is private
    Node *search(Node *curr, int value);
    void inorder_traversal(Node* curr);
    void clear(Node* curr);
    Node* findMin(Node* curr);
    Node* findMax(Node* curr);
    Node* remove(Node* curr, int value);

public:
    BST();
    Node *insert(int value); // will expose this insert method and call the private one inside it
    Node *search(int value);
    void display();
    Node *remove(int value);

    ~BST();
};

#endif