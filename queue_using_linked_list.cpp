#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node*next;
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
}*front=NULL,*rear=NULL;
void enqueue(int data)
{
    struct Node*temp=new Node(data);
    if(temp==NULL)
    {
        cout<<"Queue Full!!!"<<endl;
        return;   
    }
    if(front==NULL)
    {
        rear=temp;
        front=temp;
        return;
    }
    rear->next=temp;
    rear=temp;
    return;
}
int Dequeue()
{
    if(front==NULL)
    {
        cout<<"underflow!!!"<<endl;
        return -1;
    }
    else
    {
        int x=front->data;
        struct Node*t=front;
        front=front->next;
        delete t;
        return x;
   }    
}


void display()
{
    struct Node*temp=front;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


int main()
{
    for(int i=1;i<=10;++i)
        enqueue(i);
    display();
    int x;
    for(int i=1;i<=10;++i)
        x=Dequeue();
    x=Dequeue();
    for(int i=1;i<=10;++i)
        enqueue(i+10);
    display();
}