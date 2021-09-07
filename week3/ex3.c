#include <stdio.h>
#include <stdlib.h>
typedef struct Nodes Node;
struct Nodes{
    Node* next;
    int data;
};
void insert_node(Node* head, Node* after_this, Node* to_insert){
    if(after_this->next != NULL && after_this != head){
        to_insert->next = after_this->next;
    }
    after_this->next = to_insert;
}
void print_list(Node* head){
    Node* next = head->next;
    int limit = 0;
    while(next != NULL){
        printf("%d ", next->data);
        next = next->next;
        limit++;
        if (limit > 100) { next = 0;}
    }
}
int main() {
    Node* head = (struct Nodes*)malloc(sizeof(struct Nodes));
    Node* node1 = (struct Nodes*)malloc(sizeof(struct Nodes));
    node1->data = 1;
    Node* node2 = (struct Nodes*)malloc(sizeof(struct Nodes));
    node2->data = 2;
    Node* node3 = (struct Nodes*)malloc(sizeof(struct Nodes));
    node3->data = 3;
    insert_node(head, head, node3);
    insert_node(head, node3, node1);
    insert_node(head, node1, node2);
    print_list(head);
    return 0;
}
