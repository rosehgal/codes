#include <bits/stdc++.h>
using namespace std;


pair<int,int> max_palindrome(string str)
{
    vector<vector<int> > palin(str.size());
    for(auto &x:palin)
        x.resize(str.size());

    for(int i=0;i<str.size();++i)
        palin[i][i]=1;

    pair<int,int> ret;
    for(int k=1;k<str.size();++k)
    {
        for(int i=0,j=k;j<str.size();++i,++j)
            if(str[i]==str[j])
            {
                palin[i][j]=palin[i+1][j-1];
                if(palin[i][j]){
                    ret.first=i;
                    ret.second=j;
                }
            }
    }

    for(auto &x:palin)
    {
        for(auto y:x)
            cout<<y<<" ";
        cout<<endl;
    }
    return ret;
}


int main()
{
    string str;
    cin>>str;
    pair<int,int> p = max_palindrome(str);
    cout<<str.substr(p.first,p.second-p.first+1);
    return 0;
}
