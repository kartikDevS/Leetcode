

bool isPalindrome(int x) {
    if(x<0 || (x%10==0 && x!=0)){
        return false;
    }
    long long a=0;
    int b=x;
    while(b>0){
        a=a*10+b%10;
        b=b/10;
    }
    return x==a;

}