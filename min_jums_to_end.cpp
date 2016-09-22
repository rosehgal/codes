#include <bits/stdc++.h>
using namespace std;


int min_jumsp_to_end(vector<int> arr)
{
    vector<int> minjump(arr.size(),arr.size()+1);

    minjump[0]=0;

    for(int i=0;i<minjump.size();++i)
         for(int j=i+1;j<=i+arr[i]&&j<minjump.size();++j)
            minjump[j]=min(minjump[j],minjump[i]+1);

    return minjump.back();
}


int main()
{
    int arr[]={1, 3, 6, 1, 0, 9};
    cout<<min_jumsp_to_end(vector<int>(arr,arr+sizeof(arr)/sizeof(int)));
    return 0;
}
