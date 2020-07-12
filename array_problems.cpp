#include <bits/stdc++.h>
using namespace std;


int nearestLarger(int*a,int n)
{
    stack<int>s;
    s.push(INT_MIN);
    for(int i=0;i<n;++i)
    {
        while(s.top()>a[i])
            s.pop();
        s.push(a[i]);
    }
}



int maximum(int*a,int n,int i)
{
    if(i==n-1)
        return a[n-1];
    return max(a[i],maximum(a,n,i+1));
}





int count_the_zeros(int*a,int n)
{
    int i=0;
    int j=n-1;
    int mid;
    while(i<=j)
    {
        mid=(i+j)/2;
        if(a[mid]==0)
        {
            if(a[mid-1]==1)
                return (n-mid);
            else
            {
                j=mid-1;
                continue;
            }
        }
        else
        {
            i=mid+1;
            continue;
        }
    }
    return (n-i);
}



int maximum_sum(int*a,int n)
{
    int sum=0;
    int best_sum=0;
    for(int i=0;i<n;++i)
    {
        sum=max(a[i],sum+a[i]);
        best_sum=max(best_sum,sum);
    }
    return best_sum;
}



// minimum no of coins needed
int solve(int*coins,int n,int x)
{
    
    if(x==0)
        return 0;
    int best=INT_MAX;
    for(int i=0;i<n;++i)
    {
        best=min(best,solve(coins,n,x-i)+1);
    }
    return best;
}






int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int*a=new int[n];
	    for(int i=0;i<n;++i)
	        cin>>a[i];     
        int c=count_the_zeros(a,n);
        cout<<c<<endl;
        int max_subarray_sum=maximum_sum(a,n);
        cout<<max_subarray_sum<<endl;
        int res=solve(a,n,10);
        cout<<res<<endl;
        res=solve(a,n,23);
        cout<<res<<endl;
        res=solve(a,n,32);
        cout<<res<<endl;
        res=solve(a,n,44);
        cout<<res<<endl;
	}
	return 0;
}