#include <iostream>
#include <vector>
using namespace std;

int min_sum_path(vector<vector<int> > &mat)
{
    int row = mat.size(),col =mat[0].size();
    vector<vector<int> > dp(row);
    for(int i=0;i<row;++i)
        dp[i].resize(col);

    dp[0][0]=mat[0][0];

    for(int i=1;i<row;++i)
        dp[i][0]=dp[i-1][0]+mat[i][0];
    for(int j=1;j<col;++j)
        dp[0][j]=dp[0][j-1]+mat[0][j];

    for(int i=1;i<row;++i)
        for(int j=1;j<col;++j)
            dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+mat[i][j];

    return dp[row-1][col-1];
}


int main()
{
    int a[]={1,3,1},b[]={-1,4,5},c[]={5,6,1};
    vector<int> a1(a,a+3),b1(b,b+3),c1(c,c+3);
    vector<vector<int> > mat;
    mat.push_back(a1);
    mat.push_back(b1);
    mat.push_back(c1);
    cout<<min_sum_path(mat);
    return 0;
}
