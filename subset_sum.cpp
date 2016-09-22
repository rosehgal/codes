#include <bits/stdc++.h>
using namespace std;



bool subset_sum(vector<int> arr,int sum)
{
    int row=arr.size()+1,col=sum+1;
    vector<vector<int> > subset(row);

    for(auto &x:subset)
        x.resize(col);

    subset[0][arr[0]]=1;
    for(int i=1;i<row;++i)
        for(int j=1;j<col;++j)
            if(j-arr[i]>=0)
                subset[i][j]=subset[i-1][j-arr[i]] || subset[i-1][j];
            else
                subset[i][j]=subset[i-1][j];

    // for(auto &x:subset)
    // {
    //     for(auto &y:x)
    //         cout<<y<<" ";
    //     cout<<endl;
    // }
    return subset[row-1][col-1];
}


int main()
{
    int arr[]={1,5,6,7,9};
    cout<<subset_sum(vector<int>(arr,arr+sizeof(arr)/sizeof(arr[0])),28);
    return 0;
}
