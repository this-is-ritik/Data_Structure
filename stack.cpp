#include<bits/stdc++.h>
using namespace std;
#define MAX 100
// LIFO - last in first out
class Stack
{
    int top;
    int*A;
    public:
        Stack()
        {   
            top=-1;
            A=new int[MAX];
        }
        void push(int data)
        {
            if(isFull())
                return;
            A[++top]=data;
        }
        int pop()
        {
            if(isEmpty())
                return -1;
            return A[top--];
        }
        bool isEmpty()
        {
            if(top==-1)
                return true;
            return false;
        }
        bool isFull()
        {
            if(top==MAX-1)
                return true;
            return false;
        }
        int stacking()
        {
            if(isEmpty())
                return -1;
            return A[top];
        }
        int peek(int position)
        {
            int index=top+1-position;
            if(index<0 or index>top)
            {
                return -1;
            }
            return A[index];
        }
};
void displayChoice()
{
    cout<<"Stack Menu : \n";
    cout<<"1. push\n";
    cout<<"2. pop\n";
    cout<<"3. Value at given Position\n";
    cout<<"4. Value at top\n";
    cout<<"5. Quit\n";
}
int main()
{
    Stack s1;
    bool flag=true;
    while(flag)
    {
        int choice;
        displayChoice();
        cin>>choice;
        switch(choice)
        {
            case 1:
                int data;
                cout<<"Enter element to push : ";
                cin>>data;
                s1.push(data);
                break;
            case 2:
                cout<<"Popped value is : "<<s1.pop();
                break;
            case 3:
                int position;
                cout<<"Enter Position : ";
                cin>>position;
                cout<<"Value is : "<<s1.peek(position);
                break;
            case 4:
                cout<<"Value at top is : "<<s1.stacking();
                break;
            default :
                flag=false;
                break;
        }
        cout<<endl;
        cout<<endl;
    }
    return 0;
}