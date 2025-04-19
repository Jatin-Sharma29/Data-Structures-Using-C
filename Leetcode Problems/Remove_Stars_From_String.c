char* removeStars(char* s) {
    int top=-1;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]!='*'){
            s[++top]=s[i];
        }
        else if(s[i]=='*')
        top--;
    }
    s[++top]='\0';
    return s;
}
