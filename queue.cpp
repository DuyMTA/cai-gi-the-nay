#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

template <typename T> class Queue;

template <typename T>
class Node{
	friend class Queue<T>;
	  private:
	  //main fields
	  T data;
	  Node<T> *next;
	  //other fields
	  
	  public:
	  //main methods
	  Node(T x){
	  	data = x;
	  	next = NULL;
	  }
	  
	  //other methods
	  
};

template <typename T>
class Queue{
	  private:
	  //main fields
		Node<T> *first;
		Node<T> *last;
		int maxSize, currentSize;
	  //other fields

	  public:
	  //main methods
	  Queue(int x) : first(NULL), last(NULL), currentSize(0){
	  	maxSize = x;
	  }
	  ~Queue(){
	  	if(currentSize > 0)
	  	{
	  		Node<T> *k = first;
	  		Node<T> *temp;
	  		while(k->next != NULL)
	  		{
				temp = k;
				k = k->next;	
				delete temp;
			}
		}
	  }
	  Queue<T>& Push(T);
	  bool isFull();
	  bool isEmpty();
	  T Pop();
	  T Top();
	  //other methods

};
template <typename T>	  
Queue<T> &Queue<T>::Push(T value){
	if(!isFull()){
		Node<T> *x = new Node<T>(value);
		if(x == NULL) cout<<"Tran bo nho"<<endl;
		else
		{
			if(currentSize == 0)
			{
				first = last = x;
			}
			else
			{
				last->next = x;
				last = x;
			}
			++currentSize;
		}
	}
	else cout<<"Full."<<endl;
	
	return *this;
}

template <typename T>
bool Queue<T>::isFull(){
	return (currentSize == maxSize);
}

template <typename T>	  
bool Queue<T>::isEmpty(){
	return (currentSize == 0);
}

template <typename T>	  
T Queue<T>::Pop(){
	if(!isEmpty()){
		Node<T> *temp = first;
		first = first->next;
		currentSize--;
		return temp->data;
		delete temp;
	}
	else
	{
		cout<<"Empty."<<endl;
		return NULL;
	}
}

template <typename T>
T Queue<T>::Top(){
	return first->data;
}

int main()
{
	Queue<int> Number(10);
	
	Number.Push(3);
	Number.Push(4);
	cout<<Number.Pop();
	cout<<Number.Top();
		
	
 return 0;
}

