#include<bits/stdc++.h>
using namespace std;
class Queue
{
    stack<int>s1;
    stack<int>s2;
    public:
        void enqueue(int data)
        {
            s1.push(data);
        }
        int Dequeue()
        {
            if(s2.empty())
            {
                if(s1.empty())
                    return -1;
                while(!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            int res=s2.top();
            s2.pop();
            return res;
        }

};
int main()
{
    Queue q1;
    for(int i=0;i<10;++i)
    {
        q1.enqueue(i+1);
    }
    for(int i=0;i<4;++i)
        cout<<q1.Dequeue()<<" ";
    cout<<endl;
    for(int i=0;i<2;++i)
        q1.enqueue(i+20);
    cout<<endl;
    for(int i=0;i<9;++i)
        cout<<q1.Dequeue()<<" ";
    return 0;
}