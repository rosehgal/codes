#include <bits/stdc++.h>

using namespace std;

int min_sq_rep_of_num(int number)
{
    vector<int> sq(number+1);
    sq[0]=0;
    sq[1]=1;
    for(int i=2;i<=number;++i)
    {
        int min = INT_MAX;
        for(int j=1;j*j<i;++j)
            if(sq[i-j*j]+1<min)
                min=sq[i-j*j]+1;
        sq[i]=min;
    }
    return sq[number];
}

int main()
{
    int number;
    cin>>number;
    cout<<min_sq_rep_of_num(number);
    return 0;
}
