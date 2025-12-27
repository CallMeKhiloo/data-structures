#include "doubly-linked-list.h"

int main()
{
    DoublyLinkedList list;
    list.push(5);
    list.push(6);
    list.push(7);
    list.push(8);
    list.push(10);

    list.display();
    cout << '\n';

    list.insertAfter(9, 8);
    list.insertAfter(11, 10);
    list.insertAfter(13, 31);
    list.insertBefore(12, 13);
    list.insertBefore(4, 5);
    list.insertBefore(999, 8);
    list.display();
    cout << '\n';
    cout << list.getCount() << '\n';
    cout << list.getDataByIndex(4) << '\n';
    list.removeAllNodes();
    list.display();

    return 0;
}