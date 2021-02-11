#include <iostream>
#include <string>
#include "linkedlist.cpp"

template<class T>
class Stack {
	private:
		LinkedList<T> *dbLinkedList;
	public:
		Stack(LinkedList<T> *dbLinkedList = new LinkedList<T>) {
			this->dbLinkedList = dbLinkedList;
		}
		
		void push(T val) {
			dbLinkedList->append(val);	
		}
		
		Node<T>* pop() {
			return dbLinkedList->removeLast();
		} 
};

int main() {
	Stack<int> myStack;
	myStack.push(1);
	myStack.push(2);
	myStack.push(3);
	myStack.pop()->print();
	myStack.pop()->print();
	myStack.pop()->print();
}



