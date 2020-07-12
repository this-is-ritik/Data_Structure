#include<bits/stdc++.h>
using namespace std;

int Knapsack(int*price,int*weight,int N,int W)
{
    int dp[N+1][W+1];
    for(int i=0;i<=N;++i)
    {
        for(int w=0;w<=W;++w)
        {
            if(i==0 or w==0)
            {
                dp[i][w]=0;
            }
            else if(weight[i-1]<=w)
            {
                dp[i][w]=max( price[i-1]+ dp[i-1][w-weight[i-1]],dp[i-1][w]);
            }
            
            else
            {
                dp[i][w]=dp[i-1][w];
            }
        }
    }
    return dp[N][W];
}
int main()
{
    int n,w;
    cout<<"Enter size of knapsack : ";
    cin>>n;
    cout<<"Enter capacity : ";
    cin>>w;
    int *Price=new int[n];
    int*Weight=new int[n];
    for(int i=0;i<n;++i)
    {
        cout<<"Enter Price of "<<i+1<<" th item : ";
        cin>>Price[i];
        cout<<"Enter Weight of "<<i+1<<" th item : ";
        cin>>Weight[i];
    }
    cout<<Knapsack(Price,Weight,n,w)<<endl;
}