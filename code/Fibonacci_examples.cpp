//regular recursion
int fibonacciRecursion(int n){
    if (n==1)
        return 1;
    if (n==2)
        return 1;
    return fibonacciRecursion(n-1)+fibonacciRecursion(n-2);
}

//dynamic programming
int fibonacciDP(int n, int array[]){
    if (n==0)
        return 0;
    if (n<=2)
        return 1;
    if (array[n-1]==0)
        array[n-1]=fibonacciDP(n-1,array)+fibonacciDP(n-2,array);
    return array[n-1];
}

int main(){
    int fooREG,fooDP;
    int SIZE=6;
    int array[SIZE];
    for (int i=0;i<SIZE;i++){
        array[i]=0;
    }
    fooREG=fibonacciRecursion(SIZE);
    fooDP=fibonacciDP(SIZE,array);
    cout <<fooREG<<endl;
    cout<<fooDP<<endl;
    return 0;
}
