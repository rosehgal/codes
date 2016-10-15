#include <string>
#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if(strs.size()==0)
        return "";

    int min=strs[0].size();

    for(int i=0;i<strs.size();++i)
        if(strs[i].size()<min)
            min=strs[i].size();

    string lcp="";

    for(int i=0;i<min;++i)
    {
        for(int j=0;j<strs.size();++j)
        {
            if(strs[0][i]!=strs[j][i])
                return lcp;
        }
        lcp+=strs[0][i];
    }
    return lcp;
}

int main()
{
    int n,i=0;
    cin>>n;
    vector<string> str(n);
    while(n--)
        cin>>str[i++];
    cout<<longestCommonPrefix(str);
}
