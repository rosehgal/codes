#include <bits/stdc++.h>
using namespace std;


int max_sq_submatix_of_one(vector<vector<int> >mat)
{
    vector<vector<int> > ones(mat.size());
    for(auto &x:ones)
        x.resize(mat[0].size());

    for(int i=0;i<mat[0].size();++i)
        ones[0][i]=mat[0][i];

    for(int i=0;i<mat.size();++i)
        ones[i][0]=mat[i][0];

    int largest=0;
    for(int i=1;i<mat.size();++i)
        for(int j=1;j<mat[0].size();++j)
        {
            if(mat[i-1][j] && mat[i][j-1] && mat[i-1][j-1])
                mat[i][j]=min(min(mat[i-1][j],mat[i][j-1]),mat[i-1][j-1])+1;
            else
                mat[i][j]=0;
            if(largest<mat[i][j])
                largest=mat[i][j];
        }

    return largest;
}

int main()
{
    vector<vector<int> > x(6);
    for(auto &y:x)
        y.resize(5);

    x[0][1]=1;
    x[0][2]=1;
    x[0][4]=1;

    x[1][0]=1;
    x[1][1]=1;
    x[1][3]=1;

    x[2][1]=1;
    x[2][2]=1;
    x[2][3]=1;

    x[3][1]=1;
    x[3][2]=1;
    x[3][4]=1;
    x[3][0]=1;

    x[4][1]=1;
    x[4][2]=1;
    x[4][4]=1;
    x[4][0]=1;
    x[4][5]=1;

    cout<<max_sq_submatix_of_one(x);
    return 0;
}
