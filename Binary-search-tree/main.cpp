#include "BST.h"
int main()
{
    BST tree;

    // 1. Test Insert
    cout << "Inserting: 50, 30, 70, 20, 40, 60, 80" << endl;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // 2. Test Display (In-order should be sorted)
    cout << "In-order traversal: ";
    tree.display(); // Should print: 20 30 40 50 60 70 80
    cout << endl
         << "---------------------------" << endl;

    // 4. Test Search
    int key = 40;
    if (tree.search(key))
        cout << "Key " << key << " found in tree." << endl;
    else
        cout << "Key " << key << " not found." << endl;

    // 5. Test Remove
    cout << "---------------------------" << endl;

    cout << "Removing 20 (Leaf node)..." << endl;
    tree.remove(20);
    tree.display();
    cout << endl;

    cout << "Removing 30 (Node with one child)..." << endl;
    tree.remove(30);
    tree.display();
    cout << endl;

    cout << "Removing 50 (Root node with two children)..." << endl;
    tree.remove(50);
    tree.display();
    cout << endl;

    cout << "Final tree search for old root (50): "
         << (tree.search(50) ? "Found" : "Not Found") << endl;

    return 0;
}