/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.
*/

#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int> nums){
    int lastpos=nums.size()-1;
    for(int i=nums.size()-1;i>=0;i--){
        if(i+nums[i]>=lastpos)
            lastpos=i;
    }
    return lastpos==0;
}

int main(){
    vector<int> v{1,0,2};
    cout<<canJump(v);
    return 0;
}
