#include "BST.h"

Node::Node(int data) : val(data), left(NULL), right(NULL) {}

BST::BST()
{
    root = NULL;
}

Node *BST::insert(int value)
{
    root = insert(root, value);
    return root;
}

Node *BST::insert(Node *current, int value)
{
    if (current == NULL)
    {
        Node *newnode = new Node(value);
        current = newnode;
    }
    else if (value < current->val)
        current->left = insert(current->left, value);
    else
        current->right = insert(current->right, value);
    return current;
}

Node *BST::search(int value)
{
    return search(root, value);
}

Node *BST::search(Node *curr, int value)
{
    if (curr == NULL)
        return NULL;
    else if (value < curr->val)
        return search(curr->left, value);
    else if (value > curr->val)
        return search(curr->right, value);
    else
        return curr;
}

void BST::display()
{
    inorder_traversal(root);
}

void BST::inorder_traversal(Node *curr)
{
    if (curr == NULL)
        return;
    inorder_traversal(curr->left);
    cout << curr->val << "\t";
    inorder_traversal(curr->right);
}

Node *BST::findMin(Node *curr)
{
    if (curr == NULL)
        return NULL;
    if (curr->left == NULL)
        return curr;
    return findMin(curr->left);
}

Node *BST::findMax(Node *curr)
{
    if (curr == NULL)
        return NULL;
    if (curr->right == NULL)
        return curr;
    return findMax(curr->right);
}

Node *BST::remove(int value)
{
    return remove(root, value);
}

Node *BST::remove(Node *curr, int value)
{
    if (curr == NULL)
    {
        return NULL;
    }

    if (value < curr->val)
    {
        curr->left = remove(curr->left, value);
    }
    else if (value > curr->val)
    {
        curr->right = remove(curr->right, value);
    }
    else
    {
        if (curr->left == NULL && curr->right == NULL)
        { // leaf
            delete curr;
            curr = NULL;
        }
        else if (curr->left == NULL && curr->right != NULL)
        { // only right child
            Node *temp = curr->right;
            delete curr;
            curr = temp;
        }
        else if (curr->left != NULL && curr->right == NULL)
        { // only left child
            Node *temp = curr->left;
            delete curr;
            curr = temp;
        }
        else
        {
            Node *successor = findMin(curr->right);
            curr->val = successor->val;
            curr->right = remove(curr->right, successor->val);
        }
    }
    return curr;
}

void BST::clear(Node *curr)
{ // should use post-order in order to remove the children first then the parent
    if (curr == NULL)
        return;

    clear(curr->left);
    clear(curr->right);
    delete curr;
}

BST::~BST()
{
    clear(root);
}