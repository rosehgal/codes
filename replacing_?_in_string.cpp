#include <bits/stdc++.h>

using namespace std;

bool possible = false;

void strings(string prefix,string str,int i)
{
    if(i==str.size())
    {
        cout<<prefix<<"\n";
        return ;
    }
    else if(str[i]=='?')
    {
        possible=true;
        if(i==0)
        {
            if(str[i+1]!='a')
                strings(prefix+"a",str,i+1);
            if(str[i+1]!='b')
                strings(prefix+"b",str,i+1);
            if(str[i+1]!='c')
                strings(prefix+"c",str,i+1);
        }

        else
        {
            if(prefix[i-1]=='a')
            {
                if(str[i+1]!='b')
                    strings(prefix+"b",str,i+1);
                if(str[i+1]!='c')
                    strings(prefix+"c",str,i+1);
            }
            else if(prefix[i-1]=='b')
            {
                if(str[i+1]!='a')
                    strings(prefix+"a",str,i+1);
                if(str[i+1]!='c')
                    strings(prefix+"c",str,i+1);
            }
            else
            {
                if(str[i+1]!='a')
                    strings(prefix+"a",str,i+1);
                if(str[i+1]!='b')
                    strings(prefix+"b",str,i+1);
            }
        }
    }
    else
        strings(prefix+str[i],str,i+1);
}



int main()
{
    string str;
    cin>>str;
    strings("",str,0);
    if(!possible)
        cout<<"Not Possible ";
    return 0;
}
