#include<bits/stdc++.h>
using namespace std;

//Linked List are self-referencial structure
typedef struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
}Node;

void addBegin(Node**head_ref,int data)
{
    Node*last=(*head_ref);
    while(last->next!=(*head_ref))
    {
        last=last->next;
    }
    Node*node=new Node(data);
    last->next=node;
    node->next=(*head_ref);
    (*head_ref)=node;
}



void addLast(Node**head_ref,int data)
{
    Node*last=(*head_ref);
    while(last->next!=(*head_ref))
    {
        last=last->next;
    }
    Node*node=new Node(data);
    last->next=node;
    node->next=(*head_ref);
}

void addbetween(Node**head_ref,int position,int data)
{
    Node*curr=(*head_ref),*prev=NULL;
    position--;
    while(position--)
    {
        prev=curr;
        curr=curr->next;
    }
    Node*node=new Node(data);
    prev->next=node;
    node->next=curr;
}






Node*create()
{
    Node*root=NULL;
    int x;
    cout<<"Enter data for head node : ";
    cin>>x;
    if(x==-1)
        return root;
    root=new Node(x);
    Node*prev=root,*curr=NULL;
    do
    {
        cout<<"Enter data : ";
        cin>>x;
        if(x!=-1)
        {
            curr=new Node(x);
            prev->next=curr;
            prev=curr;
        }
    } while (x!=-1);
    prev->next=root;
    return root;
    
}

void display(Node*root)
{
    if(root==NULL)
        return;
    Node*curr=root;
    do
    {
        cout<<curr->data<<" -> ";
        curr=curr->next;
    }while(curr!=root);
    cout<<endl;
}

Node* Search(Node*root,int data)
{
    if(root==NULL)
        return root;
    Node*curr=root;
    do
    {
        if(curr->data==data)
            return curr;
        curr=curr->next;
    }while(curr!=root);
    return NULL;
}



int length(Node*root)
{
    if(root==NULL)
        return 0;
    Node*curr=root;
    int len=0;
    do
    {
        curr=curr->next;
        len++;
    }while(curr!=root);
    return len;
}

void Delete(Node**head_ref,int data)
{
    Node*node=Search((*head_ref),data);
                                                        // data not present in circular linked list
    if(node==NULL)
        return;
                                                        // node to be deleted is head node
    if(node==(*head_ref))
    {
        Node*curr=(*head_ref);
        while (curr->next!=(*head_ref))
        {
            curr=curr->next;
        }
        curr->next=curr->next->next;
        (*head_ref)=curr->next;
        return;
    }
                                            // node to be deleted is not head node
    Node*curr=(*head_ref);
    while(curr->next!=node)
    {
        curr=curr->next;
    }
    curr->next=curr->next->next;
    delete node;
    return;
}
int main()
{   
    Node *root=create();
    display(root);
    int len=length(root);
    int position;
    cout<<"\nLength : "<<len<<endl;
    cout<<"Where you want to add element : ";
    cin>>position;
    int data;
    cout<<"Enter data : ";
    cin>>data;
    if(position==1)
    {
        addBegin(&root,data);
    }
    else if(position==len+1)
    {
        addLast(&root,data);
    }
    else
    {
        addbetween(&root,position,data);
    }
    display(root);
    Delete(&root,1);
    display(root);
    Delete(&root,5);
    display(root);
    Delete(&root,3);
    display(root);
}