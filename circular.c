#include <stdio.h>
#define MAX 4

int queue[MAX];
int front = -1, rear = -1;

int isFull() {
    if ((front == 0 && rear == MAX - 1) || (rear + 1 == front))
        return 1;
    return 0;
}

int isEmpty() {
    if (front == -1)
        return 1;
    return 0;
}

void insert() {
    int num;
    printf("\nEnter the number: ");
    scanf("%d", &num);

    if (isFull()) {
        printf("\nOVERFLOW\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == MAX - 1 && front != 0) {
        rear = 0;
    } else {
        rear++;
    }

    queue[rear] = num;
}

int delete_element() {
    int val;

    if (isEmpty()) {
        printf("\nUNDERFLOW\n");
        return -1;
    }

    val = queue[front];

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }

    return val;
}

int peek() {
    if (isEmpty()) {
        printf("\nQUEUE IS EMPTY\n");
        return -1;
    } else {
        return queue[front];
    }
}

void display() {
    int i;

    if (isEmpty()) {
        printf("\nQueue is empty\n");
        return;
    }

    printf("\nQueue elements are: ");

    if (front <= rear) {
        for (i = front; i <= rear; i++)
            printf("%d\t", queue[i]);
    } else {
        for (i = front; i < MAX; i++)
            printf("%d\t", queue[i]);
        for (i = 0; i <= rear; i++)
            printf("%d\t", queue[i]);
    }
    printf("\n");
}

int main() {
    int option, val;
    do {
        printf("\n*** Main Menu ***\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                insert();
                break;
            case 2:
                val = delete_element();
                if (val != -1)
                    printf("\nDeleted element: %d\n", val);
                break;
            case 3:
                val = peek();
                if (val != -1)
                    printf("\nFront element: %d\n", val);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while(option != 5);

    return 0;
}

