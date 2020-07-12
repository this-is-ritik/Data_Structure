#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
    char data;
    struct Node *left,*right;
    Node(char data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
}Node;

Node* convertutil(string str,int low,int high)
{
    Node*root=NULL;
    if(low==high)
        root=new Node(str[high]);
    if(low<high)
    {
        root=new Node(str[low]);
        root->right=new Node(str[high]);
        root->left=convertutil(str,low+2,high-2);
    }
    return root;
}
Node* convert_ternary(string str)
{
    Node*root=convertutil(str,0,str.length()-1);
    return root;
}
void preorder(Node*root)
{
    if(root)
    {
        preorder(root->left);
        cout<<root->data<<" ";
        preorder(root->right);
    }
}
int main()
{
    string str;
    cout<<"enter ternary expression : ";
    getline(cin,str);
    Node*root=convert_ternary(str);
    preorder(root);
}