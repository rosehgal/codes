#include <iostream>
#include <string>

using namespace std;


int supersequence(string s1,string s2)
{
      int **lcs =  new int*[s1.length()+1];
      for(int i=0;i<=s1.length();++i)
            lcs[i] = new int[s2.length()+1];

      for(int i=0;i<=s1.size();++i)
            lcs[i][0]=0;
      for(int j=0;j<=s2.size();++j)
            lcs[0][j]=0;

      for(int i=1;i<=s1.size();++i)
            for(int j=1;j<=s2.size();++j)
                  lcs[i][j]=(s1[i-1]==s2[j-1])?lcs[i-1][j-1]+1:max(lcs[i-1][j],lcs[i][j-1]);

      return (s1.size()+s2.size())-lcs[s1.size()][s2.size()];
}


int main()
{
      string s1="AGGTAB",s2="GXTXAYB";
      cout<<supersequence(s1,s2);
      return 0;
}
