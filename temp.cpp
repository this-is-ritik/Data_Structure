#include <bits/stdc++.h>
using namespace std;
void showstack(stack<char>s) 
{ 
    cout<<"Stack contains :\t";
    while (s.top()!='$') 
    { 
        cout << s.top()<<" ";
        s.pop(); 
    } 
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        stack<char>stk;
        stk.push('$');
        showstack(stk);
        cout<<endl<<endl;
        int count=0;
        for(int i=0;str[i]!='\0';++i)
        { 
            if(stk.top()==str[i])
                stk.push(str[i]);
            else
            {
                if(stk.top()!='$')
                {
                    stk.pop();
                    count++;
                }
                else
                    stk.push(str[i]);
            }
        }
        cout<<count<<endl;
    }
	return 0;
}
/*
3
xy
xyxxy
yy
*/