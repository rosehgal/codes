#include<bits/stdc++.h>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int count = (nums1.size()+nums2.size())/2;

    int i=0,j=0,m1=-1,m2=-1,k;
    for(k=0;k<=count && i<nums1.size() && j<nums2.size();++k)
        if(nums1[i]<=nums2[j])
        {
            m1=m2;
            m2=nums1[i++];
        }
        else
        {
            m1=m2;
            m2=nums2[j++];
        }

    if(i==nums1.size() && j<nums2.size())
        while(k++<=count)
        {
            m1=m2;
            m2=nums2[j++];
        }
    if(j==nums2.size() && i<nums1.size())
        while(k++<=count)
        {
            m1=m2;
            m2=nums1[i++];
        }

    if(((nums1.size()+nums2.size())%2)==0)
        return (m1+m2)/(float)2;
    else
        return m2;
}

int main()
{
    vector<int> v1{1,2,4,5,7},v2{4,6,8,8};
    cout<<findMedianSortedArrays(v1,v2);
    return 0;
}
