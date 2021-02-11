#include <iostream>
#include <string>

using namespace std;

template <class T>
class Node {
	private:
		T val;
		Node* next;
		Node* prev;
	public:
		Node(T val, Node* prev = NULL, Node* next = NULL) {
			this->val = val;
			this->prev = prev;
			this->next = next;
		}
		
		T getVal() {
			return this->val;
		}
		
		Node* getNext() {
			return this->next;
		}
		
		Node* getPrev() {
			return this->prev;
		}
		
		void setNext(Node *next) {
			this->next = next;
		}
		
		void setPrev(Node *prev) {
			this->prev = prev;
		}
		
		void print() {
			cout << this->val << endl;
		}
};

template <class U>
class LinkedList {
	private:
		Node<U> *head;
		Node<U> *tail;
	public:
	
		LinkedList(Node<U> *head =  NULL) {
			this->head = head;
			Node<U> *cur = head;
			if (cur != NULL) {
				while (cur->getNext() != NULL) {
				cur = cur->getNext();
			}
			}
			this->tail = cur;
		}
		
		void append(U val) {
			Node<U> *node = new Node<U>(val);
			if (head == NULL) {
				this->head = node;
				this->tail = node;
			} else {
				this->tail->setNext(node);
				node->setPrev(this->tail);
				this->tail = node;
			}
		}
		
		void prepend(U val) {
			Node<U> *node = new Node<U>(val);
			if (head == NULL) {
				this->head = node;
				this->tail = node;
			} else {
				node->setNext(this->head);
				this->head->setPrev(node);
				this->head = node;
			}
		}
		
		Node<U>* removeFirst() {
			if (this->head == NULL) return NULL;
			Node<U> *temp = this->head;
			this->head = this->head->getNext();
			if (this->head != NULL) this->head->setPrev(NULL);
			else this->tail = NULL;
			temp->setPrev(NULL);
			temp->setNext(NULL);
			return temp;
		}
		
		Node<U>* removeLast() {
			if (this->tail == NULL) return NULL;
			Node<U> *temp = this->tail;
			this->tail = this->tail->getPrev();
			if(this->tail != NULL) this->tail->setNext(NULL);
			else this->head = NULL;
			temp->setPrev(NULL);
			temp->setNext(NULL);
			return temp;	
		}
		
		void print() {
			Node<U> *cur = this->head;
			while(cur != NULL) {
				cout << cur->getVal() << " -> ";
				cur = cur->getNext();
			}
			cout << endl;
		}
		
		
};

/*int main() {
	LinkedList<int> myList;
	myList.append(11);
	myList.append(10);
	myList.append(9);
	myList.append(8);
	myList.prepend(7);
	myList.print();
	myList.removeFirst()->print();
	return 0;
}*/
