#pragma once
#include<iostream>

using namespace std;
template<typename T>
struct node {
	T data;
	node<T>* next;
	node(T val) :data(val), next(nullptr) {}
};
template<typename T>
class nodelist {
private:
	node<T>* head;
	int count;

public:
	nodelist() {
		head = 0;
		count = 0;
	}
	nodelist(const nodelist& other) {
		head = nullptr;
		node<T>* p = other.head;
		while (p != nullptr) {
			push_back(p->data);
			count++;
			p = p->next;
		}


	}
	

	~nodelist() {
		node<T>* p = head;
		while (p != nullptr) {
			node<T>* tem = p;
			p = p->next;
			delete tem;

		}
		head = 0;
		count = 0;
	}
	void push_back(T val) {
		node<T>* newnode = new node<T>(val);
		if (!head) {
			head = newnode;
			count++;
			return;

		}
		node<T>* p = head;
		while (p->next != nullptr) {
			p = p->next;
		}
		p->next = newnode;
		++count;


	}
	void push_front(T val) {
		node<T>* newnode = new node<T>(val);
		newnode->next = head;
		head = newnode;
		++count;

	}
	void insert(T val, int pos) {
		node<T>* newnode = new node<T>(val);
		if (pos == 0) {
			newnode->next = head;
			head = newnode;
			++count;
			return;
		}


		node<T>* p = head;
		for (int i = 0; i < pos - 1; i++) {
			p = p->next;

		}
		newnode->next = p->next;
		p->next = newnode;
		++count;

	}
	void print() {
		node<T>* p = head;
		while (p != nullptr) {
			cout << p->data <<" ";
			p = p->next;
		}
		cout << endl;

	}
	void deletlist(int  a) {
		if (head == nullptr || a < 1) {
			return;
		}
		node<T>* p = head;
		if (a == 1) {
			head = head->next; 
			delete p;  
			count--;
			return;
		}

		for (int i = 0; i < a - 2; i++) {
			p = p->next;
			if (p == nullptr || p->next == nullptr) {
				return;
			}
			node<T>* tem = p->next;
			p->next = tem->next;
			delete tem;
			count--;


		}

	}
	void clearlist() {
		node<T>* tem = head;
		while (tem != nullptr) {
			node<T>* p = tem;
			tem = tem->next;
			delete p;


		}

		head = nullptr;
		cout << " list clear" << endl;
	}

	void insert(T val, int pos, int n) {
		for (int i = 0; i < n; i++) {

			node<T>* newnode = new node<T>(val);
			if (pos == 0) {
				newnode->next = head;
				head = newnode;
				count++;
				continue;
			}
			node<T>* p = head;
			for (int k = 0; k < pos - 1; k++) {
				p = p->next;
			}
			if (p == nullptr)
				break;
			newnode->next = p->next;
			p->next = newnode;
			count++;
		}
	}

	void leftmove(int k) 
	
	{
		if (head == nullptr || head->next == nullptr) {
             return;
	}
			
		k %= count;
		if (k <= 0)
			return;
		
		node<T>* tail = head;
	
		while (tail->next != nullptr)
		{
			tail = tail->next;

		}
	   
		node<T>* p = head;
		for (int i = 0; i < k-1; ++i) 
		{
			p = p->next;

		}
		tail->next = head;
		head = p->next;
		p->next = nullptr;


	}

	void rightmove(int k)

	{
		if (head == nullptr || head->next == nullptr) {
			return;
		}

		k %= count;
		if (k <= 0)
			return;

		node<T>* tail = head;

		while (tail->next != nullptr)
		{
			tail = tail->next;

		}

		node<T>* p = head;
		int step = count - k;
		for (int i = 0; i < step-1; ++i)
		{
			p = p->next;

		}
		tail->next = head;
		head = p->next;
		p->next = nullptr;


	}







};


