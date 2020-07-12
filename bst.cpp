#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int data;
    struct Node*left,*right;
    Node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
}Node;

Node*generatefromInorder(int*in,int start,int end)
{
    if(start>end)
        return NULL;
    int index=(start+end)/2;
    int data=in[index];
    Node*root=new Node(data);
    root->left=generatefromInorder(in,start,index-1);
    root->right=generatefromInorder(in,index+1,end);
    return root;
}
  
Node* generatefromPostorder(int post[], int n) 
{
    Node* root = new Node(post[n - 1]); 
    stack<Node*> s; 
    s.push(root); 
  
    for (int i = n - 2; i >= 0; --i) 
    { 
        Node* t = new Node(post[i]); 
        Node* p = NULL; 
        while (s.size() && (post[i] < s.top()->data))  
            p = s.top(), s.pop();      
        if (p != NULL)  
            p->left = t;      
        else
            s.top()->right = t; 
        s.push(t); 
    } 
    return root;
} 
void generatefromPreorder(int*pre,int n,Node**root)
{
    Node*inf=new Node(INT_MAX);
    stack<Node*>s;
    s.push(inf);
    int i=0;
    (*root)=new Node(pre[i++]);
    Node*p=(*root),*t=NULL;
    while(i<n)
    {
        if(pre[i]<p->data)
        {
            t=new Node(pre[i++]);
            p->left=t;
            s.push(p);
            p=t;
        }
        else
        {
            if(s.top()->data>pre[i])
            {
                t=new Node(pre[i++]);
                p->right=t;
                p=t;
            }
            else
            {
                p=s.top();
                s.pop();
            }
        }
    }
}
/*
Node* generatefromPreorder(int*pre,int start,int end)
{
    if(start>end)
        return NULL;
    Node* node=new Node(pre[start]);
    int i;
    for(i=start;i<=end;++i)
        if(pre[i]>node->data)
            break;
    node->left=generatefromPreorder(pre,start+1,i-1);
    node->right=generatefromPreorder(pre,i,end);
    return node;
}
*/

//  iterative
void I_insert(Node*root,int key)
{
    Node*prev=NULL,*temp;
    while(root!=NULL)
    {
        prev=root;
        if(root->data<key)
            root=root->right;
        else if(root->data>key)
            root=root->left;
        else
            return;
    }
    temp=new Node(key);
    if(prev->data<key)
        prev->right=temp;
    if(prev->data>key)
        prev->left=temp;
    return;
}
// recursive
Node* insert(Node*root,int data)
{
    Node*curr=root;
    if(curr==NULL)
    {
        curr=new Node(data);
        return curr;
    }
    if(data<curr->data)
    {
        curr->left=insert(curr->left,data);
    }
    if(data>curr->data)
    {
        curr->right=insert(curr->right,data);
    }
    return curr;
}
void display(Node*root)
{
    if(root==NULL)
        return;
    queue<Node*>q;
    q.emplace(root);
    while(!q.empty())
    {
        int n=q.size();
        while(n--)
        {
            Node*temp=q.front();
            q.pop();
            if(temp)
                cout<<temp->data<<" ";
            if(temp->left)
                q.emplace(temp->left);
            if(temp->right)
                q.emplace(temp->right);
        }
        cout<<endl;
    }
}
void display_(Node*root)
{
    if(!root)
        return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node*temp=q.front();
        q.pop();
        cout<<root->data<<" ";
        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
    }
}

// recursive search    O(logn)
Node* search(Node*root,int key)
{
    if(root==NULL)
        return NULL;
    if(root->data==key)
        return root;
    if(root->data>key)
        return search(root->left,key);
    if(root->data<key)
        return search(root->right,key);
    return NULL;
}


// iterative
Node* I_search(Node*root,int key)
{
    if(root==NULL)
        return NULL;
    while(root!=NULL)
    {
        if(root->data<key)
            root=root->right;
        else if(root->data>key)
            root=root->left;
        else
            return root;
    }
    return NULL;
}




// find minimum
// recursive
int findMin(Node*root)
{
    if(root==NULL)
        return INT_MIN;
    if(root->left==NULL)
        return root->data;
    return findMin(root->left);
}



// iterative 
int I_findMin(Node*root)
{
    if(!root)
        return INT_MIN;
    while(root->left)
        root=root->left;
    return root->data;
}
Node*InPre(Node*root)
{
    while(root && root->right!=NULL)
        root=root->right;
    return root;
}

Node*InSucc(Node*root)
{
    while(root && root->left!=NULL)
        root=root->left;
    return root;
}
int height(Node*root)
{
    if(root==NULL)
        return 0;
    return 1+max(height(root->left),height(root->right));
}
Node* Delete(Node*root,int key)
{
    if(root==NULL)
        return NULL;
    else if(root->left==NULL and root->right==NULL)
    {
        delete root;
        return NULL;
    }
    else if(key<root->data)
        root->left=Delete(root->left,key);
    else if(key>root->data)
        root->right=Delete(root->right,key);
    else
    {
        if(height(root->left)>height(root->right))
        {
            Node*q=InPre(root->left);
            root->data=q->data;
            root->left=Delete(root->left,q->data);
        }
        else
        {
            Node*q=InSucc(root->right);
            root->data=q->data;
            root->right=Delete(root->right,q->data);
        }
    }
    return root;
}






//  always sorted in bst
void inorder(Node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<< " ";
    inorder(root->right);
}




int main()
{
    int pre[8]={25,15,40,10,20,30,45,50};
    Node *root1=NULL;
    generatefromPreorder(pre,8,&root1);
    display(root1);
    cout<<endl;
    cout<<endl;
    Node*root2=NULL;
    int in[]={10,15,20,25,30,40,45,50};
    root2=generatefromInorder(in,0,7);
    display(root2);
    cout<<endl;
    cout<<endl;
    Node*root3=NULL;
    int post[7]={2,7,5,12,18,15,10};
    root3=generatefromPostorder(post,7);
    display(root3);
    Node*root=NULL;
    int data;
    do
    {
        cout<<"Enter data : ";
        cin>>data;
        if(data!=-1)
            root=insert(root,data);
    } while(data!=-1);
    display(root);
    Node* node=search(root,20);
    if(node)
        cout<<node->data;
    Node* node1=I_search(root,20);
    if(node1)
        cout<<" "<<node1->data<<endl;
    root=Delete(root,5);
    cout<<"\n5 deleted\n";
    display(root);
    root=Delete(root,10);
    cout<<"\n10 deleted\n";
    display(root);
    root=Delete(root,12);
    cout<<"\n12 deleted\n";
    display(root);
    root=Delete(root,16);    
    cout<<"\n16 deleted\n";
    display(root);
    return 0;
}




// inorder is always sorted
// no duplicates
// no of bst for n nodes : catalan number
