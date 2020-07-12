#include<bits/stdc++.h>
using namespace std;
class Cqueue
{
    int MAX;
    int front;
    int rear;
    int*Q;
    public: 
        Cqueue()
        {
            front=rear=-1;
            MAX=10;
            Q=new int[MAX];
        }
        Cqueue(int size)
        {
            MAX=size;
            front=-1;
            rear=-1;
            Q=new int[MAX];
        }
        void enqueue(int data)
        {
            if(isFull())
            {
                cout<<"Queue overflow element can't be added!!!!!"<<endl;
                return;
            }
            rear=(rear+1)%MAX;
            Q[rear]=data;
            return;
        }
        int Dequeue()
        {
            if(isEmpty())
            {
                cout<<"Underflow!!!";
                front-=1;                                   // reset pointers when queue becomes empty
                rear=-1;
                return -1;
            }
            front=(front+1)%MAX;
            return Q[front];
        }
        bool isEmpty()
        {
            if(front==rear and front==-1)
                return true;
            return false;
        }
        bool isFull()
        {
            if(rear==MAX-1 and front==-1) 
                return true;
            return false;
        }
        void display()
        {
            if(isEmpty())
                cout<<"Empty queue!!!";
            int i=(front+1)%MAX;
            do
            {
                cout<<Q[i]<<" ";
                i=(i+1)%MAX;
            }while(i!=(rear+1)%MAX);
            cout<<endl;
        }
};
int main()
{
    Cqueue q1;
    Cqueue q2(25);




    // adding elements in queue
    for (int i = 0; i < 10; i++)
        q1.enqueue(i+1);
    for(int i=0;i<25;++i)
        q2.enqueue(i+1);
    q1.display();
    q2.display();
    q1.enqueue(500);
    q2.enqueue(600);
    for(int i=0;i<10;++i)
    {
        int x=q1.Dequeue();
    }
    for(int i=0;i<25;++i)
    {
        int x=q2.Dequeue();
    }
    int x1=q1.Dequeue();
    int x2=q2.Dequeue();
    q1.enqueue(234);
    q1.enqueue(567);
    q2.enqueue(890);
    q2.enqueue(123);
    q1.display();
    q2.display();
    return 0;
}