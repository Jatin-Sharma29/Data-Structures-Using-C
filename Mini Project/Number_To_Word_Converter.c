#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *units[]={"","one","two","three","four","five","six","seven","eight","nine","ten",
               "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
char *tens[]={"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
char *scale[]={"","thousand","million","billion"};


void Convert_chunks_to_word(int num,char*result){
    result[0]='\0';
    if(num==0) return;
    int hundreds=num/100;
    int remainder=num%100;
    if(hundreds>0){
        strcat(result,units[hundreds]);
        strcat(result," hundred");
        if(remainder>0){
            strcat(result," ");
        }
    }
    if(remainder>0){
        if(remainder<20){
            strcat(result,units[remainder]);
        }else{
            int ten=remainder/10;
            int unit=remainder%10;
            strcat(result,tens[ten]);
            if(unit>0){
                strcat(result," ");
                strcat(result,units[unit]);
            }
        }
    }
}
void Convert_to_words(int num,char*final_result){
    final_result[0]='\0';
    if(num==0){
        strcat(final_result,"zero");
        return;
    }
    int chunk[4];
    int chunk_count=0;
    int flag=0;
    if(num<0){
        flag=1;
        num=-num;
    }
    while(num>0){
        chunk[chunk_count]=num%1000;
        num=num/1000;
        chunk_count++;
    }
    char chunk_words[100];
    final_result[0]='\0';
    if(flag){
        strcat(final_result,"minus ");
    }
    for(int i=chunk_count-1;i>=0;i--){
        if(chunk[i]!=0){
            Convert_chunks_to_word(chunk[i],chunk_words);
            strcat(final_result,chunk_words);
            if(strlen(scale[i]) > 0){
                strcat(final_result," ");
                strcat(final_result,scale[i]);
            }
            if(i>0){
                strcat(final_result," ");
            }
        }
    }
}
int main(){
    int num;
    char result[500];
    printf("Enter The Number:");
    scanf("%d",&num);
    Convert_to_words(num,result);
    printf("The Number in Words is: %s\n",result);
    return 0;
}