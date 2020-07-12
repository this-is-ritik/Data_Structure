
// horner's rule
// calculating polynomial with minimum multiplication
// to calculate this  : a0x^0 + a1x^1 + a2x^2 + ....... + an-1x^n-1 + anx^n


//    a0 + x*(a1 + x*(a2 + x*(.....) ) )


#include<bits/stdc++.h>
using namespace std;


int horner_multiply(int *a,int size,int index,int x)
{
    if(index<size)
    {
        return a[index] + x*(horner_multiply(a,size,index+1,x));
    }
    return 0;
}

int main()
{
    int n;
    cout<<"Enter degree of polynomial : ";
    cin>>n;
    int *a=new int[n+1];
    for(int i=0;i<=n;++i)
    {
        cout<<"Enter coefficient of degree "<<i<<" : ";
        cin>>a[i];
    }
    int x;
    cout<<"Enter x : ";
    cin>>x;
    cout<<horner_multiply(a,n+1,0,x)<<endl;
}