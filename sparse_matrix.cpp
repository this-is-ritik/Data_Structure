#include<bits/stdc++.h>
using namespace std;




#define Vector vector<vector<int>>





// coordinate list representation or sparse matrix







Vector create()
{
    Vector V1;
    int temp;
    vector<int>v;
    cout<<"Enter no of rows : ";
    cin>>temp;
    v.push_back(temp);
    cout<<"Enter no of columns : ";
    cin>>temp;
    v.push_back(temp);
    cout<<"Enter no of non-zero elements : ";
    cin>>temp;
    v.push_back(temp);
    V1.push_back(v);
    cout<<"\n";
    for(int i=0;i<temp;++i)
    {
        int x;
        vector<int>v;
        cout<<"Enter row : ";
        cin>>x;
        v.push_back(x);
        cout<<"Enter col : ";
        cin>>x;
        v.push_back(x);
        cout<<"Enter value : ";
        cin>>x;
        v.push_back(x);
        V1.push_back(v);
        cout<<endl;
    }
    cout<<"\n\n\n";
    return V1;
}













Vector addition(Vector V1,Vector V2)
{
    Vector V;
    if(V1[0][0]!=V2[0][0] or V1[0][1]!=V2[0][1])
    {
        cout<<"Addition criteria not met!!!!";
        return V;
    }
    vector<int>first;
    first.push_back(V1[0][0]);
    first.push_back(V1[0][1]);
    int i=1,j=1;
    while(i<V1.size() and j<V2.size())
    {
        
        vector<int>temp;
        if(V1[i][0]==V2[j][0])
        {
            if(V1[i][1]==V2[j][1])
            {
                temp.push_back(V1[i][0]);
                temp.push_back(V1[i][1]);
                temp.push_back(V1[i][2]+V2[j][2]);
                i++;
                j++;
            }
            else if(V1[i][1]<V2[j][1])
            {
                temp.push_back(V1[i][0]);
                temp.push_back(V1[i][1]);
                temp.push_back(V1[i][2]);
                i++;
            }
            else
            {
                temp.push_back(V2[j][0]);
                temp.push_back(V2[j][1]);
                temp.push_back(V2[j][2]);
                j++;
            }    
        }
        else if(V1[i][0]<V2[j][0])
        {
            temp.push_back(V1[i][0]);
            temp.push_back(V1[i][1]);
            temp.push_back(V1[i][2]);
            i++;
        }
        else
        {
            temp.push_back(V2[j][0]);
            temp.push_back(V2[j][1]);
            temp.push_back(V2[j][2]);
            j++;
        }
        V.push_back(temp);
    }
    for(;i<V1.size();++i)
    {
        vector<int>temp;
        temp.push_back(V1[i][0]);
        temp.push_back(V1[i][1]);
        temp.push_back(V1[i][2]);
        V.push_back(temp);
    }
    for(;j<V2.size();++j)
    {
        vector<int>temp;
        temp.push_back(V2[j][0]);
        temp.push_back(V2[j][1]);
        temp.push_back(V2[j][2]);
        V.push_back(temp);
    }
    first.push_back(V.size());
    V.insert(V.begin(),first);
    return V;
}

Vector Transpose(Vector V)
{
    Vector VT;
    vector<int>first;
    first.push_back(V[0][1]);
    first.push_back(V[0][0]);
    first.push_back(V[0][2]);
    VT.push_back(first);
    int counter=0;
    while(counter<V[0][2])
    {
        for(int i=1;i<=V[0][2];++i)
        {
            if(V[i][1]==counter)
            {
                vector<int>temp;
                temp.push_back(V[i][1]);
                temp.push_back(V[i][0]);
                temp.push_back(V[i][2]);
                VT.push_back(temp);
            }
        }
        counter++;
    }
    return VT;
}










void display(Vector V)
{
    for(int i=0;i<V.size();++i)
    {
        for(int j=0;j<3;++j)
            cout<<V[i][j]<<" ";
        cout<<endl;
    }
}







int main()
{
    Vector V1=create();
    Vector V2=create(); 
    Vector V3=multiply(V1,V2);
    display(V1);
    cout<<"\n\n**************\n\n";
    display(V2);
    cout<<"\n\n==============\n\n";
    display(V3);
}