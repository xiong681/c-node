#pragma once

#include <iostream>   
using namespace std;
template<typename T>
struct node {
	T data;
	node<T>* next;
	node(T val) :data(val), next(nullptr) {}
};
template<typename T>
struct stack2 {
	node<T>* top;
	int count;
	stack2():top(nullptr),count(0){}
	~stack2() {
		node<T>* tem = top;
		while (tem != nullptr) 
		{
			node<T>* cur = tem;
			tem = tem->next;
			delete cur;
			

		}
top = nullptr;
			count = 0;
	}

	void push(T val) 
	{
		node<T>* newnode = new node<T>(val);
		newnode->next = top;
		top = newnode;
		++count;
	}

	void pop()
	{
		if (top == nullptr)
			return;
		node<T>* temp = top;
		top = top->next;
			delete temp;
		count--;

	}

	int getcount() 
	{
		return count;
	}

	void print()
	{
		
		node<T>* tem = top;
	    
		while (tem != nullptr) 
		{
			cout << tem->data<<" ";
			tem = tem->next;


	    }

		cout << endl;

		

	}








};
