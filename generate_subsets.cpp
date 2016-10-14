#include <bits/stdc++.h>

using namespace std;

void generate_subsets(string prefix,string str)
{
    if(str.size()==0)
        if(prefix.size()==0)
            cout<<"\u0444"<<endl;
        else
            cout<<prefix<<endl;
    else
    {
        generate_subsets(prefix,str.substr(1));
        generate_subsets(prefix+str[0],str.substr(1));
    }
}

int main()
{
    string str;
    cin>>str;
    generate_subsets("",str);
    return 0;
}
