#include<bits/stdc++.h>
using namespace std;


class Matrix
{
    int n;
    int*A;
    int index(int row,int col)
    {
        if(row<=n and col<=n and row>=1 and col>=1 and row>=col)
        {
            /// row major mapping
            return ((row*(row-1))/2)+(col-1);
            // col major mapping
            // n*(j-1) - ((j-2)*(j-1))/2 + (i-j)
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
                for(int j=1;j<=i;++j)
                {
                    cout<<"Enter mat["<<i<<"]["<<j<<"] : ";
                    int pos=index(i,j);
                    if(pos!=-1)
                        cin>>A[pos];
                }
            }
        }
        int get(int row,int col)
        {
            if(row>col)
                return 0;
            int pos=index(row,col);
            return A[pos];
        }
        void set(int row,int col,int data)
        {
            if(row<col)
            {
                cout<<"You cant set a 0 element"<<endl;
                return;
            }
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
                    if(i<j)
                        cout<<0<<" ";
                    else
                    {
                        int pos=index(i,j);
                        cout<<A[pos]<<" ";
                    }
                }
                cout<<endl;
            }
        }
};




int main()
{
    // no of elements that are non-zero is n*(n+1)/2
    // no of elements that are zero is n*(n-1)/2
    // if(i<j)   M[i][j]=0
    // else      M[i][j]!=0
    int d;
    cout<<"Enter dimensions : ";
    cin>>d;
    Matrix mat=Matrix(d);
    mat.display();
    mat.set(2,1,19);
    mat.set(1,2,18);
    mat.display();
}