#include<bits/stdc++.h>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;
};


void func(int A[],int n)                    // array is passed as reference so value is changed globally
{
    A[0]=20;
}


int area(struct Rectangle r)
{
    // call by value
    return r.length*r.breadth;
}


int Area(struct Rectangle *r)
{
    // call by referance
    (*r).length=50;
    return (*r).length*(*r).breadth;
}




int main()
{
    int a=8;
    // Referance is just an alias to an existing variable
    int &r=a;
    cout<<r<<endl;
    cout<<a<<endl;
    r++;
    cout<<a<<endl;

    // Pointer to structure
    struct Rectangle r1={10,5};
    struct Rectangle *ptr_r1;
    ptr_r1=&r1;
    cout<<(*ptr_r1).length<<endl;              // . precedence is higher than *
    cout<<ptr_r1->length<<endl;                 // 2nd method of use arrow
    
    // Passing of structure
    // Call by value
    
    cout<<"Area of Rectangle : "<<area(r1)<<endl;
    
    // Call by referance
    cout<<"area of rectangle with length = 50 : "<<Area(&r1)<<endl;
    cout<<r1.length<<endl;
    
    // Array passing
    // array passing can be only call by referance not by value
    // but call by value of array can be done by placing array in a structure
    //and passing structure by value
    int A[]={2,4,6,8,10};
    func(A,5);
    cout<<"array : "<<endl;
    cout<<A[0]<<endl;
    return 0;
}