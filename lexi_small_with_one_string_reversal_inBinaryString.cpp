#include <bits/stdc++.h>

using namespace std;

//check if string a is smaller than string b
bool is_small(string a,string b)
{
    for(int i=0;i<a.size();++i)
        if(a[i]<b[i])
            return true;
    return false;
}

pair<int,int> reverse_pair(string str)
{
    int first=-1,last=-1,i;
    for(i=str.size()-1;i>=0;--i)
        if(str[i]=="b")
            break;
    first=i;

    for()

}


int main()
{
    string str;
    cin>>str;
    cout<<reverse_pair(str).first<<" "<<reverse_pair(str).second;
    return 0;
}
