#include<bits/stdc++.h>
#include<string.h>
#include<ctype.h>
using namespace std;

int cost(char c1,char c2)
{
    if(c1==c2)
        return 0;
    return 1;
}    
int edit_distance(string s1,string s2)
{
    int n1=s1.length();
    int n2=s2.length();
    int edit[n1][n2];
    for(int i=0;i<n1;++i)
        for(int j=0;j<n2;++j)
            edit[i][j]=min(edit[i][j-1]+1,min(edit[i-1][j]+1,edit[i-1][j-1]+cost(i,j)));
    for(int i=0;i<n1;++i)
    {
        for(int j=0;j<n2;++j)
        {
            cout<<edit[i][j]<<" ";
        }
        cout<<endl;
    }
    return edit[n1-1][n2-1];
}



void change_case(string &str)
{
    string s;
    for(int i=0;str[i]!='\0';++i)
    {
        
        if(isupper(str[i]))
            s.push_back(tolower(s[i]));
        else if(islower(str[i]))
            s.push_back(toupper(s[i]));
        else
            s.push_back(str[i]);        
    }
    str=s;
}


bool valid(char*str)
{
    for(int i=0;str[i]!='\0';++i)
    {
        if(isalnum(str[i]))
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

// anagrams are the same string but different permutation

// permutation of a string 

void display(char a[])
{
    for(int i=0;a[i]!='\0';++i)
        cout<<a[i];
    cout<<endl;
}
void perm(string str,int k)
{
    static int A[10]={0};
    static char res[10];
    int i;
    if(str[k]=='\0')
    {
        res[k]='\0';
        display(res);
        return;
    }
    for(i=0;str[i]!='\0';++i)
    {
        if(A[i]==0)
        {
            res[k]=str[i];
            A[i]=1;
            perm(str,k+1);
            A[i]=0;
        }
    }
}
void permutation(string str,int l,int r)
{
    // backtracking
    
    if(l==r) 
    {
        cout<<"Permutation : ";
        cout<<str<<endl;
    }
    for(int i=l;i<=r;++i)
    {
        swap(str[l],str[i]);
        permutation(str,l+1,r);
        swap(str[l],str[i]);
    }
}

int main()
{
    string s1="MOVIE",s2="LOVE";
    cout<<edit_distance(s2,s1)<<endl;
    //int x;
    //cin>>x;
    //cin.ignore();
    //getline(cin,str);
    //cout<<str;
    //cout<<endl<<x;

    //int length=0;
    //int i=0;
    //while(str[i++]!='\0');
    //cout<<(length=i)<<endl;

    // change case of string
    string a="abc";
    //change_case(a);   
    //cout<<a<<endl;
    //cout<<valid(a)<<endl;
    //permutation(a,0,a.length()-1);
    //perm(a,0);
    return 0;
}