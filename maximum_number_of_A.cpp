#include <bits/stdc++.h>

using namespace std;

int max_A(int n)
{
    vector<int> number(n+1,0);
    number[1]=1;number[2]=2,number[3]=3;
    for(int i=4;i<=n;++i)
    {
        int m=INT_MIN;
        for(int j=i-3;j>=0;--j)
        {
            int temp = number[j]*(i-j-1);
            if(temp>m)
                m=temp;
        }
        number[i]=max(m,number[i-1]+1);
    }

    // for(auto a:number)
    //     cout<<a<<"\t";
    return number[n];
}

int main()
{
    int num;
    cin>>num;
    cout<<max_A(num)<<endl;
    return 0;
}
