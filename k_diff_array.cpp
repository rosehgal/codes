#include<bits/stdc++.h>

using namespace std;

int kth_diff(vector<int> arr,int k)
{
    unordered_map<int,int> map;
    for(auto x:arr)
        if(map.count(x)<=0)
            map[x]=1;

    int count=0;
    for(auto x:arr)
        if(map[x+k]==1)
        {
            cout<<"("<<x<<","<<x+k<<")"<<endl;
            count++;
        }
    return count;
}


int main()
{
    vector<int> arr{1,7,5,9,2,12,3};
    int k;
    cin>>k;
    cout<<kth_diff(arr,k);
    return 0;
}
