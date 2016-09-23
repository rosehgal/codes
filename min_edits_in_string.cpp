#include <iostream>
#include<string>
#include <vector>

using namespace std;


int min_edit(string a,string b)
{
    int row=a.size(),col=b.size();

    vector<vector<int> > edits(row+1);
    for(int i=0;i<=row;++i)
        edits[i].resize(col+1);

    for(int i=0;i<=row;++i)
        edits[i][0]=i;
    for(int j=0;j<=col;++j)
        edits[0][j]=j;
    // the first row is already set to 0

    for(int i=1;i<=row;++i)
        for(int j=1;j<=col;++j)
            if(a[i-1]==b[j-1])
                edits[i][j]=edits[i-1][j-1];
            else
                edits[i][j]=min(min(edits[i-1][j],edits[i][j-1]),edits[i-1][j-1])+1;
    for(auto x:edits)
    {
        for(auto y:x)
            cout<<y<<" ";
        cout<<"\n";
    }
    return edits[row][col];
}


int main()
{
    string a,b;
    cin>>a>>b;
    cout<<min_edit(a,b);
    return 0;
}
