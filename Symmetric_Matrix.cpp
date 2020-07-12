#include<bits/stdc++.h>
using namespace std;


class Matrix
{
    private:
        int n;
        int*A;
        int index(int row,int col)
        {
            if(row<=n and col<=n and row>=1 and col>=1)
            {
                // row major mapping
                int i=min(row,col),j=max(row,col);
                return (i-1)*n - ((i-2)*(i-1))/2 + (j-i);
                // col major mapping
                // (j*(j-1))/2 + (i-1)
            }
            return -1;
        }
    public:
        Matrix(int n)
        {
            // nXn is size of matrix
            this->n=n;
            A=new int[(n*(n+1))/2];
            for(int i=1;i<=n;++i)
            {
                for(int j=i;j<=n;++j)
                {
                    int x;
                    cout<<"Enter mat["<<i<<"]["<<j<<"] : ";
                    cin>>x;
                    set(i,j,x);
                }
            }
        }
        int get(int row,int col)
        {
            int pos=index(row,col);
            return A[pos];
        }
        void set(int row,int col,int data)
        {
            int pos=index(row,col);
            A[pos]=data;
            cout<<"Element set succesfully"<<endl;
            return;
        }
        void display()
        {
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    int pos=index(i,j);
                    cout<<A[pos]<<" ";
                }
                cout<<endl;
            }
        }
};




int main()
{
    
    
    
    // no of elements that are non-zero is n*(n+1)/2
    
    
    
    // no of elements that are zero is n*(n-1)/2
    
    
    // M[i][j]=M[j][i]
    
    
    
    int d;
    cout<<"Enter dimensions : ";
    cin>>d;
    Matrix mat=Matrix(d);
    mat.display();



}


