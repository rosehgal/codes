#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        unordered_map<int,bool> sq;
        for(int i=1;i*i<=n+1;++i)
            sq[i*i]=true;

        vector<int> count(n+1);
        count[0]=1;
        count[1]=1;
        count[2]=2;

        for(int i=3;i<=n;++i)
        {
            if(sq[i])
            {
                count[i]=1;
                continue;
            }

            int j=i,min=10000;
            for(auto &it:sq)
            {
              int j=it.first;
              int temp=count[j]+count[i-j];
              if(temp<min)
                min=temp;
              if(min==2)
                break;
            }

            count[i]=min;
        }

        // for(int x:count)
        //     cout<<x<<" ";
        // cout<<endl;
        return count[n];
    }
};




int main()
{
  Solution s;
  int n;
  cin>>n;
  cout<<s.numSquares(n);
}
