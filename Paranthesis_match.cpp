#include<bits/stdc++.h>
#include<string>
using namespace std;
//Application of stack

/*def valid(self):
        openList=[ "[","(","{"]
        closedList=["]",")","}"]
        stack=[] 
        for i in range(0,len(self.s)):
            if(self.s[i] in openList):
                stack.append(self.s[i])
                continue
            elif(self.s[i] in closedList):
                if(len(stack)==0):
                    return False
                else:
                    pos=closedList.index(self.s[i])
                    if(stack[-1]==openList[pos]):
                        stack.pop()
                        continue
                    else:
                        return False
            else:
                continue
        if(len(stack)==0):
            return True
        return False
*/
bool validate(string s)
{
    stack<char>stk;
    for(int i=0;s[i]!='\0';++i)
    {
        if(s[i]=='(' or s[i]=='[' or s[i]=='{')
            stk.push(s[i]);
        else if(s[i]==')')
        {
            if(stk.top()=='(' and !stk.empty())
                stk.pop();
            else
                return false;
        }
        else if(s[i]==']')
        {
            if(stk.top()=='[' and !stk.empty())
                stk.pop();
            else
                return false;
        }
        else if(s[i]=='}')
        {
            if(stk.top()=='{' and !stk.empty())
                stk.pop();
            else
                return false;
        }
        else
            ;        
    }
    return stk.empty();
}
// [{]}
int main()
{
    string s;                           // {(a+b})[] is invalid expression
    getline(cin,s);
    if(validate(s))
        cout<<"Valid expression!!!";
    else
        cout<<"Not a valid expression!!!";
}