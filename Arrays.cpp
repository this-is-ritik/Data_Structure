#include<bits/stdc++.h>
using namespace std;
int main()
{
    int A[5];        // this array is stored in stack
    int*p;         // this pointer is stored in stack

    p=new int[5];   //   this array is stored in heap memory


    //This is the difference between new and upper array declaration


    delete [] p;    // this is used to delete a location of a pointer

    
    //     increasing array size alternatively
    
    // we will increase size of *p

    //take a new pointer q
    int*q=new int[10];
    for(int i=0;i<5;++i)                // either use for loop or use memcopy function like memset in cpp
        q[i]=p[i];

    delete [] p;
    p=q;
    q=NULL;
    // size increased of array denoted by p initially
    
    
    return 0;
}