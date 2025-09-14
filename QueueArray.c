#include <stdio.h>

#define SIZE 8

typedef struct {
    char data;
}arrayType; 

typedef struct {
    arrayType arr[SIZE];
    int front;
    int rear;
}queueArray;

void initArr(queueArray* A);
void enqueueArr(queueArray* A, char data);
void dequeueArr(queueArray* A);
void display(queueArray A);

int main(){
    queueArray A;
    initArr(&A);
    int choice;
    char data;

    printf("----[0]Exit [1]Enqueue [2]Dequeue [3]Display----\n");
    
    do{
        printf("Enter your choice: ");
        scanf("%d", &choice); 

        switch(choice){
            case 0: { 
                printf("Program Exited.");
                break;
            }
            case 1: {
                printf("Enter data: ");
                scanf(" %c", &data);
                enqueueArr(&A, data);
                break; 
            }
            case 2: {
                dequeueArr(&A);
                break;
            }
            case 3: {
                display(A);
                break;
            }
            default: {
                printf("Invalid Input!");
                break;
            }
        }

    } while(choice != 0);


    return 0;
}

void initArr(queueArray* A){
    A->front = 1;
    A->rear = 0;
}

void enqueueArr(queueArray* A, char data){
    int next = (A->rear + 1) % SIZE;

    if ((A->rear + 2) % SIZE == A->front){
        printf("Array is full.\n");
    } else {
        A->rear = next;
        A->arr[next].data = data;
    }
}

void dequeueArr(queueArray* A){
    if ((A->rear + 1) % SIZE == A->front){
        printf("Array is already empty.\n");
    } else { 
        A->front = (A->front + 1) % SIZE; 
    }
}

void display(queueArray A){
    int front = A.front, rear = (A.rear + 1) % SIZE;

    if (front == rear){
        printf("Array is empty.\n");
    } else {
        printf("Array: ");
        while (front != rear){
            printf("%c ", A.arr[front].data);
            front = (front + 1) % SIZE;
        }
    }
    printf("\n");

}

