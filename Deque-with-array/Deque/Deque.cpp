#include <iostream>
using namespace std;

/*
Simple Queue :
  problems : deleted Elements cant Be reused
  solution : Circular Queue

Delete ===> Front
Insert ===> Rear
==================================================
Circular Queue
Delete ===> Front
Insert ===> Rear
==================================================
Priority Queue

Delete ===> Priority, Front
Insert ===>  Rear
==================================================
Double Ended Queue
=============================
Input Restricted  [One Inertion , Both Delete]
insertRear();
deleteFront();
deleteRear();


Output Restricted
insertRear();
insertFront();
deleteFront();


*/
class MinaQueue
{
private:
    int *items;
    int rear; // EnterIndex
    // int front; //OutIndex
    int capacity;

public:
    int front; // OutIndex
    MinaQueue(int capacity)
    {
        rear = -1;
        front = -1;
        // size=0;
        this->capacity = capacity;
        items = new int[capacity];
    }
    ~MinaQueue()
    {
        delete[] items;
    }
    void insertRear(int item)
    {
        // Check Full
        if ((front == 0 && rear == capacity - 1) || (front == rear + 1))
        {
            // if(size == capacity){}
            // Resize Dynamic Array
            cout << "is Full " << endl;
            return;
        }

        // Setting Rear and Front
        // First Element
        if (rear == -1 && front == -1)
        {
            rear = 0;
            front = 0;
        }
        else if (rear == capacity - 1)
        { //&& front != 0
            rear = 0;
        }
        else
        {
            rear++;
        }
        // Add item
        items[rear] = item;
        // size++;
    }
    int deleteFront()
    {
        // Check Empty
        if (front == -1)
        {
            cout << "Empty Queue";
            return -1;
        }
        // if(size == 0 ){cout<<"Empty Queue" ; return -1;}

        // Backup Item
        int temp = items[front];
        // Delete Item
        items[front] = -10; //-10 for Debug
        // Change Front and Rear
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == capacity - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        // return Item
        // size--;
        return temp;
    }

    void display()
    {
        cout << "\n========================================\n";

        // Empty
        if (front == -1)
        {
            cout << "Empty Queue";
            return;
        }
        /*if(front <= rear){
            for (int i= front ; i<= rear; i++){
                cout<<items[i]<< "\t";
            }
        }else { //front >= rear
            for (int i= front ; i< capacity; i++){
                cout<<items[i]<< "\t";
            }
            for (int i= 0 ; i<= rear; i++){
                cout<<items[i]<< "\t";
            }

        }*/
        // rear =0 front =1
        // front 3   rear = 2   3 4 0 1 2
        int i = (front) % capacity; // 3%5 ===> 3
        while (i != rear)
        {
            cout << items[i] << "\t";
            i = (i + 1) % capacity;
        }
        cout << items[rear];
        cout << "\n========================================\n";
    }

    void insertFront(int item)
    {
        // check full
        if ((front == 0 && rear == capacity - 1) || (front == rear + 1))
        {
            cout << "Deque is FULL" << '\n';
            return;
        }
        // check empty
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (front == 0)
            front = capacity - 1;
        else
            front--;
        items[front] = item;
    }

    int deleteRear()
    {
        // check empty
        if (rear == -1)
        {
            cout << "Empty Deque" << '\n';
            return -1;
        }
        int temp = items[rear];
        items[rear] = -10;
        // last element
        if (rear == front)
        {
            rear = front = -1;
        }
        else if (rear == 0)
            rear = capacity - 1;
        else
            rear--;

        return temp;
    }
};

int main()
{
    MinaQueue q(5);
    q.insertRear(10);
    q.insertRear(20);
    q.insertRear(30);
    q.insertRear(40);
    q.insertRear(50);
    q.insertRear(60); // full
    q.display();      // 10 20 30 40 50
    cout << q.deleteRear() << '\n';
    cout << q.deleteRear() << '\n';
    cout << q.deleteRear() << '\n';
    cout << q.deleteRear() << '\n';
    cout << q.deleteRear() << '\n';
    cout << q.deleteRear() << '\n';
    cout << q.deleteRear() << '\n';
    cout << q.deleteRear() << '\n';
    q.insertRear(10);
    q.insertRear(20);
    q.insertRear(30);
    q.insertRear(40);
    q.insertRear(50);
    q.display();                     // 10 20 30 40 50
    cout << q.deleteFront() << '\n'; // _ 20 30 40 50
    q.insertRear(60);
    q.display();                    // 60 20 30 40 50
    cout << q.deleteRear() << '\n'; // _ 20 30 40 50
    cout << q.deleteRear() << '\n'; // _ 20 30 40 _
    q.display();
    cout << q.deleteRear() << '\n'; // _ 20 30 _ _
    cout << q.deleteRear() << '\n'; // _ 20 _ _ _
    cout << q.deleteRear() << '\n'; // _ _ _ _ _
    cout << q.deleteRear() << '\n'; // empty

    q.insertFront(10);
    q.insertFront(20);
    q.insertFront(30);
    q.insertFront(40);
    q.insertFront(50);
    q.insertFront(60); // full
    q.display(); // 10 50 40 30 20

    cout << q.deleteRear() << '\n'; // _ 50 40 30 20
    cout << q.deleteRear() << '\n'; // _ 50 40 30 _
    cout << q.deleteRear() << '\n'; // _ 50 40 _ _

    q.display(); /// _ 50 40 _ _

    cout << q.deleteRear() << '\n'; // _ 50 _ _ _
    cout << q.deleteRear() << '\n'; // _ _ _ _ _

    q.display();

    return 0;
}