#include<bits/stdc++.h>
using namespace std;
#define Vector vector<vector<int>>

Vector Polynomial()
{
    Vector P;
    int n;
    cout<<"Enter how many terms to be added  : ";
    cin>>n;
    for(int i=0;i<n;++i)
    {
        vector<int>temp;
        int power,coeff;
        cout<<"Enter co-efficient : ";
        cin>>coeff;
        cout<<"Enter power : ";
        cin>>power;
        temp.push_back(coeff);
        temp.push_back(power);
        P.push_back(temp);
    }
    return P;
}
int evaluate(Vector P,int x)
{
    int res=0;
    for(int i=0;i<P.size();++i)
    {
        res+=P[i][0]*pow(x,P[i][1]);
    }
    return res;
}
Vector addition(Vector P1,Vector P2)
{
    Vector P;
    int i=0,j=0;
    while(i<P1.size() and j<P2.size())
    { 
        vector<int>entry;
        if(P1[i][1]==P2[j][1])
        {
            entry.push_back(P1[i][0]+P2[j][0]);
            entry.push_back(P1[i][1]);
            i++,j++;
        }
        else if(P1[i][1]>P2[j][1])
        {
            entry.push_back(P1[i][0]);
            entry.push_back(P1[i][1]);
            i++;
        }
        else
        {
            entry.push_back(P2[j][0]);
            entry.push_back(P2[i][1]);
            j++;
        }
        P.push_back(entry);
    }
    vector<int>entry;
    while(i<P1.size())
    {
        entry.push_back(P1[i][0]);
        entry.push_back(P1[i][1]);
        i++;
    }
    while(j<P2.size())
    {
        entry.push_back(P2[j][0]);
        entry.push_back(P2[j][1]);
        j++;
    }
    return P;
}
void display(Vector P)
{
    int i=0;
    for(i=0;i<P.size()-1;++i)
    {
        cout<<P[i][0]<<" x^ "<<P[i][1]<<" + ";
    }
    cout<<P[i][0]<< " x^ "<<P[i][1]<<endl;
}
int main()
{
    Vector P1=Polynomial();
    display(P1);
    Vector P2=Polynomial();
    display(P2);
    Vector P3=addition(P1,P2);
    display(P3);
    return 0;
}