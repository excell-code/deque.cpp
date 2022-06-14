#include <iostream>

using namespace std;
struct deq
{
    int r = -1;
    int f = -1;
    int arr[10];
} q;

void enqf(int x)
{
    if (q.f == (q.r + 1) % 10)
    {
        cout << "overflow" << endl;
    }
    else if (q.r == -1 && q.f == -1)
    {
        q.f = 0;
        q.r = 0;
        q.arr[q.f] = x;
    }
    else if (q.f == 0)
    {
        q.f = 9;
        q.arr[q.f] = x;
    }
    else
    {
        q.f = q.f - 1;
        q.arr[q.f] = x;
    }
}

void enqr(int y)
{
    if (q.f == (q.r + 1) % 10)
    {
        cout << "overflow" << endl;
    }
    else if (q.r == -1 && q.f == -1)
    {
        q.r = 0;
        q.f = 0;
        q.arr[q.r] = y;
    }
    else
    {
        q.r = q.r + 1;
        q.arr[q.r] = y;
    }
}

void deqf()
{
    if (q.f == -1 && q.r == -1)
    {
        cout << "deque is under flow" << endl;
    }
    else if (q.f == q.r)
    {
        cout << q.arr[q.f] << " is deleted" << endl;
        q.f = -1;
        q.r = -1;
    }
    else
    {
        cout << q.arr[q.f] << " is deleted" << endl;
        q.f = (q.f + 1) % 10;
    }
}

void deqr()
{
    if (q.r == -1 && q.f == -1)
    {
        cout << "deque is underflow" << endl;
    }
    else if (q.r == 0)
    {
        cout << q.arr[q.r] << " is deleted " << endl;
        q.r = 9;
    }
    else if (q.r == q.f)
    {
        cout << q.arr[q.r] << " is deleted" << endl;
        q.r = -1;
        q.f = -1;
    }
    else
    {
        cout << q.arr[q.r] << " is deleted" << endl;
        q.r = q.r - 1;
    }
}

int main()
{
    char x;
    /*a. for pushing element from rear end
    b. for pushing element from front of queue
    c.deleting elment from front of queue
    d.deleting element from rear end*/
    int num;
    while (true)
    {
        cin >> x;
        switch (x)
        {
        case 'a':
            cin >> num;
            enqr(num);
            break;
        case 'b':
            cin >> num;
            enqf(num);
            break;
        case 'c':
            deqf();
            break;

        case 'd':
            deqr();
            break;
        case 'e':
            return 0;
        }
    }
    return 0;
}
