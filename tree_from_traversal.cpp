#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    struct Node*left,*right;
    Node(int data)
    {
        this->data=data;
        left=right=NULL;
    }
}Node;
void scan(int*a,int n)
{
    for(int i=0;i<n;++i)
        cin>>a[i];
}

int main()
{
    int n;
    cout<<"Enter no of nodes in tree : ";
    cin>>n;
    int*pre=new int[n];
    int*in=new int[n];
    int*post=new int[n];
    scan(pre,n);
    scan(in,n);
    scan(post,n);
}



    // generating tree from 1 traversal
    // from only 1 traversal catalan no of trees are possible

    // generating tree from 2 traversals
    // if pre and post are given even then more than 1 trees are possible 

    // if pre and in traversals are given then we can generate tree
    // if post and in traversals are given then we can generate tree

    // for constructing a binary tree inorder traversal is must
    // for constructing a binary search tree pre,post any one is enough as we can obtain inorder by sorting the given traversal 