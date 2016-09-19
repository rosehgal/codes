#include <iostream>

using namespace std;

int count(int num)
{
      int *n = new int[num+1],sum=0;
      n[0]=0;
      for(int i=1;i<=num;++i)
            sum+=(n[i]=n[i/10]+i%10);
      return sum;
}


int main()
{
      int x;
      cin>>x;
      cout<<count(x);
      return 0;
}
