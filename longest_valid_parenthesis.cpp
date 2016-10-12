#include <bits/stdc++.h>
using namespace std;


void isvalid(string str,int i,int j,vector<vector<int>> &isValid)
{
    stack<char> stk;
    int start=i;
    while(i<=j)
    {

        if(stk.size()!=0 && (stk.top()=='(' && str[i]==')'))
                stk.pop();
        else
            stk.push(str[i]);
        if(stk.size()==0 && i!=start)
            isValid[start][i]=1;
        i++;
    }
}
int longestValidParentheses(string s) {
    if(s.size()<1)
        return 0;

    vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
    vector<vector<int>> isValid(s.size(),vector<int>(s.size(),0));

    for(int i=0;i<s.size();++i)
        if(s[i]=='(')
            isvalid(s,i,s.size()-1,isValid);
    for(auto iv:isValid)
    {
        for(auto i:iv)
            cout<<i;
        cout<<endl;
    }
    for(int k=0;k<s.size()-1;++k)
        for(int i=0,j=k+1;i<s.size() && j<s.size();++i,++j)
            if(s[i]=='(' && s[j]==')' && isValid[i][j])
                    dp[i][j]=j-i+1;
            else
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
    return dp[0][s.size()-1];
}

int main()
{
    cin>>s;
    cout<<isvalid(s,0,s.size()-1);
    cout<<longestValidParentheses(s);
    return 0;
}
