#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int queue[MAX],front=-1,rear=-1;
int isempty(){
    return(front==-1) ? 1 : 0;
}
int isfull(){
    return((rear+1)% MAX==front) ? 1 : 0 ;
}
void enqueue(int data){
    rear=(rear+1)%MAX;
    queue[rear]=data;
    if(front==-1)
    front=rear;
    printf("Element Inserted!!!\n");
}
int dequeue(){
    int data=queue[front];
    if(front==rear)
        front=rear=-1;
    else 
    front=(front+1)%MAX;
    return data;
}
int peek(){ // front 
    return queue[front];
}
void display(){
    printf("Elements of Circular Queue are :\n");
    int i=front;
    while(front!=rear){
        printf("%d ",queue[i]);
        i=(i+1)%MAX;
    }
    printf("%d",queue[rear]);
    printf("\n");
}
int main(){
    while(1){
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        int choice,data;
        printf("Your Choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            if(isfull()){
                printf("Queue Overflow\n");
            }else {
                printf("Enter Element :");
                scanf("%d",&data);
                enqueue(data);
            }
            break;
            case 2:
            if(isempty()){
                printf("Queue Underflow\n");
            }else{
            printf("%d is deleted from the queue\n",dequeue());
            }
            break;
            case 3:
            printf("Front element of Queue is %d:\n",peek());
            break;
            case 4:
            if(isempty())
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
