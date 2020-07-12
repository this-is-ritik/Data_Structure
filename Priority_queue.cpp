#include<bits/stdc++.h>
using namespace std;
class Pqueue
{
    int *P;
    int*Q;
    int lastloc;
    int size;
    public:
        Pqueue(int size)
        {
            lastloc=-1;
            this->size=size;
            Q=new int[size];
            P=new int[size];
        }
        void enqueue(int data,int priority)
        {
            if(lastloc==size-1)
            {
                cout<<"Element can't be added!!!!!";
                return;
            }
            Q[++lastloc]=data;
            P[lastloc]=priority;
        }
        int Dequeue()
        {
            if(lastloc==-1)
            {
                cout<<"Cant delete from an empty priority queue!!!!!"<<endl;
                return -1;
            }
            int index=-1,maxpriority=-1;
            for(int i=0;i<=lastloc;++i)
            {
                if(P[i]>maxpriority)
                {
                    maxpriority=P[i];
                    index=i;
                }
            }
            int elem=Q[index];
            for(int i=index;i<lastloc;++i)
            {
                P[i]=P[i+1];
                Q[i]=Q[i+1];
            }
            lastloc--;
            return elem;
        }
        void display()
        {
            for(int i=0;i<=lastloc;++i)
                cout<<Q[i]<<" : "<<P[i]<<"\t";
            cout<<endl;
        }

};
int main()
{
    Pqueue p1(20);
    for(int i=0;i<10;++i)
    {
        p1.enqueue(i+10,i%5);
    }                                           // queue : 10,11,12,13,......,19
    p1.display();
    int x1=p1.Dequeue();                        // 14 is deleted with max priority 4 and first appearance
    p1.display();
    x1=p1.Dequeue();                            // 19 is deleted with max priority 4
    p1.display();
    x1=p1.Dequeue();                           /// 13 is deleted with max priority 3
    p1.display();
    return 0;
}