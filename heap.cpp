#include<bits/stdc++.h>
using namespace std;



// max heap
class maxHeap
{
    int *h,n;
    int MAX;
    public:
        maxHeap(int n)
        {
            this->MAX=n;
            this->n=-1;
            h=new int[MAX];
        }
        bool isFull()
        {
            if(n==MAX-1)
                return true;
            return false;
        }
        void insert(int data)                // O(logn)
        {
            if(isFull())
            {
                cout<<"overflow!!!";
                return;
            }
            int temp=data,i=n+1;
            h[n+1]=data;
            while(i>0 && temp>h[i/2])
            {
                h[i]=h[i/2];
                i=i/2;
            }
            n++;
            h[i]=temp;
        }
        int search(int data)
        {
            for(int i=0;i<=n;++i)
                if(h[i]==data)
                    return i;
            return -1;
        }
        void Delete(int data)               // O (logn)
        {
            int index=search(data);
            if(index==-1)
            {
                cout<<"Element not present!!!!"<<endl;
                return;
            }
            swap(h[index],h[n]);
            n--;
            int i=index;
            while(2*i+1<=n or 2*i+2<=n)
            {
                int change;
                if(2*i+1<=n and 2*i+2<=n)
                {
                    if(h[2*i+1]<h[2*i+2])
                    {
                        change=2*i+2;
                    }
                    else
                    {
                        change=2*i+1;
                    }
                    
                }    
                else if(2*i+1<=n)
                {
                    change=2*i+1;
                }
                else if(2*i+2<=n)
                {
                    change=2*i+2;
                }
                else
                    return;
                swap(h[i],h[change]);
                i=change;
            }
            return;
        }
        void heapify( int n, int i) 
        { 
            int largest = i; // Initialize largest as root 
            int l = 2*i + 1; // left = 2*i + 1 
            int r = 2*i + 2; // right = 2*i + 2 
        
            // If left child is larger than root 
            if (l < n && h[l] > h[largest]) 
                largest = l; 
        
            // If right child is larger than largest so far 
            if (r < n && h[r] > h[largest]) 
                largest = r; 
        
            // If largest is not root 
            if (largest != i) 
            { 
                swap(h[i], h[largest]); 
        
                // Recursively heapify the affected sub-tree 
                heapify(n, largest); 
            } 
        } 
        
        // main function to do heap sort 
        void heap_sort() 
        { 
            // in this case heap is already built but still we show the procedure for any array
            //for (int i = n / 2; i >= 0; i--) 
            //    heapify( n, i); 
        
            for (int i=n; i>0; i--) 
            {  
                swap(h[0], h[i]); 
        
                heapify(i, 0); 
            } 
        } 
        void display()
        {
            for(int i=0;i<=n;++i)
            {
                cout<<h[i]<<" ";
            }
            cout<<endl;
        }
};

class minHeap
{
    int *h;
    int n;
    int MAX;
    public: 
        minHeap(int size)
        {
            MAX=size;
            n=-1;
            h=new int[size];
        }
        bool isFull()
        {
            if(n==MAX-1)
                return true;
            return false;
        }
        void insert(int data)
        {
            if(isFull())
                return ;
            h[n+1]=data;
            int i=n+1;
            while(i>=0 and h[i]<h[i/2])
            {
                swap(h[i],h[i/2]);
                i=i/2;
            }
            n++;
            return;
        }
        int search(int data)
        {
            for(int i=0;i<=n;++i)
                if(h[i]==data)
                    return i;
            return -1;
        }


        // delete incomplete
        void Delete(int data)
        {
            int index=search(data);
            if(index==-1)
            {
                cout<<"Element not present!!!!"<<endl;
                return;
            }
            swap(h[index],h[n]);
            
        }
};



int main()
{
    int n;
    cout<<"Enter size of heap : ";
    cin>>n;
    maxHeap obj(n);
    obj.insert(20);
    obj.insert(10);
    obj.insert(30);
    obj.insert(40);
    obj.insert(50);
    obj.insert(25);
    obj.insert(5);
    obj.display();
    obj.display();
    obj.Delete(30);
    obj.display();
    obj.Delete(50);
    obj.display();
    obj.Delete(5);
    obj.display();


    cout<<"heap sort : "<<endl;
    obj.heap_sort();
    obj.display();
}


//conditions for heap
// heap must be a complete binary tree 
// every node has an element>= its descendents






