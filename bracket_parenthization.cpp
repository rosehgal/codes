#include <bits/stdc++.h>
using namespace std;


void bracket_parethization(string prefix,int total,int left)
{
    if(total==left)
    {
        cout<<prefix;
        for(int i=0;i<left;++i)
            cout<<")";
        cout<<endl;
        return ;
    }

    if(left<total)
        bracket_parethization(prefix+"(",total,left+1);
    if(left>0 && total>0)
        bracket_parethization(prefix+")",total-1,left-1);
}

int main()
{
    int temp;
    cout<<"Enter the size of the Parentization ";
    cin>>temp;
    bracket_parethization("",temp,0);
    return 0;
}
