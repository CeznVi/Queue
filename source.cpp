#include <iostream>
#include <Windows.h>
#include "Queue.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "Демонстрація роботи переробленої черги\n";
    PriorityQueue<int> q;
    PriorityQueue<int> q2;

    q.enqueue(1, PRIORITY::HIGH);
    q.print();
    q2.enqueue(999, PRIORITY::HIGH);
    q2.enqueue(998, PRIORITY::HIGH);
    q2.enqueue(997, PRIORITY::HIGH);
    q2.enqueue(996, PRIORITY::HIGH);
    q2.print();
    q = q2;
    cout << "q is = \n";
    q.print();

    q.enqueue(10);
    q.enqueue(111, PRIORITY::MEDIUM);
    q.enqueue(112, PRIORITY::MEDIUM);
    q.enqueue(113, PRIORITY::MEDIUM);
    q.enqueue(20);
    q.enqueue(30);
    q.print();
    q.dequeue();
    q.dequeue();
    q.print();


    return 0;
}
