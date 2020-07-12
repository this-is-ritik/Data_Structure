#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int data;
    struct Node*next,*back;
    Node(int value)
    {
        data=value;
        next=NULL;
        back=NULL;
    }
}Node;



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

void insert(Node**head_ref,int position,int data)
{
    if((*head_ref)==NULL)
    {
        (*head_ref)=new Node(data);
        return;
    }
    if(position==1)
    {
        Node*temp=new Node(data);
        temp->next=(*head_ref);
        (*head_ref)->back=temp;
        (*head_ref)=temp;
        return;
    }
    Node*curr=(*head_ref),*prev=NULL;
    position--;
    while(position--)
    {
        prev=curr;
        curr=curr->next;
    }
    Node*temp=new Node(data);
    prev->next=temp;
    temp->back=prev;
    temp->next=curr;
    if(curr!=NULL)
    {
        curr->back=temp;
    }
    return;
}




Node*create()
{
    Node*head;
    int data;
    cout<<"Enter head node data : ";
    cin>>data;
    if(data==-1)
        return NULL;
    head=new Node(data);
    Node*curr,*prev=head;
    while(data!=-1)
    {
        cout<<"Enter data : ";
        cin>>data;
        if(data!=-1)
        {
            curr=new Node(data);
            curr->back=prev;
            prev->next=curr;
            prev=curr;
        }
    }
    return head;
}

void displayForward(Node*root)
{
    cout<<"Forward : "<<endl<<endl;
    if(root==NULL)
        return;
    while(root)
    {
        cout<<root->data<<" -> ";
        root=root->next;
    }
    cout<<endl;
    cout<<endl;
    return;
}


Node*reverse(Node*head)
{
    if(head==NULL or head->next==NULL)
        return head;
    Node*curr=head,*ptr=NULL;
    while(curr)
    {
        ptr=curr->back;
        curr->back=curr->next;
        curr->next=ptr;
        curr=curr->back;
    }
    if(ptr!=NULL)
        return ptr->back;
    return ptr->back;
}

Node* Search(Node*root,int data)
{
    if(root==NULL)
        return root;
    while(root)
    {
        if(root->data==data)
            return root;
        root=root->next;
    }
    return root;
}



void Delete(Node**head_ref,int data)
{
    Node*node=Search((*head_ref),data);
    if(node==NULL)
        return;
    if(node==(*head_ref))
    {
        (*head_ref)=(*head_ref)->next;
        (*head_ref)->back=NULL;
        return;
    }
    Node*curr=(*head_ref);
    while(curr->next!=node)
    {
        curr=curr->next;
    }
    curr->next=node->next;
    if(node->next)
    {
        node->next->back=curr;
    }
    return;
}


void displayBackward(Node*root)
{
    cout<<"Backward : "<<endl<<endl;
    if(root==NULL)
        return;
    while(root->next)
    {
        root=root->next;
    }
    while(root)
    {
        cout<<root->data<<" -> ";
        root=root->back; 
    }
    cout<<endl;
    cout<<endl;
    return;
}
int main()
{
    Node*root=create();
    insert(&root,1,123);
    displayForward(root);
    displayBackward(root);
    insert(&root,7,456);
    displayForward(root);
    displayBackward(root);
    insert(&root,3,789);
    displayForward(root);
    displayBackward(root);
    Delete(&root,789);
    displayForward(root);
    displayBackward(root);
    Delete(&root,123);
    displayForward(root);
    displayBackward(root);
    Delete(&root,456);
    displayForward(root);
    displayBackward(root);
    Node *rev=reverse(root);
    displayForward(rev);
    displayBackward(rev);
}