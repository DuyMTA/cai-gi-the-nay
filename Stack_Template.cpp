#include<iostream>
#include<math.h>
using namespace std;
template<typename T> class Stack;
template<typename T> 
class Node{
	friend class Stack<T>;
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
class Stack{
	private:
		Node<T> *first;
		Node<T> *ptri;
		int size;
	public:
		Stack();
		~Stack();
		void Pop(T&);
		Stack<T> &Push(const T&);
		void PrintStack();
		bool isEmpty() const;
};
template<typename T>
Stack<T>::Stack()
{
	first = NULL;
	size = 0;
}
template<typename T>
Stack<T>::~Stack()
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
void Stack<T>::Pop(T& i)
{
	if(ptri == first)
	ptri = NULL;
	if(size == 0) cout << "Ngan xep rong";
	Node<T> *temp = first;
	first = temp->next;
	i = temp->data;
	delete temp;
	-- size;
	return;
}
template<typename T>
Stack<T> &Stack<T>::Push(const T& value)
{
	Node<T> *temp = new Node<T>(value);
	if(temp == NULL)
	{
		cout << "Tran bo nho." << endl;
		return *this;
	}
	if(size == 0)
	{
		first = temp;
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
void Stack<T>::PrintStack()
{
	Node<T> *temp;
	temp = first;
	while(temp->next != NULL)
	{
		cout << temp->data << "\t";
		temp = temp->next;
	}
}
template<typename T>
bool Stack<T>::isEmpty() const
{
	return size == 0;
}
main()
{
	int a;
	Stack<int> MyStack;
	if(MyStack.isEmpty()) cout << "Ngan xep rong" << endl;
	for(int i = 0; i < 10; i++)
	{
		MyStack.Push(i);
	}
	MyStack.PrintStack();
	MyStack.Pop(a);
	cout << "\nGia tri o dinh ngan xep: " << a << endl; 
	MyStack.PrintStack();
}
