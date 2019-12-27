#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>  

#include "BezierCurveReconstruction.h"
#include <xstring>
template <typename DATA>
class Node
{
public:
	Node* next;
	DATA data;
};

using namespace std;

template <typename DATA>
class LinkedList
{
public:
	int length;
	Node<DATA>* head;
	LinkedList();
	~LinkedList();
	void addfirst(DATA data);
	void addtail(DATA data);
	void remove(string data);
	bool find(string data);
	void print();
};
template <typename DATA>
LinkedList<DATA>::LinkedList() {
	this->length = 0;
	this->head = nullptr;
}
template <typename DATA>
LinkedList<DATA>::~LinkedList() {
	std::cout << "LIST DELETED";
}
template <class DATA>
void LinkedList<DATA>::addfirst(DATA data) {
	Node<DATA>* node = new Node<DATA>();
	node->data = data;
	node->next = this->head;
	this->head = node;
	this->length++;
}
template <class DATA>
void LinkedList<DATA>::addtail(DATA data) {
	Node<DATA>* node = new Node<DATA>();
	Node<DATA>* temp = this->head;
	node->data = data;
	node->next = NULL;
	if (head == NULL) {
		node->next = this->head;
		this->head = node;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = node;
	}
	this->length++;
}
template <class DATA>
bool LinkedList<DATA>::find(string name) {
	Node<DATA>* node = this->head;
	if (this->head == NULL) {
		return false;
	}
	NhanVien* temp = new NhanVien;
	temp = node->data;
	while (temp->getname() != name)
	{
		if (node->next = NULL) {
			cout << "\nKhong co trong danh sach." << endl;
			return false;
		}
		else {
			node = node->next;
			temp = node->data;
		}
	}
	temp->xuat();
	return true;
}
template <class DATA>
void LinkedList<DATA>::remove(string name) {
	Node<DATA>* node = this->head;
	Node<DATA>* temp = NULL;
	NhanVien* nv = new NhanVien();
	nv = node->data;
	if (find(name)) {
		while (nv->getname() != name)
		{
			node = node->next;
			nv = node->data;
		}
		if (node == head) {
			temp = head;
			head = node->next;
			delete temp;
		}
		else if (node->next == NULL) {
			node = head;
			while (node->next->next != NULL) {
				node = node->next;
			}
			temp = node;
			delete node->next;
			temp->next = NULL;
		}
		else {
			temp = node;
			nv = temp->data;
			NhanVien* tmp = new NhanVien();
			node = head;
			while (tmp->getname() != name) {
				node = node->next;
				tmp = (node->next)->data;
			}
			/* while (SoSanh(tmp->getname(), nv->getname())) {
				 node = node->next;
				 tmp = (node->next)->data;
			 }*/
			node->next = temp->next;
			delete temp;
		}
	}
	else {
		cout << "\nban da nhap sai thong tin";
	}
}
template <typename DATA>
void LinkedList<DATA>::print() {
	Node<DATA>* head = this->head;
	int i = 1;
	while (head) {
		NhanVien* temp = new NhanVien;
		temp = head->data;
		cout << i << ": ";
		temp->xuat();
		cout << endl;
		head = head->next;
		i++;
	}
}

