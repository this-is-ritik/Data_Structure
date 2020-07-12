#include<bits/stdc++.h>
using namespace std;

class Dequeue
{
    int size,front,rear;
    int*A;
    public:
        Dequeue()
        {
            size=10;
            front=rear=-1;
            A=new int[size];
        }
        Dequeue(int size)
        {
            this->size=size;
            front=rear=-1;
            A=new int[this->size];
        }
        void insertFront(int data)
        {
            if(front==-1)
            {
                cout<<"Can't add in front side"<<endl;
                return;
            }
            A[front--]=data;
            return;
        }
        void insertRear(int data)
        {
            if(rear==size-1)
            {
                cout<<"Can't add in rear side"<<endl;
                return;
            }
            A[++rear]=data;
            return;
        }
        int deleteFront()
        {
            if(front==rear)
            {
                cout<<"Can't delete from front side"<<endl;
                return -1;
            }
            return A[++front];
        }
        int deleteRear()
        {
            if(rear==front)
            {
                cout<<"Can't delete from rear side"<<endl;
                return -1;
            }
            return A[rear--];
        }
        void display()
        {
            for(int i=front+1;i<=rear;++i)
            {
                cout<<A[i]<<" ";
            }
            cout<<endl;
        }
};

int main()
{
    Dequeue q1(20);
    int x1=q1.deleteFront();
    int x2=q1.deleteRear();
    q1.insertFront(20);
    q1.display();
    x1=q1.deleteFront();
    q1.insertRear(20);
    q1.display();
    x2=q1.deleteRear();
    for(int i=0;i<20;++i)
        q1.insertRear(i+1);
    q1.display();
    q1.deleteFront();
    q1.display();
}