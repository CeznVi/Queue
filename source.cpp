#include <iostream>
#include <Windows.h>
#include "Queue.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "Демонстрація роботи переробленої черги\n";

	PriorityQueue<int> q = { 1,2,3 };
    q.print();
    q.enqueue(10, PRIORITY::MEDIUM);
    q.enqueue(20, PRIORITY::HIGH);
    q.enqueue(30, PRIORITY::HIGH);
    q.print();
    q.dequeue();
    q.dequeue();
    q.print();

    return 0;
}
