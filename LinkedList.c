// Rafael Clinch
// Chpt4 PA

#include <stdio.h>
#include <stdlib.h>

// Struct to hold the data and pointer of a node
struct node {
    int data;
    struct node *next;
};

// Pointer to the head node
struct node *head = NULL;

// Function to perform the same list operation as the pseudocode found in section 4.2.5
void listPrepend(int data) {
    struct node *lk = (struct node*) malloc(sizeof(struct node));
    lk->data = data;
    lk->next = head;
    head = lk;
}

// Function to perform the same list operation as the pseudocode found in section 4.2.3
void listAppend(int data) {
    if (head == NULL) {
        listPrepend(data);
    } else {
        struct node *lk = (struct node*) malloc(sizeof(struct node));
        lk->data = data;
        struct node *linkedlist = head;
        while (linkedlist->next != NULL) {
            linkedlist = linkedlist->next;
        }
        linkedlist->next = lk;
    }
}

// Function to perform the same list operation as the pseudocode found in section 4.3.1
void listInsertAfter(struct node *list, int data) {
    if (list == NULL) {
        // Error: list is NULL, cannot insert after a NULL pointer
        return;
    }
    struct node *lk = (struct node*) malloc(sizeof(struct node));
    lk->data = data;
    lk->next = list->next;
    list->next = lk;
}

// Function to perform the same list operation as the pseudocode found in section 4.4.1
void listRemoveNode(int key) {
    struct node *temp = head, *prev;
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

// Function to perform the same list operation as the pseudocode found in section 4.5.1
int listSearch(int key) {
    struct node *temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// Function to perform the same list operation as the pseudocode found in section 4.9.1
void listTraverse() {
    struct node *p = head;
    printf("\nThe list order is: ");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

// Implement sumDataValues method
int sumDataValues() {
    struct node *temp = head; 
    int sum = 0;
    while (temp != NULL) {
        sum += temp->data; 
        temp = temp->next;
    }
    return sum;
}

int main() {
    listAppend(1); // Append a node with a data value of 1 to the linked list
    listAppend(2); // Append a node with a data value of 2 to the linked list
    listPrepend(3); // Prepend a node with a data value of 3 to the linked list
    listInsertAfter(head, 4); // Insert a node with a data value of 4 after the head node in the linked list
    listAppend(5); // Insert a node with a data value of 5 at the end of the linked list
    struct node *temp = head;
    while (temp != NULL && temp->data != 4) { // Insert a node with a data value of 6 after the node with a data value of 4 in the linked list
        temp = temp->next;
    }
    if (temp != NULL) {
        listInsertAfter(temp, 6);
    }
    temp = head;
    while (temp != NULL && temp->data != 2) { // Insert a node with a data value of 7 after the node with a data value of 2 in the linked list
        temp = temp->next;
    }
    if (temp != NULL) {
        listInsertAfter(temp, 7);
    }
    listTraverse(); // Display the list
    listRemoveNode(3); // Remove the head node
    temp = head;
    while (temp != NULL && temp->data != 7) { // Remove the node after the node with a data value of 7
        temp = temp->next;
    }
    if (temp != NULL) {
        listRemoveNode(temp->next->data); 
    }
    listTraverse(); // Display the list
    printf("\nNode with data value 5 is%sfound", listSearch(5) ? " " : " not "); // Search for the node with a data value of 5 and display if it was found or not found
    printf("\nNode with data value 2 is%sfound", listSearch(2) ? " " : " not "); // Search for the node with a data value of 2 and display if it was found or not found
    printf("\nThe sum of the linked list data values is %d", sumDataValues()); // Sum and display the sum of the node values
    return 0;
}
