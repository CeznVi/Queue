#include <iostream>
#include <Windows.h>
#include "Queue.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "Демонстрація роботи переробленої черги\n";

    QueueRing<int> q = { 1,2,3 };
    q.print();
    //QueueRing<int> q1 = { 11,22,33 };
   
    //q = q1;
    ;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print();
    q.dequeue();
    q.dequeue();
    q.print();





    //enqueue<int> q = { 1,2,3 };
    //q.print();
    //q.enqueue(10, PRIORITY::MEDIUM);
    //q.enqueue(20, PRIORITY::HIGH);
    //q.enqueue(30, PRIORITY::HIGH);
    //q.print();
    //q.dequeue();
    //q.dequeue();
    //q.print();

    return 0;
}
