#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& v, int k) {
    make_heap(v.begin(),v.end());
    while(k-1>0){
        pop_heap(v.begin(),v.end());
        v.pop_back();
        k--;
    }
    return v.front();
}

int main()
{
    int n,i=0;
    cin>>n;
    vector<int> v(n);
    while(n--)
        cin>>v[i++];
    int k;
    cin>>k;
    cout<<findKthLargest(v,k);
    return 0;
}
