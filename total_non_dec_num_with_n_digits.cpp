#include <bits/stdc++.h>

using namespace std;

int inc_num_n_digits(int digits)
{
    vector<int> *sum;
    sum = new vector<int>(10,1);

    for(int i=1;i<=digits;++i)
    {
        for(auto &x:(*sum))
            cout<<x<<" ";
        cout<<"\n";

        vector<int> *tempvec = new vector<int>(10);
        int temp=0;
        (*tempvec)[0]=1;

        for(int j=1;j<10;++j)
            (*tempvec)[j]=(*tempvec)[j-1]+(*sum)[j];

        sum = tempvec;
    }

    return (*sum)[9];
}


int main()
{
    int digits;
    cin>>digits;
    cout<<inc_num_n_digits(digits);
    return 0;

}
