#include <iostream>
using namespace std;

struct DoublyLinkedListNode {
    int data;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;

    DoublyLinkedListNode(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode* new_node = new DoublyLinkedListNode(data);

    // Case 1: Empty list
    if (llist == nullptr) {
        return new_node;
    }

    // Case 2: Insert at beginning
    if (data < llist->data) {
        new_node->next = llist;
        llist->prev = new_node;
        return new_node;
    }

    // Case 3: Insert somewhere in the middle or at the end
    DoublyLinkedListNode* temp = llist;
    while (temp->next != nullptr && temp->next->data < data) {
        temp = temp->next;
    }

    new_node->next = temp->next;
    new_node->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = new_node;
    }

    temp->next = new_node;

    return llist;
}
