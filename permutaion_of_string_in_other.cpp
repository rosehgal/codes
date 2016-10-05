/* finding all permutations of shorter sting in the longer one and print its position */


#include <bits/stdc++.h>

using namespace std;

bool same(vector<int> a,vector<int>b)
{
    for(int i=0;i<a.size()&&i<b.size();++i)
        if(a[i]!=b[i])
            return false;
    return true;
}

vector<int> string_permutations_in_other(string text,string pattern)
{
    vector<int> count1(CHAR_MAX,0),count2(CHAR_MAX,0);
    vector<int> result;

    for(int i=0;i<pattern.size();++i)
    {
        count1[text[i]]++;
        count2[pattern[i]]++;
    }

    for(int i=0;i<text.size()-pattern.size()+1;++i)
    {
        if(same(count1,count2))
            result.push_back(i);
        count1[text[i]]--;
        count1[text[pattern.size()+i]]++;

    }
    return result;
}



int main()
{
    string text,pattern;
    cin>>text;
    cin>>pattern;
    for(int i:string_permutations_in_other(text,pattern))
        cout<<text.substr(i,pattern.size())<<endl;
    return 0;
}
