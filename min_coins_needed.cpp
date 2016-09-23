#include <bits/stdc++.h>
using namespace std;

int min_coins_needed(vector<int> coins,int amount)
{
    if(amount==0)
        return 0;

    vector<int> mincoin(amount+1,INT_MAX);      //to avoid integer overflow

    mincoin[0]=0;
    for(int i=1;i<=amount;++i)
    {
        int min = INT_MAX;
        for(auto &c:coins)
        {
            if(i-c>=0)
            {    if(mincoin[i-c]<min)
                    min=mincoin[i-c]+1;
            }
        }
        mincoin[i]=min;
    }


    for(auto a:mincoin)
        cout<<a<<" ";
    cout<<endl;
    return  mincoin[amount]==INT_MAX?-1:mincoin[amount];
}



int main()
{
    int coins[]={2};//,5,6};
    int amount;
    cin>>amount;
    cout<<min_coins_needed(vector<int>(coins,coins+sizeof(coins)/sizeof(coins[0])),amount);
    return 0;
}
