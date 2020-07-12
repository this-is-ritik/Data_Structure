#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cout<<"Enter String 1 : ";
    getline(cin,s1);
    cout<<"Enter String 2 : ";
    getline(cin,s2);
    int m=s1.length();
    int n=s2.length();
    int LCS[m+1][n+1];
    // set first row to zero 
    for(int i=0;i<n;++i)
        LCS[0][i]=0;    
    // set first column to zero
    for(int i=0;i<m;++i)
        LCS[i][0]=0;
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(s1[i]==s2[j])
                LCS[i][j]=1+LCS[i-1][j-1];
            else
                LCS[i][j]=max(LCS[i][j-1],LCS[i-1][j]);            
        }
    }
    cout<<"Length of Longest Common Subsequence is : "<<LCS[m][n];
}