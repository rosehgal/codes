#include <bits/stdc++.h>
using namespace std;


int longest_palindrome_sequence(string str)
{
    vector<vector<int> > palin_mat(str.size());
    for(int i=0;i<str.size();++i)
        palin_mat[i].resize(str.size());

    cout<<"roht\n";

    for(int i=str.size()-1;i>=0;--i)
        for(int j=str.size()-1;j>=str.size()-1-i;--j)
            if(i==j)
                palin_mat[i][j]=1;
            else if(str[i]==str[j])
                palin_mat[i][j]=palin_mat[i+1][j-1]+2;
            else
                palin_mat[i][j]=max(palin_mat[i+1][j],palin_mat[i][j-1]);
    return palin_mat[0][str.size()-1];
}

int main()
{
    string str;
    cin>>str;
    cout<<longest_palindrome_sequence(str);
    return 0;
}
