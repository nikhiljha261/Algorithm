//har har mahadev
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(i,a,b)     for(int i=(a);i<(b);i++)
#define endl            "\n"
#define MAX 100
// cout<<fixed<<setprecision(9)<<" ";
// double rounded = std::floor((V * 100) + .5) / 100;

void ganeshji(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

class Stack
{
    int top; 
    public :
        int a[MAX];
        Stack()
        {
            top=-1;
        }
        bool push(int x);
        int pop();
        int peek();
        bool isempty();
};
bool Stack::push(int x)
{
    if(top>=MAX-1)
    {
        cout<<"Stack Overflow";
        return false;
    }
    else
    {
        a[++top]=x;
        cout<<x<<" has been pushed"<<endl;
        return true;
    }
}

int Stack::peek()
{
    if(top<0)
    {
        cout<<"stack is empty";
        return 0;
    }
    else
    {
        int x=a[top];
        return x;
    }
}

int Stack::pop(){
    if(top<0)
    {
        cout<<"stack is underflow";
        return 0;
    }
    else
    {
        int x=a[top--];
        return x;
    }
}
bool Stack::isempty()
{
    return top<0;
}
int main()
{
    ganeshji();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    clock_t begin = clock();
    ll t=1;
    // cin>>t;
    while(t--)
    {
        class Stack s;
        s.push(10);
        s.push(20);
        s.push(30);
        cout<<s.pop()<<" popped element from stack"<<endl;
        cout<<s.peek();
    }
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
}

