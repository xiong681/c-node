#pragma once
#include <iostream>     
template<typename T>
struct node {
	T data;
	node<T>* next;
	node(T val):data(val), next(nullptr){}
};
template<typename T>
class stack1
{
private:
	node<T>* top;
	int count;
public:
	stack1():top(nullptr),count(0)
	{}
	~stack1() 
	{  while(top!=nullptr)
	{
		node<T>* tem = top;
		top = top->next;
		delete tem;
	
	}



	}
	void push(const T& val)
	{
		node<T>* newnode = new node<T>(val);
		newnode->next = top;
		top = newnode;
		++count;	
	}
	void pop()
	{  node<T>* tem = top;
		if (tem == nullptr) {
			std::cout << "空栈"<<std::endl;
				return;

		}
		
		
			
		top = top->next;
		delete tem;
		count--;
	
	}
	T peek()
	{	if(top!=nullptr)
		return top->data;
	}

	int size() const {
		return count;
	}
	void print() {
		if (top == nullptr)
			return;
		node<T>* tem = top;
		while (tem!=nullptr) {
			std::cout << tem->data << " ";
			
			tem = tem->next;

		}
		std::cout << std::endl;

	}




};