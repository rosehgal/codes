#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    vector<vector<int>> paths(obstacleGrid.size(),vector<int>(obstacleGrid[0].size()));
    if(obstacleGrid[0][0]==1)
        return 0;
    paths[0][0]=1;
    for(int j=1;j<paths[0].size();++j)
        if(!obstacleGrid[0][j])
            paths[0][j]=paths[0][j-1];
        else
            paths[0][j]=0;
    for(int i=1;i<paths.size();++i)
        if(!obstacleGrid[i][0])
            paths[i][0]=paths[i-1][0];
        else
            paths[i][0]=0;

    for(int i=1;i<paths.size();++i)
        for(int j=1;j<paths[i].size();++j)
        if(!obstacleGrid[i][j])
            paths[i][j]=paths[i-1][j]+paths[i][j-1];
        else
            paths[i][j]=0;
    for(auto path:paths)
    {
        for(auto p:path)
            cout<<p<<"\t";
        cout<<endl;
    }
    return paths[paths.size()-1][paths[paths.size()-1].size()-1];
}

int main()
{
    vector<vector<int>> obstacleGrid{{0,0,0,1,0},{0,1,0,1,1},{1,0,0,0,0},{0,0,0,0,0}};
    cout<<uniquePathsWithObstacles(obstacleGrid);
    return 0;
}
