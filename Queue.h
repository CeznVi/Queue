#pragma once
#include<initializer_list>
#include<cassert>
#include "Data.h"
#include "Func.h"
////×ÅÐÃÀ Ï²ÑËß ìîäåðí³çàö³¿
//ÍÅÄÎÐÎÁÈÂ


using namespace std;

template<class T>
class BasicQueue
{
protected:
	Data<T>* first = nullptr;
	Data<T>* last = nullptr;
	size_t   size = 0;

public:
	BasicQueue() {}
	BasicQueue(initializer_list<T> list);
	~BasicQueue();
	BasicQueue(const BasicQueue& q);
	BasicQueue<T>& operator=(const BasicQueue<T>& q);
	void enqueue(const T& value);
	void dequeue();
	T peek();
	size_t length() const;
	bool isEmpty() const;
	void clear();
	void print() const;
	void print(int x, int y);
};

template<class T>
BasicQueue<T>::BasicQueue(initializer_list<T> list)
{
	for (auto i = list.begin(); i < list.end(); i++)
		enqueue(*i);
}

template<class T>
BasicQueue<T>::~BasicQueue()
{
	this->clear();
}

template<class T>
BasicQueue<T>::BasicQueue(const BasicQueue& q)
{
	Data<T>* temp = q.first;
	while (temp)
	{
		this->enqueue(temp->value);
		temp = temp->next;
	}
}

template<class T>
BasicQueue<T>& BasicQueue<T>::operator=(const BasicQueue<T>& q)
{
	Data<T>* temp = q.first;
	while (temp)
	{
		this->enqueue(temp->value);
		temp = temp->next;
	}
	return *this;
}

template<class T>
void BasicQueue<T>::enqueue(const T& value)
{
	if (size == 0)
	{
		first = new Data<T>;
		first->value = value;
		last = first;
	}
	else
	{
		last->next = new Data<T>;
		last->next->value = value;
		last = last->next;
	}
	size++;
}

template<class T>
void BasicQueue<T>::dequeue()
{
	if (size > 0)
	{
		Data<T>* temp = first;
		first = first->next;
		delete temp;
		size--;
		last = (size == 0) ? nullptr : last;
	}
}

template<class T>
T BasicQueue<T>::peek()
{
	assert(size > 0);
	return first->value;
}

template<class T>
size_t BasicQueue<T>::length() const
{
	return size;
}

template<class T>
bool BasicQueue<T>::isEmpty() const
{
	return size == 0;
}

template<class T>
void BasicQueue<T>::clear()
{
	Data<T>* temp = first;
	while (temp)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
	last = nullptr;
	size = 0;
}

template<class T>
void BasicQueue<T>::print() const
{
	Data<T>* temp = first;
	while (temp)
	{
		cout << temp->value << endl;
		temp = temp->next;
	}
	cout << endl;
}

template<class T>
void BasicQueue<T>::print(int x, int y)
{
	Data<T>* temp = first;
	for (size_t i = 0; i < size; i++)
	{
		if (i <= 10)
		{
			gotoxy(x, y++);
			cout << temp->value << '\n';
		}
		else
		{
			if (i < size - 10)
			{
				if (i == size - 10)
				{
					gotoxy(x, y++);
					cout << "======^^^=====" << '\n';
				}
				else
				{
					gotoxy(x, y++);
					cout << temp->value << '\n';
				}
			}
		}

		temp = temp->next;
	}
	cout << '\n';
}

template<class T>
class QueueRing : public virtual BasicQueue<T>
{


public:
	QueueRing() : BasicQueue() {}
	QueueRing(initializer_list<T> list);
	~QueueRing();
	//QueueRing(const QueueRing& q);
	//QueueRing<T>& operator=(const QueueRing<T>& q);
	void enqueue(const T& value);
	//void print() const;
	void ring();

	

};




template<class T>
QueueRing<T>::QueueRing(initializer_list<T> list)
{
	for (auto i = list.begin(); i < list.end(); i++)
		enqueue(*i);
}

template<class T>
QueueRing<T>::~QueueRing()
{
	this->clear();
}

template<class T>
void QueueRing<T>::enqueue(const T& value)
{
	if (size == 0)
	{
		first = new Data<T>;
		first->value = value;
		last = first;
	}
	else
	{
		last->next = new Data<T>;
		last->next->value = value;
		last = last->next;
	}
	size++;
}

template<class T>
void QueueRing<T>::ring()
{

	if (size > 1)
	{
		Data<T>* temp = first;
		first = first->next;
		last->next = temp;
		last = temp;
		last->next = nullptr;
	}
}

