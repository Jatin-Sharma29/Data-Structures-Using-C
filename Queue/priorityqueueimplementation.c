#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Priority_Queue
{
    int element;
    int priority;
} pqueue;
pqueue pq[MAX];
int front = -1, rear = -1;
int isempty()
{
    return (front == -1) ? 1 : 0;
}
int isfull()
{
    return (rear == MAX - 1) ? 1 : 0;
}
void enqueue(int data, int priority)
{
    rear++;
    pq[rear].element = data;
    pq[rear].priority = priority;
    if (front == -1)
    {
        front = rear;
    }
    printf("Element Inserted!!!\n");
}
int Get_higher_priority_element()
{
    int max = 0, index = -1;
    for (int i = front; i <= rear; i++)
    {
        if (pq[i].priority > max)
        {
            max = pq[i].priority;
            index = i;
        }
    }
    return index;
}
int dequeue()
{
    int index = Get_higher_priority_element();
    int data = pq[index].element;
    if (index == front && index == rear)
        front = rear = -1;
    else if (index == front)
        front++;
    else
    {
        for (int i = index; i < rear; i++)
        {
            pq[i] = pq[i + 1];
        }
        rear--;
    }
    return data;
}
int peek()
{
    int i = Get_higher_priority_element();
    return pq[i].element;
}
void display()
{
    printf("Queue Elements are :\n");
    for (int i = front; i <= rear; i++)
    {
        printf("Element : %d => Priority : %d\n", pq[i].element, pq[i].priority);
    }
    printf("\n");
}
int main()
{
    while (1)
    {
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        int choice, data, pr;
        printf("Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (isfull())
            {
                printf("Queue Overflow\n");
            }
            else
            {
                printf("Enter Element :");
                scanf("%d", &data);
                printf("Enter Priority :");
                scanf("%d", &pr);
                enqueue(data, pr);
            }
            break;
        case 2:
            if (isempty())
            {
                printf("Queue Underflow\n");
            }
            else
            {
                printf("%d is deleted from the queue\n", dequeue());
            }
            break;
        case 3:
            printf("Highest Priority element of Queue is %d:\n", peek());
            break;
        case 4:
            if (isempty())
                printf("Queue is empty\n");
            else
                display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Choice!!!!\n");
        }
        system("pause");
    }
    return 0;
}