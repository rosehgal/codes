/*
   Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 */
#include <bits/stdc++.h>
using namespace std;
int threeSumClosest(vector<int>& nums, int target) {
    if(nums.size()<3)
        return 0;
    sort(nums.begin(),nums.end());
    int closest=nums[0]+nums[1]+nums[2],curr;
    for(int i=0;i<nums.size()-2;++i)
    {
        int j=i+1,k=nums.size()-1;
        while(j<k)
        {
            curr=nums[i]+nums[j]+nums[k];
            if(curr==target)
                return curr;
            else if(abs(target-closest)>abs(target-curr))
                closest=curr;
            if(curr>target)
                k--;
            else
                j++;
        }
    }
    return closest;
}

int main()
{
	vector<int> test {1,1,1,0};
	int target;
	cin>>target;
	cout<<threeSumClosest(test,target);
	return 0;
}
