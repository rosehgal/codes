#include<bits/stdc++.h>
using namespace std;

bool mysort(string a,string b)
{
    string ab=a+b,ba=b+a;
    return ab>ba;
}


string largestNumber(vector<int>& nums) {
    //sort(nums.begin(),nums.end(),mysort);
    vector<string> n;
    for(auto a:nums)
    {
        stringstream ss;
        ss<<a;
        n.push_back(ss.str());
    }
    sort(n.begin(),n.end(),mysort);
    string s="";
    if(n[0]=="0")
        return "0";
    for(auto a:n)
        s+=a;
    return s;

}


int main()
{
    vector<int> v{2,3,4,7};
    cout<<largestNumber(v);
    return 0;
}
