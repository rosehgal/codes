#include <bits/stdc++.h>

using namespace std;

int count_disticnt_subsequences(string str)
{
    vector<int> last(CHAR_MAX,-1);
    vector<int> count(str.size()+1);

    count[0]=1;

    for( int i=1;i<=str.size();++i)
    {
        if(last[str[i-1]]==-1)
            count[i]=count[i-1]*2;
        else
            count[i]=count[i-1]*2-count[last[str[i-1]]-1];

        last[str[i-1]]=i;
    }
    return count[str.size()];
}


int main()
{
    string str;
    cin>>str;
    cout<<count_disticnt_subsequences(str);
    return 0;
}
