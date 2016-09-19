#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:

    // int count;
    // void combinations(vector<int>&nums,int target)
    // {
    //     if(target==0)
    //         count++;

    //     if(nums.size()==0)
    //         return;

    //     for(int i=0;i<nums.size();++i)
    //     {
    //         if(nums[i]<=target)
    //             combinations(nums,target-nums[i]);
    //     }
    // }

    int combinationSum4(vector<int>& nums, int target) {
        // count=0;
        // if(target==0)
        //     return 0;
        // combinations(nums,target);
        // return count;

        vector<int> sums(target+1);
        sums[0]=0;
        for(int i=0;i<nums.size() && i<sums.size();++i)
            sums[i]=0;

        for(int i=0;i<nums.size() && i<sums.size();++i)
            sums[nums[i]]=1;
        // for(int i=0;i<sums.size();++i)
        //     cout<<sums[i];
        //     cout<<"\n";

        for(int i=1;i<sums.size();++i)
        {
            for(int j=0;j<nums.size();++j)
                if(nums[j]<i)
                    sums[i]+=sums[i-nums[j]];
        }

        // for(int i=0;i<sums.size();++i)
        //     cout<<i<<" "<<sums[i]<<endl;

        cout<<sums[target]<<endl;
        int x=sums[target];
        return x;

    }
};

int main()
{
    int a[]={13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,615};
    std::vector<int> v(a,a+sizeof(a)/sizeof(int));
    Solution s;
    cout<<s.combinationSum4(v,220);

}
