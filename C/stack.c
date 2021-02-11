#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "linkedlist.c"
#include "stack.h"

struct Stack {
    List *dbLinkedList;
};

int main() {
    List myList = list();
    Stack myStack = {&myList};

    Node n1 = node(12);
    Node n2 = node(11);
    Node n3 = node(10);
    push(&myStack, &n2);
    push(&myStack, &n1);
    push(&myStack, &n3);


    print(myStack.dbLinkedList);

    printNode(pop(&myStack));
    print(myStack.dbLinkedList);

    return 0;
}

void push (Stack *target, Node* node) {
    append(target->dbLinkedList, node);
}

Node pop(Stack *target) {
    return removeBack(target->dbLinkedList);
}