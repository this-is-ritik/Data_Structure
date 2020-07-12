#include<bits/stdc++.h>
using namespace std;
int main()
{
    int *a=new int[10],value=1;
    int pos=5;
    cout<<pos<<endl;
    bool flag=true;
    for(int i=0;i<10;++i)
    {
        if(flag and i==pos)
        {
            value++;
            i--;
            flag=false;
            continue;
        }
        a[i]=value++;
    }
    for(int i=0;i<10;++i)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    // find missing number

    //1st method by sum of n natural numbers
    // for this we need to know the sum of array
    int s=0;
    for(int i=0;i<10;++i)
        s+=a[i];
    int S=(12*11)/2;
    cout<<S-s<<" is missing"<<endl;

    //2nd method
    // in sorted array next element should be previous element + 1
    for(int i=0;i<9;++i)
    {
        if(a[i+1]!=a[i]+1)
        {
            cout<<a[i]+1<<" is missing"<<endl;
            break;
        }
    }

    // 3rd method
    //taking xor of array is missing element
    int x=0;
    for(int i=0;i<10;++i)
    {
        x=x^a[i];
    }

    cout<<x<<" is missing"<<endl;








    //find missing element(s) in array

    // by hashing


    int b[10]={3,7,4,9,12,6,1,11,2,10};
    int max_in_b=12;
    int temp[max_in_b+1]={0};
    for(int i=0;i<10;++i)
    {
        temp[b[i]]++;
    }   
    cout<<"Missing Elements are : ";
    for(int i=0;i<=max_in_b;++i)
    {
        if(temp[i]==0)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;







    // find duplicates in a sorted array
     
    int c[10]={3,6,8,8,10,12,15,15,15,20};
    int i=0;
    while(i<10)
    {
        int j=i+1;
        if(c[i]==c[j])
        {
            cout<<c[i]<<" ";
            while(c[++j]==c[i]);                            // waiting until equal terms come in array
            cout<<"is appearing "<<j-i<<" times"<<endl;

        }
        i=j;
    }





    // find duplicates in an unsorted array
    int d[9]={8,3,3,6,6,8,2,2,7};
    // xor of even no of occurrence of an element is zero
    // using this but it will only yield true result if all other occurrences of other elements is even and required ans
    // element occurrence is 1
    x=0;
    for(int i=0;i<9;++i)
        x=x^d[i];
    cout<<x<<endl;






    return 0;
}
