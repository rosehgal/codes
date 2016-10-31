#include<buts/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int maxsofar,currmax=nums[0],currmin=nums[0],tempmin,tempmax;
    maxsofar=max(currmax,currmin);
    for(int i=1;i<nums.size();++i){
        tempmin=currmin*nums[i];
        tempmax=currmax*nums[i];
        currmax=max(tempmax,max(nums[i],tempmin));
        currmin=min(tempmin,min(nums[i],tempmax));
        maxsofar=max(maxsofar,currmax);
    }
    return maxsofar;
}

int main(){
    vector<int> temp{-1,2,3,4,5,-2};
    cout<<maxProduct(temp);
    return 0;
}
