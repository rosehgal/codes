#include <bits/stdc++.h>
using namespace std;

int sum_of_all_numbers_till_n(int number)
{
    vector<int> digitcount(number+1);
    int sum=0;
    for(int i=0;i<10 && i<=number;++i)
    {    digitcount[i]=i;
        sum+=digitcount[i];
    }

    for(int i=10;i<=number;++i)
    {
        digitcount[i]=digitcount[i/10]+i%10;
        sum+=digitcount[i];
    }
     return sum;
}

int main()
{
    int number;
    cin>>number;
    cout<<sum_of_all_numbers_till_n(number);
    return 0;
}
