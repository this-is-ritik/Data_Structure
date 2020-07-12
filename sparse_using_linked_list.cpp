#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int data;
    int row;
    int col;
    struct Node*next;
    Node(int m,int n,int value)
    {
        row=m;
        col=n;
        data=value;
        next=NULL;
    }
}Node;
void insert(Node**root,int data,int row,int col)
{
    if((*root)==NULL)
    {
        Node*temp=new Node(row,col,data);
        (*root)=temp;
        return;
    }
    Node*curr=(*root),*prev=NULL;
    while(curr)
    {
        prev=curr;
        curr=curr->next;
    }
    Node*node=new Node(row,col,data);
    prev->next=node;
    node->next=curr;
    return;
}

void display(Node*start)
{
    if(start==NULL)
        return;
    while(start)
    {
        cout<<start->row<<" "<<start->col<<" "<<start->data<<endl;
        start=start->next;     
    }
}

int main()
{
    Node*sparse=NULL;
    int m,n;
    cout<<"Enter matrix dimensions : ";
    cin>>m>>n;
    int data,row,col;
    while(true)
    {
        cout<<"Enter data : ";
        cin>>data;
        if(data==-1)
            break;
        cout<<"Enter row : ";
        cin>>row;
        cout<<"Enter col : ";
        cin>>col;
        insert(&sparse,data,row,col);
    }
    display(sparse);
}