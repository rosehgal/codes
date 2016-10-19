#include<bits/stdc++.h>
using namespace std;

void printSteppingNumber(int start,int end)
{
    queue<int> q;
    if(start==0)cout<<start<<" ";
    for(int i=1;i<=9;++i)q.push(i);
    while(!q.empty()){
        int curr=q.front(),next;q.pop();
        if(curr>=start)
            cout<<curr<<" ";
        int lastdigit=curr%10;
        if(lastdigit-1>=0){
            next=curr*10+lastdigit-1;
            if(next<=end)q.push(next);
        }
        if(lastdigit+1<=9){
            next=curr*10+lastdigit+1;
            if(next<=end)q.push(next);
        }
    }
}

int main()
{
    int start,end;
    cin>>start>>end;
    printSteppingNumber(start,end);
    return 0;
}
