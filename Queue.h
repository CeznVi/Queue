#pragma once
#include<initializer_list>
#include<cassert>
#include "Data.h"
#include "Func.h"

using namespace std;

template<class T>
class BaseQueue
{
protected:
	Data<T>* first = nullptr;
	Data<T>* last  = nullptr;
	size_t   size  = 0;

public:
	BaseQueue() {}
	BaseQueue(initializer_list<T> list);
	virtual ~BaseQueue() = 0;
	BaseQueue(const BaseQueue& q);
	BaseQueue& operator=(const BaseQueue& q);
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
BaseQueue<T>::BaseQueue(initializer_list<T> list)
{
	for (auto i = list.begin(); i < list.end(); i++)
	{
		enqueue(*i);
	}
}

template<class T>
BaseQueue<T>::~BaseQueue()
{
	this->clear();
}

template<class T>
BaseQueue<T>::BaseQueue(const BaseQueue& q)
{
	Data<T>* temp = q.first;
	while (temp)
	{
		this->enqueue(temp->value);
		temp = temp->next;
	}
}

template<class T>
BaseQueue<T>& BaseQueue<T>::operator=(const BaseQueue<T>& q)
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
void BaseQueue<T>::enqueue(const T& value)
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
void BaseQueue<T>::dequeue()
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
T BaseQueue<T>::peek()
{
	assert(size > 0);
	return first->value;
}

template<class T>
size_t BaseQueue<T>::length() const
{
	return size;
}

template<class T>
bool BaseQueue<T>::isEmpty() const
{
	return size == 0;
}

template<class T>
void BaseQueue<T>::clear()
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
void BaseQueue<T>::print() const
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
void BaseQueue<T>::print(int x, int y)
{
	Data<T>* temp = first;
	for (size_t i = 0; i < size; i++)
	{
		if (i <= 10)
		{
			gotoxy(x, y++);
			cout << temp->value << endl;
		}
		else
		{
			if (i < size - 10)
			{
				if (i == size - 10)
				{
					gotoxy(x, y++);
					cout << "======^^^=====" << endl;
				}
				else
				{
					gotoxy(x, y++);
					cout << temp->value << endl;
				}
			}
		}
		
		temp = temp->next;
	}
	cout << endl;
}


/////////////////  QUEUE //////////////
template<class T>
class Queue : public BaseQueue<T>
{

};

/////////////////  RING QUEUE //////////////
template<class T>
class RingQueue : public BaseQueue<T>
{
public:
	void ring();
};


template<class T>
void RingQueue<T>::ring()
{
	if (this->size > 1)
	{
		Data<T>* temp = this->first;
		this->first = this->first->next;
		this->last->next = temp;
		this->last = temp;
		this->last->next = nullptr;
	}
}


/////////////////  PRIORITY QUEUE //////////////
template<class T>
class PriorityQueue : public BaseQueue<T>
{

public:
	void enqueue(const T& value, PRIORITY pri = PRIORITY::LOW);
};

template<class T>
void PriorityQueue<T>::enqueue(const T& value, PRIORITY pri)
{
	Data<T>* temp = new Data<T>;
	temp->value = value;
	temp->pri = pri;

	if (this->size == 0)
	{
		this->first = this->last = temp;
		this->size++;
		return;
	}

	if (pri <= this->last->pri)
	{
		this->last->next = temp;
		this->last = temp;
	}
	else if (pri > this->first->pri)
	{
		temp->next = this->first;
		this->first = temp;
	}
	else
	{
		Data<T>* pos = this->first;
		while (pri <= pos->next->pri)
		{
			pos = pos->next;
		}
		temp->next = pos->next;
		pos->next = temp;
	}
	this->size++;
}

