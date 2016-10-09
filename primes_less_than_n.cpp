#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
    vector<bool> primes(n,true);
    primes[0]=false;
    primes[1]=false;

    for(int i=2;i<sqrt(n);++i)
        for(int j=i;j<n && i*j<n;++j)
            primes[i*j]=false;

    int count = 0;
    for(auto a:primes)
        if(a)
            count++;

    return count;

}

int main()
{
    int n;
    cin>>n;
    cout<<countPrimes(n);
    return 0;
}
