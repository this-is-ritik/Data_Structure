#include<bits/stdc++.h>
using namespace std;
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
        int n;
        cin>>n;
        int*array=new int[n];
        for(int i=0;i<n;++i)
            cin>>array[i];
         
        int dp[n][n];
        // set diagonal elements to zero
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                dp[i][j]=0;
        
        for (int length=2; length<n; length++) 
        {        //find the chain length starting from 2
            for (int i=1; i<n-length+1; i++) 
            {
                int j = i+length-1;
                dp[i][j] = INT_MAX;     //set to infinity
                for (int k=i; k<=j-1; k++) 
                {
                    //store cost per multiplications
                    int q = dp[i][k] + dp[k+1][j] + array[i- 1]*array[k]*array[j];
                    if (q < dp[i][j])
                       dp[i][j] = q;
                }
            }
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        cout<<dp[1][n-1]<<endl;
     }
	return 0;
}