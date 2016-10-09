#include<bits/stdc++.h>

using namespace std;
vector<int> countSmaller(vector<int>& nums) {
    vector<int> sorted,result;
    for(int i=nums.size()-1;i>=0;--i)
    {
        auto it = sorted.insert(lower_bound(sorted.begin(),sorted.end(),nums[i]),nums[i]);
        result.insert(result.begin(),it-sorted.begin());
    }
    return result;
}

int main()
{
    vector<int> a{1,5,8,9,12};
    for(auto x:countSmaller(a))
        cout<<x;
    return 0;
}
