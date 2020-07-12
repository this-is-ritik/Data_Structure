#include<bits/stdc++.h>
using namespace std;




int precedence(char ch)
{
    switch(ch)
    {
        case '(':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
            return 3;
        case '/':
            return 4;
        case '^':
            return 5;
        default:
            return 0;
    }

}

// copied from course
string infixtopostfix(string s)
{
    string res;
    stack<char>stk;
    stk.push('$');
    for(int i=0;s[i]!='\0';++i)
    {
        if(s[i]=='(')
            stk.push(s[i]);
        else if(isalnum(s[i]))
            res.push_back(s[i]);
        else if(s[i]==')')
        {
            while(stk.top()!='(')
            {
                res.push_back(stk.top());
                stk.pop();
            }
            stk.pop();
        }
        else
        {
            while(precedence(s[i])<=precedence(stk.top()))
            {
                res.push_back(stk.top());
                stk.pop();
            }
            stk.push(s[i]);
        }
    }
    while(stk.top()!='$')
    {
        res.push_back(stk.top());
        stk.pop();
    }
    return res;
}

string InfixToPostfix(string s)
{
    string res;
    stack<char>opr;
    opr.push('$');
    for(int i=0;s[i]!='\0';++i)
    {
        if(s[i]=='(')
            opr.push('(');
        else if(isalnum(s[i]))
            res.push_back(s[i]);
        else if(s[i]==')')
        {
            while(opr.top()!='(')
            {
                res.push_back(opr.top());
                opr.pop();
            }
            opr.pop();          // for removing '(' from stack
        }
        else
        {
            while(precedence(s[i])<=precedence(opr.top()))
            {
                res.push_back(opr.top());
                opr.pop();
            }
            opr.push(s[i]);
        }
    }
    while(!opr.empty())
    {
        if(opr.top()=='$')
            break;
        res.push_back(opr.top());
        opr.pop();
    }
    return res;
}
int evaluate(int n1,int n2,char ch)
{
    switch(ch)
    {
        case '+':
            return n2+n1;
        case '-':
            return n2-n1;
        case '*':
            return n2*n1;
        case '/':
            return n2/n1;
        case '^':
            return (pow(n2,n1));
    }
    // in case of any error
    return -1;
}





int postfixEval(string s)
{
    stack<int>stk;
    for(int i=0;s[i]!='\0';++i)
    {   
        if(isdigit(s[i]))
            stk.push((int)s[i] - 48);
        else
        {
            int x1=stk.top();
            stk.pop();
            int x2=stk.top();
            stk.pop();
            int res=evaluate(x1,x2,s[i]);
            stk.push(res);
        }
    }
    int res=stk.top();
    stk.pop();
    return res;
}



int main()
{
    string inexpr;
    getline(cin,inexpr);
    string postexpr=infixtopostfix(inexpr);
    cout<<"Postfix : "<<postexpr<<endl;
    cout<<"Postfix (not copied code) : "<<InfixToPostfix(inexpr)<<endl; 
    cout<<"Value : "<<postfixEval(postexpr)<<endl;
    return 0;
}