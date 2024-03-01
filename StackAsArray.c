// Rafael Clinch
// Chpt5 PA

#include <stdio.h>
#include <stdlib.h>

int* stack;
int capacity;
int top;
int peek();
int pop();
int isEmpty();
int push(int item);
void stackResize();
void printStack();

// Main function
int main() {

    
    printf("Enter the allocation size of the stack: "); // Prompt user to enter allocation size of stack
    scanf("%d", &capacity);

    
    stack = (int*)malloc(capacity * sizeof(int)); // Allocate memory for the stack

   
    printf("Enter the maximum length of the stack: "); // Prompt the user to enter the max length of stack
    scanf("%d", &top);

    // Perform operations
    printf("Item 1 was pushed %s\n", push(1) == 1 ? "successfully" : "unsuccessfully"); 
    printf("Item 2 was pushed %s\n", push(2) == 1 ? "successfully" : "unsuccessfully");
    printf("The top item on the stack is: %d\n", peek());
    printf("Item 3 was pushed %s\n", push(3) == 1 ? "successfully" : "unsuccessfully");
    printf("Stack length: %d\n", top + 1);
    printf("The item popped from the stack was %d\n", pop());
    printf("The top item on the stack is: %d\n", peek());
    printf("Item 4 was pushed %s\n", push(4) == 1 ? "successfully" : "unsuccessfully");
    printf("The stack contents are the following:\n");
    printStack();
    printf("Item 5 was pushed %s\n", push(5) == 1 ? "successfully" : "unsuccessfully");
    printf("The item popped from the stack was %d\n", pop());
    printf("Item 6 was pushed %s\n", push(6) == 1 ? "successfully" : "unsuccessfully");
    printf("The stack contrnts are the following:\n");
    printStack();
    printf("The item popped from the stack was %d\n", pop());
    printf("The stack is emtpy: %s\n", isEmpty() == 1 ? "True" : "False");
    printf("The item popped from the stack was %d\n", pop());
    printf("The item popped from the stack was %d\n", pop());
    printf("The item popped from the stack was %d\n", pop());
    printf("The stack is emtpy: %s\n", isEmpty() == 1 ? "True" : "False");

    
    free(stack); // Clear memory

    return 0;
}

void stackResize() { // This function doubles the capacity of stack when full
    capacity *= 2;
    stack = (int*)realloc(stack, capacity * sizeof(int));
}

int push(int item) { // This function pushes item onto stack
    if (top == capacity - 1) {
        stackResize();
    }
    stack[++top] = item;

    return 1;
}

int pop() { // This function pops the item from top of stack
    if (isEmpty()) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack[top--];
}

int isEmpty() { // This function checks if stack is empty
    return top == -1;
}

int peek() { // This function peeks at the top item of stack
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return -1;
    }
    
    return stack[top];
}

void printStack() { // This function prints the stack
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}