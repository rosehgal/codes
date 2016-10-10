#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
	for(int i=0;i<nums.size();++i)
		for(int j=i+1;j<nums.size();++j)
			if(nums[i]+nums[j]==target)
				return vector<int>{i,j};

	return {0,0};

}

int main()
{
	vector<int> arr{3,2,1,4};
	int target;
	cin>>target;
	for(auto a:twoSum(arr,target))
			cout<<a<<" "<<endl;
	return 0;
}
