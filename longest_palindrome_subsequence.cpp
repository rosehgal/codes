#include <bits/stdc++.h>
using namespace std;

int longest_palindrome_sequence(string a)
{
    if(a.size()==1)
        return 1;
    else if(a.size()==2)
        if(a[0]==a[1])
            return 2;
        else
            return 1;
    else
        if(a[0]==a[a.size()-1])
        {
            string newstr = a.substr(1,a.size()-2);
            return longest_palindrome_sequence(newstr)+2;
        }
        else
        {
            string str1,str2;
            str1=a.substr(0,a.size()-1);
            str2=a.substr(1);
            return max(longest_palindrome_sequence(str1),longest_palindrome_sequence(str2));
        }
}


int main()
{
    string str;
    cin>>str;
    cout<<longest_palindrome_sequence(str);
    return 0;
}
