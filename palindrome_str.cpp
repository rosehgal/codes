#include <bits/stdc++.h>
using namespace std;

static bool to_remove(char c){
    if((c>='a'&&c<='z') || (c>='A'&& c<='Z') || (c>='0' && c<='9'))
        return false;
    return true;
}
bool isPalindrome(string s) {
    s.erase(remove_if(s.begin(),s.end(),to_remove),s.end());
    for(auto &c:s)if(isalpha(c))c=tolower(c);
    string o=s;
    reverse(o.begin(),o.end());
    return o==s;
}

int main()
{
    string str;
    cin>>str;
    cout<<((isPalindrome(str)==true)?"True":"False");
    return 0;
}
