#include<bits/stdc++.h>
using namespace std;
// hash size
#define MAX 10


//OPEN hashing
// chaining
int hash_func_chain(int x)
{
    return x%MAX;
}

// hash vector
vector<int>v[MAX]; 

void clear()
{
    for(int i=0;i<MAX;++i)
        v[i].clear();
}




void chaining_hash(int*a,int n)
{
    // average successfull search time = 1 + lambda/2
    // average unsuccessfull search time = 1 + lambda


    for(int i=0;i<n;++i)
    {
        v[hash_func_chain(a[i])].push_back(a[i]);
    }   
}

















int func(int x)
{
    return x;
}

int hash_func_linear_probing(int data,int i)
{
    return (hash_func_chain(data)+func(i))%MAX;
}




//closed hashing
// linear probing
void linear_probing(int*a,int n)
{
    // average successfull searcch time= ln(1/(1-lambda))/lambda
    // average unsuccessfull searcch time= 1/(1-lambda)
    // optimal lambda <= 0.5
    // for deletion solution is rehashing only
    

    clear();
    for(int k=0;k<n;++k)
    for(int i=0;i<MAX;++i)
    {
        if(v[hash_func_linear_probing(a[k],i)].size()==0)
            v[hash_func_linear_probing(a[k],i)].push_back(a[i]);
    }
} 

bool search_linear_probing(int data)
{
    for(int i=0;i<MAX;++i)
    {
        if(v[hash_func_linear_probing(data,i)][0]==data)
            return true;
    }
    return false;
}

bool search(int data)
{
    for(int i=0;i<v[hash_func_linear_probing(data)].size();++i)
    {
        if(v[hash_func_linear_probing(data)][i]==data)
            return true;
    }
    return false;
}








int main()
{
    int a[9]={16,12,25,39,6,122,5,68,75};
    chaining_hash(a,9);
    cout<<search(16)<<endl;
    cout<<search(6)<<endl;
    cout<<search(122)<<endl;
    cout<<search(166)<<endl;
}




// quad hashing
/*


    h(x) = ( h(x) + f(i));
    f(i) = i*i
    i=0,1,2,.....MAX-1



*/


// Double hashing

/*

    h1(x) = x % 10
    h2(x) = 7 - ( x % 7 )
    h(x) = ( h1(x) + i * h2(x) ) % 10
    i=0,1,2,3,.....MAX-1

*/





// hash functions

/* 
1.MOD
2.Midsquare
3.Folding

in mod the size of hash should be a prime number


2. midsquare
    means to insert 11 square it and put 11 in middle digit positioin i.e. 11^2 =121  add it to 2 position


3.folding
    adding key 123347 in hash
    12+33+47 = 92 
    add 92 in hash
    or add 9 + 2 =11
    or add 1+1 = 2 
    add 2 
*/