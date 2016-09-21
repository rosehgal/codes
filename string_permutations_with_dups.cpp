#include <bits/stdc++.h>
using namespace std;

int permutations(string prefix,unordered_map<char,int> &map,int size)
{
    static int count=0;
    if(prefix.size()==size)
    {
        cout<<prefix<<endl;
        count++;
    }

    for(auto &m:map)
    {
        if(m.second==0)
            continue;
        m.second--;
        permutations(prefix+m.first,map,size);
        m.second++;
    }
    return count;
}


int main()
{
    string str;
    unordered_map<char,int> count;
    cin>>str;

    for(auto &s:str)
        if(count.count(s)<=0)
            count[s]=1;
        else
            count[s]++;

    cout<<permutations("",count,str.size());
    return 0;
}
