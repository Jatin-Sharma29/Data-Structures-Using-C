char* removeDuplicates(char* s) {
    int top=-1;
    for(int i=0;s[i]!='\0';i++){
        if(top>=0 && s[top]==s[i])
        top--;
        else{
        top++;
        s[top]=s[i];
        }
    }
    s[++top]='\0';
    return s;   
}
