#incldue <bits/stdc++.h>
using namespace std;

bool island(vector<vector<char>> &grid,int i,int j){
    if(i<0||j<0||i>=grid.size()||j>=grid[i].size()||grid[i][j]=='X'||grid[i][j]=='0')return false;
    else{
        grid[i][j]='X';
        island(grid,i+1,j);
        island(grid,i,j+1);
        island(grid,i-1,j);
        island(grid,i,j-1);
        return true;
    }
}

int numIslands(vector<vector<char>>& grid) {
    int count=0;
    for(int i=0;i<grid.size();++i)
        for(int j=0;j<grid[i].size();++j)
            if(island(grid,i,j))count++;
    return count;
}
