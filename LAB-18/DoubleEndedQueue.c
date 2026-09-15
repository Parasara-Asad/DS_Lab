#include <stdio.h>

#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

void insertFront(int value) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Deque is Full\n");
    } else if (front == -1) {
        front = rear = 0;
        deque[front] = value;
    } else if (front == 0) {
        front = SIZE - 1;
        deque[front] = value;
    } else {
        front--;
        deque[front] = value;
    }
}

void insertRear(int value) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Deque is Full\n");
    } else if (front == -1) {
        front = rear = 0;
        deque[rear] = value;
    } else if (rear == SIZE - 1) {
        rear = 0;
        deque[rear] = value;
    } else {
        rear++;
        deque[rear] = value;
    }
}

void deleteFront() {
    if (front == -1) {
        printf("Deque is Empty\n");
    } else if (front == rear) {
        printf("Deleted: %d\n", deque[front]);
        front = rear = -1;
    } else if (front == SIZE - 1) {
        printf("Deleted: %d\n", deque[front]);
        front = 0;
    } else {
        printf("Deleted: %d\n", deque[front]);
        front++;
    }
}

void deleteRear() {
    if (front == -1) {
        printf("Deque is Empty\n");
    } else if (front == rear) {
        printf("Deleted: %d\n", deque[rear]);
        front = rear = -1;
    } else if (rear == 0) {
        printf("Deleted: %d\n", deque[rear]);
        rear = SIZE - 1;
    } else {
        printf("Deleted: %d\n", deque[rear]);
        rear--;
    }
}

void display() {
    if (front == -1) {
        printf("Deque is Empty\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    if (front <= rear) {
        while (i <= rear) {
            printf("%d ", deque[i++]);
        }
    } else {
        while (i <= SIZE - 1) {
            printf("%d ", deque[i++]);
        }
        i = 0;
        while (i <= rear) {
            printf("%d ", deque[i++]);
        }
    }
    printf("\n");
}

int main() {
    insertRear(10);
    insertFront(20);
    insertRear(30);
    display();
    deleteFront();
    display();
    deleteRear();
    display();
    return 0;
}
