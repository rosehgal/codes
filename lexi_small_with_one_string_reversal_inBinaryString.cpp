#include <bits/stdc++.h>

using namespace std;

//check if string a is smaller than string b
bool is_small(string a,string b)
{
    for(int i=a.size()-1;i>=0;--i)
        if(a[i]<b[i])
            return true;
    return false;
}

pair<int,int> reverse_pair(string str)
{
    int first=-1,last=-1,i;
    string minstr = str;

    for(i=str.size()-1;i>=0;--i)
        if(str[i]=='b')
            break;
    first=i;

    if(first == -1)
        return pair<int,int>(-1,-1);

    for(int j=0;j<first;++j)
    {
        if(str[j]=='a')
        {
            //cout<<j<<endl;
            string prev = str.substr(0,j);
            string suff = str.substr(first+1);
            string mid = str.substr(j,first-j+1);
            //reverse(mid.begin(),mid.end());
            string curr="";
            curr=prev+curr;
            curr=mid+curr;
            curr=suff+curr;
            cout<<curr<<endl;
            cin.get();
            cout<<prev<<"\t"<<mid<<"\t"<<suff<<endl;
            if(is_small(curr,minstr))
            {
                minstr=curr;
                last=j;
            }
        }
    }
    return pair<int,int>(first,last);
}


int main()
{
    string str;
    cin>>str;
    cout<<reverse_pair(str).first<<" "<<reverse_pair(str).second;
    return 0;
}
