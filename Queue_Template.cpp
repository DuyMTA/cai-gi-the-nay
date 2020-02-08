#include<iostream>
#include<math.h>
using namespace std;
template<typename T> class Queue;
template<typename T> 
class Node{
	friend class Queue<T>;
	private:
		T data;
		Node<T> *next;
	public:
		Node(const T&);
};
template<typename T>
Node<T>::Node(const T& value)
{
	data = value;
	next = NULL;
}
template<typename T>
class Queue{
	private:
		Node<T> *first;
		Node<T> *ptri;
		Node<T> *last;
		int size;
	public:
		Queue();
		~Queue();
		void DeQueue(T&);
		Queue<T> &EnQueue(const T&);
		void PrintQueue();
		bool isEmpty() const;
};
template<typename T>
Queue<T>::Queue()
{
	first = NULL;
	size = 0;
}
template<typename T>
Queue<T>::~Queue()
{
	if(size > 0)
	{
		Node <T> *cur = first;
		Node <T> *temp;
		while(cur != 0){
			temp = cur;
			cur = cur->next;
			delete temp;
		}
	}
}
template<typename T>
void Queue<T>::DeQueue(T& i)
{
	if(ptri == first)
	ptri = NULL;
	if(size == 0) cout << "Hang doi rong";
	Node<T> *temp = first;
	first = temp->next;
	i = temp->data;
	delete temp;
	-- size;
	return;
}
template<typename T>
Queue<T> &Queue<T>::EnQueue(const T& value)
{
	Node<T> *temp = new Node<T>(value);
	if(temp == NULL)
	{
		cout << "Tran bo nho." << endl;
		return *this;
	}
	if(size == 0)
	{
		first = last = temp ;
	}
	else
	{
		last->next = temp;
		last = temp;
	}
	++size;
	ptri = last;
	return *this;
}
template<typename T>
void Queue<T>::PrintQueue()
{
	Node<T> *temp;
	temp = first;
	while(temp-> next != NULL)
	{
		cout << temp->data << "\t";
		temp = temp->next;
	}
}
template<typename T>
bool Queue<T>::isEmpty() const
{
	return size == 0;
}
main()
{
	int a;
	Queue<int> MyQueue;
	if(MyQueue.isEmpty()) cout << "Hang doi rong" << endl;
	for(int i = 0; i < 10; i++)
	{
		MyQueue.EnQueue(i);
	}
	MyQueue.PrintQueue();
	MyQueue.DeQueue(a);
	cout << endl << "Gia tri o dau hang doi: " << a << endl; 
	MyQueue.PrintQueue();
}
