#include "Deque.h"

using namespace std;

int main()
{
    Deque dq;

    // 1. Test Push Back
    cout << "Testing push_back (10, 20):" << endl;
    dq.push_back(10);
    dq.push_back(20);
    dq.display(); // Should print 10, 20
    cout << "Size: " << dq.size() << endl
         << endl;

    // 2. Test Push Front
    cout << "Testing push_front (5, 2):" << endl;
    dq.push_front(5);
    dq.push_front(2);
    dq.display(); // Should print 2, 5, 10, 20
    cout << "Size: " << dq.size() << endl
         << endl;

    // 3. Test Pop Back
    cout << "Testing pop_back:" << endl;
    dq.pop_back();
    dq.display(); // Should print 2, 5, 10
    cout << "Size: " << dq.size() << endl
         << endl;

    // 4. Test Pop Front
    cout << "Testing pop_front:" << endl;
    dq.pop_front();
    dq.display(); // Should print 5, 10
    cout << "Size: " << dq.size() << endl
         << endl;

    // 5. Test emptying the Deque
    cout << "Emptying the deque..." << endl;
    dq.pop_front();
    dq.pop_front();
    dq.display();
    cout << "Size: " << dq.size() << endl;

    // 6. Test Pop on empty
    cout << "Testing pop on empty deque:" << endl;
    dq.pop_back(); // Should print "Deque is empty !!"

    return 0;
}