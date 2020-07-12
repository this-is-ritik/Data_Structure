#include<bits/stdc++.h>
using namespace std;
int main()
{
    //1st method
    int A[3][4];        // stack storage only

    //2d array in heap
    int *a[3];                  // its in stack
    for(int i=0;i<3;++i)
        a[i]=new int[4];        //its in heap
    
    //3rd method  
    // when everything is in heap
    int **arr;
    arr=new int*[3];    // no of rows = 3
    for(int i=0;i<3;++i)
        arr[i]=new int[4];      // no of columns = 4

    // arrays in compilers
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<4;++j)
        {
            cout<<&A[i][j]<<" "<<&a[i][j]<<" "<<&arr[i][j]<<endl;
        }
        cout<<endl;
    }
    // for single dimensional arrays

    // address(A[i])= address(A[0])+index*sizeof(data_type)

    
    
    // for 2d arrays

    //   row major mapping

    //    address(A[i][j]) = address(A[0][0]) + ( i*col + j ) * sizeof(data_type)

    // column major mapping

    // address(A[i][j]) = address(A[0][0]) + ( j*rows + i ) * sizeof(data_type)



    // for 4d arrays

    // row major mapping

    // address(A[i1][i2][i3][i4]) = address(A[0][0][0][0]) + ( i1*d2*d3*d4 + i2*d3*d4 + i3*d4 + i4)*sizeof(data_type)
    
    // for column major

    // address(A[i1][i2][i3][i4]) = address(A[0][0][0][0]) + ( i4*d3*d2*d1 + i3*d2*d1 + i2*d1 + i1)*sizeof(data_type)


    // for nD arrays

    // row major mapping

    // address(A[i1][i2][i3][i4]) = address(A[0][0][0][0]) + (  sum( i(x)*prod( dy) )  y=x+1 to n    x=1 to m )*sizeof(data_type)


    // apply horner's rule in this nD array formula
    

    
    return 0;
}