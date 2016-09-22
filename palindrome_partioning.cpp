#include <bits/stdc++.h>
using namespace std;

int maximum_size_palin_parition(string str)
{
    vector<vector<int> > cuts(str.size());
    for(auto &x:cuts)
        x.resize(str.size());

    for(int i=0,j=0;i<cuts.size();++i,++j)
        cuts[i][j]=1;

    for(int s=1;s<cuts.size();++s)
    {
        for(int i=0,j=s;i<str.size()&&j<str.size();++i,++j)
            if(str[i]==str[j])
                cuts[i][j]=cuts[i+1][j-1]+2;
            else
                cuts[i][j]=min(cuts[i][j-1],cuts[i+1][j]);
    }
    return cuts[0][str.size()-1];
}

int main()
{
    string str;
    cin>>str;
    cout<<maximum_size_palin_parition(str);
    return 0;
}
