/*
Given an arbitrary ransom note string  and  another  string  containing  letters from  all  the  magazines,  write  a  function  that  will  return  true  if  the  ransom   note  can  be  constructed  from  the  magazines ;  otherwise,  it  will  return  false.   
*/


#include<bits/stdc++.h>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
   vector<int> vector(27,0);
   for(auto s:ransomNote)
       vector[s-'a']++;

   for(auto s:magazine)
       if(vector[s-'a']!=0)
           vector[s-'a']--;

   for(auto v:vector)
       if(v)
           return false;
}

int main()
{
    string a,b;
    cin>>a>>b;
    cout<<canConstruct(a,b);
    return 0;
}
