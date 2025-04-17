#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node*next;
}Node;
Node*front=NULL,*rear=NULL;
void enqueue(int data){
    Node*new_node=(Node*)malloc(sizeof(Node));
    if(new_node==NULL){
    printf("Queue Overflow!!\n");
    return;
    }else{
        new_node->data=data;
        new_node->next=NULL;
        if(front==NULL)
        front=rear=new_node;
    else{
    rear->next=new_node;
    rear=new_node;
   }
 }
   printf("Element Added!!\n");
}
void dequeue(){
    if(front==NULL){
        printf("Queue Underflow!!\n");
        return;
    }
    else{
        int data=front->data;
        Node*temp=front;
        front=front->next;
        if(front== NULL){
            rear=NULL;
        }
        free(temp);
        printf("%d is Dequeued!!\n",data);
  }
}
void peek(){
    if(front==NULL)
    printf("Queue is Empty\n");
    else
        printf("%d\n",front->data); 
}
void display(){
    if(front==NULL)
    printf("Stack is Empty\n");
    else{
        printf("Elements are:");
        Node*temp=front;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
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
        int choice, data;
        printf("Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Choice!!!!\n");
        }
    }
    return 0;
}
