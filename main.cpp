#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

void Translation(string c,string A,char* B)
{
    char k;
    stack<char> s;
    stack<char> t;
    queue<char> q;
    for(int i=c.size()-1;i>=0;i--)
    {
        s.push(c[i]);
    }
    while(!s.empty())
    {
        k=s.top();
        s.pop();
        t.push(k);
        if(k==')')
        {
            char x;
            t.pop();
            while(t.top()!='(')
            {
                x=t.top();
                q.push(x);
                t.pop();
            }
            t.pop();
            while(q.size()>1)
            {
                t.push(x);
                t.push(q.front());
                q.pop();
            }
            t.push(q.front());
            q.pop();
        }
    }
    while(!t.empty())
    {
        s.push(t.top());
        t.pop();
    }
    while(!s.empty())
    {
        k=s.top();
        s.pop();

        if(k=='A')
        {
            cout<<A;
            continue;
        }
        else if(k=='B')
        {
            for(int i=0;i<4;i++)
            {
                if(B[i]=='A') cout<<A;
                else cout<<B[i];
            }
            continue;
        }
             else
             {
                 cout<<k;
             }

    }



    cout<<endl;
}
int main()
{
    queue<char> q;
    string A="sae";
    char B[4]={'t','A','d','A'};
    string c;
    cin>>c;
    cout<<"解释后的语言为：\n";
    Translation(c,A,B);


    cout<<"\n";
    cout<<"再次输入魔王语言\n";
return 0;
}




