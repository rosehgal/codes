#include <bits/stdc++.h>
using namespace std;


int permutation(string prefix,string suffix)
{
    static int count=0;

    if(suffix.size()==0)
    {
        cout<<prefix<<endl;
        count++;
    }
    else{
        for(int i=0;i<suffix.size();++i)
        {
            string rest = suffix.substr(0,i)+suffix.substr(i+1);
            permutation(prefix+suffix[i],rest);
        }
    }
    return count;
}


int main(int argc, char const *argv[]) {
    string str;
    cin>>str;
    cout<<permutation("",str);
    return 0;
}
