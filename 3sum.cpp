/*
   Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 */

#include <bits/stdc++.h>
using namespace std;
 vector<vector<int>> threeSum(vector<int>& nums) {
    	sort(nums.begin(),nums.end());
    	vector<vector<int>> res;
    	int minsum=INT_MAX;
    	int previ,prevj,prevk;
    	previ=prevj=prevk=INT_MAX;
    	for(int i=0;i<nums.size();++i){
    		if(i==0 || (i!=0 && nums[i-1]!=nums[i]))
    		{		
    			int j=i+1,k=nums.size()-1;
    			while(j<k)
    			{
    				if(-1*nums[i]<nums[j]+nums[k])
    					k--;
    				else if(-1*nums[i]>nums[j]+nums[k])
    					j++;
    				else if(-1*nums[i]==nums[j]+nums[k])
    				{
    				    if(nums[i]!=previ || nums[j]!=prevj || nums[k]!=prevk)
    					    res.push_back({nums[i],nums[j],nums[k]});
    					previ=nums[i];prevj=nums[j];prevk=nums[k];
    					j++;
    					k--;
    				}
    			}
    		}
    	}
    	return res;
    }

int main()
{
	vector<int> test1{-1, 0, 1, 2, -1, -4},test2{0,0,0,0},test3{-2,0,0,2,2,2};
	for(auto a:threeSum(test1)){
		for(auto b:a)
			cout<<b<<"\t";
		cout<<"\n";
	}
	return 0;
}
