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
        (*head_ref)->next=(*head_ref);
        (*head_ref)->back=(*head_ref);
        return;
    }
    if(position==1)
    {
        Node*temp=new Node(data);
        Node*last=(*head_ref)->back;
        last->next=temp;
        temp->next=(*head_ref);
        (*head_ref)->back=temp;
        temp->back=last;
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
    curr->next=head;
    head->back=curr;
    return head;
}

void displayForward(Node*root)
{
    cout<<"Forward : "<<endl<<endl;
    if(root==NULL)
        return;
    Node*curr=root;
    do
    {
        cout<<curr->data<<" -> ";
        curr=curr->next;
    }while(curr!=root);
    cout<<endl;
    cout<<endl;
    return;
}


Node*reverse(Node*head)
{
    if(head==NULL)
        return head;
    Node*curr=head,*ptr=NULL;
    do
    {
        ptr=curr->back;
        curr->back=curr->next;
        curr->next=ptr;
        curr=curr->back;
    } while (curr!=head);
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
        Node*last=(*head_ref)->back;
        (*head_ref)=(*head_ref)->next;
        last->next=(*head_ref);
        (*head_ref)->back=last;
        delete node;
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
    Node*curr=root->back;
    do
    {
        cout<<curr->data<<" -> ";
        curr=curr->back;
    } while (curr!=root->back);
    cout<<endl;
    cout<<endl;
    return;
}
int main()
{
    Node*root=create();
    displayForward(root);
    displayBackward(root);
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