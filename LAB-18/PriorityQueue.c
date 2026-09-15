#include <stdio.h>

#define SIZE 5

int pqueue[SIZE];
int front = -1, rear = -1;

void insert(int value) {
    if (rear == SIZE - 1) {
        printf("Priority Queue is Full\n");
    } else {
        if (front == -1) {
            front = rear = 0;
            pqueue[rear] = value;
        } else {
            int i;
            for (i = rear; i >= front; i--) {
                if (value > pqueue[i]) {
                    pqueue[i + 1] = pqueue[i];
                } else {
                    break;
                }
            }
            pqueue[i + 1] = value;
            rear++;
        }
    }
}

void delete() {
    if (front == -1) {
        printf("Priority Queue is Empty\n");
    } else {
        printf("Deleted: %d\n", pqueue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Priority Queue is Empty\n");
    } else {
        printf("Priority Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", pqueue[i]);
        }
        printf("\n");
    }
}

int main() {
    insert(10);
    insert(30);
    insert(20);
    display();
    delete();
    display();
    return 0;
}
