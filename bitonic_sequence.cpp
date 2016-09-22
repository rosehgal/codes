#include <bits/stdc++.h>
using namespace std;

vector<int> length_max_inc_subseq(vector<int> &arr)
{
    vector<int> maxseq;
    for(int i=0;i<arr.size();++i)
    {
        int val=1;
        for(int j=0;j<i;++j)
            if(arr[i]>arr[j] && maxseq[j]+1>val)
                val=maxseq[j]+1;
        maxseq.push_back(val);
    }
    return maxseq;
}


int bitonic_seq(vector<int> arr)
{
    vector<int> fwd = length_max_inc_subseq(arr);
    reverse(arr.begin(),arr.end());
    vector<int> rev = length_max_inc_subseq(arr);
    int length = fwd[0]+rev[0];

    for(int i=1;i<fwd.size();++i)
    {
        int temp = fwd[i]+rev[i];
        if(temp>length)
            length = temp;
    }
    //one element is counted twice
    return length-1;
}


int main()
{
    int arr[]={10,23,1,43,67,90,12};
    cout<<bitonic_seq(vector<int>(arr,arr+sizeof(arr)/sizeof(arr[0])));
    return 0;
}
