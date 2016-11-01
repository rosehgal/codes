#include <bits/stdc++.h>
using namespace std;


vector<int> supperPasser(vector<int> nums){
    vector<int> sorted,result;
    for(int i=nums.size()-1;i>=0;--i){
        auto it = upper_bound(sorted.begin(),sorted.end(),nums[i]);
        result.insert(result.begin(),sorted.end()-it);
        sorted.insert(it,nums[i]);
    }
    return result;
}

int main(){
    vector<int> nums{2, 7, 5,3,3,3,3, 0, 8, 1};
    for(auto x:supperPasser(nums))
        cout<<x<<" ";
    return 0;
}
