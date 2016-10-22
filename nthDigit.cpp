#include <bits/stdc++.h>
using namespace std;

vector<int> digit(int n){
    if(n<10){
        return vector<int>{n};
    }
    else{
        vector<int> result;
        vector<int> ret=digit(n/10);
        result.insert(result.end(),ret.begin(),ret.end());
        result.push_back(n%10);
        return result;
    }
}

int findNthDigit(int n){
    vector<int> d;
    for(int i=0;i<=n && d.size()<=n;++i)
    {
        vector<int> res=digit(i);
        d.insert(d.end(),res.begin(),res.end());
    }
    return d[n];
}

int main(){
    int n;
    cin>>n;
    cout<<findNthDigit(n);
    return 0;
}
