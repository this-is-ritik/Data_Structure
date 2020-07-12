#include<bits/stdc++.h>
using namespace std;

class heap
{
    vector<int>A;
    public: 
        void insert(int data)
        {
            int pos=A.size();
            A.push_back(data);
            while(pos>0 and A[(pos-1)/2]<data)
            {
                int parent=(pos-1)/2;
                A[pos]=A[parent];
                pos=parent;
            }
            A[pos]=data;
        }
        void heapify(int index)
        {
            int largest=index;
            int lchild=2*index+1;
            int rchild=2*index+2;
            if(lchild<A.size() and A[lchild]>A[largest])
                largest=lchild;
            if(rchild<A.size() and A[rchild]>A[largest])
                largest=rchild;
            if(largest!=index)
            {
                swap(A[largest],A[index]);
                heapify(largest);
            }
        }




        // according to heap sort for n size of heap
        void heapify_modified(int size,int index)
        {
            int largest=index;
            int lchild=2*index+1;
            int rchild=2*index+2;
            if(lchild<size and A[lchild]>A[largest])
                largest=lchild;
            if(rchild<size and A[rchild]>A[largest])
                largest=rchild;
            if(largest!=index)
            {
                swap(A[largest],A[index]);
                heapify_modified(size,largest);
            }
        }


        int search(int data)
        {
            int i=0;
            while(i<A.size())
            {
                if(A[i]>data)
                {
                    i++;
                    continue;
                }
                else if(A[i]<data)
                {
                    return -1;
                }
                else
                {
                    break;
                }
            }
            return i;
        }


        void Delete(int data)
        {
            if(A.size()==0)
            {
                cout<<"Underflow!!!\n heap empty!!!"<<endl;
                return;
            }
            int index=search(data);
            if(index==-1)
            {
                cout<<data<<" not found in heap!!!"<<endl;
                return;    
            }
            swap(A[0],A[index]);
            heapify(0);
        }

        void heap_sort()
        {
            for(int i=A.size()-1;i>=0;--i)
            {
                swap(A[0],A[i]);
                heapify_modified(i,0);
            }
        }



        void display()
        {
            for(auto i : A)
            {
                cout<<i<<" ";
            }
            cout<<endl;
        }
};
int main()
{
    heap h1;
    h1.insert(20);
    h1.insert(30);
    h1.insert(40);
    h1.insert(10);
    h1.insert(5);
    h1.insert(1);
    h1.insert(60);
    h1.display();
    h1.heap_sort();
    h1.display();
}