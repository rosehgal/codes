#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> *curr,*prev;
        prev=new vector<int>();
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();++i)
        {
          curr=new vector<int>();
          curr->push_back(nums[i]);

          for(int j=i-1;j>=0;--j)
            if(curr->front()%nums[j]==0)
              curr->insert(curr->begin(),nums[j]);

          //curr->push_back(nums[i]);

          for(int j=i+1;j<nums.size();++j)
            if(nums[j]%curr->back()==0)
              curr->push_back(nums[j]);

          cout<<"Current is ";
          for(vector<int>::iterator it = prev->begin();it<prev->end();++it)
              cout<<*it<<",";
            cout<<endl;
          if(curr->size()>prev->size())
            prev=curr;
        }





        // for(int i=0;i<nums.size();++i)
        // {
        //     cout<<i<<endl;
        //     curr=new vector<int>();
        //     curr->push_back(nums[i]);
        //     int j=i+1;
        //     while(j<nums.size())
        //     {
        //       cout<<"Current is ";
        //       for(vector<int>::iterator it = prev->begin();it<prev->end();++it)
        //           cout<<*it<<",";
        //         cout<<endl;
        //
        //       if(curr->size()>prev->size())
        //           prev=curr;
        //
        //         if(!(nums[j]%curr->back()))
        //             curr->push_back(nums[j++]);
        //
        //         else
        //           if(curr->size())
        //             curr->pop_back();
        //
        //     }
        //     //int k;
        //
        // }

        // for(vector<int>::iterator it = prev->begin();it<prev->end();++it)
        //     cout<<*it<<",";
        vector<int> divs(prev->begin(),prev->end());
        return divs;
    }
};



int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(6);
    nums.push_back(24);
    for(auto x:s.largestDivisibleSubset(nums))
      cout<<x;
    return 0;
}
