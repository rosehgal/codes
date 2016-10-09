#include<bits/stdc++.h>

using namespace std;

string longest_substring_wo_repeatingchars(string str)
{
    vector<int> count(27,0);
    int m=0;
    string res="";

    for(int i=0;i<str.size();++i)
    {
        int j;
        for(auto &c:count)
            c=0;

        for(j=i;j<str.size();++j)
            if(count[str[j]-'a'])
                break;
            else
                count[str[j]-'a']++;
        if(j-i>=m)
        {
            m=j-i;
            res=str.substr(i,j-i);
        }
    }
    return res;
}


int main()
{
    string str;
    cin>>str;
    cout<<longest_substring_wo_repeatingchars(str);
    return 0;
}
