#include<bits/stdc++.h>
using namespace std;
class Diagonal
{
    private:
        int row;
        int*A;
    public:
        Diagonal(int row)
        {
            this->row=row;
            A=new int[row];
            for(int i=0;i<row;++i)
            {
                cout<<"Enter A["<<i<<"]["<<i<<"] : ";
                cin>>A[i];
            }
        }
        void set(int i,int j,int data)
        {
            if(i==j)
            {
                A[i-1]=data;
            }
        }
        int get(int i,int j)
        {
            if(i==j)
                return A[i-1];
            return -1;
        }
        void display();
};


void Diagonal::display()
{
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<row;++j)
        {
            if(i==j)
                cout<<A[i]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}




int main()
{
    int row,col;
    cout<<"Enter rows : ";
    cin>>row;
    cout<<"Enter columns : ";
    cin>>col;
    if(row!=col)
    {
        cout<<"row and col must be equal for a diagonal matrix";
        return 0;
    }
    Diagonal mat1=Diagonal(row);
    int x=mat1.get(2,2);
    cout<<x<<endl;
    mat1.display();
    return 0;
}