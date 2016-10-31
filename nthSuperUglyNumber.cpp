#include <bits/stdc++.h>
using namespace std;

int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> ugly;ugly.push_back(1);
    vector<int> id(primes.size(),0);
    while(ugly.size()!=n){
        vector<int> temp(primes.size());
        for(int i=0;i<id.size();++i)
            temp[i]=ugly[id[i]]*primes[i];
        int min=*min_element(temp.begin(),temp.end());
        for(int i=0;i<temp.size();++i)if(min==temp[i])id[i]++;
        ugly.push_back(min);
    }
    return ugly.back();
}
int main()
{
    vector<int> primes{1,2,3,5,7,19};
    int n;
    cin>>n;
    cout<<nthSuperUglyNumber(n,primes);
    return 0;
}
