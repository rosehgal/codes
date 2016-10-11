#include<bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& nums) {
    int sum=0;
    for(auto s:nums)
        sum+=s;
    if(sum%2)
        return false;
    sum=sum/2;

    vector<vector<bool>> sumdp(nums.size()+1,vector<bool>(sum+1,false));
    sumdp[0][0]=true;
    for(int i=0;i<nums.size()+1;++i)
        sumdp[i][0]=true;

    for(int i=1;i<sumdp.size();++i)
        for(int j=1;j<sumdp[i].size();++j)
            if(j-nums[i-1]>=0)
                sumdp[i][j]=sumdp[i-1][j-nums[i-1]] || sumdp[i-1][j];
            else
                sumdp[i][j]=sumdp[i-1][j];

    if(sumdp[nums.size()][sum])
        return true;
    return false;
}

int main()
{
    vector<int> v{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,97,95,99,99};
    cout<<canPartition(v);
    return 0;
}
