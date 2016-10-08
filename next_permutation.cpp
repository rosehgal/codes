#include <bits/stdc++.h>
using namespace std;

string next_perm(string a)
{
    for(int i=a.size()-2;i>=0;--i)
    {
        if(a[i+1]>a[i])
        {
            int j;
            bool done=false;
            for(j=i+1;j<a.size();++j)
                if(a[j]>a[i])
                {
                    swap(a[j],a[i]);
                    done=true;
                }
            if(done)
            {
                string one=a.substr(0,i+1);
                string two=a.substr(i+1);
                sort(two.begin(),two.end());
                return one+two;
            }
        }
    }
    return a;
}

int main()
{
    string str;
    cin>>str;
    cout<<next_perm(str);
    return 0;
}
