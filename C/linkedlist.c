    #include <stdio.h>
    #include <stdlib.h>
    #include "linkedlist.h"

    struct Node{
        int value;
        struct Node *next;
        struct Node *prev;
    };

    struct List
    {
        Node *head;
        Node *tail;
    };
/*
* This main method just test to make sure the list functions work.
*/
/*
int main() {
    List myList = {NULL, NULL};
    
    Node node1 = {10, NULL};
    Node node2 = {11, NULL};
    Node node3 = {12, NULL};

    append(&myList, &node1);
    append(&myList, &node2);
    append(&myList, &node3);
    print(&myList);
    removeFront(&myList);
    print(&myList);
    removeBack(&myList);
    print(&myList);

    Node node4 = {13, NULL};
    Node node5 = {14, NULL};

    append(&myList, &node4);
    print(&myList);
    prepend(&myList, &node5);
    print(&myList);

    return 0;
}*/

void append(List *target, Node* node)
{
    if (target->tail == NULL)
    {
        target->head = node;
        target->tail = node;
    } else
    {
        target->tail->next = node;
        node->prev = target->tail;
        target->tail = node;
    }
}

void prepend(List *target, Node* node) {
    if (target->head == NULL)
    {
        target->head = node;
        target->tail = node;
    } else
    {
        node->next = target->head;
        target->head->prev = node;
        target->head = node;
    }
}

Node removeFront(List *target) {
    if (target->head == NULL)
    {
        //do nothing?
    } else if (target->head->next == NULL)
    {
        Node* temp = target->head;
        target->head = NULL;
        target->tail = NULL;
        return *temp;
    } else
    {
       Node* temp = target->head;
       target->head = target->head->next;
       target->head->prev = NULL;
       return *temp;
    }
}

Node removeBack(List *target) {
    if (target->tail == NULL)
    {
        //do nothing?
    } else if (target->tail->prev == NULL)
    {
        Node* temp = target->tail;
        target->head = NULL;
        target->tail = NULL;
        return *temp;
    } else
    {
       Node* temp = target->tail;
       target->tail = target->tail->prev;
       target->tail->next = NULL;
       return *temp;
    }
}

void print(List *src)
{
    Node *cur = src->head;
    if (cur == NULL) printf("empty");
    while (cur != NULL)
    {
        printf("%d -> ", cur->value);
        cur = cur->next;
    }
    printf("\n");
}

void printNode(Node n) {
    printf("%d\n", n.value);
}

List list() {
    List myList = {NULL, NULL};
    return myList;
}

Node node(int val) {
    Node node;
    node.value = val;
    return node;
}
