#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int data,hd;
    struct Node*left,*right;
    Node(int data)
    {
        hd=0;
        this->data=data;
        left=right=NULL;
    }
}Node;
Node*create()
{
    Node*temp=NULL;
    int data;
    cin>>data;
    if(data==-1)
        return temp;
    temp=new Node(data);
    cout<<"Enter Left of "<<data<<" : ";
    temp->left=create();
    cout<<"Enter right of "<<data<<" : ";
    temp->right=create();
    return temp;    
    /*Node*root = new Node(50);
    root->left=new Node(15);
    root->right=new Node(62);
    root->left->left=new Node(5);
    root->left->right=new Node(20);
    root->left->right->left=new Node(200);
    root->left->right->left->left=new Node(201);
    root->left->right->left->left->left=new Node(202);
    root->left->right->left->left->left->left=new Node(203);
    root->right->left=new Node(58);
    root->right->right=new Node(91);
    return root;*/
}
bool identical(Node*root1,Node*root2)
{
    if(root1==NULL^root2==NULL)
        return false;
    if(root1==NULL and root2==NULL)
        return true;
    if(root1->data!=root2->data)
        return false;
    return identical(root1->left,root2->left)&& identical(root1->right,root2->right);
}
bool I_identical(Node*root1,Node*root2)
{
    stack<Node*>first,second;
    if(!root1 and !root2)
        return true;
    if(!root1 or !root2)
        return false;
    first.push(root1);
    second.push(root2);
    while(!first.empty() or !second.empty())
    {
        Node*x1=first.top();
        Node*x2=second.top();
        first.pop();
        second.pop();
        if(x1->data!=x2->data)
            return false;
        if((x1->left!=NULL)^(x2->left!=NULL) or (x1->right!=NULL)^(x2->right!=NULL))
            return false;
        if(x1->left and x2->left)
        {
            first.push(x1->left);
            second.push(x2->left);
        }
        if(x1->right and x2->right)
        {
            first.push(x1->right);
            second.push(x2->right);
        }     
    }
    return true;
}
void deleteBinaryTree(Node*root)
{
    if(root==NULL)
        return;
    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);
    delete root;
    return;
}
void I_deleteBinaryTree(Node*root)
{
    // use level order again with a minor change
    if(root==NULL)
        return;
    queue<Node*>q;
    q.emplace(root);
    Node*temp=NULL;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->left)
            q.emplace(temp->left);
        if(temp->right)
            q.emplace(temp->right);
        delete temp;
    }
}
int height(Node*root)
{
    if(root==NULL)
        return 0;
    return 1+max(height(root->left),height(root->right));
}
int I_height(Node*root)
{
    if(root==NULL)
        return 0;
    int h=0;

    // modifying level order a little bit


    queue<Node*>q;
    q.emplace(root);
    while(!q.empty())
    {
        int size=q.size();
        while(size--)
        {
            Node*temp=q.front();
            q.pop();
            if(temp->left)
                q.emplace(temp->left);
            if(temp->right)
                q.emplace(temp->right);
        }
        h++;
    }
    return h;
}
int countnodewithdegree1(Node*root)
{
    int x,y;
    if(root!=NULL)
    {
        x=countnodewithdegree1(root->left);
        y=countnodewithdegree1(root->right);
        if(root->left!=NULL ^ root->right!=NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}
int countnonleafnodes(Node*root)
{
    int x,y;
    if(root!=NULL)
    {
        x=countnonleafnodes(root->left);
        y=countnonleafnodes(root->right);
        if(root->left!=NULL or root->right!=NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}
int countleafnodes(Node*root)
{
    int x,y;
    if(root!=NULL)
    {
        x=countleafnodes(root->left);
        y=countleafnodes(root->right);
        if(root->left==NULL and root->right==NULL)  
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}
int countwithdegree2(Node*root)
{
    int x,y;
    if(root!=NULL)
    {
        x=countwithdegree2(root->left);
        y=countwithdegree2(root->right);
        if(root->left and root->right)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}
int countTotalnodes(Node*root)
{
    int x,y;
    if(root!=NULL)
    {
        x=countTotalnodes(root->left);
        y=countTotalnodes(root->right);
        return x+y+1;
    }
    return 0;
}
void preorder(Node*root)
{
    if(root)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    return;
}
void inorder(Node*root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    return;
}
void postorder(Node*root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
    return;
}
void I_preorder(Node*root)
{
    stack<Node*>s;
    s.push(root);
    Node*temp=NULL;
    while(!s.empty())
    {
        temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
        if(temp->right)
            s.push(temp->right);
        if(temp->left)
            s.push(temp->left);
    }
    cout<<endl;
}
void I_inorder(Node*root)
{
    if(root==NULL)
        return;
    stack<Node*>s;
    Node*temp=root;
    while(!s.empty() or temp!=NULL)
    {
        if(temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }
        else
        {
            temp=s.top();
            s.pop();
            cout<<temp->data<<" ";
            temp=temp->right;
        }
    }
    cout<<endl;
}
void I_postorder(Node*root)
{
    if(root==NULL)
        return;
    stack<Node*>s,out;
    s.push(root);
    Node*temp;
    while(!s.empty())
    {
        temp=s.top();
        s.pop();
        out.push(temp);
        if(temp->left)
            s.push(temp->left);
        if(temp->right)
            s.push(temp->right);
    }
    while(!out.empty())
    {
        temp=out.top();
        cout<<temp->data<<" ";
        out.pop();
    }
    cout<<endl;
}
bool printGivenlevel(Node*root,int level)
{
    if(root==NULL)
        return true;
    if(level==1)
    {
        cout<<root->data<<" ";
        return true;
    }
    return printGivenlevel(root->left,level-1) or printGivenlevel(root->right,level-1); 
}
void levelorder(Node*root)
{
    if(root==NULL)
        return;
    int level=1;
    while(printGivenlevel(root,level++));

}
void I_Levelorder(Node*root)
{
    queue< Node*>q;
    if(root==NULL)
        return;
    q.emplace(root);
    while(!q.empty())
    {
        Node*temp=q.front();
        q.pop();
        cout<<q.front()->data<<" ";
        if(temp->left)
            q.emplace(temp->left);
        if(temp->right)
            q.emplace(temp->right);
    }
    return;
}
void reverseLevelorder(Node*root)
{
    if(root==NULL)
        return;
    queue<Node*>q;
    q.emplace(root);
    stack<Node*>s;
    while(!q.empty())
    {
        s.push(q.front());
        if(q.front()->right)
            q.emplace(q.front()->right);
        if(q.front()->left)
            q.emplace(q.front()->left);
        q.pop();
    }
    while(!s.empty())
    {
        cout<<s.top()->data<<" ";
        s.pop();
    }
}
void spiralorder(Node*root)
{
    // using deque
    if(root==NULL)
        return;
    deque<Node*>q;
    q.push_back(root);
    bool flag=true;
    while(!q.empty())
    {
        int size=q.size();
        if(flag)
        {
            // print left to right
            while(size--)
            {
                Node*temp=q.front();
                q.pop_front();
                cout<<temp->data<<" ";
                if(temp->left)
                    q.push_back(temp->left);
                if(temp->right)
                    q.push_back(temp->right);
            }
        }
        else
        {
            // print right to left
            while(size--)
            {
                Node*temp=q.back();
                q.pop_back();
                cout<<temp->data<<" ";
                if(temp->left)
                    q.push_front(temp->left);
                if(temp->right)
                    q.push_front(temp->right);
            }
        }
        flag=not flag;
        cout<<endl;
    }
}
void specificorder(Node*root)
{
    if(root==NULL)
        return;
    queue<Node*>q1,q2;
    cout<<root->data<<" ";
    if(root->left)
        q1.emplace(root->left);
    if(root->right)
        q2.emplace(root->right);
    while(!q1.empty())
    {
        int size=q1.size();
        while(size--)
        {
            //1st queue
            Node*temp=q1.front();
            q1.pop();
            cout<<temp->data<<" ";
            if(temp->left)
                q1.emplace(temp->left);
            if(temp->right)
                q1.emplace(root->right);
            
            // 2nd queue
            temp=q2.front();
            cout<<temp->data<<" ";
            if(temp->right)
                q2.emplace(temp->right);
            if(temp->left)
                q2.emplace(temp->left);
        }
    }
}
void leftView(Node*root)
{
    // print only first node for a given level
    queue< Node*>q;
    if(root==NULL)
        return;
    q.emplace(root);
    while(!q.empty())
    {
        int size=q.size();
        bool flag=true;
        while(size--)
        {
            Node*temp=q.front();
            q.pop();
            if(flag)
                cout<<temp->data<<" ";
            if(temp->left)
                q.emplace(temp->left);
            if(temp->right)
                q.emplace(temp->right);
            flag==false;
        }
    }
    return;
}
void rightView(Node*root)
{
    // print only last node for a given level
    queue< Node*>q;
    if(root==NULL)
        return;
    q.emplace(root);
    while(!q.empty())
    {
        int size=q.size();
        Node*temp=NULL;
        while(size--)
        {
            temp=q.front();
            q.pop();
            if(size==1)
                cout<<temp->data<<" ";
            if(temp->left)
                q.emplace(temp->left);
            if(temp->right)
                q.emplace(temp->right);
        }
    }
    return;
}
void topView(Node*root)
{
    if (root == NULL) 
        return; 
    int hd = 0; 
    map<int, int> m; 
    queue<Node *> q; 
    root->hd = hd; 
    q.push(root);
    while (!q.empty()) 
    { 
        Node *temp = q.front(); 
        q.pop(); 
        hd = temp->hd; 
        if(m.count(hd)==0)
            m[hd] = temp->data; 
        if (temp->left != NULL) 
        { 
            temp->left->hd = hd-1; 
            q.push(temp->left); 
        } 
        if (temp->right != NULL) 
        { 
            temp->right->hd = hd+1; 
            q.push(temp->right); 
        } 
    }
    for (auto i = m.begin(); i != m.end(); ++i) 
        cout << i->second << " ";
}
void bottomView(Node*root) 
{ 
    if (root == NULL) 
        return; 
    int hd = 0; 
    map<int, int> m; 
    queue<Node *> q; 
    root->hd = hd; 
    q.push(root);
    while (!q.empty()) 
    { 
        Node *temp = q.front(); 
        q.pop(); 
        hd = temp->hd; 
        m[hd] = temp->data; 
        if (temp->left != NULL) 
        { 
            temp->left->hd = hd-1; 
            q.push(temp->left); 
        } 
        if (temp->right != NULL) 
        { 
            temp->right->hd = hd+1; 
            q.push(temp->right); 
        } 
    }
    for (auto i = m.begin(); i != m.end(); ++i) 
        cout << i->second << " ";
} 
void isCompleteUtil(Node*root,bool*a,int i,int n)
{
    if(root==NULL)
        return;
    if(i<n) 
        a[i]=true;
    isCompleteUtil(root->left,a,2*i+1,n);
    isCompleteUtil(root->right,a,2*i+2,n);
    return;
}
bool isComplete(Node*root)
{
    if(root==NULL)
        return true;
    int n=countTotalnodes(root);
    bool *a=new bool[n];
    memset(a,false,n);
    isCompleteUtil(root,a,0,n);
    for(int i=0;i<n;++i)
    {
        if(!a[i])
            return false;
    }
    return true;
}
bool isSymmetricUtil(Node*r1,Node*r2)
{
    if(r1==NULL ^ r2==NULL)
        return false;
    if(r1==NULL and r2==NULL)
        return true;
    if(r1->data!=r2->data)
        return false;
    return isSymmetricUtil(r1->left,r2->right) and isSymmetricUtil(r1->right,r2->left);
}
bool isSymmetric(Node*root)
{
    if(!root)
        return true;
	return isSymmetricUtil(root->left,root->right);
}
void isBSTUtil(Node*root,stack<int>&stk)
{
    if(root==NULL)
        return;
    isBSTUtil(root->left,stk);
    stk.push(root->data);
    isBSTUtil(root->right,stk);
}
bool isBST(Node*root)
{
    stack<int>stk;
    isBSTUtil(root,stk);
    int prev=stk.top();
    stk.pop();
    while(!stk.empty())
    {
        if(stk.top()>=prev)
            return false;
        prev=stk.top();
        stk.pop();
    }
    return true;
}
int main()
{
    Node*root=create();
    cout<<"Recursive : "<<endl;
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    cout<<"Iterative : "<<endl;
    I_preorder(root);
    cout<<"Preordercompleted";
    cout<<endl;
    I_inorder(root);
    cout<<"inorder completed";
    cout<<endl;
    I_postorder(root);
    cout<<"Postorder Completed";
    cout<<endl;
    cout<<"is BST ? : ";
    cout<<(isBST(root)==1?"true":"false")<<endl;
    cout<<"is symmetric ? : ";
    cout<<(isSymmetric(root)==1?"true":"false")<<endl;
    cout<<"is Complete ? : ";
    cout<<(isComplete(root)==1?"true":"false")<<endl;
}











// No of binary search tree using n nodes(unlabelled nodes)  =    ( (2*n) C n )/(n+1)    = catalan nummber 

    // No of trees having maximum height using n nodes    =     2^(n-1)    
 
    // No of binary trees using n nodes (labelled nodes) = (catalan number)*n!

    // catalan number T(n) = E ( T(i-1)*T(n-i))       i = 1 to n 



    // Q. if height is h 
    // min nodes required is : h+1
    // max nodes are : 2^0+2^1+2^2+.....2^h = ( 2^(h+1) ) - 1
    
    //Q.if no of nodes are : n
    // min height = log2(n+1) - 1
    // max height = n-1


    // degree(0)=degree(2)+1
    // degree(0) means no of nodes with degree 0

//  ...........................................................................................................

    // strict/complete/Proper binary tree
    // for a strictly binary tree

    // Q. if height is h 
    // min nodes required is : h+1 + h = 2*h+1
    // max nodes are : 2^0+2^1+2^2+.....2^h = ( 2^(h+1) ) - 1
    
    //Q.if no of nodes are : n
    // min height = log2(n+1) - 1
    // max height = (n-1)/2

    // external _nodes =internal_nodes + 1 in a strict binary tree





// A binary tree having maximum nodes is FULL Binary Tree



// Complete Binary Tree
// Tree in array representation should not be containing any blank spaces in array
// then that tree is called a complete binary tree



// strict VS complete binary tree
// strict binary tree can not have degree 1 nodes
// but complete binary tree can have degree 1 nodes





// important facts to get tree from the traversals
// first element in pre order and last element in postorder is always root

