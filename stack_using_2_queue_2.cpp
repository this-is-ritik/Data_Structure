#include<bits/stdc++.h>
using namespace std;


queue<int>q1;
queue<int>q2;
// by making push operation costly
void push()
{
    int elem;
    cout<<"Enter element to be inserted : ";
    cin>>elem;
    while(!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
    q1.push(elem);
    while(!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }
}


void pop()
{
    if(q1.empty())
    {
        cout<<"Stack underflow!!"<<endl;
        return;
    }
    q1.pop();
    return;
}



int top()
{
    if(q1.empty())
    {
        cout<<"Stack underflow!!";
        return -1;
    }
    return q1.front();
}
void display()
{
    cout<<"What do you wanna do?"<<endl;
    cout<<"1.Push\n2.Pop\n3.Top\n";
}
int main()
{
    // implement stack using 2 queues
    bool flag=true;
    while(flag)
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
            case 4:
                flag=false;
                break;
            default:
                cout<<"Wrong choice!!!"<<endl;
        }
    }
    return 0;
}