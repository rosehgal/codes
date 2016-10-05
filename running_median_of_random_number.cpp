/*
elements are inserted into the expanding array
keeping tracks of the median using two heaps
*/


#include <bits/stdc++.h>
using namespace std;

void balance(auto &minheap,auto &maxheap)
{
    if(minheap.size()-maxheap.size()==1)
        return;

    while(minheap.size()-maxheap.size()<1)
    {
            minheap.push(maxheap.top());
            maxheap.pop();
    }
}

int main()
{
    vector<int> arr;
    int n,temp,curr_median,i=0;

    priority_queue<int> maxheap;
    priority_queue<int,vector<int>, greater<int> > minheap;

    cin>>n;
    int a,b;
    cin>>a>>b;

    if(a<b)
    {
        maxheap.push(a);
        minheap.push(b);
    }
    else
    {
        maxheap.push(b);
        minheap.push(a);
    }

    n=n-2;
    int count=2;
    while(n--)
    {

        cin>>a;
        count++;
        if(a<maxheap.top())
            maxheap.push(a);
        else
            minheap.push(a);
        balance(minheap,maxheap);
        cout<<"Current Median -- ";
        if(count%2==0)
            cout<<((float)minheap.top()+maxheap.top())/2;
        else
        {
            if(minheap.size()>maxheap.size())
                cout<<minheap.top();
            else
                cout<<maxheap.top();
        }
        cout<<endl;
    }
    return 0;
}
