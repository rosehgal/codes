#include <bits/stdc++.h>

using namespace std;

void wiggleSort(vector<int>& nums)
 {
     vector<int> sorted = nums;
     sort(sorted.begin(),sorted.end());
     int upper_limit = ceil((float)nums.size()/2);
     int i=0,j=upper_limit,loc=nums.size()-1;
     while(i<j && loc>=0)
     {
         if(loc%2==1)
            nums[loc]=sorted[j++];
        else
            nums[loc]=sorted[i++];
        loc--;
     }
 }


int main()
{

    vector<int> arr{4,5,5,6};
    wiggleSort(arr);
    for(auto &a:arr)
        cout<<a<<" ";
    return 0;
}
