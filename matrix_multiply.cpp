#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrix_multiply(vector<vector<int>> mat1,vector<vector<int>> mat2)
{
    vector<vector<int>> mat(mat1.size(),vector<int>(mat2.size()));
    if(mat1[0].size() != mat2.size())
        return mat;

    for(int i=0;i<mat1.size();++i)
        for(int j=0;j<mat2.size();++j)
        {
            int sum=0;
            for(int k=0;k<mat2.size();++k)
                sum+=mat1[i][k]*mat2[k][j];
            mat[i][j]=sum;
        }

    return mat;
}


int main()
{
    vector<vector<int>> mat1{{1,1},{1,0}},mat2{{1,1},{1,0}},prod;
    prod=matrix_multiply(mat1,mat2);
    for(auto a:prod)
    {
        for(auto b:a)
            cout<<b<<" ";
        cout<<"\n";
    }
    return 0;
}
