#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int coeff,exp;
    struct Node*next;
    Node(int c,int e)
    {
        coeff=c;
        exp=e;
        next=NULL;
    }
}Node;
Node* create()
{
    Node*start=NULL,*prev=NULL;
    int n;
    cout<<"Enter no of terms in polynomial : ";
    cin>>n;
    int coeff,exp;
    for(int i=0;i<n;++i)
    {
        cout<<"Enter exp : ";
        cin>>exp;
        cout<<"Enter coeff : ";
        cin>>coeff;
        Node*temp=new Node(coeff,exp);
        if(start==NULL)
        {
                start=temp;
                prev=start;
                continue;
        }
        prev->next=temp;
        prev=temp;
    }
    return start;
}
void display(Node*start)
{
    if(start==NULL)
        return;
    cout<<start->coeff<<"x^"<<start->exp;
    while(start->next)
    {
        start=start->next;
        cout<<" + "<<start->coeff<<"x^"<<start->exp;
    }
    return;
}
int main()
{
    Node*poly1=NULL;
    poly1=create();
    display(poly1);
    return 0;
}