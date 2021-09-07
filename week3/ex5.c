#include <stdio.h>
#include <stdlib.h>
typedef struct Nodes Node;
struct Nodes{
    Node* next;
    Node* prev;
    int data;
};
void insert_node(Node* after_this, Node* to_insert){
    if(after_this->next != NULL){
        to_insert->next = after_this->next;
        after_this->next->prev = to_insert;
    }
    after_this->next = to_insert;
    to_insert->prev = after_this;
}
void print_list(Node* head, Node* tail){
    Node* next = head->next;
    while(next != NULL){
        if(next != tail) printf("%d ", next->data);
        next = next->next;
    }
}
void print_list_reverse(Node* head, Node* tail){
    Node* prev = tail->prev;
    while(prev != NULL){
        if(prev != head) printf("%d ", prev->data);
        prev = prev->prev;
    }
}
int main() {
    Node* head = (struct Nodes*)malloc(sizeof(struct Nodes));
    Node* tail = (struct Nodes*)malloc(sizeof(struct Nodes));
    Node* node1 = (struct Nodes*)malloc(sizeof(struct Nodes));
    node1->data = 1;
    Node* node2 = (struct Nodes*)malloc(sizeof(struct Nodes));
    node2->data = 2;
    Node* node3 = (struct Nodes*)malloc(sizeof(struct Nodes));
    node3->data = 3;
    insert_node(head, tail);
    insert_node(head, node3);
    insert_node(node3, node1);
    insert_node(node1, node2);
    print_list(head, tail);
    printf("\n");
    print_list_reverse(head, tail);
    return 0;
}
