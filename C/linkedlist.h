
typedef struct Node Node;

typedef struct List List;

void prepend(List *target, Node *node);
void append(List *target, Node *node);
Node removeFront(List *target);
Node removeBack(List *target);
Node node(int val);
List list();

void print(List *src);
void printNode(Node n);