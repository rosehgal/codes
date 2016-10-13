#include <bits/stdc++.h>


//only for nodes that have single digits + null # no ,
using namespace std;

bool has_leaf_then_remove(string &s)
{
    bool has_leaf=false;
    for(int i=0;i<s.size()-2 && s.size()!=1;++i)
    {
        if(isdigit(s[i]) && s[i+1]=='#' && s[i+2]=='#')
        {
            cout<<i<<endl;
            s[i]='#';
            has_leaf=true;
            s.erase(s.begin()+i+2);
            s.erase(s.begin()+i+1);
        }
    }
    return has_leaf;
}


bool valid_preorder(string &s)
{
    if(s=="#")
        return true;
    else{
        bool ret=has_leaf_then_remove(s);
        if(!ret)
            return false;
        valid_preorder(s);
    }
}

bool to_remove(char c)
{
    if(c==',')
        return true;
    else
        return false;
}

int main()
{
    string str;
    cin>>str;
    str.erase(remove_if(str.begin(),str.end(),to_remove),str.end());
    cout<<str;
    //has_leaf_then_remove(str);
    cout<<valid_preorder(str);
    return 0;
}
