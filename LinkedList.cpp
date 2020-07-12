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





Node* findMid(Node*root)
{
    if(root==NULL or root->next==NULL)
        return root;
    Node*ptr1=root,*ptr2=root;
    do
    {
        ptr2=ptr2->next;
        if(ptr2)
        {
            ptr2=ptr2->next;
            ptr1=ptr1->next;
        }
    } while (ptr2!=NULL);
    return ptr1;
}




int intersection(Node*head1,Node*head2)
{
    if(head1->next and head2->next)
        Node* temp=intersection(head1->next,head2->next);
    if(head1->next)
        Node*temp=intersection(head1->next,head2);
    if(head2->next)
        Node*temp=intersection(head1,head2->next);
    if(head1->data==head2->data)
        return;
    else
    {
        return temp->data;
    }
}






void insert(Node**head_ref,int position,int data)
{
    Node*temp=new Node(data);
    if((*head_ref)==NULL)
    {
        (*head_ref)=temp;
        return;
    }
    if(position==1)
    {
        temp->next=(*head_ref);
        (*head_ref)=temp;
        return;
    }
    //go to the required position
    Node*curr=(*head_ref);
    int i=0;
    while(curr->next and i!=position-1)
    {
        i++;
        curr=curr->next;
        if(curr->next==NULL)
        {
            curr->next=temp;
            return;
        }
    }
    Node*next=curr->next;
    curr->next=temp;
    temp->next=next;
}


void insertSorted(Node**head_ref,int data)
{
    Node*temp=new Node(data);
    if((*head_ref)==NULL or ((*head_ref)->data>=data))
    {
        temp->next=(*head_ref);
        (*head_ref)=temp;
        return;
    }
    Node*curr=(*head_ref);
    while(curr->next and curr->next->data<data)
    {
        curr=curr->next;
    }
    temp->next=curr->next;
    curr->next=temp;
    return;
}






Node* create()
{
    Node*head=NULL,*prev;
    int position=1;
    while(true)
    {
        int x;
        cout<<"Enter data : ";
        cin>>x;
        if(x==-1)
        {
            return head;
        }
        insert(&head,position,x);
        position++;
    }
    return head;
}

Node*createSorted()
{
    Node*head=NULL;
    while(true)
    {
        int x;
        cout<<"Enter data : ";
        cin>>x;
        if(x==-1)
        {
            return head;
        }
        insertSorted(&head,x);
    }
    return head;
}
 
bool checkSorted(Node*root)
{
    if(root==NULL or root->next==NULL)
        return true;
    Node*prev=root;
    root=root->next;
    while(root)
    {
        if(prev->data>root->data)
            return false;
        prev=root;
        root=root->next;
    }
    return true;
}


Node* search(Node*node,int data)
{
    if(!node)
        return NULL;
    while(node)
    {
        if(node->data==data)
        {
            return node;
        }
        node=node->next;
    }
    return node;
}



void Delete(Node**head_ref,int data)
{
    Node*head=(*head_ref);
    Node*node=search(head,data);
    if(node==NULL)                                      // data not present
        return;
    if(node==head)                                     // delete head node                                                      
    {
        (*head_ref)=(*head_ref)->next;
        return;
    }                                                       
    Node*curr=head;                                     // delete any other node
    while(curr->next!=node)
    {
        curr=curr->next;
    }
    curr->next=curr->next->next;
    delete node;
    return;
}



void removeDuplicates(Node**head_ref)
{
    Node*ptr1=(*head_ref);
    Node*ptr2=(*head_ref)->next;
    while(ptr1 and ptr2)
    {
        if(ptr1->data!=ptr2->data)
        {
            ptr1=ptr2;
            ptr2=ptr2->next;
        }
        else
        {
            ptr1->next=ptr2->next;
            delete ptr2;
            ptr2=ptr1->next;
        }
    }
}





Node*concatenate(Node*root1,Node*root2)
{
    Node*ptr=root1;
    while(ptr->next)
    {
        ptr=ptr->next;
    }
    ptr->next=root2;
    return root1;
}





Node*concatSorted(Node*root1,Node*root2)
{
    if(root1==NULL)
        return root2;
    if(root2==NULL)
        return root1;
    Node*root3=NULL,*ptr1=NULL,*ptr2=NULL;
    if(root1->data<=root2->data)
    {
        root3=root1;
        ptr1=root1->next;
        ptr2=root2;
    }
    else
    {
        root3=root2;
        ptr1=root1;
        ptr2=root2->next;
    }
    Node*ptr=root3;
    while(ptr1 and ptr2)
    {
        if(ptr1->data<=ptr2->data)
        {
            ptr->next=ptr1;
            ptr=ptr1;
            ptr1=ptr1->next;
        }
        else
        {
            ptr->next=ptr2;
            ptr=ptr2;
            ptr2=ptr2->next;
        }
    }
    if(ptr1)
        ptr->next=ptr1;
    if(ptr2)
        ptr->next=ptr2;
    return root3;
}




void reverse(Node**head_ref)
{
    if((*head_ref)==NULL or (*head_ref)->next==NULL)
        return;
    Node*curr=(*head_ref),*prev=NULL;
    Node*n=NULL;
    while(curr)
    {
        n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
    }
    (*head_ref)=prev;
    return;
}


bool detectLoop(Node*head)
{
    Node*turtle=head,*hare=head->next;
    do
    {
        turtle=turtle->next;
        hare=hare->next;
        hare=(hare!=NULL)?hare->next:NULL;
    } while (turtle!=hare and turtle and hare);
    if(turtle==hare)
        return true;
    else
        return false;
}








void display(Node*node)
{
    if(node==NULL)
        return;
    while(node)
    {
        cout<<node->data<<" -> ";
        node=node->next;
    }
    cout<<endl;
}






void Rdisplay(Node*node)
{
    if(node==NULL)
    {
        cout<<endl;
        return;
    }
    cout<<node->data<<" -> ";
    Rdisplay(node->next);
}




int main()
{   
    Node *root1=createSorted();
    Node* mid=findMid(root1);
    cout<<mid->data<<endl;
    Node *root2=createSorted();
    display(root1);
    display(root2);
    Node *root3=concatSorted(root1,root2);
    display(root3);
}