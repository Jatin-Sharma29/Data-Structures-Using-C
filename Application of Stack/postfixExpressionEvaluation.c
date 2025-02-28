#include <stdio.h>
#include <string.h>
#include <math.h>
#include<ctype.h> 
int operand[100],top1=-1;
int postfix_Evaluation(char *exp){
    for(int i=0;exp[i]!='\0';i++){
        char ch=exp[i];
        if(isdigit(ch)){
            int num=0;
            while(isdigit(exp[i])){
                num=num*10+exp[i]-48;
                i++;
            }
            i--;
            operand[++top1]=num;
        }
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
            int z;
            int x=operand[top1--];
            int y=operand[top1--];
            char opr=ch;
            switch(opr){
                case'+':
                z=y+x;
                break;
                case'-':
                z=y-x;
                break;
                case'*':
                z=y*x;
                break;
                case'/':
                z=y/x;
                break;
                case'^':
                z=pow(y,x);
                break;
            }
            operand[++top1]=z;
        }     
    }
    return operand[top1--];
}
int main(){
    char exp[100];
    printf("Enter Postfix Expression : ");
    gets(exp);
    printf("Result : %d\n",postfix_Evaluation(exp));
    return 0;
}