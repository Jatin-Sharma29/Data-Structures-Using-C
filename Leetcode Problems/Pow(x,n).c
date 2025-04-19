double myPow(double x, int n) {
    double result=1.0;
    long long exp=n;
    int isnegative=(n<0);
   if(exp<0){
    exp=-exp;
    x=1.0/x;
   }
    while(exp>0){
        if(exp%2==1)
        result*=x;
        x*=x;
        exp/=2;
    }
    return result;

}
