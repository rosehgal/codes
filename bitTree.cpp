#include <bits/stdc++.h>
using namespace std;

class BitTree{
private:
    vector<int> bit;
public:
    BitTree(vector<int> v){
        bit.resize(v.size()+1,0);
        for(int i=0;i<v.size();++i)update(i+1,v[i]);
    }
    void update(int i,int val){
        for(;i<bit.size();i+=i&-i)bit[i]+=val;
    }
private:
    int query(int i){
        int sum=0;
        for(;i>0;i-=i&-i)sum+=bit[i];
        return sum;
    }
public:
    //enter the range in upper and lower... where lower is inclusive.
    int rangeSum(int upper,int lower){
        return query(upper)-query(lower-1);
    }
};

int main(){
    vector<int> v{1,2,3,1,2,3,4};
    BitTree b(v);
    int x,y;
    cin>>x>>y;
    cout<<b.rangeSum(x,y);
    return 0;
}
