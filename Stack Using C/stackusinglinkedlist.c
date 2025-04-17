#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node*next;
}Node; // we can also write *top=NULL after the braces to define a global top.
Node*top=NULL;
void push(int data){
    Node*new_node=(Node*)malloc(sizeof(Node));
    if(new_node==NULL)
        printf("Stack overflow!!\n");
    else{
    new_node->data=data;
    new_node->next=top;
    top=new_node;
    printf("Element Pushed!!!\n");
    }
}
void pop(){
    if(top==NULL){
    printf("Stack Underflow!!\n");
    return;
    }
    else{
    int data=top->data;
    Node*temp=top;
    top=top->next;
    free(temp);
    printf("%d is popped!!!\n",data);
    }
}
void peek(){
    if(top==NULL)
    printf("Stack is Empty\n");
    else
        printf("%d\n",top->data); 
}
void display(){
    if(top==NULL)
    printf("Stack is Empty\n");
    else{
        printf("Elements are:");
        Node*temp=top;
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
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        int choice, data;
        printf("Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Element:");
            scanf("%d",&data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Choice!!!!\n");
        }
    }
    return 0;
}