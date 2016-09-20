#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int possible_denominations(vector<int> coins, int amount)
{
    int row = coins.size(),col=amount;
    vector<vector<int> > coinMat(row);

    for(auto &i:coinMat)
        i.resize(col+1);

    for(int i=0;i<=col;i+=coins[0])
        coinMat[0][i]=1;


    for(int i=1;i<row;++i)
    {
        for(int j=0;j<=col;++j)
            if(j-coins[i]>=0)
                coinMat[i][j]=coinMat[i][j-coins[i]]+coinMat[i-1][j];
            else
                coinMat[i][j]=coinMat[i-1][j];
    }

    /*for(auto i:coinMat){
        for(auto j:i)
            cout<<j<<" ";
            cout<<"\n";
    }*/

    return coinMat[row-1][col];
}

int main()
{
    int coin[]={1,2,5},amount=10;
    vector<int> coins(coin,coin+3);
    sort(coins.begin(),coins.end());
    cout<<possible_denominations(coins,amount);
    return 0;
}
