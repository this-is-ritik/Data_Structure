#include<bits/stdc++.h>
using namespace std;
class Queue
{
    int MAX;
    int front;
    int rear;
    int*Q;
    public: 
        Queue()
        {
            front=rear=-1;
            MAX=10;
            Q=new int[MAX];
        }
        Queue(int size)
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
            Q[++rear]=data;
            return;
        }
        int Dequeue()
        {
            if(isEmpty())
            {
                cout<<"Underflow!!!";
                front=-1;                                   // reset pointers when queue becomes empty
                rear=-1;
                return -1;
            }
            return Q[++front];
        }
        bool isEmpty()
        {
            if(front==rear)
                return true;
            return false;
        }
        bool isFull()
        {
            if(rear==MAX-1) 
                return true;
            return false;
        }
        void display()
        {
            if(front==rear)
                cout<<"Empty queue!!!";
            for(int i=front+1;i<=rear;++i)
                cout<<Q[i]<<" ";
            cout<<endl;
        }
        void reverse()
        {
            if(isEmpty())
                return;
            int i;
            if(!isEmpty())
            {
                i=Dequeue();
                reverse();
                enqueue(i);
            }
        }
};
int main()
{
    Queue q1(20);
    Queue q2(5);


    // adding elements in empty queue
    //for(int i=0;i<25;++i)
    //    q2.enqueue(i);
    for(int i=0;i<5;++i)
        q1.enqueue(i+25);
    q1.display();
    //q2.display();

    q1.reverse();
    q1.display();


    // empty the queues
    /*for(int i=0;i<25;++i)
        int x=q2.Dequeue();
    
    for(int i=0;i<10;++i)
        int x=q1.Dequeue();




    // adding elements in queue
    q1.enqueue(234);
    q2.enqueue(567);
    q1.display();
    q2.display();*/
    return 0;
}