#include <bits/stdc++.h>

using namespace std;

struct elem{
    int val;
    int dir;
};

bool LCS(string a,string b)
{
    elem **mat = new elem*[a.size()+1];
    for(int i=0;i<=a.size();++i)
        mat[i]=new elem[b.size()+1];

    for(int i=0;i<=a.size();++i)
    {
        mat[i][0].val=0;
        mat[i][0].dir=0;
    }

    for(int j=0;j<=b.size();++j)
    {
        mat[0][j].val=0;
        mat[0][j].dir=1;
    }

    for(int i=1;i<=a.size();++i)
        for(int j=1;j<=b.size();++j)
        {
            if(a[i-1]==b[j-1])
            {
                mat[i][j].val=mat[i-1][j-1].val+1;
                mat[i][j].dir=2;
            }
            else
            {
                if(mat[i][j-1].val>=mat[i-1][j].val)
                {
                    mat[i][j].val=mat[i][j-1].val;
                    mat[i][j].dir=0;
                }
                else
                {
                    mat[i][j].val=mat[i-1][j].val;
                    mat[i][j].dir=1;
                }
            }
        }

    //cout<<mat[a.size()][b.size()].dir<<endl;
    int i=a.size(),j=b.size();
    string lcs = "";

    while(i>=0 && j>=0)
    {
        if(mat[i][j].dir==0)
            j--;
        else if(mat[i][j].dir==1)
            i--;
        else
        {
            lcs = a[i-1]+lcs;
            //cout<<lcs<<endl;
            i--;j--;
        }
    }
    if(a==lcs)
        return true;
    else
        return false;
}


int main()
{
    string a,b;
    cin>>a>>b;
    cout<<LCS(a,b);
    return 0;
}
