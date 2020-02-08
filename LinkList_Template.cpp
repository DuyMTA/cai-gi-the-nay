#include<iostream>
#include<math.h>
using namespace std;
template<typename T> class LinkedList;
template<typename T> 
class Node{
	friend class LinkedList<T>;
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
class LinkedList{
	private:
		Node<T> *first;
		Node<T> *last;
		Node<T> *ptri;
		int size;
	public:
		LinkedList();
		~LinkedList();
		void deleteAtFirst(T&);
		void deleteAtLast(T&);
		LinkedList<T> &insertAtFirst(const T&);
		LinkedList<T> &insertAtLast(const T&);
		void PrintLinkedList();
		bool isEmpty() const;
};
template<typename T>
LinkedList<T>::LinkedList():ptri(NULL)
{
	first = last = NULL;
	size = 0;
}
template<typename T>
LinkedList<T>::~LinkedList()
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
LinkedList<T> &LinkedList<T>::insertAtFirst(const T& value)
{
	Node<T> *temp = new Node<T>(value);
	if(temp == NULL)
	{
		cout << "Tran bo nho." << endl;
		return *this;
	}
	if(size == 0)
	{
		first = last = temp;
	}
	else
	{
		temp->next = first;
		first = temp;
	}
	++size;
	ptri = first;
	return *this;
}
template<typename T>
LinkedList<T> &LinkedList<T>::insertAtLast(const T& value)
{
	Node<T> *temp = new Node<T>(value);
	if(temp == NULL)
	{
		cout << "Tran bo nho." << endl;
		return *this;
	}
	if(size == 0)
	{
		first = last = temp;
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
void LinkedList<T>::deleteAtFirst(T &i)
{
	if(ptri == first)
	ptri = NULL;
	if(size == 0) return;
	Node<T> *temp = first;
	first = temp->next;
	i = temp->data;
	delete temp;
	-- size;
}
template<typename T>
void LinkedList<T> ::deleteAtLast(T &i)
{
	if(ptri == last)
	ptri = NULL;
	if(size == 0) return;
	Node<T> *temp = first;
	if(temp == last)
	{
		i = last->data;
		delete temp;
		first = last = ptri = NULL;
		-- size;
		return;
	}
	while(temp->next != last)
	temp = temp->next;
	i = last->data;
	delete temp;
	last = temp;
	temp->next = NULL;
	--size;
}
template<typename T>
bool LinkedList<T>::isEmpty() const
{
	return(size > 0);
}
template<typename T>
void LinkedList<T>::PrintLinkedList()
{
	Node<T> *temp;
	temp = first;
	while(temp->next != NULL)
	{
		cout << temp->data << "\t";
		temp = temp->next;
	}
}
main()
{
	int a = 1;
	int b = 2;
	LinkedList<int> list1;
//	for(int i = 0; i < 10; i++)
//	{
//		list1.insertAtFirst(i);
//	}
	for(int i = 0; i < 10; i++)
	{
		list1.insertAtLast(i);
	}
	list1.deleteAtFirst(a);
	list1.deleteAtLast(b);
	list1.PrintLinkedList();
	cout << endl << a << endl << b;
}

