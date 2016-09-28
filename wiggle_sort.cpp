#include <bits/stdc++.h>

using namespace std;

void wiggleSort(vector<int>& nums)
{
    vector<int> sorted = nums;

    sort(sorted.begin(),sorted.end());

    int upper_limit = ceil((float)nums.size()/2),loc=0;
    cout<<upper_limit<<endl;
    for(int i=0;i<upper_limit;++i,loc+=2)
        nums[loc]=sorted[i];

    loc=1;
    for(int i=upper_limit;i<nums.size();++i,loc+=2)
        nums[loc]=sorted[i];
}



int main()
{
    vector<int> arr{4,5,6,7,8,9,10};
    wiggleSort(arr);
    for(auto &a:arr)
        cout<<a<<" ";
    return 0;
}
