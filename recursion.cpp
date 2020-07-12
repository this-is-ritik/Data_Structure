#include<bits/stdc++.h>
using namespace std;


//   recursion 
void fun(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        fun(n-1);
    }
}


int func(int n)
{
    static int x=0;
    if(n>0)
    {
        cout<<x<<" ";
        x++;
        return x+func(n-1);
    }
    return 0;
}

void tree_recursion(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        tree_recursion(n-1);
        cout<<" ";
        tree_recursion(n-1);
        cout<<" ";
    }
}

// sum of first n natural numbers
int sumofnnumbers(int n)
{
    if(n>0)
    {
        return n+sumofnnumbers(n-1);
    }
    return 0;
}

// factorial of a number
int factorial(int n)
{
    if(n<0)
    {
        cout<<"Not Possible";
        return -1;
    }
    else if(n==0)
        return 1;
    else
        return n*factorial(n-1);
}


int power(int x,int n)
{
    if(n>0)
    {
        return x*power(x,n-1);
    }
    return 1;
}

int power_modified(int x,int n)
{
    if(n==0)
        return 1;
    // even cases of n
    if(n%2==0)
        return power_modified(x*x,n/2);
    //odd cases of n
    return x*power_modified(x*x,(n-1)/2);
}


// e^x = sum( (x^i)/i!  )   i=0 to n
double Taylor(int x,int n)
{
    static double p=1,f=1;
    if(n==0)
        return 1.0;
    double r=Taylor(x,n-1);
    p=p*x;
    f=f*n;
    return r+p/f;
}

double Taylor_using_horner(int x,int n)
{
    static double S=1.0;
    if(n==0)
        return S;
    S=1.0+x*S/n;
    return Taylor_using_horner(x,n-1);
}

int f[1000]={-1};
int fib(int n)
{
    if(n<=1)
    {
        f[n]=n;
        return n;
    }
    if(f[n-2]==-1)
        f[n-2]=fib(n-2);
    if(f[n-1]==-1)
        f[n-1]=fib(n-1);
    return f[n-1]+f[n-2];
}


// combination nCr
int nCr(int n,int r)
{
    int t1,t2,t3;
    t1=factorial(n);
    t2=factorial(r);
    t3=factorial(n-r);
    return t1/(t2*t3);
}

//but by pascal triangle

//                  1
//                 1 1
//                1 2 1
//               1 3 3 1
//              1 4 6 4 1

int nCr_modified(int n,int r)
{
    if(r==0 or n==r)
        return 1;
    return nCr_modified(n-1,r-1)+nCr_modified(n-1,r);
}

void TowerOfHanoi(int disks,int A,int B,int C)
{
    if(disks>0)
    {
        TowerOfHanoi(disks-1,A,C,B);
        cout<<A<<"->"<<C<<endl;
        TowerOfHanoi(disks-1,B,A,C);
    }
}
int main()
{
    int n=3;
    fun(n);
    cout<<endl;
    int res=func(n);
    cout<<endl;
    cout<<res;
    cout<<endl;
    tree_recursion(n);
    cout<<endl;
    n++;
    cout<<sumofnnumbers(n)<<endl;
    cout<<factorial(n)<<endl;    
    cout<<factorial(-1)<<endl;
    cout<<power(3,0)<<endl;
    // a function calling A, A calling B, B calling C, C calling A again is known as indirect recursion
    
    
    // if parameter to a function is recursive call then it is called as nested recursion
    cout<<power_modified(3,4)<<endl;

    cout<<Taylor(2,10)<<endl;

    cout<<Taylor_using_horner(2,10)<<endl;

    cout<<fib(10)<<endl;


    cout<<nCr(4,2)<<endl;
    cout<<"Tower of Hanoi\n";
    TowerOfHanoi(2,1,2,3);

}