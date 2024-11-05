
#include <iostream>

//Det her er opgave 'LabWeek05Part2of2' fra uge 5!! Fra DSA Tutorials

// Standard Input/Output library for C
#include <stdio.h>
#include <stdlib.h>

// Define the structure for each node in the queue
struct Node {
    int data;
    struct Node* next;
};

// Define the front and rear pointers for the queue
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to initialize an empty queue 
void initializeQueue() {
    front = rear = NULL;
}

//b) Function to check if the queue is empty
bool isEmpty() {
    return (front == NULL);
}

// Function to add an element to the queue
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Function to remove an element from the queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty, cannot dequeue.\n");
        return -1; 
    }
    struct Node* temp = front;
    int value = temp->data;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
    return value;
}

// Function to display all elements in the entire queue with displayQueue
void displayQueue() {
struct Node* temp = front;
	if (isEmpty()) {
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements are: ");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

// Function to return the size of the queue
int queueSize() {
    int size = 0;
    struct Node* temp = front;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }
    return size;
}

int main()
{
    // Call initializeQueue inside main to initialize the queue
    initializeQueue();
    printf("Queue initialized and empty.\n");

    enqueue(22);
    enqueue(33);
    enqueue(44);
	displayQueue();


    // Dequeue elements
    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());
    displayQueue();

    // Display the size of the queue
    printf("Size of the queue: %d\n", queueSize());
    return 0;
 
}

