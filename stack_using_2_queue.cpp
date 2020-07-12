#include<bits/stdc++.h>
using namespace std;


queue<int>q1;
queue<int>q2;
// by making pop operation costly
void push()
{
    int elem;
    cout<<"Enter element to be inserted : ";
    cin>>elem;
    q1.push(elem);
}


void pop()
{
    if(q1.empty())
    {
        cout<<"Stack underflow!!";
        return;
    }
    while(q1.size()!=1)
    {
        q2.push(q1.front());
        q1.pop();
    }
    q1.pop();
    while(!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }
    return;
}



int top()
{
    if(q1.empty())
    {
        cout<<"Stack underflow!!"<<endl;
        return -1;
    }
    int elem;
    while(!q1.empty())
    {
        elem=q1.front();
        q1.pop();
        q2.push(elem);
    }
    while(!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }
    return elem;
}
void display()
{
    cout<<"What do you wanna do?"<<endl;
    cout<<"1.Push\n2.Pop\n3.Top\n";
}
int main()
{
    // implement stack using 2 queues
    while(true)
    {
        int choice;
        display();
        cin>>choice;
        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                cout<<top()<<endl;
                break;
            default:
                cout<<"Wrong choice bsdk!!!"<<endl;
        }
    }
}