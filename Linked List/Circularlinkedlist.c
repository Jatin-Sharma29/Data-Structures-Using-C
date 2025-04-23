#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node*next;
}Node;
Node *head=NULL;
Node* createnode(int ele){
    Node*new_node=(Node*)malloc(sizeof(Node));
    new_node->data=ele;
    new_node->next=NULL;
    return new_node;
}
void Insert_At_Begining(int ele){
    Node* new_node=createnode(ele);
    if(head==NULL){
    head=new_node;
    new_node->next=head;
    }else{
        Node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        new_node->next=head;
        head=new_node;
        temp->next=head;
    }
    printf("Node Inserted!!!\n");
}
void Insert_At_End(int ele){
    Node*new_node=createnode(ele);
    if(head==NULL){
    head=new_node;
    new_node->next=head;
    }else{
    Node*ptr=head;
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    ptr->next=new_node;
    new_node->next=head; 
    printf("Node Inserted!!!\n");
    }
}
void Insert_At_Any_Position(int ele,int pos){   
    if(head==NULL)
    printf("List is Empty!!\n");
    else if(pos==1)
    Insert_At_Begining(ele);
    else{
    Node*new_node=createnode(ele);
    Node*p=head;
    int i=1;
    while(i<pos-1 && p->next!=head){
        p=p->next;
        i++;
    }
    if(p->next!=head && pos>0){
    new_node->next=p->next;
    p->next=new_node;
    printf("Node Inserted!!!\n");
    }else
    printf("Invalid Position!!!\n");
   }
}
void Delete_From_Beginning(){
    if(head==NULL){
    printf("List is Empty\n");
    return;
    }
     if(head->next== head){
        free(head);
        head=NULL;
        printf("Element Deleted!!!\n");
        return;
    }
    Node*temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    head=head->next;
    temp->next=head;
    free(temp);
    printf("Element deleted!!!\n");
}
void Delete_from_End(){
    if(head==NULL){
    printf("List is Empty\n");
    return;
    }if(head->next== head){
        free(head);
        head=NULL;
        printf("Element Deleted!!!\n");
        return;
    }
    else{
    Node*temp=head;
    while(temp->next->next!=head){
    temp=temp->next;
    }
    Node*p=temp->next;
    temp->next=head;
    free(p);
    }
    printf("Element Deleted !!!\n");
}
void Delete_from_any_position(int pos){
    if(head==NULL)
    printf("List is Empty\n");
    else if(pos==1){
        Delete_From_Beginning();
    }
    else{
    Node*temp=head;
    int i=1;
    while(i<pos-1 && temp->next!=head){
        temp=temp->next;
        i++;
    }
    if(temp->next!=head && pos>0){
        Node*p=temp->next;
        temp->next=temp->next->next;
        free(p);
        printf("element deleted!!!\n");
    }
    else
    printf("Invalid Position!!!\n");
 }
}
void Search(int target){
    if(head==NULL)
    printf("List is Empty\n");
    else{
        Node*temp=head;
        do{
            if(temp->data==target){
            printf("Element Found!!!\n");
            return;
        }
        temp=temp->next;
    }while(temp!=head);
    printf("Not Found!!!\n");
  }
}
void display(){
    if(head==NULL)
    printf("List is Empty\n");
    else{
    printf("Elements are :\n");
    Node*ptr=head;
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
  }
     printf("\n");
}       
int main(){
    while(1){
        printf("1.Insert at Begining \n");
        printf("2.Insert at End\n");
        printf("3.Insert at any Position\n");
        printf("4.Delete from Beginning\n");
        printf("5.Delete from End\n");
        printf("6.Delete from any position\n");
        printf("7.Search element from list\n");
        printf("8.Display list\n");
        printf("9.Exit\n");
        int choice,data,pos,target;
        printf("Your Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        printf("Enter the element :");
        scanf("%d",&data);
        Insert_At_Begining(data);
        break;
        case 2:
        printf("Enter the element :");
        scanf("%d",&data);
        Insert_At_End(data);
        break;
        case 3:
        printf("Enter the element :");
        scanf("%d",&data);
        printf("Enter the position :");
        scanf("%d",&pos);
        Insert_At_Any_Position(data,pos);
        break;
        case 4:
        Delete_From_Beginning();
        break;
        case 5:
        Delete_from_End();
        break;
        case 6:
        printf("Enter Position :");
        scanf("%d",&pos);
        Delete_from_any_position(pos);
        break;
        case 7:
        printf("Enter target :");
        scanf("%d",&target);
        Search(target);
        break;
        case 8:
        display();
        break;
        case 9:
            exit(0);    
        default:
        printf("Invalid Choice!!!!!\n");   
        }
    }
    return 0;
}
