#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int max_value(vector<int> wts, vector<int> values,int capacity)
{
    int row = wts.size(),col=capacity;
    vector<vector<int> > capMat(row+1);

    for(auto &i:capMat)
        i.resize(col+1);

    for(int i=1;i<=row;++i)
    {
        for(int j=1;j<=col;++j)
            if(wts[i-1]<=j)
                capMat[i][j]=max(capMat[i-1][j-wts[i-1]]+values[i-1],capMat[i-1][j]);
            else
                capMat[i][j]=capMat[i-1][j];
    }
    
    return capMat[row][col];
}

int main()
{
    int wts[]={1,2,5,3,6},value[]={10,4,5,5,10},capacity=9;
    vector<int> weights(wts,wts+sizeof(wts)/sizeof(int)),values(value,value+sizeof(value)/sizeof(int));
    cout<<max_value(weights,values,capacity);
    return 0;
}
