#include<bits/stdc++.h>
using namespace std;


int maximum(int*a,int n)
{
    int m=INT_MIN;
    for(int i=0;i<n;++i)
    {
        m=max(m,a[i]);
    }
    return m;
}
int minimum(int*a,int n)
{
    int m=INT_MAX;
    for(int i=0;i<n;++i)
    {
        m=min(m,a[i]);
    }
    return m;
}

void swap(int*x,int *y)
{
    int t=*x;
    *x=*y;
    *y=t;
}


void bubble(int*a,int n)
{
    // we made bubble sort as ADAPTIVE by introducing variable flag
    // stable sort
    for(int i=0;i<n;++i)
    {
        /*
        bool flag=false;
        for(int j=n-1;j>i;--j)              // bring smallest to top
        {
            if(a[j]<a[j-1])
            {
                swap(a[j],a[j-1]);
                flag=true;
            }
        }        
        if(!flag)
            return;
        */

        bool flag=false;                        
        for(int j=0;j<n-i-1;++j)              // bring largest element down
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
                flag=true;
            }
        }
        if(!flag)
            return;
    }
}


void insertion(int*a,int n)
{
    // adaptive sort by its nature
    // stable sort
    // if list is sorted comparison : O(n)   min swap : O(n) 
    // if list is descending order O(n^2)

    for(int i=1;i<n;++i)
    {
        int j=i-1;
        int elem=a[i];
        while(a[j]>elem and j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=elem;
    }
}





void selection(int*a,int n)         // O(n^2)
{
    
    // minimum no of swaps = O(n)
    // only selection sort gives minimum no of swaps

    // not stable sort
    // not adaptive
    
    for(int i=0;i<n;++i)
    {
        int m=a[i],index=i;
        for(int j=i+1;j<n;++j)
        {
            if(a[j]<m)
            {
                m=a[j];
                index=j;
            }
        }
        swap(a[i],a[index]);
    }
}

int partition(int*arr,int start,int end)
{
    /*
    // Hoare's Quick sort
    int pivot=A[start];
    int i=start,j=high;
    do
    {
        do
        {
            i++;
        }while(arr[i]<pivot);
        do
        {
            j--;
        }while(arr[j]>pivot);
        if(i<j)
            swap(arr[i],arr[j]);
    }while(i<j);
    swap(a[l],a[j]);
    return j;
    */
    int pivot=arr[end];
    int i=start-1;
    int j=start;
    while(j<=end)
    {
        if(arr[j]<pivot)
            swap(&arr[++i],&arr[j]);
        j++;
    }
    swap(&arr[i+1],&arr[end]);
    return (i+1);
}

void quicksort(int *a,int start,int end)            // O(nlogn) is best 
{                                                   // O(n^2) is worst
    if(start<end)
    {
        int pi=partition(a,start,end);            // pivot
        quicksort(a,start,pi-1);
        quicksort(a,pi+1,end);
    }
}

void merge(int*a,int low,int mid,int high)
{
    vector<int>v;
    int i=low,j=mid+1;
    while(i<=mid and j<=high)
    {
        if(a[i]<a[j])
            v.push_back(a[i++]);
        else
            v.push_back(a[j++]);        
    }
    while(i<=mid)
        v.push_back(a[i++]);
    while(j<=high)
        v.push_back(a[j++]);
    for(int i=0;i<v.size();++i) 
        a[i+low]=v[i];
    delete v;
}

// iterative
void merge_sort(int *a,int n)
{
    int p,i,l,h,m;
    for(p=2;p<=n;p*=2)
    {
        for(i=0;i+p-1<n;i+=p)
        {
            l=i;
            h=i+p-1;
            m=(l+h)/2;
            merge(a,l,m,h);
        }
    }
    if(p/2<n)
        merge(a,0,p/2,n-1);
}

// recursive
void merge_sort(int *a,int start,int end)
{
    if(start<end)
    {
        int mid=(start+end)/2;
        merge_sort(a,start,mid);
        merge_sort(a,mid+1,end);
        merge(a,start,mid,end);
    }
}


void count_sort(int*a,int n)
{
    int m=maximum(a,n);
    int b[n+1]={0};
    for(int i=0;i<n;++i)
        b[a[i]]++;
    int i=0;
    int k=0;
    while(i<=m)
    {
        if(b[i]==0)
        {
            i++;
            continue;
        }
        else
        {
            a[k++]=i;
            b[i]--;
            continue;
        }
        
    }
}



// space optimized count_sort
void countSort(vector <int>& arr) 
{ 
    int max = *max_element(arr.begin(), arr.end()); 
    int min = *min_element(arr.begin(), arr.end()); 
    int range = max - min + 1; 
      
    vector<int> count(range), output(arr.size()); 
    for(int i = 0; i < arr.size(); i++) 
        count[arr[i]-min]++; 
          
    for(int i = 1; i < count.size(); i++) 
           count[i] += count[i-1]; 
    
    for(int i = arr.size()-1; i >= 0; i--) 
    {  
         output[ count[arr[i]-min] -1 ] = arr[i];  
              count[arr[i]-min]--;  
    } 
      
    for(int i=0; i < arr.size(); i++) 
            arr[i] = output[i]; 
} 



void bucket_sort(int *a,int n)
{
    int m=maximum(a,n);
    vector<int>v[m+1];
    for(int i=0;i<n;++i)
    {
        v[a[i]].push_back(a[i]);
    }
    int k=0;
    for(int i=0;i<=m;++i)
    {
        for(int j=0;j<v[i].size();++j)
        {
            a[k++]=v[i][j];
        }
    }
}


void radix_sort(int *a,int n)
{
    vector<int>v[10];
    int m=maximum(a,n);
    int nod=floor(log(m)/log(10) + 1);
    int size=pow(10,nod);
    for(int p=1;p<=size;p*=10)
    {
        for(int i=0;i<n;++i)
        {
            int t=(a[i]/p)%10;
            v[t].push_back(a[i]);
        }
        int k=0;
        for(int i=0;i<10;++i)
        {
            for(int j=0;j<v[i].size();++j)
            {
                a[k++]=v[i][j];
            }
        }
        for(int i=0;i<10;++i)
            v[i].clear();

    }
}



// based on insertion sort
// gap is defined as floor(no of elements/2)

// incomplete
//void shell_sort(int *a,int n)
//{
    
//}

void display(int*a,int n)
{
    for(int i=0;i<n;++i)
        cout<<a[i]<<" ";
    cout<<endl;
}



void display(vector<int>v)
{
    for(int i=0;i<v.size();++i)
        cout<<v[i]<<" ";
    cout<<endl;
}




int main()
{
    int n=10;
    int a[n]={6,10,0,9,9,3,7,4,5,6};
    /*vector<int>v;
    for(int i=0;i<n;++i)
    {
        cin>>data;
        v.push_back(data);
    }*/
    //bubble(a,n);
    //insertion(a,n);
    //selection(a,n);
    //quicksort(a,0,n-1);
    //merge_sort(a,0,n-1);
    //countSort(v);
    //count_sort(a,n);
    //bucket_sort(a,n);
    radix_sort(a,n);
    display(a,n);
    return 0;
}






/*

Comparison Based Sort : 

1.Bubble sort               O(n^2)
2.Insertion sort           O(n^2)
3.Selection sort            O(n^2)

4.Heap sort                 O(nlogn)
5.Merge sort
6.Quick sort
7.Tree sort

8.Shell sort                O(n^1.5)


Index Based Sorts : 


9.Count sort                O(n)
10.Bucket Sort
11.Radix sort

*/