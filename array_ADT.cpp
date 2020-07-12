#include<bits/stdc++.h>
using namespace std;
struct Array
{
    int*A;
    int size;
    int length;
};

// displays the array
void display(struct Array arr)
{
    for(int i=0;i<arr.length;++i)
    {
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}

// add / append in an array 
void append(struct Array &arr,int data)
{
    if(arr.length==arr.size)
    {
        cout<<"Element cant be added as array is full!!!\n\tOverFlow!!!";
        return;
    }
    arr.A[arr.length]=data;
    arr.length++;
}


// insert in a given position 4

void insert(struct Array &arr,int index,int data)
{
    if(arr.length==arr.size)
    {
        cout<<"Element cant be added as array is full!!!\n\tOverFlow!!!";
        return;
    }
    else if(index<0)
    {
        cout<<"Index should be non-negative!!!";
        return;
    }
    
    else if(index<=arr.length)
    {
        for(int i=arr.length;i>index;--i)
        {
            arr.A[i]=arr.A[i-1];
        }
        arr.A[index]=data;
        arr.length++;
        return;
    }
    else
    {
        cout<<"Your index should be less than length of array!!";
        return;
    }
    
}


// delete an element at given index
void delete_index(struct Array &arr,int index)
{
    if(index<0)
    {
        cout<<"Index should be non-negative!!!";
        return;
    }
    if(index>=arr.length)
    {
        cout<<"Element at given index is unavailable!!!!";
        return;
    }
    cout<<arr.A[index]<<" is being deleted"<<endl;
    for(int i=index;i<arr.length;++i)
    {
        arr.A[i]=arr.A[i+1];
    }
    arr.length--;
    cout<<"Deletion Successfull!!!"<<endl;
}



// linear search


void linear_search(struct Array &arr,int key)
{
    if(arr.length==0)
    {
        cout<<"Array is Empty !!!";
        return;
    }
    for(int i=0;i<arr.length;++i)
    {
        if(arr.A[i]==key)
        {
            cout<<key<<" found at index : "<<i<<endl;
            return;
        }
    }
    cout<<key<<" not found in given array : ";
    display(arr);
}



// binary search but array must be sorted for this
// best case O(1)
// worst case O(logn)
// average case O(logn)
void binary_search(struct Array &arr,int key)
{
    if(arr.length==0)
    {
        cout<<"Array is Empty!!!";
        return;
    }
    int start=0,end=arr.length;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(arr.A[mid]==key)
        {
            cout<<key <<" found at index : "<<mid<<endl;
            return;
        }
        else if(arr.A[mid]<key)
        {
            start=mid+1;
            continue;
        }
        else
        {
            end=mid-1;
            continue;
        }
    }
    cout<<key<<" not found in array : ";
    display(arr);
}



// reverse the array

void reverse(struct Array &arr)
{
    if(arr.length==0)
        return;
    for(int i=0;i<ceil(arr.length/2);++i)
    {
        int temp=arr.A[i];
        arr.A[i]=arr.A[arr.length-i-1];
        arr.A[arr.length-i-1]=temp;
    }
}


// check array is sorted
bool check_sorted(struct Array &arr)
{
    if(arr.length==0 or arr.length==1)
        return true;
    for(int i=0;i<arr.length-1;++i)
    {
        if(arr.A[i]>arr.A[i+1])
            return false;
    }
    return true;
}


// merge two sorted arrays
void merge(struct Array &arr1,struct Array &arr2,struct Array &arr3)
{
    int i=0,j=0;
    int index=0;
    arr3.length=0;
    while(i<arr1.length and j<arr2.length)
    {
        if(arr1.A[i]<=arr2.A[j])
        {
            arr3.A[index++]=arr1.A[i++];
        }
        else
        {
            arr3.A[index++]=arr2.A[j++];
        }
        arr3.length++;        
    }
    while(i<arr1.length)
    {
        arr3.A[index++]=arr1.A[i++];
        arr3.length++;
    }
    while(j<arr2.length)
    {
        arr3.A[index++]=arr2.A[j++];
        arr3.length++;
    }
}
int main()
{

    // lets take an array of size 10
    int n;
    cout<<"Enter array size  : ";
    cin>>n;
    struct Array arr;
    arr.size=n;
    arr.A=new int[n];
    arr.length=0;
    int choice;
    cout<<"Enter how many numbers you wanna add in array : ";
    cin>>choice;
    int i=0;
    while(choice--)
    {
        cout<<"Enter Array Element : ";
        cin>>arr.A[i++];
        arr.length++;
    }
    display(arr);
    // length of an array is how many elements we are using
    
    append(arr,6);
    insert(arr,6,7);
    display(arr);
    binary_search(arr,4);
    binary_search(arr,10);
    delete_index(arr,0);
    display(arr);
    delete_index(arr,5);
    display(arr);
    delete_index(arr,3);
    display(arr);
    linear_search(arr,6);
    return 0;
}