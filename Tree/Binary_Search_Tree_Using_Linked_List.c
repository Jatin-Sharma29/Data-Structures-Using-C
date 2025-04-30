// Binary Search Tree Implementation Using Linked List
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    struct TreeNode*left;
    int data;
    struct TreeNode*right;
} Node;
Node* createnode(int data){
    Node*new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;
    new_node->left=new_node->right=NULL;
    return new_node;
}
void insert(int value){}
void preorder(Node* root){
    if(root!=NULL){
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}
void postorder(Node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}
void levelorder(Node* root){}
void search(Node* root,int value){}
void delete(Node* root,int value){}
int main(){
    int choice,value;
    Node*root=NULL;
    while(1){
        printf("1.Insert\n");
        printf("2.Preorder\n");
        printf("3.Inorder\n");
        printf("4.Postorder\n");
        printf("5.Levelorder\n");
        printf("6.Search\n");
        printf("7.Delete\n");
        printf("8.Exit\n");
        printf("Your Choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 6:
            break;
            case 7:
            break;
            case 8:
            exit(0);
            default:
            printf("Invalid Choice!!!!\n");
        }
    }
    return 0;
}